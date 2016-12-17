#include "Tetris.h"

namespace tetris
{
	glm::vec3 Tetris::Colors[TILE_COUNT];
	Mesh* Tetris::Tiles[TILE_COUNT];
	Block Tetris::Blocks[BLOCK_TYPE_COUNT];


	std::vector<std::pair<glm::mat4, Mesh*>> Tetris::GetTileModelPairs()
	{
		std::vector<std::pair<glm::mat4, Mesh*>> Result;

		for (int x = 0; x < 10; x++)
		{
			for (int y = 0; y < 20; y++)
			{
				if (m_Board[x][y] == EMPTY)
					continue;

				glm::mat4 Model;
				Model = glm::translate(Model, glm::vec3(TileSizeX, TileSizeY, 0.0f) + glm::vec3(m_Position.x + (x * 2 * TileSizeX), m_Position.y + (y * 2 * TileSizeY), 0.0f));

				Result.push_back(std::make_pair(Model, Tiles[m_Board[x][y]]));
			}
		}


		return Result;
	}
	Tetris::Tetris(glm::vec3 Size, glm::vec3 Position)
	{
			Colors[YELLOW] = glm::vec3(0.3f);
			Colors[BLUE	 ] = glm::vec3(0.3f);
			Colors[RED	 ] = glm::vec3(0.3f);
			Colors[GREEN ] = glm::vec3(0.3f);
			Colors[ORANGE] = glm::vec3(0.3f);
			Colors[PINK	 ] = glm::vec3(0.3f);
			Colors[PURPLE] = glm::vec3(0.3f);

			TileSizeX = Size.x / 10.0f;
			TileSizeY = Size.y / 20.0f;
			TileSizeX /= 2;
			TileSizeY /= 2;
		for (int i = 0; i < TILE_COUNT; i++)
		{
			Tiles[i] = MeshFactory::CreateQuad(glm::vec3(0.0f), TileSizeX * 0.9f, TileSizeY * 0.9f, Colors[i]);
		}


		Blocks[O].Rotations[NORTH].Blocks[0][0] = YELLOW;
		Blocks[O].Rotations[NORTH].Blocks[1][0] = YELLOW;
		Blocks[O].Rotations[NORTH].Blocks[0][1] = YELLOW;
		Blocks[O].Rotations[NORTH].Blocks[1][1] = YELLOW;
		Blocks[O].Rotations[SOUTH] = Blocks[O].Rotations[WEST] = Blocks[O].Rotations[EAST] = Blocks[O].Rotations[NORTH];

		for (int x = 0; x < 10; x++)
		{
			for (int y = 0; y < 20; y++)
			{
				m_Board[x][y] = EMPTY;
			}
		}

		CurrentBlock = O;
		BlockPosition = glm::vec2(2.0f, 20.0f);
		BlockRotation = NORTH;
	}
	void Tetris::Update(GLfloat DeltaTime)
	{
		ElapsedTime += DeltaTime;
		std::cout << ElapsedTime << std::endl;
		if (ElapsedTime > 1.0f)
		{
			ElapsedTime -= 1.0f;
		}
		else
		{
			return;
		}

		BlockPosition.y--;
		if (BlockPosition.y == 0)
		{
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
				{
					if (GetPiece().Blocks[i][j] == EMPTY)
						continue;
					m_Board[((int)BlockPosition.x + i)][(int)BlockPosition.y + j] = GetPiece().Blocks[i][j];
				}
		}

		for (int x = 0; x < 10; x++)
		{
			for (int y = 0; y < 20; y++)
			{

			}
		}
	}
}
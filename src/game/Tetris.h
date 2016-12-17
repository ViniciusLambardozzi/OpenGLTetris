#pragma once

#include "../Common.h"
#include "../graphics/Mesh.h"

namespace tetris
{
	enum Tile
	{
		YELLOW,
		BLUE,
		RED,
		GREEN,
		ORANGE,
		PINK,
		PURPLE,
		TILE_COUNT,
		EMPTY
	};

	enum Rotation
	{
		NORTH = 0,
		SOUTH = 1,
		WEST = 2,
		EAST = 3,
		ROTATION_COUNT
	};

	struct Piece
	{
		Tile Blocks[4][4];
		Piece()
		{
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					Blocks[i][j] = EMPTY;
		}
	};

	struct Block
	{
		Piece Rotations[ROTATION_COUNT];
	};

	enum BlockTypes
	{
		O = 0,
		I,
		S,
		Z,
		L,
		J,
		T,
		BLOCK_TYPE_COUNT
	};

	class Tetris
	{
	public:
		static Mesh* Tiles[TILE_COUNT];
		static glm::vec3 Colors[TILE_COUNT];
		static Block Blocks[BLOCK_TYPE_COUNT];
		std::vector<std::pair<glm::mat4, Mesh*>> GetTileModelPairs();

		Tetris(glm::vec3 Size, glm::vec3 Position = glm::vec3(0.0f));

		void Update(GLfloat DeltaTime);

		void MoveBlockLeft();
		void MoveBlockRight();


	private:
		Tile m_Board[10][24];
		glm::vec3 m_Position;
		glm::vec3 m_Size;

		GLfloat TileSizeX;
		GLfloat TileSizeY;

		BlockTypes CurrentBlock;
		glm::vec2 BlockPosition;
		int BlockRotation;

		GLfloat ElapsedTime = 0.0f;

		Piece GetPiece() { return Blocks[CurrentBlock].Rotations[BlockRotation]; }
		void RotateLeft() {  BlockRotation++; BlockRotation %= 4; }
		void RotateRight() { BlockRotation--; if (BlockRotation < 0) BlockRotation = 3; }

		
	};
}

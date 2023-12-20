/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>
#include "color.h"
#include "myscene.h"
#include "myentity.h"

MyScene::MyScene() : Scene()
{
	// Initialize grid parameters
	gridwidth = 9;
	gridheight = 9;
	cellwidth = 64;
	cellheight = 64;

	// Create grid
	grid = new MyEntity();
	grid->addGrid("assets/boardGrid.tga", 8, 8, gridwidth, gridheight, cellwidth, cellheight);
	grid->position = Point2(SWIDTH / 3.34, SHEIGHT / 7);
	this->addChild(grid);

	// Calculate the center of the window.
	float centerX = SWIDTH / 2;
	float centerY = SHEIGHT / 2;

	// Create positions for each team in the corners.
	Point2 teamPositions[4] = 
	{
		Point2(centerX - cellSize * (gridSize - 1) / 2, centerY - cellSize * (gridSize - 1) / 2),   // Team 1 (top left corner)
		Point2(centerX + cellSize * (gridSize - 1) / 2, centerY - cellSize * (gridSize - 1) / 2),   // Team 2 (top right corner)
		Point2(centerX - cellSize * (gridSize - 1) / 2, centerY + cellSize * (gridSize - 1) / 2),   // Team 3 (bottom left corner)
		Point2(centerX + cellSize * (gridSize - 1) / 2, centerY + cellSize * (gridSize - 1) / 2)    // Team 4 (bottom right corner)
	};

	for (int i = 0; i < 4; ++i)
	{
		// Form the filename based on the team color
		std::string kingFilename = "assets/king_" + getTeamColorName(i) + ".tga";
		MyEntity* king = createAndAddEntity(kingFilename, teamPositions[i]);

		// Adjust positions for guards and knights relative to kings
		std::string guard1Filename = "assets/guard_" + getTeamColorName(i) + ".tga";
		MyEntity* guard1 = createAndAddEntity(guard1Filename, king->position + (i % 2 == 0 ? Point2(cellSize, 0) : Point2(-cellSize, 0)));

		std::string guard2Filename = "assets/guard_" + getTeamColorName(i) + ".tga";
		MyEntity* guard2 = createAndAddEntity(guard2Filename, king->position + (i < 2 ? Point2(0, cellSize) : Point2(0, -cellSize)));

		std::string knight1Filename = "assets/knight_" + getTeamColorName(i) + ".tga";
		MyEntity* knight1 = createAndAddEntity(knight1Filename, guard1->position + (i % 2 == 0 ? Point2(cellSize, 0) : Point2(-cellSize, 0)));

		std::string knight2Filename = "assets/knight_" + getTeamColorName(i) + ".tga";
		MyEntity* knight2 = createAndAddEntity(knight2Filename, guard2->position + (i < 2 ? Point2(0, cellSize) : Point2(0, -cellSize)));

		std::string knight3Filename = "assets/knight_" + getTeamColorName(i) + ".tga";
		MyEntity* knight3 = createAndAddEntity(knight3Filename, guard2->position + (i % 2 == 0 ? Point2(cellSize, 0) : Point2(-cellSize, 0)));
	}
}

MyScene::~MyScene()
{
	// Clean up grid
	this->removeChild(grid);
	delete grid;
}

void MyScene::update(float deltaTime)
{
	// Handle user input
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	// Update grid visuals
	updateGridVisuals();
}

MyEntity* MyScene::createAndAddEntity(const std::string& spritePath, const Point2& position)
{
	MyEntity* entity = new MyEntity();
	entity->addSprite(spritePath);
	entity->scale = Point3(0.45, 0.45, 0);
	entity->setPosition(position.x, position.y);
	this->addChild(entity);
	return entity;
}
std::string MyScene::getTeamColorName(int teamIndex)
{
	switch (teamIndex)
	{
	case 0: return "red";
	case 1: return "black";
	case 2: return "blue";
	case 3: return "purple";
	default: return "white";
	}
}

void MyScene::updateGridVisuals()
{
	std::vector<Sprite*> spritebatch = grid->spritebatch();
	int counter = 0;
	for (int x = 0; x < gridwidth; x++) 
	{
		for (int y = 0; y < gridheight; y++) 
		{
			spritebatch[counter]->frame(24);
			spritebatch[40]->frame(16);
			counter++;
		}
	}
}
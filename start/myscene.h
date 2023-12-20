/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include "scene.h"
#include "myentity.h"

class MyScene : public Scene
{
public:
	MyScene();
	~MyScene();

	virtual void update(float deltaTime);

	MyEntity* createAndAddEntity(const std::string& spritePath, const Point2& position);
	std::string getTeamColorName(int teamIndex);

private:
	const float cellSize = 64.0f;
	const int gridSize = 9;

	MyEntity* grid;

	int gridwidth;
	int gridheight;
	int cellwidth;
	int cellheight;

	void updateGridVisuals();
};

#endif /* MYSCENE_H */
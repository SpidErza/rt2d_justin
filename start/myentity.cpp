/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "color.h"
#include "myentity.h"
#include "input.h"


MyEntity::MyEntity() : Entity()
{
	
}

MyEntity::~MyEntity()
{

}

void MyEntity::update(float deltaTime)
{
	
}

void MyEntity::setPosition(float x, float y)
{
	position.x = x;
	position.y = y;
}
// myentity.h

#ifndef MYENTITY_H
#define MYENTITY_H

#include <rt2d/entity.h>
#include "color.h"

class MyEntity : public Entity {
public:
	MyEntity();
	virtual ~MyEntity();

	virtual void update(float deltaTime);

	void setPosition(float x, float y);

	void setTeamColor(const RGBAColor& color) {
		teamColor = color;
	}

	Point2 getPosition() const {
		return position;
	}

protected:
	std::vector<MyEntity*> layers;

private:
	RGBAColor teamColor;
};

#endif /* MYENTITY_H */

#pragma once
#include "Field.h"

struct Body
{
	Point point;
	Body* next;
};

class Snake
{
private:
	Body* body;
	int points;
	bool isDead;

	void eatFood();
	void die();
	void drawSnake(Field* field) const;

public:
	Snake(Field* field, const Point& startPosition);
	~Snake();

	void move(Field* field, const Point& point);
	bool hasDied() const;
	int getPoints() const;
};
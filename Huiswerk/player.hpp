#pragma once
#include "ball.hpp"

class player {
public:
	player(std::unique_ptr<paddle> & paddle1, int id = 0) :
		paddle1( paddle1 ),
		id(id)
	{}

	std::unique_ptr<paddle>& paddle1;
	int id;
	int health = 5;
};

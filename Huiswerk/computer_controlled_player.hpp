#pragma once
#include "player.hpp"

class computer_controlled_player : public player {
public:
	computer_controlled_player(std::unique_ptr<paddle>& paddle) :
		player(paddle )
	{}

};
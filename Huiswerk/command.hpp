#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "player.hpp"

class command {
public:
	command(player* actor, int value):
		actor(actor),
		value(value)
	{};

	player* actor;
	int value;
	virtual void execute(){actor->paddle1->position += sf::Vector2f(value,value);};
	virtual ~command(){}
};

// class change_color_command : public command{
// private:
// 	int & color_id;
// public:
// 	change_color_command( player* actor, int color_id ):
// 		command(actor),
// 		color_id(color_id)
// 	{}
// 	void execute() override;
// };

// class move_command : public command{
// private:
// 	int & value;
// public:
// 	move_command( player* actor, int value ):
// 		command(actor),
// 		value(value)
// 	{}

// 	void execute() override;
// };

#endif
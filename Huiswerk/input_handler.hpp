#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include "player.hpp"
#include "command.hpp"

class input_handler{
private:
	player* player_1;
	player* player_2;
	player* player_3;
	player* player_4;
	
public:

	input_handler( player* player_1, player* player_2 = NULL, player* player_3 = NULL, player* player_4 = NULL );

	void handle_input( std::vector< command > & commands );
	
}; // class input_handler.

#endif
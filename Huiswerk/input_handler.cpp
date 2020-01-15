// Class for handling all user input.

#include "input_handler.hpp"

input_handler::input_handler( player* player_1, player* player_2, player* player_3, player* player_4 ):
		player_1( player_1 ),
		player_2( player_2 ),
		player_3( player_3 ),
		player_4( player_4 )
	{}

void input_handler::handle_input(std::vector< command > & commands){
	
	// Ugly, use enum class later?
	auto button_red = 0;
	auto button_yellow = 1;
	auto button_green = 2;
	auto button_blue = 3;

	
	// Input handling for player 1.
	if( sf::Joystick::isButtonPressed( player_1->id, button_blue ) ) {
		commands.push_back(command( player_1, 0 ));
	}

	else if( sf::Joystick::isButtonPressed( player_1->id, button_yellow ) ) commands.push_back(command( player_1, 1 ));
	else if( sf::Joystick::isButtonPressed( player_1->id, button_green ) ) commands.push_back( command( player_1, 2 ));
	else if( sf::Joystick::isButtonPressed( player_1->id, button_red ) ) commands.push_back( command( player_1, 3 ));
	int_fast8_t y_axis_value = sf::Joystick::getAxisPosition( player_1->id, sf::Joystick::Y );
	commands.push_back(command( player_1, y_axis_value ));
	
	// Input handling for player 2, but only if player 2 exists.
//	if( player_2 != NULL ){
//		if( sf::Joystick::isButtonPressed( player_2.id, button_blue ) ) button_blue_->execute( player_2, button_blue );
//		else if( sf::Joystick::isButtonPressed( player_2.id, button_yellow ) ) button_yellow_->execute( player_2, button_yellow );
//		else if( sf::Joystick::isButtonPressed( player_2.id, button_green ) ) button_green_->execute( player_2, button_green );
//		else if( sf::Joystick::isButtonPressed( player_2.id, button_red ) ) button_red_->execute( player_2, button_red );
//		int_fast8_t y_axis_value = sf::Joystick::getAxisPosition( player_2.id, sf::Joystick::Y );
//		y_axis_->execute( player_2, y_axis_value );
//
//		// Input handling for player 3, but only if player 3 exists.
//		// Only check for player 3 if player 2 exists, there is no point otherwise.
//		if( player_3 != NULL ){
//			if( sf::Joystick::isButtonPressed( player_3.id, button_blue ) ) button_blue_->execute( player_3, button_blue );
//			else if( sf::Joystick::isButtonPressed( player_3.id, button_yellow ) ) button_yellow_->execute( player_3, button_yellow );
//			else if( sf::Joystick::isButtonPressed( player_3.id, button_green ) ) button_green_->execute( player_3, button_green );
//			else if( sf::Joystick::isButtonPressed( player_3.id, button_red ) ) button_red_->execute( player_3, button_red );
//			int_fast8_t x_axis_value = sf::Joystick::getAxisPosition( player_3.id, sf::Joystick::X );
//			x_axis_->execute( player_3, x_axis_value );
//		
//			// Input handling for player 4, but only if player 4 exists.
//			// Only check for player 4 if player 3 exists, there is no point otherwise.
//			if( player_4 != NULL ){
//				if( sf::Joystick::isButtonPressed( player_4.id, button_blue ) ) button_blue_->execute( player_4, button_blue );
//				else if( sf::Joystick::isButtonPressed( player_4.id, button_yellow ) ) button_yellow_->execute( player_4, button_yellow );
//				else if( sf::Joystick::isButtonPressed( player_4.id, button_green ) ) button_green_->execute( player_4, button_green );
//				else if( sf::Joystick::isButtonPressed( player_4.id, button_red ) ) button_red_->execute( player_4, button_red );
//				int_fast8_t y_axis_value = sf::Joystick::getAxisPosition( player_4.id, sf::Joystick::Y );
//				x_axis_->execute( player_4, x_axis_value );
//			}
//		}
//	}
};
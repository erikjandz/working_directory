#include "paddle.hpp"

void paddle::draw(sf::RenderWindow & window){
	rectangle.setPosition(position);
	window.draw(rectangle);
}

void paddle::update(int64_t passed_time, int8_t value){
	//move the paddle if user input and don't move out of the game
	if(sideways){
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && position.x >= 420){
			position.x -= 200 * (passed_time / 1000000.0);
		} 
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && position.x + rectangle.getSize().x <= 1500){
			position.x += 200 * (passed_time / 1000000.0);
		}
	} else{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && position.y >= 0){
			position.y -= 200 * (passed_time / 1000000.0);
		} 
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && position.y + rectangle.getSize().y <= 1065){
			position.y += 200 * (passed_time / 1000000.0);
		} 
	}
}

void paddle::setColor(uint_fast8_t color_id){
	switch(color_id){
		case 0:
			color = colors::RED;
			break;
		case 1:
			color = colors::YELLOW;
			break;
		case 2:
			color = colors::GREEN;
			break;
		case 3:
			color = colors::BLUE;
			break;
	}
}
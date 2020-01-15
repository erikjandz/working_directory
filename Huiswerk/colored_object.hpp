#pragma once
#include "drawable.hpp"

//every object with a color is a subclass of this class, and can store and retreive their color attribute here
class colored_object : public drawable {
public:
	colored_object(sf::Vector2f position):
		drawable{ position }
	{
		setRandomColor();
	}
	//enum that stores the color the object is
	enum class colors {RED, YELLOW, GREEN, BLUE};
	colors color;

	//return a sf::color depending on the the enum color
	sf::Color getSFMLColor() {
		if (color == colors::RED) {
			return sf::Color::Red;
		}else if (color == colors::YELLOW) {
			return sf::Color::Yellow;
		}else if (color == colors::GREEN) {
			return sf::Color::Green;
		}else{
			return sf::Color::Blue;
		}
	}

	//choose a random color and set the enum color
	void setRandomColor() {
		switch(rand() % 4){
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
		};
	};
	
	//choose a random color which is different than it was
	void setRandomDifferentColor() {
		colors temp = color;
		while (true) {
			setRandomColor();
			if (temp != color) {
				return;
			}
		}
	}

	virtual void setColor(uint_fast8_t color_id) {};
};
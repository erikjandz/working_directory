#pragma once
#include "player.hpp"
#include "ball.hpp"
#include "command.hpp"
#include "color_changing_powerup.hpp"

class game {
public:
	game(player player1, player player2, player player3, player player4);

	double timestamp_last_spawn = 0;

	//function decides whether or not to spawn a ball depending on passed time and amount of balls 
	void generate_ball();

	//this function adds power_ups sometimes
	void generate_power_ups();

	//void processInput(){
		//userInput = functie()
	//}

	//update the game
	void update();

	//draw everything on the window
	void render(sf::RenderWindow& window);

	//the game loop which handles user input, updates the game and renders it
	void game_loop();

	sf::Clock clock;
	sf::Time passed_time;
	int64_t passed_time_in_microseconds;
	double total_time_in_s;
	std::vector<std::unique_ptr<ball>> balls = {};
	std::vector<std::unique_ptr<player>> players = {};
	std::vector<std::unique_ptr<power_up>> power_ups = {};
};
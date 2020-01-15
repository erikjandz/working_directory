#include "game.hpp"

game::game(player player1, player player2, player player3, player player4)
{
	srand(time(NULL));
	players.push_back(std::make_unique<player>(player1));
	players.push_back(std::make_unique<player>(player2));
	players.push_back(std::make_unique<player>(player3));
	players.push_back(std::make_unique<player>(player4));
}

void game::generate_ball() {
	if ((total_time_in_s - timestamp_last_spawn) > 1) {
		if (balls.size() < 1 && total_time_in_s < 60) {
			balls.push_back(std::make_unique<ball>(sf::Vector2f{ 940, 520 }, rand() % 360 - 180, rand() % 170 + 80));
			timestamp_last_spawn = total_time_in_s;
		}
		else if (balls.size() < 2 && total_time_in_s >= 60) {
			balls.push_back(std::make_unique<ball>(sf::Vector2f{ 940, 520 }, rand() % 360 - 180, rand() % 170 + 80));
			timestamp_last_spawn = total_time_in_s;
		}
	}
};

void game::generate_power_ups() {
	if (rand() % 100 == 0) {
		power_ups.push_back(std::make_unique<color_changing_powerup>(sf::Vector2f{ sf::Vector2i{rand() % 1060 + 420, rand() % 1040 + 10 } }));
	}
}

void game::update() {
	//maybe spawn a ball, depending on passed time and amount of balls 
	generate_ball();
	//maybe spawn a power_up
	generate_power_ups();

	// for(const auto & commands : command){
	// 	command.execute();
	// }
	//command testcommand = command(&*players[0],10);

	if (rand() % 3 == 0) {
		//testcommand.execute();
		std::cout << "executed" << std::endl;
	};

	//update all objects with the passed time since last update
	for (auto& object : balls) {
		object->update(passed_time_in_microseconds);
	}
	// for (auto& object : players) {
	// 	object->paddle1->update(passed_time_in_microseconds);
	// }

	//let all balls interact with balls and paddles
	for (auto& object : balls) {
		for (auto& object2 : balls) {
			if (object != object2) {
				object->interact(object2);
			}
		}
		for (auto& object2 : players) {
			object->interact(object2->paddle1);
		}
		for (auto& power_up : power_ups) {
			power_up->interact(object);
		}
	}

	//if balls are out of bounds, yeetus deletus
	balls.erase(std::remove_if(balls.begin(), balls.end(), [](auto& object) {return object->position.x <= 420 || object->position.x >= 1500 || object->position.y <= 0 || object->position.y >= 1080; }), balls.end());
	//delete collected powerups
	power_ups.erase(std::remove_if(power_ups.begin(), power_ups.end(), [](auto& object) {return object->collected; }), power_ups.end());
}

void game::render(sf::RenderWindow& window) {
	//clear the window and draw all objects
	window.clear();
	for (auto& object : players) {
		object->paddle1->draw(window);
	}
	for (auto& object : balls) {
		object->draw(window);
	}
	for (auto& object : power_ups) {
		object->draw(window);
	}

	//draw the window on the screen
	window.display();
}

void game::game_loop() {
	sf::RenderWindow window{ sf::VideoMode{ 1920, 1080 }, "Ultimate Madness" };
	while (window.isOpen()) {
		//get the passed time, convert it to microseconds and restart clock
		passed_time = clock.getElapsedTime();
		clock.restart();
		passed_time_in_microseconds = passed_time.asMicroseconds();
		total_time_in_s += passed_time.asSeconds();

		//processinput
		update();
		render(window);

		//sleep
		sf::sleep(sf::milliseconds(20));

		//handle events
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}
}

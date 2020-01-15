#include "game.hpp"
#include <iostream>

int main() {
	auto paddle1 = std::make_unique<paddle>(sf::Vector2f{ 420, 10 }, 0);
	player player1 = player(paddle1);
	auto paddle2 = std::make_unique<paddle>(sf::Vector2f{ 1490, 10 }, 0);
	player player2 = player(paddle2);
	auto paddle3 = std::make_unique<paddle>(sf::Vector2f{ 420, 10 }, 1);
	player player3 = player(paddle3);
	auto paddle4 = std::make_unique<paddle>(sf::Vector2f{ 420, 1060 }, 1);
	player player4 = player(paddle4);

	game pong = game(player1, player2, player3, player4);
	pong.game_loop();
}
#pragma once

#include <SFML/Graphics.hpp>
#include "Stan.hpp"
#include "Game.hpp"
#include "Pipe.hpp"
#include "Land.hpp"
#include "Bird.hpp"
#include "Collision.hpp"
#include "HUD.hpp"


namespace Engine
{
	class GameState : public Stan
	{
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;

		Pipe* pipe;
		Land* land;
		Bird* bird;
		Collision collision;
		HUD* hud;

		sf::Clock clock;

		int _gameState;

		int _score;
	};
}
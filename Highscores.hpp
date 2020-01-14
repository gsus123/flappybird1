#pragma once

#include <SFML/Graphics.hpp>
#include "Stan.hpp"
#include "Game.hpp"
#include "MainMenuState.hpp"

namespace Engine
{
	class Highscores : public Stan
	{
	public:
		Highscores(GameDataRef data);
		


		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _gameOverTitle;
		sf::Sprite _gameOverContainer;
		sf::Sprite _GoBackButton;
		

		sf::Text _scoreText;
		sf::Text _highScoreText;

		
	};
}
#pragma once

#pragma once

#include <SFML/Graphics.hpp>
#include "Stan.hpp"
#include "Game.hpp"
#include "Highscores.hpp"


namespace Engine
{
	class MainMenuState : public Stan
	{
	public:
		MainMenuState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _title;
		sf::Sprite _playButton;
		sf::Sprite _HighscoresButton;
	};
}
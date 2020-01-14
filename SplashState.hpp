#pragma once

#include <SFML/Graphics.hpp>
#include "Stan.hpp"
#include "Game.hpp"

namespace Engine
{
	class SplashState : public Stan
	{
	public:
		SplashState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Clock _clock;

		sf::Sprite _background;
	};
}

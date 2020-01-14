#include <sstream>
#include "DEFINITIONS.hpp"
#include "Highscores.hpp"



#include <iostream>
#include <fstream>

namespace Engine
{
	Highscores::Highscores(GameDataRef data) : _data(data)
	{

	}

	void Highscores::Init()
	{

		

		_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Go Back Button", GO_BACK_BUTTON_FILEPATH);


		_background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
		_GoBackButton.setTexture(this->_data->assets.GetTexture("Go Back Button"));

		_gameOverContainer.setPosition(sf::Vector2f((_data->window.getSize().x / 2) - (_gameOverContainer.getGlobalBounds().width / 2), (_data->window.getSize().y / 2) - (_gameOverContainer.getGlobalBounds().height / 2)));
		_GoBackButton.setPosition(sf::Vector2f((_data->window.getSize().x / 2) - (_GoBackButton.getGlobalBounds().width / 2), _gameOverContainer.getPosition().y + _gameOverContainer.getGlobalBounds().height + (_GoBackButton.getGlobalBounds().height * 0.2)));

	
	}

	void Highscores::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_GoBackButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}
		}
	}

	void Highscores::Update(float dt)
	{

	}

	void Highscores::Draw(float dt)
	{
		_data->window.clear(sf::Color::Red);

		_data->window.draw(_background);
		_data->window.draw(_gameOverTitle);
		_data->window.draw(_gameOverContainer);
		_data->window.draw(_GoBackButton);
		

		_data->window.display();
	}
}
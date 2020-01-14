
#include <sstream>
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"
#include "GameState.hpp"
#include "Highscores.hpp"

#include <iostream>

namespace Engine
{
	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{

	}

	void MainMenuState::Init()
	{
		_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
		_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);
		_data->assets.LoadTexture("Highscores Button", HIGHSCORES_BUTTON_FILEPATH);


		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
		_title.setTexture(this->_data->assets.GetTexture("Game Title"));
		_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
		_HighscoresButton.setTexture(this->_data->assets.GetTexture("Highscores Button"));


		_title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), _title.getGlobalBounds().height / 2);
		_playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2));
		_HighscoresButton.setPosition((SCREEN_WIDTH / 2) - (_HighscoresButton.getGlobalBounds().width / 2 + _HighscoresButton.getGlobalBounds().width /60), (SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2 - _HighscoresButton.getGlobalBounds().height /1.75 ));

	}

	void MainMenuState::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}

			if (_data->input.IsSpriteClicked(_playButton, sf::Mouse::Left, _data->window))
			{
				_data->machine.AddState(StateRef(new GameState
				(_data)), true);
			}

			if (_data->input.IsSpriteClicked(_HighscoresButton, sf::Mouse::Left, _data->window))
			{
				_data->machine.AddState(StateRef(new Highscores
				(_data)), true);
			}

		}
	}

	void MainMenuState::Update(float dt)
	{

	}

	void MainMenuState::Draw(float dt)
	{
		_data->window.clear(sf::Color::Red);

		_data->window.draw(this->_background);
		_data->window.draw(this->_title);
		_data->window.draw(this->_playButton);
		_data->window.draw(this->_HighscoresButton);

		_data->window.display();
	}
}
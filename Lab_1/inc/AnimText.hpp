#pragma once
#include<Libraries.hpp>

class AnimatedText
{
private:
	float m_x = 0, m_y = 0;
	
	sf::Text* AnimText = nullptr;
	sf::Font* TxAnimText = nullptr;
	size_t m_fontSize = 0;

	sf::Clock clock;
	float m_start = 0; //גלוסעמ duration
	float m_end = 0;
	
	std::string m_str = "";
	std::string m_tmp = "";

public:
	AnimatedText(float x, float y, size_t fontSize, const std::string& str)
	{
		m_x = x;
		m_y = y;
		m_fontSize = fontSize;
		m_str = str;
		m_end = m_str.size();
	}
	
	~AnimatedText()
	{
		if (AnimText != nullptr)
			delete AnimText;
		if (TxAnimText != nullptr)
			delete TxAnimText;
	}

	void Setup()
	{
		AnimText = new sf::Text;
		TxAnimText = new sf::Font;

		AnimText->setCharacterSize(m_fontSize);
		AnimText->setColor(sf::Color::Green);
		AnimText->setPosition(m_x, m_y);

		if (!TxAnimText->loadFromFile("Images/BELL.TTF"))
			std::cout << "Failed to load BELL.TTF" << std::endl;
		else
			AnimText->setFont(*TxAnimText);

		AnimText->setString(m_str);
	}

	sf::Text* Get() 
	{ 
		return AnimText;
	}

	void Animation()
	{
		float time = clock.getElapsedTime().asMilliseconds();
		time = time / 1000;
		if ((time > 1) && (m_start < m_end + 1))
		{
			m_tmp += m_str[m_tmp.size()];
			clock.restart();
			++m_start;
		}
		if (m_start < m_end + 1)
			AnimText->setString(m_tmp);
	}
};
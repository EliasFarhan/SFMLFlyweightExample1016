#ifndef GRASS_H
#define GRASS_H

#include <SFML/Graphics.hpp>
#include <string>

class GrassTileMap
{
public:
	GrassTileMap(std::string filename, sf::Vector2f position);
	void draw(sf::RenderWindow&);
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Vector2u size;
	std::vector<sf::Vector2i> tilesPositions;
};

#endif

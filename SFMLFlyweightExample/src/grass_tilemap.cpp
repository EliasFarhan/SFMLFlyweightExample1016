#include <grass_tilemap.h>
#include <iostream>
#include <fstream>
#include <json.hpp>
using json = nlohmann::json;


const int X = 10;
const int Y = 10;
int tilemap [Y][X]=
{
		{0,1,0,2,1,0,1,0,1,2},
		{0,1,0,2,1,0,1,0,1,2},
		{0,1,0,2,1,0,1,0,1,2},
		{0,1,0,2,1,0,1,0,1,2},
		{0,1,0,2,1,0,1,0,1,2},
		{0,1,0,2,1,0,1,0,1,2},
		{0,1,0,2,1,0,1,0,1,2},
		{0,1,0,2,1,0,1,0,1,2},
		{0,1,0,2,1,0,1,0,1,2},
		{0,1,0,2,1,0,1,0,1,2},
};

const sf::Vector2i tileSize(48,48);

GrassTileMap::GrassTileMap(std::string filename, sf::Vector2f position)
{
	this->position = position;


	if (!texture.loadFromFile(filename))
	{
	    std::cerr << "[Error] Filename: "<<filename<<" does not exist\n";
	}
	std::ifstream i("tilemap_type.json");
	json j;
	i >> j;
	for(json& tileType : j["types"])
	{
		std::cout << tileType["name"] << " "<< tileType["pos"][0] << "\n";
		tilesPositions.push_back(sf::Vector2i(
				tileType["pos"][0],tileType["pos"][1]));
	}
	size = texture.getSize();
	sprite.setTexture(texture);
	sprite.setPosition(position);
}

void GrassTileMap::draw(sf::RenderWindow& window)
{

	for(int i = 0 ; i < X;i++)
	{
		for(int j = 0; j < Y;j++)
		{
			int tileType = tilemap[j][i];
			sprite.setTextureRect(sf::IntRect(
					sf::Vector2i(
						tilesPositions[tileType].x*tileSize.x,
						tilesPositions[tileType].y*tileSize.y),
					tileSize));
			sprite.setPosition(position+
					sf::Vector2f(i*tileSize.x,j*tileSize.y));
			window.draw(sprite);
		}
	}

}



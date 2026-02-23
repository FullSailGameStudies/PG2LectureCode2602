#include "Textures.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool Textures::LoadSubtextures()
{
	//
	// Part A-1
	//
	std::string fileName = "character_robot_sheetHD.csv";
	std::ifstream inFile(fileName);
	if (inFile.is_open())
	{
		std::getline(inFile, imageFile_);

		maxWidth_ = maxHeight_ = 0;
		char delim = '?';
		while (!inFile.eof())
		{
			std::string line;
			std::getline(inFile, line);

			SubTexture tex(line, delim);
			maxWidth_ = std::max(maxWidth_, tex.width);
			maxHeight_ = std::max(maxHeight_, tex.height);

			subTextures_.push_back(tex);
		}
		inFile.close();
		return true;
	}
	else
	{
		std::cout << fileName << " could not be opened.\n";
	}
	inFile.close();

	return false;
}

bool Textures::LoadSpritesheet(SDL_Renderer* renderer)
{
	spriteSheet_ = new PG2Texture(renderer);
	return spriteSheet_->LoadFromFile(imageFile_);
}

SDL_Rect Textures::GetTextureSource(int index)
{
	SDL_Rect rect{ 0,0,0,0 };
	if (index >= 0 && index < subTextures_.size())
	{
		rect.x = subTextures_[index].x;
		rect.y = subTextures_[index].y;
		rect.w = subTextures_[index].width;
		rect.h = subTextures_[index].height;
	}
	return rect;
}

void Textures::Render(SDL_Rect* texSrc, SDL_Rect* dest, SDL_RendererFlip flip)
{
	spriteSheet_->Render(texSrc, dest, 0, 0, flip);
}

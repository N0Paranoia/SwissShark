#ifndef TEXTURES_H
#define TEXTURES_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <string>
#include <iostream>

using namespace std;

class Textures
{
    public:
        Textures();
        virtual ~Textures();
        bool LoadFromFile(SDL_Renderer* Renderer, std::string path);
        bool LoadFromRenderedText(SDL_Renderer* Renderer, TTF_Font* Font, std::string textureText, SDL_Color textColor);
        void Free();
        void Render(SDL_Renderer* Renderer, int x, int y, SDL_Rect* clip = NULL);
        int getWidth();
        int getHeight();
    protected:
    private:
        //Actual hardware texture
        SDL_Texture* texture;

        //image dimensions
        int mWidth;
        int mHeight;
};

#endif // TEXTURES_H

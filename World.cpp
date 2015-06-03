#include "World.h"
#include "Constants.h"
#include "Textures.h"
#include "Tile.h"
#include <fstream>

//Texture playerTexture;
Textures TileSheetTexture;

World::World()
{
    Type = 0;
}

World::~World()
{
    //dtor
}

int World::Init(int x, int y, int TileType)
{

}


int World::LoadMedia(SDL_Renderer* Renderer, Tile* tiles[])
{
	//Load Tilemap
	if(!SetTiles(tiles))
	{
		cout << "Unable to load Tile Map! SDL_Error: " << SDL_GetError() << endl;
		return false;
	}
	//Load Player spritesheet
	if((TileSheetTexture.LoadFromFile(Renderer, "../assets/tileSheet48.png")) == NULL)
	{
		cout << "Unable to load Tile Texture! SDL_Error: " << SDL_GetError() << endl;
		return false;
	}
	else
	{
		//All tile textures
		TileClips[TILE_CLEAR].x = -TILE_SIZE;
		TileClips[TILE_CLEAR].y = -TILE_SIZE;
		TileClips[TILE_CLEAR].w = TILE_SIZE;
		TileClips[TILE_CLEAR].h = TILE_SIZE;

		TileClips[TILE_LEFT_TOP].x = 0 * TILE_SIZE;
		TileClips[TILE_LEFT_TOP].y = 0 * TILE_SIZE;
		TileClips[TILE_LEFT_TOP].w = TILE_SIZE;
		TileClips[TILE_LEFT_TOP].h = TILE_SIZE;

		TileClips[TILE_MIDDLE_TOP].x = 1 * TILE_SIZE;
		TileClips[TILE_MIDDLE_TOP].y = 0 * TILE_SIZE;
		TileClips[TILE_MIDDLE_TOP].w = TILE_SIZE;
		TileClips[TILE_MIDDLE_TOP].h = TILE_SIZE;

		TileClips[TILE_RIGHT_TOP].x = 2 * TILE_SIZE;
		TileClips[TILE_RIGHT_TOP].y = 0 * TILE_SIZE;
		TileClips[TILE_RIGHT_TOP].w = TILE_SIZE;
		TileClips[TILE_RIGHT_TOP].h = TILE_SIZE;

		TileClips[TILE_LEFT_MIDDLE].x = 0 * TILE_SIZE;
		TileClips[TILE_LEFT_MIDDLE].y = 1 * TILE_SIZE;
		TileClips[TILE_LEFT_MIDDLE].w = TILE_SIZE;
		TileClips[TILE_LEFT_MIDDLE].h = TILE_SIZE;

		TileClips[TILE_MIDDLE_MIDDLE].x = 1 * TILE_SIZE;
		TileClips[TILE_MIDDLE_MIDDLE].y = 1 * TILE_SIZE;
		TileClips[TILE_MIDDLE_MIDDLE].w = TILE_SIZE;
		TileClips[TILE_MIDDLE_MIDDLE].h = TILE_SIZE;

		TileClips[TILE_RIGHT_MIDDLE].x = 2 * TILE_SIZE;
		TileClips[TILE_RIGHT_MIDDLE].y = 1 * TILE_SIZE;
		TileClips[TILE_RIGHT_MIDDLE].w = TILE_SIZE;
		TileClips[TILE_RIGHT_MIDDLE].h = TILE_SIZE;

		TileClips[TILE_LEFT_BOTTOM].x = 0 * TILE_SIZE;
		TileClips[TILE_LEFT_BOTTOM].y = 2 * TILE_SIZE;
		TileClips[TILE_LEFT_BOTTOM].w = TILE_SIZE;
		TileClips[TILE_LEFT_BOTTOM].h = TILE_SIZE;

		TileClips[TILE_MIDDLE_BOTTOM].x = 1 * TILE_SIZE;
		TileClips[TILE_MIDDLE_BOTTOM].y = 2 * TILE_SIZE;
		TileClips[TILE_MIDDLE_BOTTOM].w = TILE_SIZE;
		TileClips[TILE_MIDDLE_BOTTOM].h = TILE_SIZE;

		TileClips[TILE_RIGHT_BOTTOM].x = 2 * TILE_SIZE;
		TileClips[TILE_RIGHT_BOTTOM].y = 2 * TILE_SIZE;
		TileClips[TILE_RIGHT_BOTTOM].w = TILE_SIZE;
		TileClips[TILE_RIGHT_BOTTOM].h = TILE_SIZE;
		
		TileClips[TILE_INNER_RIGHT_BOTTOM].x = 3 * TILE_SIZE;
		TileClips[TILE_INNER_RIGHT_BOTTOM].y = 0 * TILE_SIZE;
		TileClips[TILE_INNER_RIGHT_BOTTOM].w = TILE_SIZE;
		TileClips[TILE_INNER_RIGHT_BOTTOM].h = TILE_SIZE;
		
		TileClips[TILE_INNER_LEFT_BOTTOM].x = 4 * TILE_SIZE;
		TileClips[TILE_INNER_LEFT_BOTTOM].y = 0 * TILE_SIZE;
		TileClips[TILE_INNER_LEFT_BOTTOM].w = TILE_SIZE;
		TileClips[TILE_INNER_LEFT_BOTTOM].h = TILE_SIZE;
		
		TileClips[TILE_INNER_RIGHT_TOP].x = 3 * TILE_SIZE;
		TileClips[TILE_INNER_RIGHT_TOP].y = 1 * TILE_SIZE;
		TileClips[TILE_INNER_RIGHT_TOP].w = TILE_SIZE;
		TileClips[TILE_INNER_RIGHT_TOP].h = TILE_SIZE;
		
		TileClips[TILE_INNER_LEFT_TOP].x = 4 * TILE_SIZE;
		TileClips[TILE_INNER_LEFT_TOP].y = 1 * TILE_SIZE;
		TileClips[TILE_INNER_LEFT_TOP].w = TILE_SIZE;
		TileClips[TILE_INNER_LEFT_TOP].h = TILE_SIZE;
	}
}

bool World::SetTiles(Tile* tiles[])
{
    int x = 0;
    int y = 0;

    std::ifstream map("../assets/level.map");

    if (map == NULL)
    {
        cout << "Unable to load Tile Map file!" << endl;
        return false;
    }
    else
    {
        //Initialize tiles
        for(int i = 0; i < TOTAL_TILES; i++)
        {
            int Type = -1;

            map >> Type;

            if(map.fail())
            {
                cout << "Error loading map: Unexpected end of file!" << endl;
                return false;
                break;
            }
            //if number is valid tile number
            if((Type >= 0) && (Type < TOTAL_TILE_SPRITES))
            {
                tiles[i] = new Tile(x, y, Type);
            }
            else
            {
               cout << "Error loading map: Invalid tile type!" << endl;
               return false;
               break;
            }
            x += TILE_SIZE;
			//If we've gone too far
			if(x >= LEVEL_WIDTH*TILE_SIZE)
			{
                //Move back
				x = 0;
				//Move to the next row
				y += TILE_SIZE;
			}
        }

    }
    return true;
}

void World::Render(SDL_Renderer* Renderer, SDL_Rect* camera, Tile* tiles[])
{
    for(int i = 0; i < TOTAL_TILES; i++)
    {
        tiles[i]->Render(&TileSheetTexture, &TileClips[Type], Renderer, camera);
    }
}

#ifndef DOORS_H
#define DOORS_H

#include <SDL.h>
#include <iostream>
#include "Constants.h"

using namespace std;

class Doors
{
    public:
        Doors();
        virtual ~Doors();
        void Connection(SDL_Rect* player, int z);
    protected:
    private:
        SDL_Rect doorA[TOTAL_DOORS];
        SDL_Rect doorB[TOTAL_DOORS];
};
#endif // DOORS_H

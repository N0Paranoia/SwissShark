#include "Timer.h"

Timer::Timer()
{
    StartTicks = 0;
    PauseTicks = 0;

    Paused = false;
    Started = false;
}

Timer::~Timer()
{
    //dtor
}

void Timer::Start()
{
    Started = true;
    Paused = false;

    StartTicks = SDL_GetTicks();
    PauseTicks = 0;
}

void Timer::Stop()
{
    Started = false;
    Paused = true;

    StartTicks = 0;
    PauseTicks = 0;
}

void Timer::Pause()
{
    if(Started && !Paused)
    {
        Paused = true;

        PauseTicks = SDL_GetTicks() - StartTicks;
        StartTicks = 0;
    }
}

void Timer::Unpause()
{
    if(Started && Paused)
    {
        Paused = false;

        StartTicks = SDL_GetTicks() - PauseTicks;
        PauseTicks = 0;
    }
}

Uint32 Timer::getTicks()
{
    Uint32 time = 0;

    if(Started)
    {
        if(Paused)
        {
            time = PauseTicks;
        }
        else
        {
            time = SDL_GetTicks() - StartTicks;
        }
    }
    return time;
}

bool Timer::isStarted()
{
    return Started;
}

bool Timer::isPaused()
{
    return Paused;
}

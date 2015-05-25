#ifndef TIMER_H
#define TIMER_H
#include <stdint.h>
#include <SDL.h>

class Timer
{
    public:
        Timer();
        virtual ~Timer();
        //Clock actions
        void Start();
        void Stop();
        void Pause();
        void Unpause();
        //gets time
        Uint32 getTicks();
        //check status
        bool isStarted();
        bool isPaused();

    protected:
    private:
        //time when timer started
        Uint32 StartTicks;
        Uint32 PauseTicks;

        bool Paused;
        bool Started;
};

#endif // TIMER_H

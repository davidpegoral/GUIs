#include <SDL2/SDL.h>

int AUX_WaitEventTimeout (SDL_Event* evt, Uint32* ms) {
    Uint32 t1 = SDL_GetTicks();
    int ret = SDL_WaitEventTimeout(evt, *ms);
    Uint32 t2 = SDL_GetTicks();
    Uint32 deltatime = t2 - t1;

    if(deltatime >= *ms){
        *ms = 0;
    }
    else{
        *ms -= deltatime;
    }
    return ret;
}

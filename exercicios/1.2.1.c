#include <SDL2/SDL.h>

int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("1.2.1",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         200, 100, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    /* EXECUÇÃO */
    SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
    SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren, 0xFF,0x00,0x00,0x00);
    SDL_Rect r = { 60,40, 2,30 };
    SDL_RenderFillRect(ren, &r);
    SDL_Rect r1 = { 140,40, 2,30 };
    SDL_SetRenderDrawColor(ren, 0x00,0xFF,0x00,0x00);
    SDL_RenderFillRect(ren, &r1);
    SDL_SetRenderDrawColor(ren, 0xFF,0x00,0xFF,0x00);
    for(int i = 0; i < 100; i += 4){
        SDL_RenderDrawPoint(ren, 150, i);
    }
    for(int i = 0; i < 100; i += 4){
        SDL_RenderDrawPoint(ren, 50, i);
    }
    SDL_SetRenderDrawColor(ren, 0x00,0x00,0x00,0x00);
    SDL_Rect r2 = { 90,40, 5,5 };
    SDL_RenderFillRect(ren, &r2);
    SDL_RenderPresent(ren);
    SDL_Delay(5000);

    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

#include <SDL2/SDL.h>

int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("1.5.3",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         200, 100, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);
    SDL_Event evt;
    int delta = 2;

    /* EXECUÇÃO */
    SDL_Rect r = { 95,-8, 10,10 };
    while (r.y < 200) {
        SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0x00);
        SDL_RenderFillRect(ren, &r);
        SDL_RenderPresent(ren);
        SDL_Delay(100);
        SDL_WaitEventTimeout(&evt, 100);
        if(evt.type == SDL_QUIT){
            SDL_DestroyRenderer(ren);
            SDL_DestroyWindow(win);
            SDL_Quit();
            return 0;
        }
        else if(evt.type == SDL_KEYDOWN){
            switch(evt.key.keysym.sym){
                case SDLK_DOWN:
                    delta = -2; //inverte o sentido do movimento
                    break;
                case SDLK_UP:
                    delta = 2; //retorna ao sentido original
                    break;
                case SDLK_LEFT:
                    delta -= 2; //desacelera o quadrado
                    break;
                case SDLK_RIGHT:
                    delta += 2; //acelera o quadrado
                    break;            
            }
        }
        r.y += delta;
        if(r.y >= 100){
            r.y = -8;
        }
        else if(r.y <= -10){
            r.y = 100;
        }
    }

    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

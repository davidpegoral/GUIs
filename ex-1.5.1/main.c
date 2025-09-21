#include <SDL2/SDL.h>

int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Movendo um Retângulo",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         800, 600, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);
    int x,y, f;
    int count = 0;
    
    /* EXECUÇÃO */
    SDL_Rect r1 = {40, 180, 20,20 };
    SDL_Rect r2 = {40,380, 20,20 };
    SDL_Rect r3 = {40,580, 20,20 };
    SDL_Event evt;


    while (1) {
        Uint32 t = SDL_GetTicks();
        f = (int)(t / 200);
        SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0x00);
        SDL_RenderFillRect(ren, &r1);
        SDL_SetRenderDrawColor(ren, 0x00,0xFF,0x00,0x00);
        SDL_RenderFillRect(ren, &r2);
        SDL_SetRenderDrawColor(ren, 0xFF,0x00,0x00,0x00);
        SDL_RenderFillRect(ren, &r3);
        SDL_RenderPresent(ren);
        
        if(f > count){
            r2.x += 10;
            count++;
        }

        SDL_GetMouseState(&x, &y);
        r3.x = x;
        r3.y = y;

        SDL_WaitEventTimeout(&evt, 100);
        if (evt.type == SDL_KEYDOWN) {
            switch (evt.key.keysym.sym) {
                case SDLK_UP:
                    r1.y -= 5;
                    break;
                case SDLK_DOWN:
                    r1.y += 5;
                    break;
                case SDLK_LEFT:
                    r1.x -= 5;
                    break;
                case SDLK_RIGHT:
                    r1.x += 5;
                    break;
            }
        }
        else if (evt.type == SDL_QUIT) {  
            SDL_DestroyRenderer(ren);
            SDL_DestroyWindow(win);
            SDL_Quit();
            return 0;
        }
    }

    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

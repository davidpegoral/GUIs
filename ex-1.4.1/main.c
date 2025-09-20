#include <SDL2/SDL.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    srand(time(NULL));
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Movendo um Retângulo",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         200, 100, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);
    int red = rand() % 256;
    int green = rand() % 256;
    int blue = rand() % 256;
    SDL_Rect rects[10];
    SDL_Color colors[10];
    for (int i = 0; i < 10; i++){
        colors[i].r = red;
        colors[i].g = green;
        colors[i].b = blue;
        colors[i].a = 255;
        red = rand() % 256;
        green = rand() % 256;
        blue = rand() % 256;
    }
    int rect_count = 0;

    /* EXECUÇÃO */
    SDL_Rect r = { 40,20, 10,10 };
    SDL_Event evt;
    while (1) {
        SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0x00);
        SDL_RenderFillRect(ren, &r);
        for (int i = 0; i < rect_count; i++) {
            SDL_SetRenderDrawColor(ren, colors[i].r, colors[i].g, colors[i].b, colors[i].a);
            SDL_RenderFillRect(ren, &rects[i]);
        }
        SDL_RenderPresent(ren);


        SDL_WaitEvent(&evt);
        if (evt.type == SDL_KEYDOWN) {
            switch (evt.key.keysym.sym) {
                case SDLK_UP:
                    r.y -= 5;
                    break;
                case SDLK_DOWN:
                    r.y += 5;
                    break;
                case SDLK_LEFT:
                    r.x -= 5;
                    break;
                case SDLK_RIGHT:
                    r.x += 5;
                    break;
            }
        }
        else if (evt.type == SDL_MOUSEBUTTONDOWN){
            if(evt.button.button == SDL_BUTTON_LEFT){
                rects[rect_count].x = evt.button.x;
                rects[rect_count].y = evt.button.y;
                rects[rect_count].w = 10;
                rects[rect_count].h = 10;
                rect_count++;
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

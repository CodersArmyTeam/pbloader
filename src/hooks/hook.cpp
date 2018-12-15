//
// Created by devildefu on 01.12.2018.
//

#include <hooks/hook.hpp>
#include <api/render.hpp>
#include <engine/sprite/sprite.hpp>

MologieDetours::Detour<tCreateWindow> *detour_CreateWindow = NULL;
MologieDetours::Detour<tRenderPresent> *detour_RenderPresent = NULL;
MologieDetours::Detour<tUpperBlit> *detour_UpperBlit = NULL;
MologieDetours::Detour<tUpperBlitScaled> *detour_UpperBlitScaled = NULL;
MologieDetours::Detour<tRenderCopy> *detour_RenderCopy = NULL;
MologieDetours::Detour<tMixPlayMusic> *detour_MixPlayMusic = NULL;
MologieDetours::Detour<tIMGLoadRW> *detour_IMGLoadRW = NULL;
MologieDetours::Detour<tCreateTextureFromSurface> *detour_CreateTextureFromSurface = NULL;
MologieDetours::Detour<tUpdateTexture> *detour_UpdateTexture = NULL;

//int dog = 0;

SDL_Surface* gSurface = NULL;

//Sprite* sprite;

bool Hooks::Init() {
    try {
        detour_CreateWindow = new MologieDetours::Detour<tCreateWindow>("SDL2.dll", "SDL_CreateWindow",
                                                                        Hooks::SDL_CreateWindow);

        detour_RenderPresent = new MologieDetours::Detour<tRenderPresent>("SDL2.dll", "SDL_RenderPresent",
                                                                          Hooks::SDL_RenderPresent);

        detour_UpperBlit = new MologieDetours::Detour<tUpperBlit>("SDL2.dll", "SDL_UpperBlit",
                                                                        Hooks::SDL_UpperBlit);

        detour_UpperBlitScaled = new MologieDetours::Detour<tUpperBlitScaled>("SDL2.dll", "SDL_UpperBlitScaled",
                                                                      Hooks::SDL_UpperBlitScaled);

        detour_RenderCopy = new MologieDetours::Detour<tRenderCopy>("SDL2.dll", "SDL_RenderCopy", Hooks::SDL_RenderCopy);


        detour_MixPlayMusic = new MologieDetours::Detour<tMixPlayMusic>("SDL2_mixer.dll", "Mix_PlayMusic", Hooks::Mix_PlayMusic);

        //detour_IMGLoadRW = new MologieDetours::Detour<tIMGLoadRW>("SDL2_image.dll", "IMG_Load_RW", Hooks::IMG_Load_RW);

        detour_CreateTextureFromSurface = new MologieDetours::Detour<tCreateTextureFromSurface>("SDL2.dll", "SDL_CreateTextureFromSurface", Hooks::SDL_CreateTextureFromSurface);

        detour_UpdateTexture = new MologieDetours::Detour<tUpdateTexture>("SDL2.dll", "SDL_UpdateTexture", Hooks::SDL_UpdateTexture);
        //sprite = new Sprite(Vector2f(0, 0), Vector2f(32, 32));
        //Render::addSprite(sprite);
    } catch(MologieDetours::DetourException& e) {
        printf("%s", e.what());
        return FALSE;
    }
}

void Hooks::Clear() {
    delete detour_CreateWindow;
    delete detour_RenderPresent;
    delete detour_UpperBlit;
    delete detour_UpperBlitScaled;
    delete detour_RenderCopy;
    delete detour_IMGLoadRW;
    delete detour_MixPlayMusic;
    delete detour_CreateTextureFromSurface;

    //delete sprite;
}


SDL_Window* Hooks::SDL_CreateWindow(const char *title, int x, int y, int w, int h, Uint32 flags) {
    SDL_Window* window = detour_CreateWindow->GetOriginalFunction()(title, x, y, w, h, flags);
    return window;
}

int Hooks::SDL_RenderPresent(SDL_Renderer *renderer) {
    printf("[PBLoader][Hooks] SDL_RenderPresent\n");

    //Render::render(renderer);
    return detour_RenderPresent->GetOriginalFunction()(renderer);
}

int Hooks::SDL_UpperBlit(SDL_Surface* src, const SDL_Rect* srcrect, SDL_Surface* dst, SDL_Rect* dstrect) {
    //printf("[PBLoader][Hooks] SDL_BlitSurface\n");

    /*
    std::string name = "GRAPH/" + std::to_string(dog) + ".bmp";
    SDL_SaveBMP(dst, name.c_str());
    dog += 1;
     */
    if(gSurface == NULL) {
        gSurface = dst;
    }
    return detour_UpperBlit->GetOriginalFunction()(src, srcrect, dst, dstrect);
}

int Hooks::SDL_UpperBlitScaled(SDL_Surface* src, const SDL_Rect* srcrect, SDL_Surface* dst, SDL_Rect* dstrect) {
    printf("[PBLoader][Hooks] SDL_BlitScaled\n");
    return detour_UpperBlitScaled->GetOriginalFunction()(src, srcrect, dst, dstrect);
}

int Hooks::SDL_RenderCopy(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect) {
    printf("[PBLoader][Hooks] SDL_RenderCopy\n");
    //dog = 0;
    return detour_RenderCopy->GetOriginalFunction()(renderer, texture, srcrect, dstrect);
}

SDL_Texture* Hooks::SDL_CreateTextureFromSurface(SDL_Renderer* renderer, SDL_Surface* surface) {
    printf("[PBLoader][Hooks] SDL_CreateTextureFromSurface");
    return detour_CreateTextureFromSurface->GetOriginalFunction()(renderer, surface);
}

int Hooks::SDL_UpdateTexture(SDL_Texture* texture, const SDL_Rect* rect, const void* pixels, int pitch) {
    printf("[PBLoader][Hooks] SDL_UpdateTexture\n");
    int returned_value = detour_UpdateTexture->GetOriginalFunction()(texture, rect, pixels, pitch);
    SDL_Rect dogg;
    dogg.x = 0;
    dogg.y = 0;
    dogg.w = 32;
    dogg.h = 32;
    Uint32 * dog = new Uint32[32 * 32];
    memset(dog, 255, 32 * 32 * sizeof(Uint32));
    detour_UpdateTexture->GetOriginalFunction()(texture, &dogg, dog, 32 * sizeof(Uint32));
    //delete[] pixels; <- crash
    return returned_value;
}

/* Not work, fuck it */
SDL_Surface* Hooks::IMG_Load_RW(SDL_RWops* src, int freesrc) {
    //SDL_Surface* surface =
    printf("IMG_Load_RW");
    return NULL;
    //return detour_IMGLoadRW->GetOriginalFunction()(src, freesrc);
}


int Hooks::Mix_PlayMusic(Mix_Music* music, int loops) {
    printf("[PBLoader][Hooks] Mix_PlayMusic\n");
    Mix_Music* changed_music = NULL;
    changed_music = Mix_LoadMUS("downpour.wav");
    return detour_MixPlayMusic->GetOriginalFunction()(changed_music, loops);
    //return -1;
}

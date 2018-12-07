//
// Created by devildefu on 02.12.2018.
//

#include <api/render.hpp>

TVectorSprite sprites;

void addSprite(Sprite* sprite) {
    sprites.push_back(sprite);
}

void popSprite() {
    sprites.pop_back();
}

void clear() {
    sprites.clear();
}

void render(SDL_Renderer* render) {
    for(int i = 0; i<sprites.size(); i++) {
        SDL_RenderCopy(render, sprites[i]->getTexture(), NULL, NULL);
    }
}

TVectorSprite* getVectorSprite() {
    return &sprites;
}
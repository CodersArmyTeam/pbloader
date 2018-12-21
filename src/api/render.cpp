//
// Created by devildefu on 02.12.2018.
//

#include <api/render.hpp>

TVectorSprite sprites;

void Render::addSprite(Sprite* sprite) {
    sprites.push_back(sprite);
}

void Render::popSprite() {
    sprites.pop_back();
}

void Render::clear() {
    sprites.clear();
}

void Render::render(MologieDetours::Detour<tUpdateTexture>* detour_UpdateTexture, SDL_Texture* texture) {
    for(int i = 0; i<sprites.size(); i++) {
        SDL_Rect rect;
        rect.x = sprites[i]->getPosition().x;
        rect.y = sprites[i]->getPosition().y;
        rect.w = sprites[i]->getSize().x;
        rect.h = sprites[i]->getSize().y;
        detour_UpdateTexture->GetOriginalFunction()(texture, &rect, sprites[i]->getTexture()->pixels, sprites[i]->getTexture()->pitch);
    }
}
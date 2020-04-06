//
// Created by bruno on 03.04.2020.
//

#include "Game.h"

SDL_Texture* playerTex;
SDL_Rect srcR {50, 50}, destR{ 0, 0};


Game::Game() {

}
Game::~Game() {

}

void Game::init(const char *title, int width, int height, bool fullscreen) {
    int flags = 0;
    if(fullscreen)
        flags=SDL_WINDOW_FULLSCREEN;

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }
        isRunning = true;
    }

    SDL_Surface* tmpSurface = IMG_Load("C:/Users/bruno/CLionProjects/TestSDL/assets/player.png");
    if(!tmpSurface)
    {
        printf("Failed to load image. Error: %s", IMG_GetError());

        __debugbreak;
    }
    playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    if(!playerTex)
    {
        printf("Failed to create texture. Error: %s", SDL_GetError());

        __debugbreak;
    }
    SDL_FreeSurface(tmpSurface);
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update() {
    srcR.h = 32;
    srcR.w = 32;
    destR.h = 32;
    destR.w = 32;
}

void Game::render() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, playerTex, &srcR, &destR);
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool Game::running() {
    return isRunning;
}
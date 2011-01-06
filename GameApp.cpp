/*
 *  GameApp.cpp
 *  SDL Test
 *
 *  Created by Mark Szymczyk on 5/1/06.
 *  Copyright 2006 Me and Mark Publishing. All rights reserved.
 *
 */

#include "GameApp.h"

// Constructor
GameApp::GameApp(void)
{
    done = false;
    //drawContext = NULL;
}

// Destructor
GameApp::~GameApp(void)
{

}


// Initialization functions
void GameApp::InitApp(void)
{
    Uint32 contextFlags;
    contextFlags = SDL_OPENGL;
    
    // Create a 640 by 480 window with the current color depth.
    InitializeSDL(640, 480, 0, contextFlags);
    InstallTimer();
    
}

void GameApp::InitializeSDL(Uint32 width, Uint32 height, Uint32 colorDepth, Uint32 flags)
{
    int error;
    SDL_Surface* drawContext;
    
    error = SDL_Init(SDL_INIT_EVERYTHING);
    
    // Create a double-buffered draw context
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
                        
    drawContext = SDL_SetVideoMode(width, height, colorDepth, flags);    
    
    gluOrtho2D(0.0, 4.0, 0.0, 3.0);
    
}

void GameApp::InstallTimer(void)
{
    timer = SDL_AddTimer(30, GameLoopTimer, this);
}

Uint32 GameApp::GameLoopTimer(Uint32 interval, void* param)
{
    // Create a user event to call the game loop.
    SDL_Event event;
    
    event.type = SDL_USEREVENT;
    event.user.code = RUN_GAME_LOOP;
    event.user.data1 = 0;
    event.user.data2 = 0;
    
    SDL_PushEvent(&event);
    
    return interval;
}


// Cleanup functions
void GameApp::Cleanup(void)
{
    SDL_bool success;
    success = SDL_RemoveTimer(timer);
    
    SDL_Quit();
}


// Event-related functions
void GameApp::EventLoop(void)
{
    SDL_Event event;
    
    while((!done) && (SDL_WaitEvent(&event))) {
        switch(event.type) {
            case SDL_USEREVENT:
                HandleUserEvents(&event);
                break;
                
            case SDL_KEYDOWN:
                // Quit when user presses a key.
                done = true;
                break;
            
            case SDL_QUIT:
                done = true;
                break;
                
            default:
                break;
        }   // End switch
            
    }   // End while
        
}

void GameApp::HandleUserEvents(SDL_Event* event)
{
    switch (event->user.code) {
        case RUN_GAME_LOOP:
            GameLoop();
            break;
            
        default:
            break;
    }
}


// Game related functions
void GameApp::GameLoop(void)
{
    RenderFrame();    
}

void GameApp::RenderFrame(void) 
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.7, 0.5, 0.8);
    glRectf(1.0, 1.0, 3.0, 2.0);
    SDL_GL_SwapBuffers();
}

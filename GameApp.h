/*
 *  GameApp.h
 *  SDL Test
 *
 *  Created by Mark Szymczyk on 5/1/06.
 *  Copyright 2006 Me and Mark Publishing. All rights reserved.
 *
 */

#include "SDL.h"
#include "SDL_opengl.h"

class GameApp
{
    protected:
        SDL_TimerID timer;
        bool done;
        
    public:
        // Constructor and destructor
        GameApp (void);
        virtual ~GameApp(void);

        // Initialization functions
        void InitApp(void);
        void InitializeSDL(Uint32 width, Uint32 height, Uint32 colorDepth, Uint32 flags);
        void CreateOrthographicProjection(GLfloat width, GLfloat height);
        void InstallTimer(void);
        static Uint32 GameLoopTimer(Uint32 interval, void* param);
        
        // Cleanup functions
        void Cleanup(void);
        
        // Event-related functions
        void EventLoop(void);
        void HandleUserEvents(SDL_Event* event);
        
        // Game related functions
        void GameLoop(void);
        void RenderFrame(void);
        
};

typedef GameApp* GameAppPtr;
typedef GameApp** GameAppHandle;

const int RUN_GAME_LOOP = 1;
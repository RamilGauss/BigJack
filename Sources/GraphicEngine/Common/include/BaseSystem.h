
#pragma once

#include "TypeDef.h"
#include "Threading/MessageQueueSystem.h"

namespace Demo
{
    class GameState;

    class DllExport BaseSystem : public Mq::MessageQueueSystem
    {
    protected:
        GameState   *mCurrentGameState;

    public:
        BaseSystem( GameState *gameState );
        virtual ~BaseSystem();

        virtual void initialize(void);
        virtual void deinitialize(void);

        virtual void createScene01(void);
        virtual void createScene02(void);

        virtual void destroyScene(void);

        void beginFrameParallel(void);
        void update( float timeSinceLast );
        void finishFrameParallel(void);
        void finishFrame(void);
    };
}

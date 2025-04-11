#pragma once

#include "Renderer.h"

namespace graphics {
    //! \class IScene
    //! \brief An abstract class representing a scene.
    //! The idea is that this class is the entry point for rendering something
    //! so that the window knows what to render.
    class IScene {
        public:
            virtual ~IScene() = default;
            
            virtual void Update(float deltaTime) = 0;
            virtual void Render(IRenderer& renderer) = 0;
    };
}
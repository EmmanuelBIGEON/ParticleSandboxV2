#pragma once

#include "Renderer.h"
#include "RenderEngine.h"
#include "View.h"
#include "core/Simulation.h"

namespace graphics {
    //! \class IScene
    //! \brief An abstract class representing a scene.
    //! The idea is that this class is the entry point for rendering something
    //! so that the window knows what to render.
    class IScene {
        public:
            virtual ~IScene() = default;
            
            virtual void Update(float deltaTime) = 0;
            virtual void Render() = 0;
    };
    
    //! \class TestScene
    //! \brief A test scene.
    class TestScene : public IScene {
        public:
            TestScene(IRenderEngine& renderEngine);
            virtual ~TestScene() override;
            
            virtual void Update(float deltaTime) override;
            virtual void Render() override;

        protected:
            std::unique_ptr<core::ISimulation> _simulation;
            std::unique_ptr<TestView> _view;

    };
}
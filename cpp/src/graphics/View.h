#pragma once

#include <memory>

#include "Renderer.h"
#include "RenderEngine.h"

namespace graphics {
    //! \class IView
    //! \brief An abstract class representing a view.
    //! Independent from scene logic, for instance a 3D view, a data view, a shader view..
    class IView {
        public:
            virtual ~IView() = default;

            virtual void Update(float deltaTime) = 0;
            virtual void Render() = 0;      
    };
    
    //! \class TestView
    //! \brief A simple test view.
    class TestView : public IView {
        public:
            TestView(IRenderEngine& renderEngine);
            virtual ~TestView() override;

            virtual void Update(float deltaTime) override;
            virtual void Render() override;
        
        private:
            // Renderers
            std::unique_ptr<TriangleRenderer> _triangleRenderer;
    };

    //! \class Simple3DView
    //! \brief A simple 3D view.
    class Simple3DView : public IView {
        public:
            Simple3DView(IRenderEngine& renderEngine);
            virtual ~Simple3DView() override;

            virtual void Update(float deltaTime) override;
            virtual void Render() override;
    };
}
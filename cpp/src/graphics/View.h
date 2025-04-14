#pragma once

#include "RenderEngine.h"

namespace graphics {
    //! \class IView
    //! \brief An abstract class representing a view.
    //! Independent from scene logic, for instance a 3D view, a data view, a shader view..
    class IView {
        public:
            virtual ~IView() = default;

            virtual void Update(float deltaTime) = 0;
            virtual void Render(IRenderEngine& renderEngine) = 0;      
    };
    
    //! \class Simple3DView
    //! \brief A simple 3D view.
    class Simple3DView : public IView {
        public:
            Simple3DView();
            virtual ~Simple3DView() override;

            virtual void Update(float deltaTime) override;
            virtual void Render(IRenderEngine& renderEngine) override;
    };
}
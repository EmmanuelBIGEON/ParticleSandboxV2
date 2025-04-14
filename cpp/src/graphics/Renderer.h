#pragma once

#include "RenderEngine.h"
#include "common/Geometry.h"

namespace graphics {
    //! \class IRenderer
    //! \brief An abstract class representing a renderer.
    //! Indicate how to render something, for instance a particle or a scene
    class IRenderer {
        public:
            virtual ~IRenderer() = default;
    };

    //! \class TriangleRenderer
    //! \brief A triangle renderer
    class TriangleRenderer : public IRenderer {
        public:
            TriangleRenderer(IRenderEngine& renderEngine);
            virtual ~TriangleRenderer() override;

            void Render(const common::Triangle& triangle);
        private:
            IRenderEngine& _renderEngine;
    };

    //! \class RectangleRenderer
    //! \brief A rectangle renderer
    class RectangleRenderer : public IRenderer {
        public:
            RectangleRenderer(IRenderEngine& renderEngine);
            virtual ~RectangleRenderer() override;

        private:
            IRenderEngine& _renderEngine;
    };

    //! \class CubeRenderer
    //! \brief A rectangle renderer
    class CubeRenderer : public IRenderer {
        public:
            CubeRenderer(IRenderEngine& renderEngine);
            virtual ~CubeRenderer() override;

        private:
            IRenderEngine& _renderEngine;
    };
}
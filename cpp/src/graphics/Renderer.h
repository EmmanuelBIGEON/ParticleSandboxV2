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

            virtual void Render() = 0;
    };

    //! \class TriangleRenderer
    //! \brief A triangle renderer
    class TriangleRenderer : public IRenderer {
        public:
            TriangleRenderer(IRenderEngine& renderEngine);
            virtual ~TriangleRenderer() override;

            void SetTriangle(const common::Triangle& triangle);

            virtual void Render() override;
        private:
            IRenderEngine& _renderEngine;
            std::unique_ptr<rhi::IVertexArray> _vertexArray;
            std::unique_ptr<rhi::IVertexBuffer> _vertexBuffer;
            std::array<float, 6> _dataArray;
    };

    //! \class RectangleRenderer
    //! \brief A rectangle renderer
    class RectangleRenderer : public IRenderer {
        public:
            RectangleRenderer(IRenderEngine& renderEngine);
            virtual ~RectangleRenderer() override;

            virtual void Render() override;
        private:
            IRenderEngine& _renderEngine;
    };

    //! \class CubeRenderer
    //! \brief A rectangle renderer
    class CubeRenderer : public IRenderer {
        public:
            CubeRenderer(IRenderEngine& renderEngine);
            virtual ~CubeRenderer() override;

            virtual void Render() override;
        private:
            IRenderEngine& _renderEngine;
    };
}
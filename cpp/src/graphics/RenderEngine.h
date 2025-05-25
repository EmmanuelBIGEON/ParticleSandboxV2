#pragma once

#ifdef USE_OPENGL
#include <glad/glad.h>
#endif

#include <memory>
#include <unordered_map>
#include <glm/ext.hpp>

#include "graphics/rhi/Shader.h"
#include "graphics/rhi/VertexArray.h"
#include "graphics/rhi/VertexBuffer.h"

namespace graphics {

    enum class DrawMode {
        Triangles,
        Lines,
        LineStrip
    };

    enum class ShaderType {
        Basic
    };

    //! \class IRenderEngine
    //! \brief An abstract class representing a render engine.
    //! Interfacing with graphic APIs such as OpenGL, VUlkan, DirectX...
    class IRenderEngine {
        public:
            virtual ~IRenderEngine() = default;

            virtual std::unique_ptr<rhi::IVertexBuffer> CreateVertexBuffer() = 0;
            virtual std::unique_ptr<rhi::IVertexArray> CreateVertexArray() = 0;
            virtual void FillScreen(const glm::vec3& color) = 0;
            virtual void DrawArrays(DrawMode topology, int vertexCount) = 0;
            virtual void BindShader(ShaderType type) = 0;
        
        protected: 
            virtual std::shared_ptr<rhi::IShader> CreateShader(const std::string& vertexSource, const std::string& fragmentSource) = 0;
    };

#ifdef USE_OPENGL
    //! \class OpenGLRenderDevice
    //! \brief An OpenGL RenderDevice.
    class OpenGLRenderEngine : public IRenderEngine {
        public:
            OpenGLRenderEngine();
            virtual ~OpenGLRenderEngine() override;

            virtual std::unique_ptr<rhi::IVertexBuffer> CreateVertexBuffer() override;
            virtual std::unique_ptr<rhi::IVertexArray> CreateVertexArray() override;
            void FillScreen(const glm::vec3& color) override;
            virtual void DrawArrays(DrawMode topology, int vertexCount) override;
            virtual void BindShader(ShaderType type) override;

        protected:
            virtual std::shared_ptr<rhi::IShader> CreateShader(const std::string& vertexSource, const std::string& fragmentSource) override;
    
            std::unordered_map<ShaderType, std::shared_ptr<rhi::IShader>> _mapShaders;
    };
#endif
}
#pragma once

#include <glm/ext.hpp>

namespace graphics::rhi {
    //! \class IVertexArray
    //! \brief An abstract class representing a shader
    class IShader {
        public:
            virtual ~IShader() = default;

            virtual void Bind() = 0;

            virtual void SetBool(const char* name, bool value) const = 0;
            virtual void SetInt(const char* name, int value) const = 0;
            virtual void SetFloat(const char* name, float value) const = 0;
            virtual void SetVec2(const char* name, const glm::vec2& value) const = 0;
            virtual void SetVec3(const char* name, const glm::vec3& value) const = 0;
            virtual void SetVec4(const char* name, const glm::vec4& value) const = 0;
            virtual void SetMat2(const char* name, const glm::mat2& value) const = 0;
            virtual void SetMat3(const char* name, const glm::mat3& value) const = 0;
            virtual void SetMat4(const char* name, const glm::mat4& value) const = 0;
    };

#ifdef USE_OPENGL
    //! \class OpenGLShader
    //! \brief An OpenGL shader.
    class OpenGLShader : public IShader {
        public:
            OpenGLShader();
            virtual ~OpenGLShader() override;
        
            virtual void Bind() override;

            virtual void SetBool(const char* name, bool value) const override;
            virtual void SetInt(const char* name, int value) const override;
            virtual void SetFloat(const char* name, float value) const override;
            virtual void SetVec2(const char* name, const glm::vec2& value) const override;
            virtual void SetVec3(const char* name, const glm::vec3& value) const override;
            virtual void SetVec4(const char* name, const glm::vec4& value) const override;
            virtual void SetMat2(const char* name, const glm::mat2& value) const override;
            virtual void SetMat3(const char* name, const glm::mat3& value) const override;
            virtual void SetMat4(const char* name, const glm::mat4& value) const override;

        private:
            unsigned int shaderID;
    };
#endif
}
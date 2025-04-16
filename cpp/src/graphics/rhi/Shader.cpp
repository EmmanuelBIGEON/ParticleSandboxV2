#include "Shader.h"

#include <iostream>

using namespace graphics::rhi;

#ifdef USE_OPENGL
#include <glad/glad.h>

OpenGLShader::OpenGLShader(const std::string& vertexSource, const std::string& fragmentSource)
{
    GLuint vs = CompileShader(GL_VERTEX_SHADER, vertexSource);
    GLuint fs = CompileShader(GL_FRAGMENT_SHADER, fragmentSource);
    if (vs && fs) LinkProgram(vs, fs);

    glDeleteShader(vs);
    glDeleteShader(fs);
}
OpenGLShader::~OpenGLShader()
{
    if (_program)
        glDeleteProgram(_program);
}

void OpenGLShader::Bind()
{
    glUseProgram(_program);
}

GLuint OpenGLShader::CompileShader(GLenum type, const std::string& source)
{
    GLuint shader = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    GLint success = GL_FALSE;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char log[512];
        glGetShaderInfoLog(shader, sizeof(log), nullptr, log);
        std::cerr << "[Shader Compilation Error] " << log << std::endl;
        glDeleteShader(shader);
        return 0;
    }

    return shader;
}

void OpenGLShader::LinkProgram(GLuint vertexShader, GLuint fragmentShader)
{
    _program = glCreateProgram();
    glAttachShader(_program, vertexShader);
    glAttachShader(_program, fragmentShader);
    glLinkProgram(_program);

    GLint success = GL_FALSE;
    glGetProgramiv(_program, GL_LINK_STATUS, &success);
    if (!success) {
        char log[512];
        glGetProgramInfoLog(_program, sizeof(log), nullptr, log);
        std::cerr << "[Shader Linking Error] " << log << std::endl;
        glDeleteProgram(_program);
        _program = 0;
    }
}

void OpenGLShader::SetBool(const char* name, bool value) const
{
    glUniform1i(glGetUniformLocation(shaderID, name), (int)value);
}

void OpenGLShader::SetInt(const char* name, int value) const
{
    glUniform1i(glGetUniformLocation(shaderID, name), value);
}

void OpenGLShader::SetFloat(const char* name, float value) const
{
    glUniform1f(glGetUniformLocation(shaderID, name), value);
}

void OpenGLShader::SetVec2(const char* name, const glm::vec2& value) const
{
    glUniform2fv(glGetUniformLocation(shaderID, name), 1, glm::value_ptr(value));
}

void OpenGLShader::SetVec3(const char* name, const glm::vec3& value) const
{
    glUniform3fv(glGetUniformLocation(shaderID, name), 1, glm::value_ptr(value));
}

void OpenGLShader::SetVec4(const char* name, const glm::vec4& value) const
{
    glUniform4fv(glGetUniformLocation(shaderID, name), 1, glm::value_ptr(value));
}

void OpenGLShader::SetMat2(const char* name, const glm::mat2& value) const
{
    glUniformMatrix2fv(glGetUniformLocation(shaderID, name), 1, GL_FALSE, glm::value_ptr(value));
}

void OpenGLShader::SetMat3(const char* name, const glm::mat3& value) const
{
    glUniformMatrix3fv(glGetUniformLocation(shaderID, name), 1, GL_FALSE, glm::value_ptr(value));
}

void OpenGLShader::SetMat4(const char* name, const glm::mat4& value) const
{
    glUniformMatrix4fv(glGetUniformLocation(shaderID, name), 1, GL_FALSE, glm::value_ptr(value));
}

#endif
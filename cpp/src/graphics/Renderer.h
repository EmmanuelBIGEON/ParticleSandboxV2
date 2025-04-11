#pragma once

namespace graphics {
    //! \class IRenderer
    //! \brief An abstract class representing a renderer.
    //! Indicate how to render something, for instance a particle or a scene
    class IRenderer {
        public:
            virtual ~IRenderer() = default;
    };

}
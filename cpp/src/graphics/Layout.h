#pragma once

#include <vector>
#include <glm/ext.hpp>

namespace graphics {
    struct LayoutInput {
        glm::ivec2 windowSize;
        uint32_t viewCount; // should i use uint32_t. uint32_t = 32bits forcibly. but 16bits is more than enough. (65535) Best practice ?
    };
    
    struct LayoutOutput {
        glm::ivec2 position; // View position
        glm::ivec2 size; // View size.
    };

    //! \class ILayout
    //! \brief An abstract class representing a layout for a scene, organizing views.
    class ILayout {
        public:
            virtual ~ILayout() = default;

            //! \brief Somehow return a position and a size for each possible view. Is there a lib that does this ? flex layout..
            virtual void Compute(const LayoutInput& input, std::vector<LayoutOutput>& output) = 0;
    };

    //! \class SimpleLayout
    class SimpleLayout : public ILayout {
        public:
            SimpleLayout();
            virtual ~SimpleLayout() override;

            virtual void Compute(const LayoutInput& input, std::vector<LayoutOutput>& output) override;
    };
}
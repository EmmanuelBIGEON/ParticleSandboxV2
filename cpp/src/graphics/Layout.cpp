#include "Layout.h"

using namespace graphics;

SimpleLayout::SimpleLayout()
{
}

SimpleLayout::~SimpleLayout()
{
}

void SimpleLayout::Compute(const LayoutInput& input, std::vector<LayoutOutput>& output)
{
    output.clear();

    int cols = std::ceil(std::sqrt(input.viewCount));
    int rows = std::ceil(static_cast<float>(input.viewCount) / cols);
    glm::ivec2 cellSize = input.windowSize / glm::ivec2(cols, rows);

    for (int i = 0; i < input.viewCount; ++i)
    {
        int col = i % cols;
        int row = i / cols;

        glm::ivec2 pos = { col * cellSize.x, row * cellSize.y };

        output.emplace_back(LayoutOutput{ pos, cellSize });
    }
}

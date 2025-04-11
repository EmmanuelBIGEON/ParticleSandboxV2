#pragma once

#include "core/Context.h"

namespace graphics {
    //! \class IGraphicContext
    //! \brief An abstract class representing a graphic context.
    class IGraphicContext {
        public:
            virtual ~IGraphicContext() = default;

            //! \brief Get the linked context
            virtual const core::IContext& GetContext() const = 0;
    };
}
#pragma once

namespace core {
    //! \class IContext
    //! \brief An abstract class representing a context.
    //! Contains data that can be processed through solvers.
    class IContext {
        public:
            virtual ~IContext() = default;

            //! \brief Empty the context.
            virtual void Clear() = 0;
    };

    //! \class SimpleContext
    //! \brief Unoptimized POC context.
    class SimpleContext : public IContext {
        public:
            SimpleContext();
            virtual ~SimpleContext() override;

            virtual void Clear() override;
    };
}
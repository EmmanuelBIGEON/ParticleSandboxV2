#pragma once

namespace app {
    class Application {
        public:
            Application();
            virtual ~Application();

            virtual bool Run() = 0;
    };
}
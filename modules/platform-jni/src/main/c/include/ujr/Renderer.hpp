#pragma once

#ifndef UJR_ONLY_WEBCORE
#include <Ultralight/Renderer.h>
#endif

#include "ujr/support/GC.hpp"

namespace ujr {
    class Renderer {
    public:
        explicit Renderer() = delete;

#ifndef UJR_ONLY_WEBCORE
        static JniLocalRef<jobject> wrap(const JniEnv &env, ultralight::RefPtr<ultralight::Renderer> renderer);
#else
        static JniLocalRef<jobject> wrap(const JniEnv &env, ultralight::RefPtr<int> renderer);
#endif
    };

    class RendererCollector : public NativeCollector {
    private:
#ifndef UJR_ONLY_WEBCORE
        ultralight::Renderer *renderer;
#else
        int *renderer;
#endif

    public:
#ifndef UJR_ONLY_WEBCORE
        explicit RendererCollector(ultralight::Renderer *renderer);
#else
        explicit RendererCollector(int *renderer);
#endif

        void collect();
    };
} // namespace ujr

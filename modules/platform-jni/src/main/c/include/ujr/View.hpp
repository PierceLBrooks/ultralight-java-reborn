#pragma once

#ifndef UJR_ONLY_WEBCORE
#include <Ultralight/View.h>
#endif

#include "ujr/support/GC.hpp"

namespace ujr {
    class View {
    public:
        explicit View() = delete;

        static JniLocalRef<jobject> wrap(const JniEnv &env, ultralight::RefPtr<int> view);
    };

    class ViewCollector : public NativeCollector {
    private:
        int *view;

    public:
        int *view_listener;
        int *load_listener;

        explicit ViewCollector(int *view);

        void collect();
    };
} // namespace ujr

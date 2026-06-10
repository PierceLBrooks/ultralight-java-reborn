#pragma once

#ifndef UJR_ONLY_WEBCORE
#include <Ultralight/View.h>
#endif

#include "ujr/support/GC.hpp"

namespace ujr {
    class View {
    public:
        explicit View() = delete;

#ifndef UJR_ONLY_WEBCORE
        static JniLocalRef<jobject> wrap(const JniEnv &env, ultralight::RefPtr<ultralight::View> view);
#else
        static JniLocalRef<jobject> wrap(const JniEnv &env, ultralight::RefPtr<int> view);
#endif
    };

    class ViewCollector : public NativeCollector {
    private:
#ifndef UJR_ONLY_WEBCORE
        ultralight::View *view;
#else
        int *view;
#endif

    public:
#ifndef UJR_ONLY_WEBCORE
        ultralight::ViewListener *view_listener;
        ultralight::LoadListener *load_listener;
#else
        int *view_listener;
        int *load_listener;
#endif

#ifndef UJR_ONLY_WEBCORE
        explicit ViewCollector(ultralight::View *view);
#else
        explicit ViewCollector(int *view);
#endif

        void collect();
    };
} // namespace ujr

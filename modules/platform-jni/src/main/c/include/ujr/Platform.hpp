#pragma once

#ifndef UJR_ONLY_WEBCORE
#include <Ultralight/platform/Clipboard.h>
#include <Ultralight/platform/FileSystem.h>
#include <Ultralight/platform/Logger.h>
#include <Ultralight/platform/Platform.h>
#endif

#include "ujr/support/GC.hpp"

namespace ujr {
    class Platform {
    public:
        explicit Platform() = delete;

#ifndef UJR_ONLY_WEBCORE
        static JniLocalRef<jobject> wrap(const JniEnv &env, ultralight::Platform &platform);
#else
        static JniLocalRef<jobject> wrap(const JniEnv &env, int &platform);
#endif
    };

    class PlatformCollector : public NativeCollector {
    public:
#ifndef UJR_ONLY_WEBCORE
        ultralight::Logger *logger;
        ultralight::FileSystem *filesystem;
        ultralight::Clipboard *clipboard;
        ultralight::SurfaceFactory *surface_factory;
#else
        int *logger;
        int *filesystem;
        int *clipboard;
        int *surface_factory;
#endif

        explicit PlatformCollector();

        void collect();
    };
} // namespace ujr

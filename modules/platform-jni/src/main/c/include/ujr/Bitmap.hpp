#pragma once

#ifndef UJR_ONLY_WEBCORE
#include <Ultralight/Bitmap.h>
#endif

#include "ujr/support/GC.hpp"
#include "ujr/util/JniEnv.hpp"
#include "ujr/util/JniRef.hpp"

namespace ujr {
    class Bitmap {
    public:
        explicit Bitmap() = delete;

#ifndef UJR_ONLY_WEBCORE
        static JniLocalRef<jobject> wrap(const JniEnv &env, ultralight::RefPtr<ultralight::Bitmap> bitmap);
#else
        static JniLocalRef<jobject> wrap(const JniEnv &env, ultralight::RefPtr<int> bitmap);
#endif
    };

    class BitmapCollector : public NativeCollector {
    private:
#ifndef UJR_ONLY_WEBCORE
        ultralight::Bitmap *bitmap;
#else
        int *bitmap;
#endif

    public:
#ifndef UJR_ONLY_WEBCORE
        explicit BitmapCollector(ultralight::Bitmap *bitmap);
#else
        explicit BitmapCollector(int *bitmap);
#endif

        void collect();
    };
} // namespace ujr

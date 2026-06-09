#pragma once

#ifndef UJR_ONLY_WEBCORE
#include <Ultralight/platform/Surface.h>
#endif

#include "ujr/util/JniRef.hpp"

namespace ujr {
#ifndef UJR_ONLY_WEBCORE
    class SurfaceFactory : public ultralight::SurfaceFactory {
#else
    class SurfaceFactory {
#endif
    private:
        JniGlobalRef<jobject> j_surface_factory;

    public:
        explicit SurfaceFactory(JniGlobalRef<jobject> j_surface_factory);

#ifndef UJR_ONLY_WEBCORE
        ultralight::Surface *CreateSurface(uint32_t width, uint32_t height);

        void DestroySurface(ultralight::Surface *surface);
#else
        int *CreateSurface(uint32_t width, uint32_t height);

        void DestroySurface(int *surface);
#endif

        /**
         * Retrieves the underlying java surface factory instance.
         *
         * @return the java surface factory instance
         */
        [[nodiscard]] const JniGlobalRef<jobject> &get_j_surface_factory() const;
    };
} // namespace ujr

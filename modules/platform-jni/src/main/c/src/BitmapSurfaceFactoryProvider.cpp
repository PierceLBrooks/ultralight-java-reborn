#include "net_janrupf_ujr_platform_jni_impl_JNIUlBitmapSurfaceFactoryProvider.h"
#include "net_janrupf_ujr_platform_jni_wrapper_surface_JNIUlSurfaceFactoryNative_native_access.hpp"

#ifndef UJR_ONLY_WEBCORE
#include <Ultralight/platform/Surface.h>
#endif

#include "ujr/util/JniEntryGuard.hpp"

JNIEXPORT jobject JNICALL
Java_net_janrupf_ujr_platform_jni_impl_JNIUlBitmapSurfaceFactoryProvider_nativeGetBitmapSurfaceFactory(
    JNIEnv *env, jobject self
) {
#ifndef UJR_ONLY_WEBCORE
    return ujr::jni_entry_guard(env, [&](auto env) {
        using ujr::native_access::JNIUlSurfaceFactoryNative;

        auto *factory = ultralight::GetBitmapSurfaceFactory();

        auto j_factory = JNIUlSurfaceFactoryNative::CLAZZ.alloc_object(env);
        JNIUlSurfaceFactoryNative::HANDLE.set(env, j_factory, reinterpret_cast<jlong>(factory));

        return j_factory.leak();
    });
#else
    return nullptr;
#endif
}

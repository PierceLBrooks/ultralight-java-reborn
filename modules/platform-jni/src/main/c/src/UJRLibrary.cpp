#include <jni.h>
#ifdef UJR_ONLY_WEBCORE
//#include <iostream>
#endif

#include "ujr/util/JniEnv.hpp"

extern "C" [[maybe_unused]] jint JNI_OnLoad(JavaVM *vm, void *) {
    ujr::JniEnv::init(vm);

    // Unload will not be called when the version is not supported, which
    // means that JniEnv::jvm will not be cleared. However, this is fine
    // since the library will be unloaded anyway and thus never have the
    // chance to create a JniEnv.
#ifdef UJR_ONLY_WEBCORE
    //std::cout << "Hello, world!" << std::endl;
#endif
    return JNI_VERSION_1_8;
}

extern "C" [[maybe_unused]] void JNI_OnUnload(JavaVM *, void *) {
    ujr::JniEnv::deinit();
}

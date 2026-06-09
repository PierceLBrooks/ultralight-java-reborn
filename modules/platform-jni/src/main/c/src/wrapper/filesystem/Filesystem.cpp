#include "ujr/wrapper/filesystem/Filesystem.hpp"
#include "net_janrupf_ujr_platform_jni_wrapper_filesystem_JNIUlFilesystem_native_access.hpp"

#include "ujr/wrapper/buffer/Buffer.hpp"

namespace ujr {
    Filesystem::Filesystem(JniGlobalRef<jobject> j_filesystem)
        : j_filesystem(std::move(j_filesystem)) {}

    bool Filesystem::FileExists(const ultralight::String &file_path) {
#ifndef UJR_ONLY_WEBCORE
        auto env = JniEnv::require_existing_from_thread();

        // Translate the file path
        auto j_file_path = JniLocalRef<jstring>::from_utf16(env, file_path.utf16());

        // Call the Java instance
        return native_access::JNIUlFilesystem::FILE_EXISTS.invoke(env, j_filesystem, j_file_path);
#else
        return false;
#endif
    }

    ultralight::String Filesystem::GetFileMimeType(const ultralight::String &file_path) {
#ifndef UJR_ONLY_WEBCORE
        auto env = JniEnv::require_existing_from_thread();

        // Translate the file path
        auto j_file_path = JniLocalRef<jstring>::from_utf16(env, file_path.utf16());

        // Call the Java instance
        auto j_mime_type = native_access::JNIUlFilesystem::GET_FILE_MIME_TYPE.invoke(env, j_filesystem, j_file_path);

        // Translate the result
        return j_mime_type.to_utf16();
#else
        return "";
#endif
    }

    ultralight::String Filesystem::GetFileCharset(const ultralight::String &file_path) {
#ifndef UJR_ONLY_WEBCORE
        auto env = JniEnv::require_existing_from_thread();

        // Translate the file path
        auto j_file_path = JniLocalRef<jstring>::from_utf16(env, file_path.utf16());

        // Call the Java instance
        auto j_charset = native_access::JNIUlFilesystem::GET_FILE_CHARSET.invoke(env, j_filesystem, j_file_path);

        // Translate the result
        return j_charset.to_utf16();
#else
        return "";
#endif
    }

    ultralight::RefPtr<ultralight::Buffer> Filesystem::OpenFile(const ultralight::String &file_path) {
#ifndef UJR_ONLY_WEBCORE
        auto env = JniEnv::require_existing_from_thread();

        // Translate the file path
        auto j_file_path = JniLocalRef<jstring>::from_utf16(env, file_path.utf16());

        try {
            // Call the Java instance
            auto j_buffer = native_access::JNIUlFilesystem::OPEN_FILE.invoke(env, j_filesystem, j_file_path);

            // Translate the result
            return Buffer::wrap_delegated_buffer(env, j_buffer);
        } catch (const JniException &e) {
            if (e.is_java_io_exception()) {
                // Only allowed exception
                return nullptr;
            } else {
                // rethrow
                throw;
            }
        }
#else
        return nullptr;
#endif
    }

    const JniGlobalRef<jobject> &Filesystem::get_j_filesystem() const { return j_filesystem; }
} // namespace ujr

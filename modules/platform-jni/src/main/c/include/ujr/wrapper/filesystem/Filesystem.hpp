#pragma once

#ifndef UJR_ONLY_WEBCORE
#include <Ultralight/platform/FileSystem.h>
#else
#include <Ultralight/Buffer.h>
#include <Ultralight/String.h>
#endif

#include "ujr/util/JniRef.hpp"

namespace ujr {
    /**
     * Filesystem adapter for Ultralight delegating to a Java instance.
     */
#ifndef UJR_ONLY_WEBCORE
    class Filesystem : public ultralight::FileSystem {
#else
    class Filesystem {
#endif
    private:
        JniGlobalRef<jobject> j_filesystem;

    public:
        explicit Filesystem(JniGlobalRef<jobject> j_filesystem);

        bool FileExists(const ultralight::String &file_path);

        ultralight::String GetFileMimeType(const ultralight::String &file_path);

        ultralight::String GetFileCharset(const ultralight::String &file_path);

        ultralight::RefPtr<ultralight::Buffer> OpenFile(const ultralight::String &file_path);

        /**
         * Retrieves the underlying java filesystem instance.
         *
         * @return the java filesystem instance
         */
        [[nodiscard]] const JniGlobalRef<jobject> &get_j_filesystem() const;
    };
} // namespace ujr
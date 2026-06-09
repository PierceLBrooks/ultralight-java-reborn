#pragma once

#ifndef UJR_ONLY_WEBCORE
#include <Ultralight/platform/Clipboard.h>
#else
#include <Ultralight/String.h>
#endif

#include "ujr/util/JniRef.hpp"

namespace ujr {
    /**
     * Clipboard adapter for Ultralight delegating to a Java instance.
     */
#ifndef UJR_ONLY_WEBCORE
    class Clipboard : public ultralight::Clipboard {
#else
    class Clipboard {
#endif
    private:
        JniGlobalRef<jobject> j_clipboard;

    public:
        explicit Clipboard(JniGlobalRef<jobject> j_clipboard);

        void Clear();

        ultralight::String ReadPlainText();

        void WritePlainText(const ultralight::String &text);

        /**
         * Retrieves the underlying java clipboard instance.
         *
         * @return the java clipboard instance
         */
        [[nodiscard]] const JniGlobalRef<jobject> &get_j_clipboard() const;
    };
} // namespace ujr

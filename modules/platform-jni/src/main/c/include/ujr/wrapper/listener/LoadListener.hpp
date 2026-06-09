#pragma once

#ifndef UJR_ONLY_WEBCORE
#include <Ultralight/Listener.h>
#else
#include <Ultralight/String.h>
#endif

#include "ujr/util/JniRef.hpp"

namespace ujr {
    /**
     * Listener adapter for Ultralight delegating to a Java instance.
     */
#ifndef UJR_ONLY_WEBCORE
    class LoadListener : public ultralight::LoadListener {
#else
    class LoadListener {
#endif
    private:
        JniGlobalRef<jobject> j_listener;

    public:
        explicit LoadListener(JniGlobalRef<jobject> j_listener);

#ifndef UJR_ONLY_WEBCORE
        void OnBeginLoading(
            ultralight::View *caller, uint64_t frame_id, bool is_main_frame, const ultralight::String &url
        );

        void OnFinishLoading(
            ultralight::View *caller, uint64_t frame_id, bool is_main_frame, const ultralight::String &url
        );

        void OnFailLoading(
            ultralight::View *caller,
            uint64_t frame_id,
            bool is_main_frame,
            const ultralight::String &url,
            const ultralight::String &description,
            const ultralight::String &error_domain,
            int error_code
        );

        void OnWindowObjectReady(
            ultralight::View *caller, uint64_t frame_id, bool is_main_frame, const ultralight::String &url
        );

        void OnDOMReady(ultralight::View *caller, uint64_t frame_id, bool is_main_frame, const ultralight::String &url)
            ;

        void OnUpdateHistory(ultralight::View *caller);
#else
        void OnBeginLoading(
            int *caller, uint64_t frame_id, bool is_main_frame, const ultralight::String &url
        ) {}

        void OnFinishLoading(
            int *caller, uint64_t frame_id, bool is_main_frame, const ultralight::String &url
        ) {}

        void OnFailLoading(
            int *caller,
            uint64_t frame_id,
            bool is_main_frame,
            const ultralight::String &url,
            const ultralight::String &description,
            const ultralight::String &error_domain,
            int error_code
        ) {}

        void OnWindowObjectReady(
            int *caller, uint64_t frame_id, bool is_main_frame, const ultralight::String &url
        ) {}

        void OnDOMReady(int *caller, uint64_t frame_id, bool is_main_frame, const ultralight::String &url)
            {};

        void OnUpdateHistory(int *caller) {}
#endif

        /**
         * Retrieves the underlying java listener instance.
         *
         * @return the java listener instance
         */
        [[nodiscard]] const JniGlobalRef<jobject> &get_j_listener() const;
    };
} // namespace ujr

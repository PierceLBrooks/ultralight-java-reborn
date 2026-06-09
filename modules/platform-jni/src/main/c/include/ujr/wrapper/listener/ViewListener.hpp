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
    class ViewListener : public ultralight::ViewListener {
#else
    class ViewListener {
#endif
    private:
        JniGlobalRef<jobject> j_listener;

    public:
        explicit ViewListener(JniGlobalRef<jobject> j_listener);

#ifndef UJR_ONLY_WEBCORE
        void OnChangeTitle(ultralight::View *caller, const ultralight::String &title);

        void OnChangeURL(ultralight::View *caller, const ultralight::String &url);

        void OnChangeTooltip(ultralight::View *caller, const ultralight::String &tooltip);

        void OnChangeCursor(ultralight::View *caller, ultralight::Cursor cursor);

        void OnAddConsoleMessage(
            ultralight::View *caller,
            ultralight::MessageSource source,
            ultralight::MessageLevel level,
            const ultralight::String &message,
            uint32_t line_number,
            uint32_t column_number,
            const ultralight::String &source_id
        );

        ultralight::RefPtr<ultralight::View> OnCreateChildView(
            ultralight::View *caller,
            const ultralight::String &opener_url,
            const ultralight::String &target_url,
            bool is_popup,
            const ultralight::IntRect &popup_rect
        );

        ultralight::RefPtr<ultralight::View>
        OnCreateInspectorView(ultralight::View *caller, bool is_local, const ultralight::String &inspected_url);

        void OnRequestClose(ultralight::View *caller);
#else
        void OnChangeTitle(int *caller, const ultralight::String &title) {}

        void OnChangeURL(int *caller, const ultralight::String &url) {}

        void OnChangeTooltip(int *caller, const ultralight::String &tooltip) {}

        void OnChangeCursor(int *caller, int cursor) {}

        void OnAddConsoleMessage(
            int *caller,
            int source,
            int level,
            const ultralight::String &message,
            uint32_t line_number,
            uint32_t column_number,
            const ultralight::String &source_id
        ) {}

        ultralight::RefPtr<int> OnCreateChildView(
            int *caller,
            const ultralight::String &opener_url,
            const ultralight::String &target_url,
            bool is_popup,
            int &popup_rect
        ) { return nullptr; }

        ultralight::RefPtr<int>
        OnCreateInspectorView(int *caller, bool is_local, const ultralight::String &inspected_url) { return nullptr; }

        void OnRequestClose(int *caller) {}
#endif

        /**
         * Retrieves the underlying java listener instance.
         *
         * @return the java listener instance
         */
        [[nodiscard]] const JniGlobalRef<jobject> &get_j_listener() const;
    };
} // namespace ujr

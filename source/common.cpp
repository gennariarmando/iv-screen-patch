#include "common.h"

uint32_t* menuAspectRatio;

BOOL CALLBACK enum_windows_callback(HWND handle, LPARAM lparam) {
    auto& data = *reinterpret_cast<handle_data*>(lparam);

    unsigned long process_id = 0;
    GetWindowThreadProcessId(handle, &process_id);

    if (data.process_id != process_id) {
        return TRUE;
    }

    data.window_handle = handle;
    return FALSE;
}

HWND find_main_window() {
    handle_data data{};

    data.process_id = GetCurrentProcessId();
    data.window_handle = nullptr;
    EnumWindows(enum_windows_callback, reinterpret_cast<LPARAM>(&data));

    return data.window_handle;
}

std::tuple<int32_t, int32_t> GetWindowRes() {
    WINDOWINFO info = {};
    info.cbSize = sizeof(WINDOWINFO);
    GetWindowInfo(find_main_window(), &info);
    int32_t w = info.rcClient.right - info.rcClient.left;
    int32_t h = info.rcClient.bottom - info.rcClient.top;
    return std::make_tuple(w, h);
}
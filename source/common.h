#pragma once
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include "Utils/MemoryMgr.h"
#include "Utils/Patterns.h"

struct handle_data {
    unsigned long process_id;
    HWND window_handle;
};

extern BOOL CALLBACK enum_windows_callback(HWND handle, LPARAM lparam);
extern HWND find_main_window();
extern std::tuple<int32_t, int32_t> GetWindowRes();

extern uint32_t* menuAspectRatio;
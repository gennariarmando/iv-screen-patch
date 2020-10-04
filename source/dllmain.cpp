#include "common.h"
#include "CViewportMgr.h"

void FixAspectRatio() {
    std::unique_ptr<ScopedUnprotect::Unprotect> Protect = ScopedUnprotect::UnprotectSectionOrFullModule(GetModuleHandle(nullptr), ".text");

    using namespace std;
    using namespace Memory;
    using namespace hook;

    menuAspectRatio = *hook::get_pattern<uint32_t*>("8B 1D ? ? ? ? 56 8B F1 57 39 5E ?", 2);
    g_viewPorts = *hook::get_pattern<CViewportMgr*>("B9 ? ? ? ? E8 ? ? ? ? C6 05 ? ? ? ? ? E8 ? ? ? ? E8 ? ? ? ? B9 ? ? ? ?", 1);
   
    auto getAspectRatio = get_pattern("A1 ? ? ? ? 83 EC ? 57 8B F9");
    InjectHook(getAspectRatio, &CViewportMgr::FindAspectRatio, PATCH_JUMP);

    auto IsWidescreen = get_pattern("51 56 6A ? 8B F1");
    InjectHook(IsWidescreen, &CViewportMgr::IsWidescreen, PATCH_JUMP);

}

void Init() {
    FixAspectRatio();
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved) {
    if (reason == DLL_PROCESS_ATTACH) {
        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Init, 0, 0, 0);
    }
    return TRUE;
}

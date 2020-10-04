#pragma once

class CViewportMgr {
public:
    float __thiscall FindAspectRatio(bool bForce16_9);
    bool __thiscall IsWidescreen();
};

extern CViewportMgr* g_viewPorts;
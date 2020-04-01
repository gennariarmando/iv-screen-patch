#pragma once

class CViewportMgr {
public:
    float FindAspectRatio(bool bForce16_9);
    bool IsWidescreen();
};

extern CViewportMgr* g_viewPorts;
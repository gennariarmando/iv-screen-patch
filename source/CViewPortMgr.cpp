#include "common.h"
#include "CViewportMgr.h"

CViewportMgr* g_viewPorts;

float CViewportMgr::FindAspectRatio(bool bForce16_9) {
    uint32_t AspectRatioWidth, AspectRatioHeight;
    uint32_t ViewPortWidth, ViewPortHeight;
    float fCustomAspectRatioHor, fCustomAspectRatioVer;

    std::tie(ViewPortWidth, ViewPortHeight) = GetWindowRes();

    AspectRatioWidth = ViewPortWidth;
    AspectRatioHeight = ViewPortHeight;

    fCustomAspectRatioHor = static_cast<float>(AspectRatioWidth);
    fCustomAspectRatioVer = static_cast<float>(AspectRatioHeight);

    switch (*menuAspectRatio) {
    case 1:
        return 4.0f / 3.0f;
    case 2:
        return 5.0f / 4.0f;
    case 3:
        return 16.0f / 9.0f;
    case 4:
        return 16.0f / 10.0f;
    default:
        return fCustomAspectRatioHor / fCustomAspectRatioVer;
    }

    if (bForce16_9)
        return 16.0f / 9.0f;
}

bool CViewportMgr::IsWidescreen() {
    if (FindAspectRatio(false) >= 3.0f / 2.0f)
        return true;
    else
        return false;
}

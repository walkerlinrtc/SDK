#ifndef XRTCSDK_XRTC_RTC_VIDEO_VIDEO_SEND_STREAM_CONFIG_H_
#define XRTCSDK_XRTC_RTC_VIDEO_VIDEO_SEND_STREAM_CONFIG_H_

#include <stdint.h>

namespace xrtc {

class RtpRtcpModuleObserver;

struct VideoSendStreamConfig {
    struct Rtp {
        uint32_t ssrc = 0;
        int payload_type = -1;
        int clock_rate = 90000;

        struct Rtx {
            uint32_t ssrc = 0;
            int payload_type = -1;
        } rtx;

    } rtp;

    // 视频的rtcp包发送间隔
    int rtcp_report_interval_ms = 1000;
    RtpRtcpModuleObserver* rtp_rtcp_module_observer = nullptr;
};

} // namespace xrtc

#endif // XRTCSDK_XRTC_RTC_VIDEO_VIDEO_SEND_STREAM_CONFIG_H_
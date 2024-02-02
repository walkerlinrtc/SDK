#ifndef XRTCSDK_XRTC_RTC_MODULES_RTP_RTCP_RTCP_PACKET_RTPFB_H_
#define XRTCSDK_XRTC_RTC_MODULES_RTP_RTCP_RTCP_PACKET_RTPFB_H_

#include "xrtc/rtc/modules/rtp_rtcp/rtcp_packet.h"

namespace xrtc {
namespace rtcp {

class Rtpfb : public RtcpPacket {
public:
    static const uint8_t kPacketType = 205;
    Rtpfb() = default;
    ~Rtpfb() override = default;

    void SetMediaSsrc(uint32_t ssrc) { media_ssrc_ = ssrc; }
    uint32_t media_ssrc() const { return media_ssrc_; }

protected:
    static const size_t kCommonFeedabackLength = 8;
    void ParseCommonFeedback(const uint8_t* payload);

private:
    uint32_t media_ssrc_ = 0;
};

} // namespace rtcp
} // namespace xrtc

#endif // XRTCSDK_XRTC_RTC_MODULES_RTP_RTCP_RTCP_PACKET_RTPFB_H_
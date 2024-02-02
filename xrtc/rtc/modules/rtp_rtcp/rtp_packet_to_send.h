#ifndef XRTCSDK_XRTC_RTC_MODULES_RTP_RTCP_RTP_PACKET_TO_SEND_H_
#define XRTCSDK_XRTC_RTC_MODULES_RTP_RTCP_RTP_PACKET_TO_SEND_H_

#include "xrtc/rtc/modules/rtp_rtcp/rtp_packet.h"

namespace xrtc {

class RtpPacketToSend : public RtpPacket {
public:
    RtpPacketToSend();
    RtpPacketToSend(size_t capacity);

};

} // namespace xrtc

#endif // XRTCSDK_XRTC_RTC_MODULES_RTP_RTCP_RTP_PACKET_TO_SEND_H_
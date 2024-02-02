#ifndef XRTCSDK_XRTC_RTC_MODULES_RTP_RTCP_RTP_UTILS_H_
#define XRTCSDK_XRTC_RTC_MODULES_RTP_RTCP_RTP_UTILS_H_

#include <api/array_view.h>
#include <system_wrappers/include/ntp_time.h>

namespace xrtc {

enum class RtpPacketType {
    kRtp = 0,
    kRtcp = 1,
    kUnknown = 2,
};

bool IsRtcpPacket(rtc::ArrayView<const uint8_t> packet);
bool IsRtpPacket(rtc::ArrayView<const uint8_t> packet);
RtpPacketType InferRtpPacketType(rtc::ArrayView<const uint8_t> packet);

inline uint32_t CompactNtp(webrtc::NtpTime ntp_time) {
    return (ntp_time.seconds()) << 16 | (ntp_time.fractions() >> 16);
}

int64_t CompactNtpRttToMs(uint32_t compact_ntp_interval);

} // namespace xrtc

#endif // XRTCSDK_XRTC_RTC_MODULES_RTP_RTCP_RTP_UTILS_H_
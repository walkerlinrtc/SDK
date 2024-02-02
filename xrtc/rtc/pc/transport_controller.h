#ifndef XRTCSDK_XRTC_RTC_PC_TRANSPORT_CONTROLLER_H_
#define XRTCSDK_XRTC_RTC_PC_TRANSPORT_CONTROLLER_H_

#include <ice/ice_agent.h>

namespace xrtc {

class SessionDescription;

class TransportController : public sigslot::has_slots<> {
public:
    TransportController();
    ~TransportController();

    int SetRemoteSDP(SessionDescription* desc);
    int SetLocalSDP(SessionDescription* desc);
    int SendPacket(const std::string& transport_name, const char* data, size_t len);
    
    sigslot::signal2<TransportController*, ice::IceTransportState>
        SignalIceState;
    sigslot::signal4<TransportController*, const char*, size_t, int64_t>
        SignalRtpPacketReceived;
    sigslot::signal4<TransportController*, const char*, size_t, int64_t>
        SignalRtcpPacketReceived;
   
private:
    void OnIceState(ice::IceAgent*, ice::IceTransportState ice_state);
    void OnReadPacket(ice::IceAgent*, const std::string&, int,
        const char* data, size_t len, int64_t ts);

private:
    ice::IceAgent* ice_agent_;
};

} // namespace xrtc

#endif // XRTCSDK_XRTC_RTC_PC_TRANSPORT_CONTROLLER_H_
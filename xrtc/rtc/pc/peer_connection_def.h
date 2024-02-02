#ifndef XRTCSDK_XRTC_RTC_PC_PEER_CONNECTION_DEF_H_
#define XRTCSDK_XRTC_RTC_PC_PEER_CONNECTION_DEF_H_

namespace xrtc {

enum class PeerConnectionState {
	kNew,
	kConnecting,
	kConnected,
	kDisconnected,
	kFailed,
	kClosed,
};

} // namespace xrtc

#endif // XRTCSDK_XRTC_RTC_PC_PEER_CONNECTION_DEF_H_
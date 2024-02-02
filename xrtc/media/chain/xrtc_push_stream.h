#ifndef XRTCSDK_XRTC_MEDIA_CHAIN_XRTC_PUSH_STREAM_H_
#define XRTCSDK_XRTC_MEDIA_CHAIN_XRTC_PUSH_STREAM_H_

#include "xrtc/media/base/media_chain.h"
#include "xrtc/media/source/xrtc_video_source.h"
#include "xrtc/media/filter/x264_encoder_filter.h"
#include "xrtc/media/sink/xrtc_media_sink.h"

namespace xrtc {

class XRTCPusher;

class XRTCPushStream : public MediaChain {
public:
    XRTCPushStream(XRTCPusher* pusher, IVideoSource* video_source);
    ~XRTCPushStream() override;

    // MediaChain
    void Start() override;
    void Stop() override;
    void Destroy() override;
    void OnChainSuccess() override;
    void OnChainFailed(MediaObject*, XRTCError err) override;

private:
    XRTCPusher* pusher_;
    IVideoSource* video_source_;
    std::unique_ptr<XRTCVideoSource> xrtc_video_source_;
    std::unique_ptr<X264EncoderFilter> x264_encoder_filter_;
    std::unique_ptr<XRTCMediaSink> xrtc_media_sink_;
};

} // namespace xrtc

#endif // XRTCSDK_XRTC_MEDIA_CHAIN_XRTC_PUSH_STREAM_H_
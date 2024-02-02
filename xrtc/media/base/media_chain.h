#ifndef XRTCSDK_XRTC_MEDIA_BASE_MEDIA_CHAIN_H_
#define XRTCSDK_XRTC_MEDIA_BASE_MEDIA_CHAIN_H_

#include <vector>
#include <string>

#include "xrtc/xrtc.h"

namespace xrtc {

 class InPin;
 class OutPin;

class MediaObject {
public:
    virtual ~MediaObject() {}

    virtual bool Start() = 0;
    virtual void Setup(const std::string& /*json_config*/) {}
    virtual void Stop() = 0;
    virtual void OnNewMediaFrame(std::shared_ptr<MediaFrame>) {}
    virtual std::vector<InPin*> GetAllInPins() = 0;
    virtual std::vector<OutPin*> GetAllOutPins() = 0;
};

class XRTC_API MediaChain {
public:
    MediaChain() = default;
    virtual ~MediaChain() = default;

    virtual void Start() = 0;
    virtual void Stop() = 0;
    virtual void Destroy() = 0;
    virtual void OnChainSuccess() {}
    virtual void OnChainFailed(MediaObject*, XRTCError) {}

protected:
    void AddMediaObject(MediaObject* obj);
    bool ConnectMediaObject(MediaObject* from, MediaObject* to);
    void SetupChain(const std::string& json_config);
    bool StartChain();
    void StopChain();

private:
    std::vector<MediaObject*> media_objects_;
};

} // namespace xrtc

#endif // XRTCSDK_XRTC_MEDIA_BASE_MEDIA_CHAIN_H_
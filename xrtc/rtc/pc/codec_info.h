#ifndef XRTCSDK_XRTC_RTC_PC_CODEC_INFO_H_
#define XRTCSDK_XRTC_RTC_PC_CODEC_INFO_H_

#include <string>
#include <map>
#include <vector>

namespace xrtc {

class AudioCodecInfo;
class VideoCodecInfo;

class FeedbackParam {
public:
    FeedbackParam(const std::string& id, const std::string& param) :
        id_(id), param_(param) { }
    FeedbackParam(const std::string& id) : id_(id), param_("") {}

    std::string id() { return id_; }
    std::string param() { return param_; }

private:
    std::string id_;
    std::string param_;
};

typedef std::map<std::string, std::string> CodecParam;

class CodecInfo {
public:
    virtual AudioCodecInfo* AsAudio() { return nullptr; }
    virtual VideoCodecInfo* AsVideo() { return nullptr; }

    int id;
    std::string name;
    int clockrate;
    std::vector<FeedbackParam> feedback_param;
    CodecParam codec_param;
};

class AudioCodecInfo : public CodecInfo {
public:
    AudioCodecInfo* AsAudio() override { return this; }

    int channels;
};

class VideoCodecInfo : public CodecInfo {
public:
    VideoCodecInfo* AsVideo() override { return this; }
};

} // namespace xrtc

#endif // XRTCSDK_XRTC_RTC_PC_CODEC_INFO_H_
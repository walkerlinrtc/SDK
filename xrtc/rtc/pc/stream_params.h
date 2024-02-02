#ifndef XRTCSDK_XRTC_RTC_PC_STREAM_PARAMS_H_
#define XRTCSDK_XRTC_RTC_PC_STREAM_PARAMS_H_

#include <string>
#include <vector>

namespace xrtc {

struct SsrcGroup {
    std::string semantics;
    std::vector<uint32_t> ssrcs;
};

struct StreamParams {
    std::string id;
    std::string stream_id;
    std::string cname;
    std::vector<uint32_t> ssrcs;
    std::vector<SsrcGroup> ssrc_groups;
};

} // namespace xrtc

#endif // XRTCSDK_XRTC_RTC_PC_STREAM_PARAMS_H_
cmake_minimum_required(VERSION 3.8)

project(xrtc)

file(GLOB all_src
	./*.cpp
	./base/*.cpp
	./device/*.cpp
	./media/base/*.cpp
	./media/chain/*.cpp
	./media/source/*.cpp
	./media/sink/*.cpp
	./media/filter/*.cpp
	./rtc/pc/*.cpp
	./rtc/modules/rtp_rtcp/*.cpp
	./rtc/modules/rtp_rtcp/rtcp_packet/*.cpp
	./rtc/video/*.cpp
)

include_directories(
	${XRTC_DIR}
	${XRTC_THIRD_PARTY_DIR}/include
)

link_directories(
	${XRTC_THIRD_PARTY_DIR}/lib
)

if (CMAKE_SYSTEM_NAME MATCHES "Windows")
	add_definitions(-DXRTC_API_EXPORT
		-DWEBRTC_WIN
		-DNOMINMAX
		-DCURL_STATICLIB
		-DICE_WIN
	)
endif()

add_library(xrtc SHARED ${all_src})
target_link_libraries(xrtc
    absl_bad_optional_access
    absl_throw_delegate
    absl_strings
    absl_bad_variant_access
	winmm
	ws2_32
	Strmiids
	jpeg-static
	yuv
	jsoncpp_static
	d3d9
	libx264
	wldap32
	Crypt32
	iphlpapi
	libssl
	libcrypto
	libcurl
	libwebrtc
	libice
)

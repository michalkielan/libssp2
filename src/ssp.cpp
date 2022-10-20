#include <string>

#include "imf/ssp/sspclient.h"
#include "imf/net/loop.h"

extern "C" imf::Loop *create_loop_class() { return new imf::Loop(); }

extern "C" imf::SspClient *create_ssp_class(const std::string &ip,
                                            imf::Loop *loop, size_t bufSize,
                                            unsigned short port,
                                            uint32_t streamStyle) {
  return new imf::SspClient(ip, loop, bufSize, port, streamStyle);
}

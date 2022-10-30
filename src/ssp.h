#include <string>

namespace imf {
  class Loop;
  class SspClient;
}

extern "C" imf::Loop *create_loop_class();

extern "C" imf::SspClient *create_ssp_class(const std::string &ip,
                                            imf::Loop *loop, size_t bufSize,
                                            unsigned short port,
                                            uint32_t streamStyle);

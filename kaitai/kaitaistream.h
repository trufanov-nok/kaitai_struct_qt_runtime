#ifndef KAITAI_STREAM_H
#define KAITAI_STREAM_H

#include <istream>
#include <stdint.h>

class KaitaiStream {
public:
    KaitaiStream(std::istream* io);

    void close();

    uint8_t read_u1();
    uint16_t read_u2le();
    uint32_t read_u4le();
    uint64_t read_u8le();

private:
    std::istream* _io;
};

#endif

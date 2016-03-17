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

    uint16_t read_u2be();
    uint32_t read_u4be();
    uint64_t read_u8be();

    int8_t read_s1();

    int16_t read_s2le();
    int32_t read_s4le();
    int64_t read_s8le();

    int16_t read_s2be();
    int32_t read_s4be();
    int64_t read_s8be();

private:
    std::istream* io_;
};

#endif

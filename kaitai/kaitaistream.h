#ifndef KAITAI_STREAM_H
#define KAITAI_STREAM_H

#include <istream>
#include <fstream>
#include <stdint.h>
#include <sys/types.h>

namespace kaitai {

class kstream {
public:
    kstream(std::istream* io);

    void seek(std::ifstream::pos_type pos);
    std::ifstream::pos_type pos();
    bool is_eof() const;
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

    std::string ensure_fixed_contents(ssize_t len, const char* expected);
    std::string read_str_byte_limit(ssize_t len);
    std::string read_strz(char term, bool include, bool consume, bool eos_error);

private:
    std::istream* m_io;
};

}

#endif

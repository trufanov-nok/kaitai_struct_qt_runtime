#include <kaitai/kaitaistream.h>

#include <endian.h>
#include <byteswap.h>

#include <iostream>
#include <vector>

kaitai::kstream::kstream(std::istream* io) {
    m_io = io;
}

void kaitai::kstream::close() {
    //  m_io->close();
}

void kaitai::kstream::seek(std::ifstream::pos_type pos) {
    m_io->seekg(pos);
}

std::ifstream::pos_type kaitai::kstream::pos() {
    return m_io->tellg();
}

bool kaitai::kstream::is_eof() const {
    char t;
    m_io->get(t);
    if (m_io->eof()) {
        return true;
    } else {
        m_io->unget();
        return false;
    }
}

uint8_t kaitai::kstream::read_u1() {
    char t;
    m_io->get(t);
    return t;
}

uint16_t kaitai::kstream::read_u2le() {
    uint16_t t;
    m_io->read(reinterpret_cast<char *>(&t), 2);
#if __BYTE_ORDER == __BIG_ENDIAN
    t = bswap_16(t);
#endif
    return t;
}

uint32_t kaitai::kstream::read_u4le() {
    uint32_t t;
    m_io->read(reinterpret_cast<char *>(&t), 4);
#if __BYTE_ORDER == __BIG_ENDIAN
    t = bswap_32(t);
#endif
    return t;
}

uint64_t kaitai::kstream::read_u8le() {
    uint64_t t;
    m_io->read(reinterpret_cast<char *>(&t), 8);
#if __BYTE_ORDER == __BIG_ENDIAN
    t = bswap_64(t);
#endif
    return t;
}

uint16_t kaitai::kstream::read_u2be() {
    uint16_t t;
    m_io->read(reinterpret_cast<char *>(&t), 2);
#if __BYTE_ORDER == __LITTLE_ENDIAN
    t = bswap_16(t);
#endif
    return t;
}

uint32_t kaitai::kstream::read_u4be() {
    uint32_t t;
    m_io->read(reinterpret_cast<char *>(&t), 4);
#if __BYTE_ORDER == __LITTLE_ENDIAN
    t = bswap_32(t);
#endif
    return t;
}

uint64_t kaitai::kstream::read_u8be() {
    uint64_t t;
    m_io->read(reinterpret_cast<char *>(&t), 8);
#if __BYTE_ORDER == __LITTLE_ENDIAN
    t = bswap_64(t);
#endif
    return t;
}

int8_t kaitai::kstream::read_s1() {
    char t;
    m_io->get(t);
    return t;
}

int16_t kaitai::kstream::read_s2le() {
    int16_t t;
    m_io->read(reinterpret_cast<char *>(&t), 2);
#if __BYTE_ORDER == __BIG_ENDIAN
    t = bswap_16(t);
#endif
    return t;
}

int32_t kaitai::kstream::read_s4le() {
    int32_t t;
    m_io->read(reinterpret_cast<char *>(&t), 4);
#if __BYTE_ORDER == __BIG_ENDIAN
    t = bswap_32(t);
#endif
    return t;
}

int64_t kaitai::kstream::read_s8le() {
    int64_t t;
    m_io->read(reinterpret_cast<char *>(&t), 8);
#if __BYTE_ORDER == __BIG_ENDIAN
    t = bswap_64(t);
#endif
    return t;
}

int16_t kaitai::kstream::read_s2be() {
    int16_t t;
    m_io->read(reinterpret_cast<char *>(&t), 2);
#if __BYTE_ORDER == __LITTLE_ENDIAN
    t = bswap_16(t);
#endif
    return t;
}

int32_t kaitai::kstream::read_s4be() {
    int32_t t;
    m_io->read(reinterpret_cast<char *>(&t), 4);
#if __BYTE_ORDER == __LITTLE_ENDIAN
    t = bswap_32(t);
#endif
    return t;
}

int64_t kaitai::kstream::read_s8be() {
    int64_t t;
    m_io->read(reinterpret_cast<char *>(&t), 8);
#if __BYTE_ORDER == __LITTLE_ENDIAN
    t = bswap_64(t);
#endif
    return t;
}

std::string kaitai::kstream::ensure_fixed_contents(ssize_t len, const char *expectedChar) {
    std::string actual = read_str_byte_limit(len, NULL);
    std::string expected(expectedChar);

    if (actual != expected) {
        std::cout << "Fixed contents mismatch!\n";
        std::cout << actual << "\n";
        std::cout << expected << "\n";
    }

    return actual;
}

std::string kaitai::kstream::read_str_byte_limit(ssize_t len, const char *encoding) {
    std::vector<char> result(len);
    m_io->read(&result[0], len);
    return std::string(&result[0], &result[len]);
}

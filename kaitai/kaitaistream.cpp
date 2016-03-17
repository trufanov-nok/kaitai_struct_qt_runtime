#include <kaitai/kaitaistream.h>

#include <endian.h>
#include <byteswap.h>

KaitaiStream::KaitaiStream(std::istream* io) {
    io_ = io;
}

void KaitaiStream::close() {
    //  io_->close();
}

uint8_t KaitaiStream::read_u1() {
    char t;
    io_->get(t);
    return t;
}

uint16_t KaitaiStream::read_u2le() {
    uint16_t t;
    io_->read(reinterpret_cast<char *>(&t), 2);
#if __BYTE_ORDER == __BIG_ENDIAN
    t = bswap_16(t);
#endif
    return t;
}

uint32_t KaitaiStream::read_u4le() {
    uint32_t t;
    io_->read(reinterpret_cast<char *>(&t), 4);
#if __BYTE_ORDER == __BIG_ENDIAN
    t = bswap_32(t);
#endif
    return t;
}

uint64_t KaitaiStream::read_u8le() {
    uint64_t t;
    io_->read(reinterpret_cast<char *>(&t), 8);
#if __BYTE_ORDER == __BIG_ENDIAN
    t = bswap_64(t);
#endif
    return t;
}

uint16_t KaitaiStream::read_u2be() {
    uint16_t t;
    io_->read(reinterpret_cast<char *>(&t), 2);
#if __BYTE_ORDER == __LITTLE_ENDIAN
    t = bswap_16(t);
#endif
    return t;
}

uint32_t KaitaiStream::read_u4be() {
    uint32_t t;
    io_->read(reinterpret_cast<char *>(&t), 4);
#if __BYTE_ORDER == __LITTLE_ENDIAN
    t = bswap_32(t);
#endif
    return t;
}

uint64_t KaitaiStream::read_u8be() {
    uint64_t t;
    io_->read(reinterpret_cast<char *>(&t), 8);
#if __BYTE_ORDER == __LITTLE_ENDIAN
    t = bswap_64(t);
#endif
    return t;
}

int8_t KaitaiStream::read_s1() {
    char t;
    io_->get(t);
    return t;
}

int16_t KaitaiStream::read_s2le() {
    int16_t t;
    io_->read(reinterpret_cast<char *>(&t), 2);
#if __BYTE_ORDER == __BIG_ENDIAN
    t = bswap_16(t);
#endif
    return t;
}

int32_t KaitaiStream::read_s4le() {
    int32_t t;
    io_->read(reinterpret_cast<char *>(&t), 4);
#if __BYTE_ORDER == __BIG_ENDIAN
    t = bswap_32(t);
#endif
    return t;
}

int64_t KaitaiStream::read_s8le() {
    int64_t t;
    io_->read(reinterpret_cast<char *>(&t), 8);
#if __BYTE_ORDER == __BIG_ENDIAN
    t = bswap_64(t);
#endif
    return t;
}

int16_t KaitaiStream::read_s2be() {
    int16_t t;
    io_->read(reinterpret_cast<char *>(&t), 2);
#if __BYTE_ORDER == __LITTLE_ENDIAN
    t = bswap_16(t);
#endif
    return t;
}

int32_t KaitaiStream::read_s4be() {
    int32_t t;
    io_->read(reinterpret_cast<char *>(&t), 4);
#if __BYTE_ORDER == __LITTLE_ENDIAN
    t = bswap_32(t);
#endif
    return t;
}

int64_t KaitaiStream::read_s8be() {
    int64_t t;
    io_->read(reinterpret_cast<char *>(&t), 8);
#if __BYTE_ORDER == __LITTLE_ENDIAN
    t = bswap_64(t);
#endif
    return t;
}

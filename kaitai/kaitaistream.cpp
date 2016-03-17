#include <kaitai/kaitaistream.h>

KaitaiStream::KaitaiStream(std::istream* io) {
    _io = io;
}

void KaitaiStream::close() {
    //  _io->close();
}

uint8_t KaitaiStream::read_u1() {
    char t;
    _io->get(t);
    return t;
}

uint16_t KaitaiStream::read_u2le() {
    uint16_t t;
    _io->read(reinterpret_cast<char *>(&t), 2);
    return t;
}

uint32_t KaitaiStream::read_u4le() {
    uint32_t t;
    _io->read(reinterpret_cast<char *>(&t), 4);
    return t;
}

uint64_t KaitaiStream::read_u8le() {
    uint64_t t;
    _io->read(reinterpret_cast<char *>(&t), 8);
    return t;
}

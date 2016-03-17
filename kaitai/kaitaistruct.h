#ifndef KAITAI_STRUCT_H
#define KAITAI_STRUCT_H

#include <kaitai/kaitaistream.h>

class KaitaiStruct {
public:
    KaitaiStruct(KaitaiStream *_io) { _m_io = _io; };
private:
    KaitaiStream *_m_io;
public:
    KaitaiStream *_io() { return _m_io; };
};

#endif

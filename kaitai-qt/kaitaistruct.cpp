#include "kaitai-qt/kaitaistruct.h"

namespace kaitai {

kstruct::kstruct(kstream *_io, QObject *parent)
    : QObject{parent}
{
    m__io = _io;
    m__struct_start_pos = m__io ? m__io->pos() : 0;
}

kstream * kstruct::_io()
{
    return m__io;
}

uint64_t kstruct::_struct_start_pos()
{
    return m__struct_start_pos;
}

kstruct::~kstruct() = default;

}

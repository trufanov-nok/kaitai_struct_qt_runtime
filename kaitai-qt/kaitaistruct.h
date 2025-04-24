#ifndef KAITAI_STRUCT_H
#define KAITAI_STRUCT_H
#include <QObject>

#include <kaitai-qt/kaitaistream.h>

namespace kaitai {

class kstruct: public QObject
{
    Q_OBJECT
public:
    kstruct(kstream *_io, QObject *parent = nullptr);
    virtual ~kstruct();

    kstream *_io();
    uint64_t _struct_start_pos();
protected:
    kstream *m__io;
    uint64_t m__struct_start_pos;
};

}

#endif

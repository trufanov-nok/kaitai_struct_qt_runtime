# Kaitai Struct: runtime library for Qt

This library implements Kaitai Struct API for Qt.

Kaitai Struct is a declarative language used for describe various binary
data structures, laid out in files or in memory: i.e. binary file
formats, network stream packet formats, etc.

Further reading:

* [About Kaitai Struct](https://kaitai.io/)
* [About API implemented in this library](https://doc.kaitai.io/stream_api.html)

This is basically a C++/STL runtime with followings changes:  

* kstruct objects are QObject-based and could be iterated via parent()/children() methods
* members are wrapped with Q_PROPERTY() macro and that makes them searchable at runtime with Qt Meta-Object System
* endian.h is repalced with QtEndian functions for crosplatform compatibility  

Requires a Qt support in Kaitai Struct Compiler: https://github.com/ALEXfeed1407/kaitai_struct_compiler/tree/qt_compiler

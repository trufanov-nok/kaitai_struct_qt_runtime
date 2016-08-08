#ifndef KAITAI_STREAM_H
#define KAITAI_STREAM_H

#include <istream>
#include <fstream>
#include <stdint.h>
#include <sys/types.h>

namespace kaitai {

/**
 * Kaitai Stream class (kstream) is a wrapper over generic STL std::istream
 * that implements Kaitai Stream API for C++/STL. It provides a wide variety
 * of simple methods to read (parse) binary representations of primitive types,
 * such as integer and floating point numbers, byte arrays and strings, and
 * also provides stream positioning / navigation methods with unified
 * cross-language and cross-toolkit semantics.
 *
 * Typically, end users won't access Kaitai Stream class manually, but would
 * describe a binary structure format using .ksy language and then would use
 * Kaitai Struct compiler to generate source code in desired target language.
 * This code, in turn, would use this class and API to do the actual parsing
 * job.
 */
class kstream {
public:
    /**
     * Constructs new Kaitai Stream object, wrapping a given std::istream.
     * \param io istream object to use for this Kaitai Stream
     */
    kstream(std::istream* io);

    /**
     * Constructs new Kaitai Stream object, wrapping a given in-memory data
     * buffer.
     * \param data data buffer to use for this Kaitai Stream
     */
    kstream(std::string& data);

    void close();

    /** @name Stream positioning */
    //@{
    /**
     * Check if stream pointer is at the end of stream. Note that the semantics
     * are different from traditional STL semantics: one does *not* need to do a
     * read (which will fail) after the actual end of the stream to trigger EOF
     * flag, which can be accessed after that read. It is sufficient to just be
     * at the end of the stream for this method to return true.
     * \return "true" if we are located at the end of the stream.
     */
    bool is_eof() const;

    /**
     * Set stream pointer to designated position.
     * \param pos new position (offset in bytes from the beginning of the stream)
     */
    void seek(std::ifstream::pos_type pos);

    /**
     * Get current position of a stream pointer.
     * \return pointer position, number of bytes from the beginning of the stream
     */
    std::ifstream::pos_type pos();

    /**
     * Get total size of the stream in bytes.
     * \return size of the stream in bytes
     */
    std::ifstream::pos_type size();
    //@}

    /** @name Integer numbers */
    //@{

    // ------------------------------------------------------------------------
    // Signed
    // ------------------------------------------------------------------------

    int8_t read_s1();

    // ........................................................................
    // Big-endian
    // ........................................................................

    int16_t read_s2be();
    int32_t read_s4be();
    int64_t read_s8be();

    // ........................................................................
    // Little-endian
    // ........................................................................

    int16_t read_s2le();
    int32_t read_s4le();
    int64_t read_s8le();

    // ------------------------------------------------------------------------
    // Unsigned
    // ------------------------------------------------------------------------

    uint8_t read_u1();

    // ........................................................................
    // Big-endian
    // ........................................................................

    uint16_t read_u2be();
    uint32_t read_u4be();
    uint64_t read_u8be();

    // ........................................................................
    // Little-endian
    // ........................................................................

    uint16_t read_u2le();
    uint32_t read_u4le();
    uint64_t read_u8le();

    //@}

    /** @name Floating point numbers */
    //@{

    // ........................................................................
    // Big-endian
    // ........................................................................

    float read_f4be();
    double read_f8be();

    // ........................................................................
    // Little-endian
    // ........................................................................

    float read_f4le();
    double read_f8le();

    //@}

    /** @name Strings */
    //@{

    std::string read_str_byte_limit(ssize_t len);
    std::string read_strz(char term, bool include, bool consume, bool eos_error);

    //@}

    /** @name Byte arrays */
    //@{

    std::string read_bytes(ssize_t len);
    std::string read_bytes_full();
    std::string ensure_fixed_contents(ssize_t len, const char* expected);

    //@}

    /** @name Byte array processing */
    //@{

    static std::string process_xor_one(std::string data, uint8_t key);
    static std::string process_xor_many(std::string data, std::string key);
    static std::string process_rotate_left(std::string data, int amount);

    //@}

private:
    std::istream* m_io;
};

}

#endif

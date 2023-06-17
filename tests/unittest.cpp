#ifdef GTEST_NANO
#include "tests/gtest-nano.h"
#else
#include <gtest/gtest.h>
#endif

#include "kaitai/kaitaistream.h"

TEST(KaitaiStreamTest, to_string)
{
    EXPECT_EQ(kaitai::kstream::to_string(123), "123");
    EXPECT_EQ(kaitai::kstream::to_string(-123), "-123");
}

TEST(KaitaiStreamTest, to_string_uint8)
{
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<uint8_t>::min()), "0");
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<uint8_t>::max()), "255");
}

TEST(KaitaiStreamTest, to_string_int8)
{
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<int8_t>::min()), "-128");
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<int8_t>::max()), "127");
}

TEST(KaitaiStreamTest, to_string_uint16)
{
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<uint16_t>::min()), "0");
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<uint16_t>::max()), "65535");
}

TEST(KaitaiStreamTest, to_string_int16)
{
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<int16_t>::min()), "-32768");
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<int16_t>::max()), "32767");
}

TEST(KaitaiStreamTest, to_string_uint32)
{
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<uint32_t>::min()), "0");
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<uint32_t>::max()), "4294967295");
}

TEST(KaitaiStreamTest, to_string_int32)
{
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<int32_t>::min()), "-2147483648");
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<int32_t>::max()), "2147483647");
}

TEST(KaitaiStreamTest, to_string_uint64)
{
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<uint64_t>::min()), "0");
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<uint64_t>::max()), "18446744073709551615");
}

TEST(KaitaiStreamTest, to_string_int64)
{
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<int64_t>::min()), "-9223372036854775808");
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<int64_t>::max()), "9223372036854775807");
}

TEST(KaitaiStreamTest, bytes_to_str_ascii)
{
    std::string res = kaitai::kstream::bytes_to_str("Hello, world!", "ASCII");
    EXPECT_EQ(res, "Hello, world!");
}

#ifndef KS_STR_ENCODING_NONE
TEST(KaitaiStreamTest, bytes_to_str_iso8859_1)
{
    auto res = kaitai::kstream::bytes_to_str("\xC4\xD6\xDC\xE4\xF6\xFC\xDF", "ISO8859-1");
    EXPECT_EQ(res, "\xC3\x84\xC3\x96\xC3\x9C\xC3\xA4\xC3\xB6\xC3\xBC\xC3\x9F");
}

TEST(KaitaiStreamTest, bytes_to_str_gb2312)
{
    auto res = kaitai::kstream::bytes_to_str("\xC4\xE3\xBA\xC3\xCA\xC0\xBD\xE7", "GB2312");
    EXPECT_EQ(res, "\xE4\xBD\xA0\xE5\xA5\xBD\xE4\xB8\x96\xE7\x95\x8C");
}

TEST(KaitaiStreamTest, bytes_to_str_cp437)
{
    auto res = kaitai::kstream::bytes_to_str("\xCC\xB2\x40", "cp437");
    EXPECT_EQ(res, "\xE2\x95\xA0\xE2\x96\x93\x40");
}

TEST(KaitaiStreamTest, bytes_to_str_utf16_le)
{
    // NB: UTF16 bytes representation will have binary zeroes in the middle, so we need to convert it to std::string with explicit length
    auto res = kaitai::kstream::bytes_to_str(std::string("\x41\x00\x42\x00\x91\x25\x70\x24", 8), "UTF-16LE");
    EXPECT_EQ(res, "AB\xE2\x96\x91\xE2\x91\xB0");
}
#endif

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

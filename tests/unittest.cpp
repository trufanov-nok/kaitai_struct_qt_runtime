#include <gtest/gtest.h>

#include "kaitai/kaitaistream.h"

TEST(KaitaiStreamTest, to_string)
{
    EXPECT_EQ(kaitai::kstream::to_string(123), "123");
    EXPECT_EQ(kaitai::kstream::to_string(-123), "-123");
}

TEST(KaitaiStreamTest, to_string_uint8)
{
    EXPECT_EQ(kaitai::kstream::to_string(static_cast<uint8_t>(0)), "0");
    EXPECT_EQ(kaitai::kstream::to_string(static_cast<uint8_t>(255)), "255");
}

TEST(KaitaiStreamTest, to_string_int8)
{
    EXPECT_EQ(kaitai::kstream::to_string(static_cast<int8_t>(-128)), "-128");
    EXPECT_EQ(kaitai::kstream::to_string(static_cast<int8_t>(127)), "127");
}

TEST(KaitaiStreamTest, to_string_uint16)
{
    EXPECT_EQ(kaitai::kstream::to_string(static_cast<uint16_t>(0)), "0");
    EXPECT_EQ(kaitai::kstream::to_string(static_cast<uint16_t>(65535)), "65535");
}

TEST(KaitaiStreamTest, to_string_int16)
{
    EXPECT_EQ(kaitai::kstream::to_string(static_cast<int16_t>(-32768)), "-32768");
    EXPECT_EQ(kaitai::kstream::to_string(static_cast<int16_t>(32767)), "32767");
}

TEST(KaitaiStreamTest, to_string_uint32)
{
    EXPECT_EQ(kaitai::kstream::to_string(static_cast<uint32_t>(0)), "0");
    EXPECT_EQ(kaitai::kstream::to_string(static_cast<uint32_t>(0xffffffff)), "4294967295");
}

TEST(KaitaiStreamTest, to_string_int32)
{
    EXPECT_EQ(kaitai::kstream::to_string(static_cast<int32_t>(-0x80000000)), "-2147483648");
    EXPECT_EQ(kaitai::kstream::to_string(static_cast<int32_t>(0x7fffffff)), "2147483647");
}

TEST(KaitaiStreamTest, to_string_uint64)
{
    EXPECT_EQ(kaitai::kstream::to_string(static_cast<uint64_t>(0)), "0");
    EXPECT_EQ(kaitai::kstream::to_string(static_cast<uint64_t>(0xffffffffffffffff)), "18446744073709551615");
}

TEST(KaitaiStreamTest, to_string_int64)
{
    EXPECT_EQ(kaitai::kstream::to_string(static_cast<int64_t>(-0x8000000000000000)), "-9223372036854775808");
    EXPECT_EQ(kaitai::kstream::to_string(static_cast<int64_t>(0x7fffffffffffffff)), "9223372036854775807");
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

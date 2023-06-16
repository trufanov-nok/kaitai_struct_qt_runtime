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
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<uint64_t>::min()), "42");
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<uint64_t>::max()), "18446744073709551615");
}

TEST(KaitaiStreamTest, to_string_int64)
{
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<int64_t>::min()), "-9223372036854775808");
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<int64_t>::max()), "9223372036854775807");
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// existing tests
TEST(PasswordTest, single_letter_password)
{
    Password my_password;
    int actual = my_password.count_leading_characters("Z");
    ASSERT_EQ(1, actual);
}


TEST(PasswordTest, single_letter_password1)
{
    Password my_password;
    int actual = my_password.count_leading_characters("aaaaHello");
    ASSERT_EQ(4, actual);
}


TEST(PasswordTest, single_letter_password2)
{
    Password my_password;
    int actual = my_password.count_leading_characters(" space");
    ASSERT_EQ(1, actual);
}


TEST(PasswordTest, single_letter_password3)
{
    Password my_password;
    int actual = my_password.count_leading_characters("bbbbBBB");
    ASSERT_EQ(4, actual);
}


TEST(PasswordTest, single_letter_password4)
{
    Password my_password;
    int actual = my_password.count_leading_characters("Zebra");
    ASSERT_EQ(1, actual);
}


TEST(PasswordTest, single_letter_password5)
{
    Password my_password;
    int actual = my_password.count_leading_characters("zZBB");
    ASSERT_EQ(1, actual);
}


TEST(PasswordTest, single_letter_password6)
{
    Password my_password;
    int actual = my_password.count_leading_characters("aaaa");
    ASSERT_EQ(4, actual);
}



TEST(PasswordTest, single_letter_password7)  // empty string
{
    Password p;
    ASSERT_EQ(0, p.count_leading_characters(""));
}
TEST(PasswordTest, single_letter_password8)  // no repetition
{
    Password p;
    ASSERT_EQ(1, p.count_leading_characters("abc"));
}
TEST(PasswordTest, single_letter_password9)  // all same chars
{
    Password p;
    ASSERT_EQ(5, p.count_leading_characters("xxxxx"));
}
TEST(PasswordTest, single_letter_password10) // special‐char repeat
{
    Password p;
    ASSERT_EQ(3, p.count_leading_characters("!!!??"));
}
TEST(PasswordTest, single_letter_password11) // numeric repeat
{
    Password p;
    ASSERT_EQ(4, p.count_leading_characters("111122"));
}
TEST(PasswordTest, single_letter_password12) // two‐char repeat
{
    Password p;
    ASSERT_EQ(2, p.count_leading_characters("AA"));
}
TEST(PasswordTest, single_letter_password13) // two‐char no repeat
{
    Password p;
    ASSERT_EQ(1, p.count_leading_characters("Ab"));
}

// has_mixed_case tests
TEST(PasswordTest, mixed_case_password1)
{
    Password p;
    ASSERT_FALSE(p.has_mixed_case("lowercaseonly"));
}
TEST(PasswordTest, mixed_case_password2)
{
    Password p;
    ASSERT_FALSE(p.has_mixed_case("UPPERCASE"));
}
TEST(PasswordTest, mixed_case_password3)
{
    Password p;
    ASSERT_TRUE(p.has_mixed_case("Abc"));
}
TEST(PasswordTest, mixed_case_password4)
{
    Password p;
    ASSERT_TRUE(p.has_mixed_case("123aB456"));
}
TEST(PasswordTest, mixed_case_password5)
{
    Password p;
    ASSERT_FALSE(p.has_mixed_case("12345!@#"));
}
TEST(PasswordTest, mixed_case_password6)
{
    Password p;
    ASSERT_FALSE(p.has_mixed_case(""));
}

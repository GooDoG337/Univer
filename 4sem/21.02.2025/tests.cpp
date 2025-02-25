#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "dateCheck.h"

using dateCheck::isValidDate;
TEST_SUITE_BEGIN("WRONG ALL");
TEST_CASE("Wrong day")
{
    CHECK_EQ(isValidDate("32.01.1980 12:00"), false);   //Январь
    CHECK_EQ(isValidDate("30.02.1980 12:00"), false);
    CHECK_EQ(isValidDate("29.02.1981 12:00"), false);
    CHECK_EQ(isValidDate("32.03.1980 12:00"), false);
    CHECK_EQ(isValidDate("31.04.1980 12:00"), false);
    CHECK_EQ(isValidDate("32.05.1980 12:00"), false);
    CHECK_EQ(isValidDate("31.06.1980 12:00"), false);
    CHECK_EQ(isValidDate("32.07.1980 12:00"), false);
    CHECK_EQ(isValidDate("32.08.1980 12:00"), false);
    CHECK_EQ(isValidDate("31.09.1980 12:00"), false);
    CHECK_EQ(isValidDate("32.10.1980 12:00"), false);
    CHECK_EQ(isValidDate("31.11.1980 12:00"), false);
    CHECK_EQ(isValidDate("32.12.1980 12:00"), false);
}
TEST_CASE("Wrong months")
{
    CHECK_EQ(isValidDate("01.00.1980 12:00"), false);
    CHECK_EQ(isValidDate("01.13.1980 12:00"), false);
    CHECK_EQ(isValidDate("01.23.1980 12:00"), false);
}
TEST_CASE("Wrong years, I guess?")
{
    CHECK_EQ(isValidDate("01.01.0999 12:00"), false);
    CHECK_EQ(isValidDate("01.01.0996 12:00"), false);
}
TEST_CASE("Wrong time")
{
    CHECK_EQ(isValidDate("01.01.1980 24:00"), false);
    CHECK_EQ(isValidDate("01.01.1980 23:60"), false);
}
TEST_SUITE_END;

TEST_SUITE_BEGIN("Righty'o");
TEST_CASE("Right day")
{
    TEST_SUITE_BEGIN("January");
    {
        CHECK_EQ(isValidDate("31.01.1980 12:00"), true);
        CHECK_EQ(isValidDate("25.01.1980 12:00"), true);
        CHECK_EQ(isValidDate("10.01.1980 12:00"), true);
        CHECK_EQ(isValidDate("01.01.1980 12:00"), true);
    }
    TEST_SUITE_END;

    TEST_SUITE_BEGIN("February");
    {
        CHECK_EQ(isValidDate("28.02.1980 12:00"), true);
        CHECK_EQ(isValidDate("27.02.1981 12:00"), true);
        CHECK_EQ(isValidDate("25.02.1980 12:00"), true);
        CHECK_EQ(isValidDate("10.02.1980 12:00"), true);
        CHECK_EQ(isValidDate("01.02.1980 12:00"), true);
    }
    TEST_SUITE_END;

    TEST_SUITE_BEGIN("April");
    {
        CHECK_EQ(isValidDate("30.04.1980 12:00"), true);
        CHECK_EQ(isValidDate("29.04.1980 12:00"), true);
        CHECK_EQ(isValidDate("10.04.1980 12:00"), true);
        CHECK_EQ(isValidDate("01.04.1980 12:00"), true);
    }
    TEST_SUITE_END;

}
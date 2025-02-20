//
// Created by stud-16 on 12/10/24.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "calc.h"

/*TEST_CASE("Testing addition") {
    CHECK(add(1,1)== 2);
    CHECK(add(-1,1)== 0);
    //CHECK_EQ(3,3);                  // ==
    //CHECK_NE(5,3);                  // !=
    //CHECK_GT(7,4);                  // >
    //CHECK_LT(3,6);                  // <
    //CHECK_GE(5,5);                  // >=
    //CHECK_LE(7,7);                  // <=
    //CHECK_FALSE(add(5,5) == 2); // !
    //REQUIRE(add(5,5)==0);       // Must make error, or something like it
    CHECK(add(-1,-1)== -2);
    //CHECK_THROWS(add("abc", 0));  //Check there is any exception
    //CHECK_THROWS_AS(f(a), std::exception); // Check exact function exception
    //CHECK_THROWS_WITH(f(a), "Exception message"); // Check exact function exception's text
    //CHECK_THROWS_WITH_AS(f(a), "Message", exception_type); // Works as CHECK_THROWS_AS+CHECK_THROWS_WITH
    //CHECK_NOTHROW(f(a)); // Check there is not exception
    //CHECK_THROWS_WITH(f(a), doctest::Contains("Wrong"));    // Check is exception message contains "Wrong"
    REQUIRE(div(22.2798,7.0) == doctest::Approx(3.141).epsilon(0.01));
}
TEST_CASE("Testing sub") {
    CHECK(sub(2,1)== 1);
    WARN(sub(2,2)== 1);         // Must just warn, no test failure
    CHECK(sub(5,5)==10);
    CHECK(sub(2,3)== -1);
}
*/

//TEST_SUITE_BEGIN("math");
TEST_SUITE("math") {
    TEST_CASE("Testing sub") {
        CHECK(sub(2,1)== 1);
        WARN(sub(2,2)== 1);         // Must just warn, no test failure
        CHECK(sub(5,5)==10);
        CHECK(sub(2,3)== -1);
    }
    TEST_CASE("Testing addition") {
        CHECK(add(1,1)== 2);
        CHECK(add(-1,1)== 0);
        CHECK(add(-1,-1)== -2);
    }
}

TEST_SUITE_BEGIN("division");
TEST_CASE("") {
    CHECK(div(33.0,3.0)==11.0);
    CHECK(div(50.0,25.0)==2.0);
    CHECK(div(77.7,7.0) == doctest::Approx(11.1).epsilon(0.01));
    CHECK(div(22.0,7.0) == doctest::Approx(3.141).epsilon(0.01));
}
TEST_SUITE_END();

//1.Один тест покрывает ОДНУ возможную ошибку
//2.Проверка ожидаемых данных
//3.Проверка левой и правых границ
//4.Проверка пустого массива
//5.Проверка выхода за границы
//6.Проверка ложных типов данных
//7.Проверка максимальных массивов

//Новые требования для новых проектов
//Проект должен быть в отдельном репозитории
//Работает над репозиторием оба человека
//У репозитория должен быть величественный README
//Проект должен быть покрыт тестами с помощью doctest
//Ни при каких условиях проект не должен крашиться
//Должен быть CMakeList.txt
//Программа делится на main+library и tests+library
//Должна быть возможность собрать library и как статическую, и как динамическую библиотеку.
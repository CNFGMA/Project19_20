#include "doctest.h"
#include "input.hpp"

TEST_CASE("testing the input of the file"){
    char quarantine;
    CHECK_THROWS(input_config("testinput.txt",quarantine));
    CHECK_THROWS(input_config("input_test1.txt",quarantine));
    CHECK_THROWS(input_config("input_test2.txt",quarantine));
    CHECK_THROWS(input_config("input_test3.txt",quarantine));
    CHECK_THROWS(input_config("input_test4.txt",quarantine));
    Board test_board = input_config("input_test5.txt", quarantine);
    CHECK(test_board(1, 1) == State::Infected);
    CHECK(test_board(2, 2) == State::Susceptible);
    CHECK(test_board(3, 3) == State::Susceptible);
    CHECK(test_board(4, 4) == State::Susceptible);
    CHECK(test_board(5, 5) == State::Susceptible);
}
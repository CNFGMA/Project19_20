#include "doctest.h"
#include "input.hpp"

TEST_CASE("testing the input of the file") {
  char quarantine;
  CHECK_THROWS(input_config("necessary_files/testinput.txt", quarantine)); //Check if the input file doesn't exist
  
  CHECK_THROWS(input_config("necessary_files/input_test1.txt", quarantine)); //Check if there is a value different from 'Y' or 'N'
  
  CHECK_THROWS(input_config("necessary_files/input_test2.txt", quarantine));
  CHECK_THROWS(input_config("necessary_files/input_test6.txt", quarantine)); //Check if the board is created with unacceptable values for Rows and Columns
  
  CHECK_THROWS(input_config("necessary_files/input_test3.txt", quarantine)); 
  CHECK_THROWS(input_config("necessary_files/input_test7.txt", quarantine)); //Check if the coordinates are negative

  CHECK_THROWS(input_config("necessary_files/input_test4.txt", quarantine)); //Check if one or more cells are created with different values from 'S', 'I', or 'R'
  
  Board test_board = input_config("necessary_files/input_test5.txt", quarantine);
  CHECK(test_board(1, 1) == State::Infected);
  CHECK(test_board(2, 2) == State::Susceptible);
  CHECK(test_board(3, 3) == State::Susceptible);
  CHECK(test_board(4, 4) == State::Susceptible);
  CHECK(test_board(5, 5) == State::Susceptible);
}

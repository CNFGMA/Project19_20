#include "doctest.h"
#include "step.hpp"

TEST_CASE("testing the movement of the cells") {
  Board test_board(5, 5);
  test_board(1, 1) = State::Infected;
  test_board(3, 1) = State::Susceptible;
  test_board(5, 2) = State::Susceptible;
  test_board(3, 3) = State::Recovered;
  test_board(3, 5) = State::Susceptible;
  test_board(5, 4) = State::Susceptible;
  for (int i = 0; i != 7; ++i) {
    stepq(test_board);
    CHECK(test_board.count_all() == 6);
  }
  CHECK(test_board.count_Susceptible() + test_board.count_Recovered() + test_board.count_Infected() == test_board.count_all());

  test_board = Board{5,5};
  test_board(1, 1) = State::Infected;
  test_board(3, 1) = State::Susceptible;
  test_board(5, 2) = State::Susceptible;
  test_board(3, 3) = State::Recovered;
  test_board(3, 5) = State::Susceptible;
  test_board(5, 4) = State::Susceptible;
  for (int i = 0; i != 7; ++i) {
    stepnq(test_board);
    CHECK(test_board.count_all() == 6);
  }
  CHECK(test_board.count_Susceptible() + test_board.count_Recovered() + test_board.count_Infected() == test_board.count_all());
}
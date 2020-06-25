#include "doctest.h"
#include "near_infect.hpp"

TEST_CASE("testing near infect") {
  Board test_board(5, 5);

  test_board(3, 3) = State::Susceptible;
  test_board(2, 2) = State::Infected;
  test_board(2, 3) = State::Infected;
  test_board(2, 4) = State::Infected;
  test_board(3, 2) = State::Infected;
  test_board(3, 4) = State::Infected;
  test_board(4, 2) = State::Infected;
  test_board(4, 3) = State::Infected;
  test_board(4, 4) = State::Infected;

  CHECK(near_infect(test_board, 3, 3) == 8);

  test_board(2, 2) = State::Susceptible;
  CHECK(near_infect(test_board, 3, 3) == 7);

  test_board(2, 3) = State::Susceptible;
  CHECK(near_infect(test_board, 3, 3) == 6);

  test_board(2, 4) = State::Susceptible;
  CHECK(near_infect(test_board, 3, 3) == 5);

  test_board(3, 2) = State::Susceptible;
  CHECK(near_infect(test_board, 3, 3) == 4);

  test_board(3, 4) = State::Susceptible;
  CHECK(near_infect(test_board, 3, 3) == 3);

  test_board(4, 2) = State::Susceptible;
  CHECK(near_infect(test_board, 3, 3) == 2);

  test_board(4, 3) = State::Susceptible;
  CHECK(near_infect(test_board, 3, 3) == 1);

  test_board(4, 4) = State::Susceptible;
  CHECK(near_infect(test_board, 3, 3) == 0);

  test_board = Board{5, 5};
  test_board(3, 3) = State::Susceptible;
  CHECK(near_infect(test_board, 3, 3) == 0);
}


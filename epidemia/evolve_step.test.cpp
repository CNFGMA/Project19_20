#include "doctest.h"
#include "evolve.hpp"
#include "step.hpp"

TEST_CASE(
    "Testing the evolution of infection with cells movement with quarantine") {
  Board test_board(10, 20);
  test_board(1, 3) = State::Susceptible;
  test_board(2, 2) = State::Susceptible;
  test_board(2, 3) = State::Susceptible;
  test_board(2, 4) = State::Susceptible;
  test_board(3, 1) = State::Susceptible;
  test_board(3, 2) = State::Susceptible;
  test_board(3, 3) = State::Infected;
  test_board(3, 4) = State::Susceptible;
  test_board(3, 5) = State::Susceptible;
  test_board(5, 3) = State::Susceptible;
  test_board(4, 2) = State::Susceptible;
  test_board(4, 3) = State::Susceptible;
  test_board(4, 4) = State::Susceptible;
  test_board(10, 3) = State::Susceptible;
  test_board(9, 2) = State::Susceptible;
  test_board(8, 3) = State::Susceptible;
  test_board(10, 20) = State::Susceptible;
  int total_cells = test_board.count_all();
  int end = test_board.count_Infected();
  for (int i = 0; end != 0; ++i) {
    stepq(test_board);
    test_board = evolve(test_board, i);
    end = test_board.count_Infected();
    CHECK(test_board.count_all() == total_cells);
  }
  CHECK(test_board.count_Recovered() + test_board.count_Susceptible() ==
        test_board.count_all());
  CHECK(test_board.count_all() == total_cells);
}

TEST_CASE("Testing the evolution of infection with cells movement without "
          "quarantine") {
  Board test_board(10, 20);
  test_board(1, 3) = State::Susceptible;
  test_board(2, 2) = State::Susceptible;
  test_board(2, 3) = State::Susceptible;
  test_board(2, 4) = State::Susceptible;
  test_board(3, 1) = State::Susceptible;
  test_board(3, 2) = State::Susceptible;
  test_board(3, 3) = State::Infected;
  test_board(3, 4) = State::Susceptible;
  test_board(3, 5) = State::Susceptible;
  test_board(5, 3) = State::Susceptible;
  test_board(4, 2) = State::Susceptible;
  test_board(4, 3) = State::Susceptible;
  test_board(4, 4) = State::Susceptible;
  test_board(10, 3) = State::Susceptible;
  test_board(9, 2) = State::Susceptible;
  test_board(8, 3) = State::Susceptible;
  test_board(10, 20) = State::Susceptible;
  int total_cells = test_board.count_all();
  int end = test_board.count_Infected();
  for (int i = 0; end != 0; ++i) {
    stepnq(test_board);
    test_board = evolve(test_board, i);
    end = test_board.count_Infected();
    CHECK(test_board.count_all() == total_cells);
  }
  CHECK(test_board.count_Recovered() + test_board.count_Susceptible() ==
        test_board.count_all());
  CHECK(test_board.count_all() == total_cells);
}



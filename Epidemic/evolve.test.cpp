#include "doctest.h"
#include "evolve.hpp"

TEST_CASE("testing the evolution of the board") {
  Board test_board(5, 5);
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
  int end = test_board.count_Infected();
  for (int i = 1; end != 0; ++i) {
    test_board = evolve(test_board, i);
    end = test_board.count_Infected();
  }
  CHECK(test_board.count_Infected() == 0);
  CHECK(test_board.count_all() == 13);

  test_board = Board{5, 2}; // reset
  test_board(1, 1) = State::Infected;
  test_board(3, 1) = State::Susceptible;
  test_board(5, 2) = State::Susceptible;
  end = test_board.count_Infected();
  for (int i = 1; end != 0; ++i) {
    test_board = evolve(test_board, i);
    end = test_board.count_Infected();
    CHECK(test_board.count_all() == 3);
  }
  CHECK(test_board.count_Recovered() + test_board.count_Susceptible() ==
        test_board.count_all());
  CHECK(test_board.count_all() == 3);
}



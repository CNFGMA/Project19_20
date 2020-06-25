#include "board.hpp"
#include "doctest.h"

TEST_CASE("Board test size") {
  Board test_board(10, 20);
  test_board(1, 1) = State::Infected;
  test_board(1, 2) = State::Susceptible;
  test_board(3, 3) = State::Infected;
  CHECK(test_board.SizeColumn() == 20);
  CHECK(test_board.SizeRow() == 10);
  CHECK(test_board.size() == 264);
  CHECK(test_board.size() != 200);
}
TEST_CASE("Board test counting cell") {
  Board test_board(10, 20);
  CHECK(test_board.count_Susceptible() == 0);
  CHECK(test_board.count_Infected() == 0);
  CHECK(test_board.count_Susceptible() == 0);
  CHECK(test_board.count_Recovered() == 0);
  CHECK(test_board.count_all() == 0);
  CHECK(count_cell<std::vector<State>, State>(test_board.get_vector_board(),
                                              State::Off) == 200);
  CHECK(count_cell<std::vector<State>, State>(test_board.get_vector_board(),
                                              State::Border) == 64);
  CHECK(count_cell<std::vector<State>, State>(test_board.get_vector_board(),
                                              State::MoveI) == 0);
  CHECK(count_cell<std::vector<State>, State>(test_board.get_vector_board(),
                                              State::MoveS) == 0);
  test_board(1, 1) = State::Infected;
  test_board(2, 2) = State::Susceptible;
  test_board(3, 3) = State::Recovered;
  CHECK(test_board.count_Susceptible() == 1);
  CHECK(test_board.count_Infected() == 1);
  CHECK(test_board.count_Susceptible() == 1);
  CHECK(test_board.count_Recovered() == 1);
  CHECK(test_board.count_all() == 3);
  CHECK(count_cell<std::vector<State>, State>(test_board.get_vector_board(),
                                              State::Off) == 197);
  CHECK(count_cell<std::vector<State>, State>(test_board.get_vector_board(),
                                              State::Border) == 64);
  CHECK(count_cell<std::vector<State>, State>(test_board.get_vector_board(),
                                              State::MoveI) == 0);
  CHECK(count_cell<std::vector<State>, State>(test_board.get_vector_board(),
                                              State::MoveS) == 0);
  test_board(1, 1) = State::MoveI;
  CHECK(count_cell<std::vector<State>, State>(test_board.get_vector_board(),
                                              State::MoveI) == 1);
  test_board(2, 2) = State::MoveS;
  CHECK(count_cell<std::vector<State>, State>(test_board.get_vector_board(),
                                              State::MoveS) == 1);
  CHECK(count_cell<std::vector<State>, State>(test_board.get_vector_board(),
                                              State::MoveS, State::MoveI) == 2);
}
TEST_CASE("testing refresh status") {
  Board test_board(2, 5);
  test_board(1, 1) = State::MoveI;
  test_board(1, 2) = State::MoveI;
  test_board(1, 4) = State::MoveI;
  test_board(2, 1) = State::MoveS;
  test_board(2, 2) = State::MoveS;
  test_board(2, 4) = State::MoveS;
  test_board.refresh_state(State::MoveI, State::Infected);
  CHECK(test_board.count_Infected() == 3);
  test_board.refresh_state(State::MoveS, State::Susceptible);
  CHECK(test_board.count_Susceptible() == 3);
}



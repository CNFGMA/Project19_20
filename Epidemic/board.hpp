#ifndef BOARD_HPP
#define BOARD_HPP

#include "count_cell.hpp"
#include <cassert>
#include <iostream>
#include <vector>

enum class State : char {
  Susceptible = '*',
  Infected = '+',
  Recovered = 'x',
  Off = ' ',
  Border = '#',
  MoveS,
  MoveI
}; // This enum represents the state of each cell

class Board { // This class represents the whole space populated by the cells
  std::vector<State> board_;
  int n_;
  int m_;

public:
  Board(int n, int m)
      : n_{n}, m_{m} { // Cycle used to fill the Board with "empty cells" when
                       // the Board is created
    for (int i = 0; i != (n_ + 2); ++i) {
      for (int j = 0; j != (m_ + 2); ++j) {
        if (i == 0 || i == (n_ + 1) || j == 0 || j == (m_ + 1)) {
          board_.push_back(State::Border);
        } else {
          board_.push_back(State::Off);
        }
      }
    }
  }

  State operator()(int i, int j) const {
    assert((i >= 0 && i <= n_ + 1) && (j >= 0 && j <= m_ + 1));
    return board_[i * (m_ + 2) + j];
  }
  State &operator()(int i, int j) {
    assert(i >= 1 && i <= n_ && j >= 1 && j <= m_);
    return board_[i * (m_ + 2) + j];
  }

  void PrintAll() {
    for (int i = 0; i != n_ + 2; ++i) {
      for (int j = 0; j != m_ + 2; ++j) {
        switch (board_[i * (m_ + 2) + j]) {
        case State::Infected:
          std::cout << "\u001b[31m" << (char)board_[i * (m_ + 2) + j];
          break;
        case State::Recovered:
          std::cout << "\u001b[32m" << (char)board_[i * (m_ + 2) + j];
          break;
        case State::Susceptible:
          std::cout << "\u001b[33m" << (char)board_[i * (m_ + 2) + j];
          break;
        default:
          std::cout << "\u001b[37m" << (char)board_[i * (m_ + 2) + j];
          break;
        }
      }
      std::cout << '\n';
    }
    std::cout << '\n';
  }
  int SizeRow() const { return n_; }
  int SizeColumn() const { return m_; }
  int size() const { return (n_ + 2) * (m_ + 2); }
  int count_all() const {
    return count_cell<std::vector<State>, State>(
        board_, State::Susceptible, State::Recovered, State::Infected);
  }
  int count_Susceptible() const {
    return count_cell<std::vector<State>, State>(board_, State::Susceptible);
  }
  int count_Infected() const {
    return count_cell<std::vector<State>, State>(board_, State::Infected);
  }
  int count_Recovered() const {
    return count_cell<std::vector<State>, State>(board_, State::Recovered);
  }
  void refresh_state(State old, State new_state) {
    for (auto &i : board_) {
      if (i == old)
        i = new_state;
    }
  }
  auto get_vector_board() const { return board_; }
};

#endif




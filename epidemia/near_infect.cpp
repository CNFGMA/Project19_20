#include "near_infect.hpp"

//This function evaluates the number of infected cells around one selected cell

int near_infect(Board const &board, int const r, int const c) {
  int inf = 0; 
  for (int i = r - 1; i != r + 2; ++i) {
    for (int j = c - 1; j != c + 2; ++j) {
      if (board(i, j) == State::Infected && (i!=r || j!=c))
        ++inf;
    }
  }
  return inf;
}

#ifndef COUNT_CELL_HPP
#define COUNT_CELL_HPP

template <class T, class S> int count_cell(T const &board, S const &state) {
  int N_cell = 0;
  for (auto const &i : board) {
    if (i == state)
      ++N_cell;
  }
  return N_cell;
}
template <class T, class S>
int count_cell(T const &board, S const &state1, S const &state2) {
  int N_cell = 0;
  for (auto const &i : board) {
    if (i == state1 || i == state2)
      ++N_cell;
  }
  return N_cell;
}
template <class T, class S>
int count_cell(T const &board, S const &state1, S const &state2,
               S const &state3) {
  int N_cell = 0;
  for (auto const &i : board) {
    if (i == state1 || i == state2 || i == state3)
      ++N_cell;
  }
  return N_cell;
}

#endif



#include "near_infect.hpp"
#include "step.hpp"
#include <random>
// without quarantine

// Function for the movements: every cell has a certain probability to move.
// Every cell can move only towards "Off" cells. The movements consist of
// swapping the initial cell with the final cell.

void stepnq(Board &curr) {
  std::random_device dev{};
  std::mt19937 gen{dev()};
  std::uniform_int_distribution<int> dis(-1, 1);

  int const N = curr.SizeRow();
  int const M = curr.SizeColumn();
  for (int i = 1; i != N + 1; ++i) {
    for (int j = 1; j != M + 1; ++j) {
      auto const &next = curr;
      if (next(i, j) == State::Infected || next(i, j) == State::Susceptible) {
        int x = dis(gen);
        int y = dis(gen);
        if (next(i + y, j + x) == State::Off) {
          if (next(i, j) == State::Susceptible)
            curr(i + y, j + x) = State::MoveS;
          else if (next(i, j) == State::Infected)
            curr(i + y, j + x) = State::MoveI;
          curr(i, j) = State::Off;
        }
      }
    }
  }
  curr.refresh_state(State::MoveS, State::Susceptible);
  curr.refresh_state(State::MoveI, State::Infected);
}


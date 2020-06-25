#include "evolve.hpp"
#include "near_infect.hpp"
#include "time_function.hpp"
#include <random>

// This function is used to update the situation of the infections with the new
// Infected, Susceptibles and Recovered cells.

Board evolve(Board const &curr, int t) // t indicates the current iteration
{
  std::mt19937 gen;
  std::normal_distribution<double> dist(
      1.5, 0.5); // Random factor added to the epidemic evolution
  std::normal_distribution<double> dist1(1., 0.5);
  int const N = curr.SizeRow();
  int const M = curr.SizeColumn();
  auto next = curr;
  for (int i = 1; i != N + 1; i++) {
    for (int j = 1; j != M + 1; j++) {
      if (curr(i, j) == State::Infected) {
        auto gamma = gamma_t(t);
        if (gamma * dist(gen) >
            0.9) // Probability that an Infected cell becomes Recovered
        {
          next(i, j) = State::Recovered;
        }
      }
      if (curr(i, j) == State::Susceptible) {
        auto n_inf = near_infect(curr, i, j);
        assert(n_inf >= 0 && n_inf <= 8);
        auto beta = beta_inf(n_inf);
        if (beta * dist1(gen) >
            0.8) // Probability that a Susceptible cell becomes Infected
        {
          next(i, j) = State::Infected;
        }
      }
    }
  }
  return next;
}



#ifndef TIME_FUNCTION_HPP
#define TIME_FUNCTION_HPP
#include <cassert>
#include <cmath>
double gamma_t(int time);
inline double gamma_t(int time) { // to make gamma change with time
  double gamma = 0.1;             // probability of healing
  return gamma * std::log2(time + 1);
}

double beta_inf(int N_inf); // beta varies in function of the infected cells
                            // next to the selected cell
inline double beta_inf(int N_inf) {
  double beta =
      0.5; // probability that a cell next to an infected cell becomes infected
  return beta * N_inf * std::log2(N_inf + 1);
}

double quarantine(int n_inf, int tot_inf, int all);
inline double quarantine(int n_inf, int tot_inf, int all) {
  assert(n_inf >= 0 && n_inf <= 8);
  return (8 - n_inf) * std::exp(static_cast<double>(-tot_inf) / all);
}
#endif


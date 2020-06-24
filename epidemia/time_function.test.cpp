#include "doctest.h"
#include "time_function.hpp"

TEST_CASE("testing gamma function") {
  auto gamma = gamma_t(0);
  CHECK(gamma == 0);
  gamma = gamma_t(10);
  CHECK(gamma == doctest::Approx(0.345).epsilon(0.001));
  gamma = gamma_t(42);
  CHECK(gamma == doctest::Approx(0.542).epsilon(0.001));
  gamma = gamma_t(100);
  CHECK(gamma == doctest::Approx(0.665).epsilon(0.001));
}
TEST_CASE("Testing beta function") {
  auto beta = beta_inf(0);
  CHECK(beta == 0);
  beta = beta_inf(2);
  CHECK(beta == doctest::Approx(1.58).epsilon(0.01));
  beta = beta_inf(3);
  CHECK(beta == 3);
  beta = beta_inf(5);
  CHECK(beta == doctest::Approx(6.46).epsilon(0.01));
  beta = beta_inf(6);
  CHECK(beta == doctest::Approx(8.42).epsilon(0.01));
  beta = beta_inf(7);
  CHECK(beta == doctest::Approx(10.50).epsilon(0.01));
  beta = beta_inf(8);
  CHECK(beta == doctest::Approx(12.67).epsilon(0.01));
}
TEST_CASE("Testing the quarantine method") {
  double q = quarantine(0, 100, 200);
  CHECK(q == doctest::Approx(4.85).epsilon(0.01));
  q = quarantine(0, 20, 200);
  CHECK(q == doctest::Approx(7.23).epsilon(0.01));
  q = quarantine(1, 100, 200);
  CHECK(q == doctest::Approx(4.24).epsilon(0.01));
  q = quarantine(3, 20, 300);
  CHECK(q == doctest::Approx(4.67).epsilon(0.01));
  q = quarantine(8, 150, 300);
  CHECK(q == 0);
}


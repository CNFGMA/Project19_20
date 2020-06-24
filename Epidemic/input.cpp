#include "input.hpp"
#include <fstream>
#include <stdexcept>

// This function is used to correctly read files from input

Board input_config(std::string namefile, char &quarantine) {
  std::ifstream is{namefile}; // Reading from input file
  if (!is) {
    throw std::runtime_error{"Input file does not exist! \n"};
  }
  int R;
  int C;
  int x;
  int y;
  char state;
  is >> R >> C >> quarantine;
  if (R < 1 || C < 1 || (quarantine != 'Y' && quarantine != 'N')) {
    throw std::runtime_error{"Invalid input configuration \n"};
  }
  Board board(R, C);
  while (is >> x >> y >> state) {
    if (x < 1 || x > R || y < 1 || y > C) {
      throw std::runtime_error{"Invalid input coordinates \n"};
    }
    switch (state) {
    case 'S':
      board(x, y) = State::Susceptible;
      break;
    case 'I':
      board(x, y) = State::Infected;
      break;
    default:
      throw std::runtime_error{"Input states must be 'S' or 'I' \n"};
    }
  }
  is.close();
  return board;
}


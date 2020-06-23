#include "evolve.hpp"
#include "step.hpp"
#include "input.hpp"
#include <chrono>
#include <iomanip>
#include <thread>
#include <fstream>
#include <stdexcept>

int main() {
  std::string nf;
  std::cout << "enter a file name : ";
  getline(std::cin, nf);
  if (nf == "\0")
    nf = "input.txt"; // sets the default input file
  char quarantine;
  Board current = input_config(nf, quarantine);
  current.PrintAll();

  std::ofstream os{"output.txt"};
  int N_infected;
  int N_susceptible;
  int N_recovered;
  int i;
  int end = current.count_Infected();
  for (i = 0; end != 0; ++i) { //This is the main cycle of the program: it is used to update the situation of the infection and the movements of the cells on the Board
    std::cout << "\033[2J\033[1;1H";
    std::cout << "\033[40m";
    N_infected = current.count_Infected();
    N_susceptible = current.count_Susceptible();
    N_recovered = current.count_Recovered();
    os << i << "  " << N_infected << std::setw(12) << i << "  " << N_susceptible
       << std::setw(12) << i << "  " << N_recovered
       << '\n'; // Write on output file

    if(quarantine == 'Y'){
      stepq(current);
    }else{
      stepnq(current);
    }   // Movements of the cells
    current = evolve(current, i); // Evolve the infections
    current.PrintAll();           // Print on terminal
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    end = current.count_Infected(); // Evaluate if the epidemic is over
  }
  N_infected = current.count_Infected();
  N_susceptible = current.count_Susceptible();
  N_recovered = current.count_Recovered();
  os << i << "  " << N_infected << std::setw(12) << i << "  " << N_susceptible
     << std::setw(12) << i << "  " << N_recovered << '\n';
  os.close();
}



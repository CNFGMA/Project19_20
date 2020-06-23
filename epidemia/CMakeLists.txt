cmake_minimum_required(VERSION 3.0)

#Build the project

project(project_epidemic)

add_executable(project_epidemic main.cpp near_infect.cpp evolve.cpp stepq.cpp stepnq.cpp input.cpp) 

#Build the tests

add_executable(run_Board_tests Board.test.cpp run.test.cpp)
add_test(NAME Board_tests COMMAND run_Board_tests)

add_executable(run_input_tests input.test.cpp run.test.cpp input.cpp)
add_test(NAME input_test COMMAND run_input_tests)

add_executable(run_evolve_tests evolve.test.cpp run.test.cpp evolve.cpp near_infect.cpp)
add_test(NAME evolve_tests COMMAND run_evolve_tests)

add_executable(run_step_tests step.test.cpp run.test.cpp stepq.cpp stepnq.cpp near_infect.cpp)
add_test(NAME step_tests COMMAND run_step_tests)

add_executable(run_evolve_step_tests evolve_step.test.cpp evolve.cpp stepq.cpp stepnq.cpp near_infect.cpp  run.test.cpp)
add_test(NAME evolve_step_tests COMMAND run_evolve_step_tests)

add_executable(run_near_infect_tests near_infect.test.cpp near_infect.cpp run.test.cpp )
add_test(NAME near_infect_tests COMMAND run_near_infect_tests)

add_executable(run_time_function_tests time_function.test.cpp run.test.cpp)
add_test(NAME time_function_tests COMMAND run_time_function_tests)

add_executable(run_global_tests  run.test.cpp Board.test.cpp evolve_step.test.cpp evolve.cpp stepq.cpp stepnq.cpp near_infect.test.cpp near_infect.cpp time_function.test.cpp input.test.cpp input.cpp)
add_test(NAME global_tests COMMAND run_global_tests)




# autograding-example-cpp-smith-struct

## Full-Name-Of-Student

**TODO - Please put your name in this README**

## Problem Description

Please reference to Group Discussion - SmithStruct assignment for requirement

## Objective

- Make the code pass correctly on all tests
   * only change the allowed files to achieve this goal (see instructions below with specific rules).


- The GitHub Actions should present a green marker when all tests are satisfied, and a red X when some (or all) of tests fail. 
    * **Advice 1:** You can click on the red X to verify which tests have failed (or if code didn't compile correctly) via Github repository Actions.
    * **Advice 2:** If no autograding test appear, contact instructor.

## Instructions

- complete the helper_functions.cpp and use main.cpp for interactive testing
   * if you want to complile manually via terminal, try this command to generate main executable
    g++ --std=c++17 helper_functions.cpp main.cpp -o main
   * Watchout the difference between windows, macOS or linux environment; GitHub codespaces is under linux environment
   * Review tasks.json file for g++ executable location and output executable file name extension.  windows has .exe file extension.
- You should change files `student.hpp` and `README.md`!
   * In file `student.hpp` put your implementations, and in `README.md` put your full name.
- enhance file `tests.cpp` has all tests for the required activity (PLEASE ADD YOUR OWN TES CASES)
- Once you are confident on the logic, porting to student.hpp and validate in the terminal using make command
> make

- You can add other c++ header and source files and ensure you reference them in the student.hpp and added in the compilation path of the makefile; make sure you add them and check into Github repository

Explanations for the test framework files:


- file `catch_amalgamated.cpp` and `catch_amalgamated.hpp` has the testing library CATCH2 v3 (DO NOT CHANGE!)
- file `makefile` has the commands for executing activity (DO NOT CHANGE!)
- file  `appTests` will be generated after compiling (if you want to test locally, just execute it; watch out the difference between Windows, Mac, and Lunux)

## Commands for Local Testing via Terminal

- Command to build and execute tests: `make test`
    * If executable is built already, just type: `./appTests`

## Notes

- The code will be evaluated only if compiling! 
   * The reason is, if it doesn't compile, it won't be possible to generate the executable and to perform tests.

- Some test cases may receive individual grade, while others may only receive grade if passing together (or even all tests passing together).

- The final grade will be given automatically on every *commit*, and will only be evaluated until the deadline of the activity.

- The deadline is defined in GitHub Classroom
   * in case you cannot find it, ask the instructor or the course webpage

ask question and check all other rules with instructor.

Reference:

*Learning Autograding with C/C++ and Catch2 - Prof. Igor Machado Coelho*

## License

MIT License 2020

#include "candy/core/CandySolverInterface.h"
#include "candy/core/CNFProblem.h"

#include "candy/frontend/CandyBuilder.h"

using namespace Candy;

int main(int argc, char **argv) {
    // Parse params for candy solver
    parseOptions(argc, argv, true);

    CNFProblem problem{};

    std::cout << "Reading Problem File: " << argv[1] << std::endl;
    const char *problemFileName = argv[1];
    problem.readDimacsFromFile(problemFileName);

    //Create solver
    CandySolverInterface *solver = createSolver();
    solver->init(problem);

    std::cout << "Adding assumption Cl { Lit(1836, 0), Lit(1938, 1), Lit(425, 1), Lit(556, 1), Lit(660, 1) }\n" << std::endl;
    std::vector<Lit> assumption = Cl { Lit(1836, 0), Lit(1938, 1), Lit(425, 1), Lit(556, 1), Lit(660, 1) };

    solver->getAssignment().setAssumptions(assumption);

    lbool result = solver->solve();

    std::cout << "Adding assumption Cl { Lit(1836, 0), Lit(1938, 1), Lit(425, 1), Lit(556, 1), Lit(660, 0) }\n" << std::endl;
    assumption = Cl { Lit(1836, 0), Lit(1938, 1), Lit(425, 1), Lit(556, 1), Lit(660, 0) };

    solver->getAssignment().setAssumptions(assumption);

    result = solver->solve();

    printf(result == l_True ? "s SATISFIABLE\n" : result == l_False ? "s UNSATISFIABLE\n" : "s INDETERMINATE\n");

    return 0;
}

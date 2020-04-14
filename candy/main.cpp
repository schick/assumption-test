#include "candy/core/CandySolverInterface.h"
#include "candy/core/CNFProblem.h"

#include "candy/frontend/CandyBuilder.h"

using namespace Candy;

int main(int argc, char **argv) {
    CNFProblem problem{};

    std::cout << "Reading Problem File: " << argv[1] << std::endl;
    const char *problemFileName = argv[1];
    problem.readDimacsFromFile(problemFileName);

    //Create solver
    CandySolverInterface *solver = createSolver();
    solver->init(problem);

    std::cout << "Adding assumption Cl { 1837_L, ~1939_L, ~426_L, ~557_L, ~661_L }" << std::endl;
    Cl assumptions1 = { 1837_L, ~1939_L, ~426_L, ~557_L, ~661_L };

    solver->getAssignment().setAssumptions(assumptions1);

    lbool result = solver->solve();

    // Mimic behavior in ipasircandy.cc
    // Leads to assertion error in ConflictAnalysis::analyze
    problem.clear();
    solver->init(problem);

    std::cout << "Adding assumption Cl { 1837_L, ~1939_L, ~426_L, ~557_L, 661_L }" << std::endl;
    Cl assumptions2 = { 1837_L, ~1939_L, ~426_L, ~557_L, 661_L };
    solver->getAssignment().setAssumptions(assumptions2);

    result = solver->solve();

    printf(result == l_True ? "s SATISFIABLE\n" : result == l_False ? "s UNSATISFIABLE\n" : "s INDETERMINATE\n");

    delete solver;

    return 0;
}

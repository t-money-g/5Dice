// ==========================================================================
//
// Your license here.
//
// ==========================================================================

// Macro to determine whether to run tests or skip the runner
#define TESTS_ENABLED 1
#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>
#include <iostream>
#include "empty.h"


int main(int argc, char* argv[])
{
#if  TESTS_ENABLED == 1
    int result = Catch::Session().run(argc, argv);
#endif

    std::cout << "Good day!" << std::endl;

#if TESTS_ENABLED == 1
    return result;
#else
    return 0;
#endif

}


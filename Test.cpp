#include "doctest.h"
#include "solver.hpp"
#include <string>

using namespace solver;


TEST_CASE("test"){

    for(size_t i = 0; i <= 100; i++){
        CHECK(i == i);
    }
}
#include <catch2/catch_test_macros.hpp>

#include "graph.h"
#include "stronglyconnected.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

Graph graph1(1, 1, "mercator🤠.png");
StronglyConnected ssc(graph1);

TEST_CASE("SSC directConnect returns a vector of nodes directly connected to the source", "[weight=1][ssc][9]")
{
    ssc.tarjan();
}
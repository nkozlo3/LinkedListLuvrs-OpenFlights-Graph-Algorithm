// #include <catch2/catch_test_macros.hpp>

// #include "graph.h"
// #include "stronglyconnected.h"
// #include <iostream>
// #include <algorithm>
// #include <cctype>
// #include <string>

// Graph graph1(1, 1, "mercator🤠.png");
// StronglyConnected ssc(graph1);

// TEST_CASE("SSC directConnect returns a vector of nodes directly connected to the source", "[weight=1][ssc][9]")
// {
//     ssc.tarjan();
//     std::vector<std::vector<Graph::airport>> vv = ssc.getConnectedComponents();
//     Graph::airport initialNode = vv.at(0).at(0);
//     std::string initialConnection = vv.at(0).at(0).airportCode;
//     std::vector<Graph::airport> vvAtZeroZero = ssc.getGraph().getAdjacentNodes(initialConnection);
//     std::vector<Graph::airport> nodesThatShouldExistZeroZero;
//     for (auto it : vvAtZeroZero)
//     {
//         std::vector<Graph::airport> curAdjNodes = ssc.getGraph().getAdjacentNodes(it.airportCode);
//         // check if initialNode is in curAdjNodes
//         if (std::find(curAdjNodes.begin(), curAdjNodes.end(), initialNode) != curAdjNodes.end())
//         {
//             nodesThatShouldExistZeroZero.push_back(it);
//         }
//     }
//     // require that every node in nodesThatShouldExistZeroZero is in vvAtZeroZero
//     for (auto it : nodesThatShouldExistZeroZero)
//     {
//         REQUIRE(std::find(vvAtZeroZero.begin(), vvAtZeroZero.end(), it) != vvAtZeroZero.end());
//     }
// }
add_test( [==[Dijkstra's returns a correct shortes path]==] /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build/test [==[Dijkstra's returns a correct shortes path]==]  )
set_tests_properties( [==[Dijkstra's returns a correct shortes path]==] PROPERTIES WORKING_DIRECTORY /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build)
add_test( [==[get adjacentMap does not return an empty list where it should and vice versa]==] /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build/test [==[get adjacentMap does not return an empty list where it should and vice versa]==]  )
set_tests_properties( [==[get adjacentMap does not return an empty list where it should and vice versa]==] PROPERTIES WORKING_DIRECTORY /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build)
add_test( [==[Graph csvToVect returns a vector of the right width and length]==] /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build/test [==[Graph csvToVect returns a vector of the right width and length]==]  )
set_tests_properties( [==[Graph csvToVect returns a vector of the right width and length]==] PROPERTIES WORKING_DIRECTORY /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build)
add_test( [==[Graph csvToVect properly maps vectors]==] /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build/test [==[Graph csvToVect properly maps vectors]==]  )
set_tests_properties( [==[Graph csvToVect properly maps vectors]==] PROPERTIES WORKING_DIRECTORY /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build)
add_test( [==[Graph csvToVect properly maps vectors and only takes in the specified columns]==] /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build/test [==[Graph csvToVect properly maps vectors and only takes in the specified columns]==]  )
set_tests_properties( [==[Graph csvToVect properly maps vectors and only takes in the specified columns]==] PROPERTIES WORKING_DIRECTORY /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build)
add_test( [==[Graph numberNormalized normalizes the numbers properly]==] /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build/test [==[Graph numberNormalized normalizes the numbers properly]==]  )
set_tests_properties( [==[Graph numberNormalized normalizes the numbers properly]==] PROPERTIES WORKING_DIRECTORY /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build)
add_test( [==[Graph sourceToDestLongLat outputs correct data]==] /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build/test [==[Graph sourceToDestLongLat outputs correct data]==]  )
set_tests_properties( [==[Graph sourceToDestLongLat outputs correct data]==] PROPERTIES WORKING_DIRECTORY /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build)
add_test( [==[Graph codeToPosition contains longitudes and latitudes]==] /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build/test [==[Graph codeToPosition contains longitudes and latitudes]==]  )
set_tests_properties( [==[Graph codeToPosition contains longitudes and latitudes]==] PROPERTIES WORKING_DIRECTORY /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build)
add_test( [==[Graph constructor populates adjacency_matrix_ properly]==] /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build/test [==[Graph constructor populates adjacency_matrix_ properly]==]  )
set_tests_properties( [==[Graph constructor populates adjacency_matrix_ properly]==] PROPERTIES WORKING_DIRECTORY /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build)
add_test( [==[Graph constructor populates node_positions_ properly]==] /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build/test [==[Graph constructor populates node_positions_ properly]==]  )
set_tests_properties( [==[Graph constructor populates node_positions_ properly]==] PROPERTIES WORKING_DIRECTORY /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build)
add_test( [==[Graph getAdjacencyListEdge gets the correct edges]==] /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build/test [==[Graph getAdjacencyListEdge gets the correct edges]==]  )
set_tests_properties( [==[Graph getAdjacencyListEdge gets the correct edges]==] PROPERTIES WORKING_DIRECTORY /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build)
add_test( [==[Graph getEdges gets the correct edges and therefore populates airports_ properly]==] /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build/test [==[Graph getEdges gets the correct edges and therefore populates airports_ properly]==]  )
set_tests_properties( [==[Graph getEdges gets the correct edges and therefore populates airports_ properly]==] PROPERTIES WORKING_DIRECTORY /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build)
add_test( [==[Graph getEdges gets the correct edges]==] /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build/test [==[Graph getEdges gets the correct edges]==]  )
set_tests_properties( [==[Graph getEdges gets the correct edges]==] PROPERTIES WORKING_DIRECTORY /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build)
add_test( [==[Graph getAdjacentNodes works properly]==] /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build/test [==[Graph getAdjacentNodes works properly]==]  )
set_tests_properties( [==[Graph getAdjacentNodes works properly]==] PROPERTIES WORKING_DIRECTORY /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build)
add_test( [==[Graph populates airport_map_ properly]==] /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build/test [==[Graph populates airport_map_ properly]==]  )
set_tests_properties( [==[Graph populates airport_map_ properly]==] PROPERTIES WORKING_DIRECTORY /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build)
add_test( [==[SSC directConnect returns a vector of nodes directly connected to the source]==] /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build/test [==[SSC directConnect returns a vector of nodes directly connected to the source]==]  )
set_tests_properties( [==[SSC directConnect returns a vector of nodes directly connected to the source]==] PROPERTIES WORKING_DIRECTORY /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build)
set( test_TESTS [==[Dijkstra's returns a correct shortes path]==] [==[get adjacentMap does not return an empty list where it should and vice versa]==] [==[Graph csvToVect returns a vector of the right width and length]==] [==[Graph csvToVect properly maps vectors]==] [==[Graph csvToVect properly maps vectors and only takes in the specified columns]==] [==[Graph numberNormalized normalizes the numbers properly]==] [==[Graph sourceToDestLongLat outputs correct data]==] [==[Graph codeToPosition contains longitudes and latitudes]==] [==[Graph constructor populates adjacency_matrix_ properly]==] [==[Graph constructor populates node_positions_ properly]==] [==[Graph getAdjacencyListEdge gets the correct edges]==] [==[Graph getEdges gets the correct edges and therefore populates airports_ properly]==] [==[Graph getEdges gets the correct edges]==] [==[Graph getAdjacentNodes works properly]==] [==[Graph populates airport_map_ properly]==] [==[SSC directConnect returns a vector of nodes directly connected to the source]==])

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
add_test( [==[Graph constructor initializes adjacency_list properly]==] /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build/test [==[Graph constructor initializes adjacency_list properly]==]  )
set_tests_properties( [==[Graph constructor initializes adjacency_list properly]==] PROPERTIES WORKING_DIRECTORY /workspaces/LinkedListLuvrs-OpenFlights-Graph-Algorithm/build)
set( test_TESTS [==[Graph csvToVect returns a vector of the right width and length]==] [==[Graph csvToVect properly maps vectors]==] [==[Graph csvToVect properly maps vectors and only takes in the specified columns]==] [==[Graph numberNormalized normalizes the numbers properly]==] [==[Graph sourceToDestLongLat outputs correct data]==] [==[Graph codeToPosition contains longitudes and latitudes]==] [==[Graph constructor initializes adjacency_list properly]==])

# Written Report

## Leading Question: How can we find the shortest path between two airports?  

 To answer this question, we first parsed through our datasets (airports.csv and routes.csv) and created a graph to store this data. Our graph consisted of the airport source code, destination code, and latitude and longitude. Then, we implemented Dijkstra’s Algorithm to find the shortest path between two airports. We also used DFS to output the result of all visited airports in order. Through this project, we discovered that when traveling from one airport to another, there is almost always a path with the help of a connecting airport. 

 Our algorithm to find strongly connected components ultimately did not come together in time, but we were close to finishing and hit some pitfalls in our process that could have been solved earlier. Our team cohesion was very good and all members were proactive and attentive in all of our meetings, however our problem with nothing being able to compile in the last week halted our process. While there is not much of anything we would have changed, we could have reached out to our mentor sooner, who was able to fix the problem in a timely manner. Up until the final week, development of our OpenFlights algorithm was going smoothly. Everyone adhered to the team contract we had laid out at the beginning of the project as well.

## Dijkstras
 **Purpose**
 Run Dijkstra’s algorithm on our graph to find the shortest path between two airports.
 
 **Implementation**
 The Dijkstra’s function takes in two airport codes as strings, a start and destination airport. It first checks if the two are directly connected already, which in that case it returns the two airports in order in a vector.
 
 We store the minimum distances to get to the starting airport from each node in an unordered map, mapping an airport to a distance. Another unordered map keeps track of predecessors, to keep track of each airport we encounter. A vector of strings called visited is used to maintain visited airports to ensure an airport is not visited an unnecessary amount of times.
 
 Each distance in the distance vector is initialized to infinity, and predecessors to empty strings. Mark the distance of the start vertex to itself as zero.
 
 Initialize a priority queue and push the start vertex. While the queue is not empty, set a string current to the top of the queue, and pop. The node that is currently being explored is marked as "visited" by adding it to the visited vector. From there, we get the adjacent airports of current, and compare each one’s distance (weights of the edges), updating the shortest path for each neighboring node if it finds a shorter path than the current one. As we explore each new node through iterations of the while loop, we continue to update the length of the shortest path accordingly. At the end, we backtrack to add each node encountered to the final path, and then return that path as a vector of strings. If the path vector is empty, that indicates that no path between those two airports exists.
 
 This function uses various helper functions along the way, to do tasks such as check if two nodes are connected, get the vertices of the graph, or get adjacent nodes.
 
 Test cases were utilized to ensure the correctness of the algorithm. Edge cases such as directly connected airports were tested, as well as general cases of two randomly selected airports. To ensure that the path returned was the correct one, I went through the csv, writing down the source, destination, and their other connecting airports. I then checked to make sure the airports returned by Dijkstra’s were all included in each other’s adjacency lists, and listed as connections in the csv. For a couple test cases I also drew out the actual graph and edge weights by hand to ensure this, however this could not be done with every test since many of the airports in our dataset have hundreds of connections.

 **Output**
 A vector of strings representing the shortest path one can travel between two airports, where the first string is our starting airport and the last is the destination.

## Strongly Connected Components
 **Purpose**
 Run SCC to populate a vector of vector of airport structs to find the number of strongly connected components. In this context, a strongly connected component of our graph is a set of airports that have flights to and from each one.

 **Implementation**
 The SCC class has 6 functions. 3 of the functions are getters for vertices, the graph, and the connected components themselves. We also have a constructor at the top of the file that configures the index, the graph, and the vertices. Then we have a function that utilizes the tarjan algorithm and calls direct connect within it. Tarjan populates the set of vertices and then checks how many connected components there are by calling direct connect. 
 
 In directConnect, we first set the current vertex to be marked visited on the stack and make the vertex’s index and lowLink to be set to the current index. Then after setting the airport  and getting the adjacent nodes, we consider the successors of the vertex using a for loop. Next, in a series of 3 if statements we check if the vertex successor has not been visited yet. Within that if statement we recurse on the vertex successor and get the new lowlink value. Then we check if the vertex successor is on the stack. If it is then we populate the lowlink. This also means the vertex successor is already in the SCC. Finally the last if statement takes the vertex as the root node and slowly generates the scc through a do while loop. 
 
 Based on Tarjan’s algorithm, it is meant to use a Depth First Search and scan the entire directed graph. Our code does not work because of the stack emptying prematurely. Our code uses a stack to keep track of the individual nodes and uses a recursive system to populate the stack. It is meant to hold nodes that have the possibility of being connected to previously visited nodes, but instead the whole stack empties. In line 67, the stack pops and it is meant to do this while populating the connected components. However, we believe it is because the stack empties so soon that we get a segmentation fault. 
 
 There were some tests cases written out, an originally we would have had more time to fix this algorithm, but due to other finals and our makefile not working for a week we were did not have sufficient time to fix the problem.
 
 **Output**
 n/a

## DFS
 **Purpose** 
 Run DFS to output the order in which all airports are visited through the graph.
 
 **Implementation**
 The DFS class has 4 functions: one that runs DFS, a helper function that gets called within the main DFS function, a function that writes the DFS path into a file, and one that returns the vector with visited airports. The helper function takes a parameter of the starting airport as it will traverse through that airport and that airport’s destination airport.
 
 The DFS functions iterates through a starting airport in the graph, then visits their destination airport and continues to traverse in this manner through all airports. We also wrote our DFS flight path into a file to check if the output was correct. To test if our DFS was correct, we checked the size of all visited airports to the size of the airports in our graph. We also made tests to ensure that the starting and ending airports were correct. 
 
 **Output**
 A vector and file with the output of all visited airports using the depth first search algorithm. 

## Graph
 **Purpose**
 To store information from our datasets in easily accessible data structures and to create a visualization of the information in our datasets. 

 **Implementation**
 The Graph class has 6 main functions and many helper functions. The function populateAdjacencyMatrix populates an unordered_map that maps strings (source airports) to unordered_maps, which in turn maps strings (destination airports) to structs of pairs of airports. These structs contain information about the airports such as longitude and latitude points, airport codes, etc. The codeToPosition function outputs a map that maps a string (airport) to its longitude and latitude points. This function was helpful for mapping the airports on our mercator projection. The populatePixelPoints function maps strings (airport codes) to the normalized pixel points (the spots on our mercator projection that map up with the longitude and latitude in a map of the world). The populateAirports function populates a vector of structs of airports. These structs are similar to the pairs of airports structs but with information pertaining to a single airport and functionality for our strongly connected components class. The drawGraphOnPNG function draws the airports and edges between airports on a mercator projection of the world. Finally, the ouputAdjacanceMatrix function outputs the airports into a .txt file. We have a large number of tests for the Graph class, with multiple tests for each function and over 5000 assertions.
 
 Essentially, the Graph class stores data from our csv files in data structures to make it easily accessible and graphs the information from the csv files onto a mercator projection of the map. 
 
 **Output**
 Data structures containing the airports and information about the routes between airports. Also outputs a map of the world with the airports and routes between airports graphed on it. 
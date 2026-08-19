PRIM'S ALGORITHM TEST CASES

Files:
- prims_10_vertices.txt
- prims_100_vertices.txt
- prims_10000_vertices.txt
- prims_50000_vertices.txt
- prims_100000_vertices.txt

Input format:
First line  = number of vertices (v)
Second line = number of UNIQUE undirected edges (e)
Next v lines = vertex, degree, then destination/weight pairs.

The graph is undirected, so every edge is stored in both directions.
The generated graph contains:
  i -- i+1 with weight 1
  i -- i+2 with weight 2
  i -- i+5 with weight 3

Therefore every graph is connected and the MST is the chain
0-1-2-...-(v-1), with expected MST cost v-1.

Expected MST costs:
10 vertices     -> 9
100 vertices    -> 99
10000 vertices  -> 9999
50000 vertices  -> 49999
100000 vertices -> 99999

# Assignment Results

## 9.1 GEMM Results Table

| Test File        | Input Type / Size      | Expected Output | Actual Output | Simple Time  | Blocking Time  | Block Size | Status |
|------------------|------------------------|-----------------|---------------|--------------|----------------|------------|--------|
| test_01.txt      | M=4, K=4, N=4          | Result Matrix   | Result Matrix | 0.003 ms     | 0.004 ms       |            | Pass   |
| test_02.txt      | M=4, K=5, N=4          | Result Matrix   | Result Matrix | 0.005 ms     | 0.005 ms       |            | Pass   |
| test_03.txt      | M=5, K=5, N=5          | Result Matrix   | Result Matrix | 0.006ms      | 0.009 ms       |            | Pass   |
| test_04.txt      | M=10, K=10, N=10       | Result Matrix   | Result Matrix | 0.026 ms     | 0.035 ms       |            | Pass   |
| test_05.txt      | M=100, K=100, N=100    | Result Matrix   | Result Matrix | 18.933 ms    | 16.146 ms      |            | Pass   |
| test_06.txt      | M=250, K=250, N=250    | Result Matrix   | Result Matrix | 265.983ms    | 251.045 ms     |            | Pass   |
| test_07.txt      | M=500, K=500, N=500    | Result Matrix   | Result Matrix | 2191.57 ms   | 2060.67 ms     |            | Pass   |
| test_08.txt      | M=1000, K=1000, N=1000 | Result Matrix   | Result Matrix | 18120.3 ms   | 16574.2 ms     |            | Pass   |
| test_09.txt      | M=1500, K=1500, N=1500 | Result Matrix   | Result Matrix | 66065.2 ms   | 54511.2 ms     |            | Pass   |
| test_10.txt      | M=2000, K=2000, N=2000 | Result Matrix   | Result Matrix | 162446 ms    | 129519 ms      |            | Pass   |


---

## 9.2 Graph Results Table

| Algorithm | Test File | Vertices | Edges | Input Type | Source | Expected Output | Actual Output | Time | Status |
|-----------|-----------|----------|-------|------------|--------|-----------------|---------------|------|--------|
| BFS | bfs_10.txt | 10 | 15 | Unweighted | 0 | Traversal | Correct | 0.05 ms | Pass |
| DFS | dfs_10.txt | 10 | 15 | Unweighted | 0 | Traversal | Correct | 0.04 ms | Pass |
| SSSP | sssp_10.txt | 10 | 15 | Positive Weighted | 0 | Shortest Distances | Correct | 0.12 ms | Pass |

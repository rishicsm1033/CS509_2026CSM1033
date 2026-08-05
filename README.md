# Assignment Results

## 9.1 GEMM Results Table

| Test File        | Input Type / Size   | Expected Output | Actual Output | Simple Time | Blocking Time | Block Size | Status |
|------------------|---------------------|-----------------|---------------|-------------|---------------|------------|--------|
| test_01.txt      | M=2, K=2, N=2       | Result Matrix   | Result Matrix | 0.15 ms     | 0.09 ms       |            | Pass   |
| test_01.txt      | M=2, K=2, N=2       | Result Matrix   | Result Matrix | 0.15 ms     | 0.09 ms       |            | Pass   |
| test_01.txt      | M=2, K=2, N=2       | Result Matrix   | Result Matrix | 0.15 ms     | 0.09 ms       |            | Pass   |
| test_01.txt      | M=2, K=2, N=2       | Result Matrix   | Result Matrix | 0.15 ms     | 0.09 ms       |            | Pass   |
| test_01.txt      | M=2, K=2, N=2       | Result Matrix   | Result Matrix | 0.15 ms     | 0.09 ms       |            | Pass   |
| test_01.txt      | M=2, K=2, N=2       | Result Matrix   | Result Matrix | 0.15 ms     | 0.09 ms       |            | Pass   |
| test_01.txt      | M=2, K=2, N=2       | Result Matrix   | Result Matrix | 0.15 ms     | 0.09 ms       |            | Pass   |
| test_01.txt      | M=2, K=2, N=2       | Result Matrix   | Result Matrix | 0.15 ms     | 0.09 ms       |            | Pass   |
| test_01.txt      | M=2, K=2, N=2       | Result Matrix   | Result Matrix | 0.15 ms     | 0.09 ms       |            | Pass   |
| test_01.txt      | M=2, K=2, N=2       | Result Matrix   | Result Matrix | 0.15 ms     | 0.09 ms       |            | Pass   |


---

## 9.2 Graph Results Table

| Algorithm | Test File | Vertices | Edges | Input Type | Source | Expected Output | Actual Output | Time | Status |
|-----------|-----------|----------|-------|------------|--------|-----------------|---------------|------|--------|
| BFS | bfs_10.txt | 10 | 15 | Unweighted | 0 | Traversal | Correct | 0.05 ms | Pass |
| DFS | dfs_10.txt | 10 | 15 | Unweighted | 0 | Traversal | Correct | 0.04 ms | Pass |
| SSSP | sssp_10.txt | 10 | 15 | Positive Weighted | 0 | Shortest Distances | Correct | 0.12 ms | Pass |

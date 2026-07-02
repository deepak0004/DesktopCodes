# Algorithms & Data Structures

A curated reference collection of algorithm and data-structure implementations in
C and C++, written for competitive programming and interview practice.

Organized by topic. Each file is a self-contained implementation.

## Graphs
| File | Description | Complexity |
|------|-------------|------------|
| `graphs/breadth_first_search.cpp` | BFS traversal of a graph | O(V + E) |
| `graphs/depth_first_search.cpp` | DFS traversal | O(V + E) |
| `graphs/dijkstra_shortest_path.cpp` | Single-source shortest path, non-negative weights (priority queue) | O((V + E) log V) |
| `graphs/bellman_ford_shortest_path.cpp` | Shortest path with negative edges + negative-cycle detection | O(V · E) |
| `graphs/topological_sort_dfs.cpp` | Topological order of a DAG via DFS | O(V + E) |
| `graphs/topological_sort_kahn.cpp` | Lexicographic topological order via Kahn's algorithm | O((V + E) log V) |
| `graphs/disjoint_set_union.cpp` | Union-Find with path compression and union by rank | ~O(α(N)) per op |
| `graphs/lowest_common_ancestor.cpp` | LCA via binary lifting | O(N log N) build, O(log N) query |
| `graphs/cycle_detection.cpp` | Detect a cycle in a graph via DFS | O(V + E) |
| `graphs/bipartite_check.cpp` | Bipartiteness / 2-coloring via DFS | O(V + E) |
| `graphs/minimum_spanning_tree.c` | Kruskal's MST (edge sort + DSU) | O(E log E) |
| `graphs/maximum_bipartite_matching.cpp` | Maximum bipartite matching (Kuhn's augmenting paths) | O(V · E) |
| `graphs/centroid_decomposition.cpp` | Centroid decomposition of a tree | O(N log N) |

## Trees & Heaps
| File | Description | Complexity |
|------|-------------|------------|
| `trees_and_heaps/segment_tree.cpp` | Range query / point update segment tree | O(log N) per op |
| `trees_and_heaps/persistent_segment_tree.cpp` | Versioned (persistent) segment tree | O(log N) per op |
| `trees_and_heaps/trie.cpp` | Prefix tree for strings | O(L) per op |
| `trees_and_heaps/binary_heap.cpp` | Binary heap (insert / extract) | O(log N) |
| `trees_and_heaps/avl_tree.cpp` | Self-balancing BST with rotations | O(log N) |

## Dynamic Programming
| File | Description | Complexity |
|------|-------------|------------|
| `dynamic_programming/knapsack_01.cpp` | 0/1 knapsack | O(N · W) |
| `dynamic_programming/longest_increasing_subsequence.cpp` | Longest increasing subsequence | O(N log N) |
| `dynamic_programming/count_ways_to_climb_stairs.cpp` | Count ways to climb stairs (Fibonacci-style DP) | O(N) |

## Math
| File | Description | Complexity |
|------|-------------|------------|
| `math/sieve_of_eratosthenes.cpp` | Prime sieve | O(N log log N) |
| `math/modular_inverse_factorials.cpp` | Precomputed factorials + modular inverses for nCr mod p | O(N) build |
| `math/matrix_exponentiation.cpp` | Fast matrix power for linear recurrences | O(K³ log N) |

## Searching
| File | Description | Complexity |
|------|-------------|------------|
| `searching/binary_search_on_answer.cpp` | Binary search on the answer (predicate + threshold) | O(N log(range)) |
| `searching/ternary_search.cpp` | Unimodal optimization (ternary / golden-section style search) | O(N log(range)) |

## Strings
| File | Description | Complexity |
|------|-------------|------------|
| `strings/longest_palindromic_subsequence.cpp` | Longest palindromic subsequence via DP | O(N²) |

## Geometry
| File | Description | Complexity |
|------|-------------|------------|
| `geometry/point_in_polygon.cpp` | Point-in-polygon test via ray casting | O(N) per query |

## Sorting
| File | Description | Complexity |
|------|-------------|------------|
| `sorting/merge_sort.c` | Merge sort | O(N log N) |
| `sorting/quick_sort.c` | Quick sort | O(N log N) average |
| `sorting/heap_sort.c` | Heap sort | O(N log N) |

## Data Structures
| File | Description | Complexity |
|------|-------------|------------|
| `data_structures/stack.c` | Array-based stack | O(1) push/pop |
| `data_structures/queue.c` | Array-based queue | O(1) enqueue/dequeue |
| `data_structures/hash_table_linear_probing.c` | Hash table with linear probing | O(1) average |
| `data_structures/linked_list_merge_sort.cpp` | Merge sort on a linked list | O(N log N) |

## Building
```bash
g++ -std=c++17 -O2 graphs/dijkstra_shortest_path.cpp -o dijkstra   # C++ files
gcc -O2 sorting/merge_sort.c -o merge_sort                          # C files
```

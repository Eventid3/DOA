# DOA NOTES

Noter til faget Algoritmer og Datastrukturer, 3. Semester, Aarhus Universitet.
Herunder er de vigtigste informationer om forskellige datastrukturer, tree strukturer, sorteringsalgoritmer, graph seach osv. nævnt. I mappen 'LectureCode' findes alt kode fra forelæsningerne. Under 'TidligereEksamener' ligger kode fra de tidligere eksamenssæt. Alle slides fra lektionerne er også samlet (tak Mads V!).

Brug dette repo med omtanke. Der tages forbehold for eventuelle fejl og mangler der måtte være. 

### Overview of Different Types of Big O Complexities

Big O notation is used to describe the performance or complexity of an algorithm. It provides an upper bound on the time or space requirements in terms of the size of the input. Here are common Big O complexities, along with examples in C/C++:

### Constant Time: O(1)
- **Description:** The algorithm takes a constant amount of time regardless of the input size.
- **Example:** Accessing an array element by index.

```cpp
int getElement(int arr[], int index) {
    return arr[index]; // O(1)
}
```

### Logarithmic Time: O(log n)
- **Description:** The algorithm's time complexity grows logarithmically with the input size. Common in divide-and-conquer algorithms.
- **Example:** Binary search.

```cpp
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid; // O(log n)
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
```

### Linear Time: O(n)
- **Description:** The algorithm's time complexity grows linearly with the input size.
- **Example:** Linear search.

```cpp
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return i; // O(n)
    }
    return -1;
}
```

### Linearithmic Time: O(n log n)
- **Description:** The algorithm's time complexity grows at a rate of \(n \log n\). Common in efficient sorting algorithms.
- **Example:** Merge sort.

```cpp
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
```

### Quadratic Time: O(n^2)
- **Description:** The algorithm's time complexity grows quadratically with the input size. Common in algorithms with nested loops.
- **Example:** Bubble sort.

```cpp
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {         // Outer loop: O(n)
        for (int j = 0; j < size - i - 1; j++) { // Inner loop: O(n)
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```

### Cubic Time: O(n^3)
- **Description:** The algorithm's time complexity grows cubically with the input size. Common in algorithms with three nested loops.
- **Example:** Checking all triplets in an array.

```cpp
void checkTriplets(int arr[], int size) {
    for (int i = 0; i < size; i++) {           // Outer loop: O(n)
        for (int j = i + 1; j < size; j++) {   // Middle loop: O(n)
            for (int k = j + 1; k < size; k++) { // Inner loop: O(n)
                if (arr[i] + arr[j] + arr[k] == 0) {
                    std::cout << "Triplet found: " << arr[i] << ", " << arr[j] << ", " << arr[k] << std::endl;
                }
            }
        }
    }
}
```

### Exponential Time: O(2^n)
- **Description:** The algorithm's time complexity doubles with each additional input element. Common in recursive algorithms solving combinatorial problems.
- **Example:** Recursive calculation of Fibonacci numbers.

```cpp
int fibonacci(int n) {
    if (n <= 1) return n; // Base cases
    return fibonacci(n - 1) + fibonacci(n - 2); // O(2^n)
}
```

### Factorial Time: O(n!)
- **Description:** The algorithm's time complexity grows factorially with the input size. Common in algorithms generating permutations.
- **Example:** Generating all permutations of a string.

```cpp
void permute(std::string str, int left, int right) {
    if (left == right) std::cout << str << std::endl; // Base case
    else {
        for (int i = left; i <= right; i++) {
            std::swap(str[left], str[i]);
            permute(str, left + 1, right); // O(n!)
            std::swap(str[left], str[i]);  // Backtrack
        }
    }
}

void generatePermutations(std::string str) {
    permute(str, 0, str.length() - 1);
}
```

### Examples with Dependent Inner Loops
- **Quadratic Time (Dependent Inner Loop):**
  - Example: Printing pairs of elements.

Certainly! Let's perform a detailed Big O analysis of the provided code:

```cpp
void printPairs(int arr[], int size) {
    for (int i = 0; i < size; i++) {            // Outer loop: O(n)
        for (int j = i + 1; j < size; j++) {    // Inner loop depends on i: O(n - i - 1)
            std::cout << "(" << arr[i] << ", " << arr[j] << ")" << std::endl;
        }
    }
}
```

1. **Outer Loop:**
   - The outer loop runs from `i = 0` to `i < size`.
   - This means the outer loop executes `size` times.
   - **Time Complexity of Outer Loop:** \(O(n)\)

2. **Inner Loop:**
   - The inner loop runs from `j = i + 1` to `j < size`.
   - For each value of `i`, the inner loop executes `size - (i + 1)` times.
   - When `i = 0`, the inner loop runs `n - 1` times.
   - When `i = 1`, the inner loop runs `n - 2` times.
   - This pattern continues until `i = n - 1`, where the inner loop runs `0` times.
   - **Time Complexity of Inner Loop for each `i`:** \(O(n - i - 1)\)

3. **Total Time Complexity:**
   - To find the total time complexity, we sum the number of iterations of the inner loop for all values of `i`.
   - Total iterations:
     \[
     (n - 1) + (n - 2) + (n - 3) + \cdots + 2 + 1 + 0
     \]
   - This is an arithmetic series sum of the first `n` numbers minus the first element (which is `n`).
   - The sum of the first `n` natural numbers is:
     \[
     \frac{(n)(n - 1)}{2}
     \]
   - Simplifying this sum gives:
     \[
     \frac{n^2 - n}{2}
     \]
   - Therefore, the total time complexity is \(O(n^2)\).

#### Summary:

- **Outer Loop:** \(O(n)\)
- **Inner Loop:** The inner loop runs approximately \(\frac{n^2 - n}{2}\) times in total.
- **Total Time Complexity:** \(O(n^2)\)

#### Space Complexity:

- The space complexity is \(O(1)\) since the algorithm uses a constant amount of extra space, regardless of the input size.

**Conclusion:** The provided code has a time complexity of \(O(n^2)\) and a space complexity of \(O(1)\). This quadratic time complexity is due to the nested loops, where the inner loop depends on the index of the outer loop.

### Summary

- **Constant Time (O(1)):** Time complexity does not change with input size. Example: Accessing an array element.
- **Logarithmic Time (O(log n)):** Time complexity grows logarithmically. Example: Binary search.
- **Linear Time (O(n)):** Time complexity grows linearly. Example: Linear search.
- **Linearithmic Time (O(n log n)):** Time complexity grows at a rate of \(n \log n\). Example: Merge sort.
- **Quadratic Time (O(n^2)):** Time complexity grows quadratically. Example: Bubble sort.
- **Cubic Time (O(n^3)):** Time complexity grows cubically. Example: Triplet checking.
- **Exponential Time (O(2^n)):** Time complexity doubles with each additional input element. Example: Fibonacci sequence.
- **Factorial Time (O(n!)):** Time complexity grows factorially. Example: Generating permutations.

## DATA TYPES

### 1. Linked Lists
- **Singly Linked List:**
  - **Structure:** Each node contains data and a reference (link) to the next node.
  - **Operations:**
    - **Insertion:** \(O(1)\) if inserting at the head, \(O(n)\) if inserting at the tail or a specific position.
    - **Deletion:** \(O(1)\) if deleting the head, \(O(n)\) for deleting a specific node.
    - **Traversal/Search:** \(O(n)\) to access or search for an element.
  - **Advantages:** Dynamic size, efficient insertions/deletions.
  - **Disadvantages:** No direct access to elements, additional memory for storing pointers, inefficient search.

- **Doubly Linked List:**
  - **Structure:** Each node contains data, a reference to the next node, and a reference to the previous node.
  - **Operations:**
    - **Insertion/Deletion:** \(O(1)\) if pointers are known.
    - **Traversal/Search:** \(O(n)\) to access or search for an element.
  - **Advantages:** Can be traversed in both directions, more flexible node operations.
  - **Disadvantages:** More memory usage due to extra pointer, slightly more complex implementation.

### 2. Queues
- **Structure:** Linear data structure following the First-In-First-Out (FIFO) principle.
- **Operations:**
  - **Enqueue (insert):** \(O(1)\)
  - **Dequeue (remove):** \(O(1)\)
  - **Peek (front element):** \(O(1)\)
  - **IsEmpty:** \(O(1)\)
- **Advantages:** Simple implementation, useful for scheduling and buffering tasks.
- **Disadvantages:** Limited to FIFO access.

### 3. Stacks
- **Structure:** Linear data structure following the Last-In-First-Out (LIFO) principle.
- **Operations:**
  - **Push (insert):** \(O(1)\)
  - **Pop (remove):** \(O(1)\)
  - **Peek (top element):** \(O(1)\)
  - **IsEmpty:** \(O(1)\)
- **Advantages:** Simple implementation, useful for recursive algorithms and undo mechanisms.
- **Disadvantages:** Limited to LIFO access.

### 4. Matrices
- **Structure:** 2D array of elements arranged in rows and columns.
- **Operations:**
  - **Access Element:** \(O(1)\)
  - **Modify Element:** \(O(1)\)
  - **Row/Column Operations:** Typically \(O(n)\) for row/column of size \(n\).
  - **Matrix Multiplication:**
    - **Standard Method:** \(O(n^3)\) for \(n \times n\) matrices.
    - **Strassen's Algorithm:** \(O(n^{2.81})\) for square matrices.
    - **Improved Algorithms:** Up to \(O(n^{2.373})\) for large matrices (Coppersmith-Winograd algorithm and variants).
- **Advantages:** Direct access to elements, suitable for mathematical and graphical computations.
- **Disadvantages:** Fixed size, inefficient for sparse data.

### 5. Sets
- **Structure:** Collection of unique elements.
- **Operations:**
  - **Insertion:** Typically \(O(1)\) with hash-based implementation.
  - **Deletion:** Typically \(O(1)\) with hash-based implementation.
  - **Search (contains):** Typically \(O(1)\) with hash-based implementation.
  - **Union/Intersection/Difference:** \(O(n)\) to \(O(n \log n)\) depending on implementation.
- **Advantages:** Automatic handling of duplicates, efficient membership checks.
- **Disadvantages:** No order of elements, performance dependent on hash function.

### 6. Maps/Dictionaries
- **Structure:** Collection of key-value pairs.
- **Operations:**
  - **Insertion:** Typically \(O(1)\) with hash-based implementation.
  - **Deletion:** Typically \(O(1)\) with hash-based implementation.
  - **Search (lookup):** Typically \(O(1)\) with hash-based implementation.
  - **Update:** \(O(1)\)
  - **Iteration:** \(O(n)\)
- **Advantages:** Efficient key-based access and retrieval, flexible data storage.
- **Disadvantages:** No order of keys, performance dependent on hash function.

### 7. Hash Tables
- **Structure:** Array of buckets (or slots) storing key-value pairs, with a hash function to map keys to buckets.
- **Operations:**
  - **Insertion:** \(O(1)\) average case.
  - **Deletion:** \(O(1)\) average case.
  - **Search (lookup):** \(O(1)\) average case.
  - **Resize/Rehash:** Typically \(O(n)\) when resizing the table to maintain load factor.
- **Collision Resolution Methods:**
  - **Separate Chaining:** Each bucket contains a linked list of entries. When collisions occur, entries are added to the list.
    - **Advantages:** Simple, handles high load factors.
    - **Disadvantages:** Increased memory usage, can degrade to \(O(n)\) in worst case.
  - **Open Addressing:** All elements are stored within the hash table array. When collisions occur, alternative slots are tried.
    - **Linear Probing:** Sequentially checks the next slots.
      - **Allowed Load Factor:** Typically up to 0.7 to avoid excessive clustering.
      - **Advantages:** Simple implementation.
      - **Disadvantages:** Clustering issues, can degrade to \(O(n)\).
    - **Quadratic Probing:** Checks slots at increasing intervals (e.g., 1, 4, 9, ...).
      - **Allowed Load Factor:** Typically up to 0.5 to balance efficiency and collision handling.
      - **Advantages:** Reduces clustering compared to linear probing.
      - **Disadvantages:** More complex computation, still prone to secondary clustering.
    - **Double Hashing:** Uses a second hash function to determine the interval for probing.
      - **Allowed Load Factor:** Typically up to 0.8 to balance efficiency and collision handling.
      - **Advantages:** Minimizes clustering, more efficient.
      - **Disadvantages:** More complex, requires two good hash functions.

## Sorting Algorithms

### 1. Bubble Sort
- **Algorithm Type:** Comparison-based, exchange sort.
- **Procedure:**
  - Repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.
  - Each pass through the list places the next largest element in its correct position.
- **Time Complexity:**
  - **Best Case:** \(O(n)\) (when the list is already sorted, with an optimization to stop early).
  - **Average Case:** \(O(n^2)\)
  - **Worst Case:** \(O(n^2)\)
- **Space Complexity:** \(O(1)\) (in-place sort).
- **Advantages:** Simple to understand and implement.
- **Disadvantages:** Inefficient for large lists, poor performance compared to other algorithms.

**Example:**
```
Initial List: [5, 3, 8, 4, 2]
Pass 1: [3, 5, 4, 2, 8]
Pass 2: [3, 4, 2, 5, 8]
Pass 3: [3, 2, 4, 5, 8]
Pass 4: [2, 3, 4, 5, 8]
```

### 2. Selection Sort
- **Algorithm Type:** Comparison-based, selection sort.
- **Procedure:**
  - Divides the list into a sorted and an unsorted region.
  - Repeatedly selects the smallest (or largest) element from the unsorted region and swaps it with the first unsorted element.
- **Time Complexity:**
  - **Best Case:** \(O(n^2)\)
  - **Average Case:** \(O(n^2)\)
  - **Worst Case:** \(O(n^2)\)
- **Space Complexity:** \(O(1)\) (in-place sort).
- **Advantages:** Simple to understand and implement, performs well on small lists.
- **Disadvantages:** Inefficient for large lists, poor performance compared to other algorithms.

**Example:**
```
Initial List: [5, 3, 8, 4, 2]
Pass 1: [2, 3, 8, 4, 5]
Pass 2: [2, 3, 8, 4, 5]
Pass 3: [2, 3, 4, 8, 5]
Pass 4: [2, 3, 4, 5, 8]
```

### 3. Insertion Sort
- **Algorithm Type:** Comparison-based, insertion sort.
- **Procedure:**
  - Builds the sorted list one element at a time.
  - Picks the next element and inserts it into the correct position in the sorted region.
- **Time Complexity:**
  - **Best Case:** \(O(n)\) (when the list is already sorted).
  - **Average Case:** \(O(n^2)\)
  - **Worst Case:** \(O(n^2)\)
- **Space Complexity:** \(O(1)\) (in-place sort).
- **Advantages:** Efficient for small lists and nearly sorted lists, simple to implement.
- **Disadvantages:** Inefficient for large lists.

**Example:**
```
Initial List: [5, 3, 8, 4, 2]
Pass 1: [3, 5, 8, 4, 2]
Pass 2: [3, 5, 8, 4, 2]
Pass 3: [3, 4, 5, 8, 2]
Pass 4: [2, 3, 4, 5, 8]
```

### 4. Merge Sort
- **Algorithm Type:** Comparison-based, divide-and-conquer.
- **Procedure:**
  - Divides the list into two halves, recursively sorts each half, and then merges the sorted halves.
- **Time Complexity:**
  - **Best Case:** \(O(n \log n)\)
  - **Average Case:** \(O(n \log n)\)
  - **Worst Case:** \(O(n \log n)\)
- **Space Complexity:** \(O(n)\) (not in-place due to the need for temporary arrays).
- **Advantages:** Consistently good performance, stable sort, suitable for large lists.
- **Disadvantages:** Requires additional space, more complex implementation.

**Example:**
```
Initial List: [5, 3, 8, 4, 2]
Divide: [5, 3, 8] and [4, 2]
Divide: [5] [3, 8] and [4] [2]
Merge: [3, 5, 8] and [2, 4]
Final Merge: [2, 3, 4, 5, 8]
```

### 5. Quick Sort
- **Algorithm Type:** Comparison-based, divide-and-conquer.
- **Procedure:**
  - Selects a pivot element, partitions the list into elements less than the pivot and elements greater than the pivot, and recursively sorts the partitions.
- **Time Complexity:**
  - **Best Case:** \(O(n \log n)\)
  - **Average Case:** \(O(n \log n)\)
  - **Worst Case:** \(O(n^2)\) (when the pivot selection is poor, e.g., already sorted list).
- **Space Complexity:** \(O(\log n)\) (in-place sort, though it uses stack space for recursion).
- **Advantages:** Good average-case performance, in-place sort, well-suited for large datasets.
- **Disadvantages:** Poor worst-case performance, not stable, performance heavily dependent on pivot selection.

**Example:**

1. **Choose a Pivot:** Select a pivot element from the array. The choice of pivot can vary (e.g., first element, last element, random element, median element). For simplicity, we'll choose the first element as the pivot.

2. **Partitioning:** Rearrange the array such that all elements less than the pivot come before it, and all elements greater come after it. The pivot is then in its final position.

3. **Recursive Sorting:** Recursively apply the above steps to the sub-arrays of elements less than and greater than the pivot.

```
Initial List: [5, 3, 8, 4, 2]
Pivot: 5
Partition: [3, 4, 2] 5 [8]
Recursively sort: [2, 3, 4] and [8]
Final Merge: [2, 3, 4, 5, 8]
```

#### Key Points in Quick Sort
- **Pivot Selection:** Choosing a good pivot is crucial. Common strategies include:
  - **Last Element:** Simple but can degrade to \(O(n^2)\) on sorted arrays.
  - **Random Element:** Helps avoid worst-case scenarios on average.
  - **Median-of-Three:** Choose the median of the first, middle, and last elements.

- **Recursive Calls:** Quick Sort is a divide-and-conquer algorithm, so it recursively sorts sub-arrays. Base case is when the array has one or no elements, which are inherently sorted.

- **Performance:** Average-case \(O(n \log n)\) due to balanced partitions. Worst-case \(O(n^2)\) occurs with poor pivot choices, like already sorted arrays when the first or last element is chosen as pivot.

- **Space Complexity:** \(O(\log n)\) due to the recursive stack space.


### 6. Count Sort
- **Algorithm Type:** Non-comparison-based.
- **Procedure:**
  - Assumes the input consists of integers within a known range.
  - Counts the number of occurrences of each integer.
  - Uses the counts to place the integers in the correct position in the output array.
- **Time Complexity:**
  - **Best Case:** \(O(n + k)\), where \(k\) is the range of the input.
  - **Average Case:** \(O(n + k)\)
  - **Worst Case:** \(O(n + k)\)
- **Space Complexity:** \(O(n + k)\) (requires additional space for counting array).
- **Advantages:** Linear time complexity for small range of integers, stable sort.
- **Disadvantages:** Not suitable for large ranges of integers, requires additional memory.

**Example:**
```
Initial List: [5, 3, 8, 4, 2]
Range: 0 to 8
Count Array: [0, 0, 1, 1, 1, 1, 0, 0, 1]
Output Array: [2, 3, 4, 5, 8]
```

## TREE TYPES

### General Tree Explanation
- **Structure:** A hierarchical data structure consisting of nodes, with each node having zero or more child nodes. A single node is the root, and each node may have its own subtrees.
- **Terminology:**
  - **Root:** The top node with no parent.
  - **Leaf:** A node with no children.
  - **Internal Node:** A node with at least one child.
  - **Height:** The length of the longest path from the root to a leaf.
  - **Depth:** The length of the path from the root to the node.
- **Operations:**
  - **Insertion/Deletion:** Dependent on tree type.
  - **Traversal:** Pre-order, In-order, Post-order, Level-order.
  - **Search:** Dependent on tree type.
- **Advantages:** Represents hierarchical relationships naturally.
- **Disadvantages:** Complex implementation and operations depending on the specific tree type.

### Binary Tree
- **Structure:** Each node has at most two children, referred to as the left and right child.
- **Operations:**
  - **Insertion:** Generally \(O(n)\) if not balanced.
  - **Deletion:** Generally \(O(n)\) if not balanced.
  - **Traversal:** Pre-order, In-order, Post-order, Level-order (\(O(n)\) for each).
- **Advantages:** Simple structure, easy to implement.
- **Disadvantages:** Can become unbalanced, leading to inefficient operations.

### Binary Search Tree (BST)
- **Structure:** A binary tree with the property that the left subtree of a node contains only nodes with keys less than the node's key, and the right subtree contains only nodes with keys greater than the node's key.
- **Operations:**
  - **Insertion:** \(O(h)\), where \(h\) is the height of the tree.
  - **Deletion:** \(O(h)\), where \(h\) is the height of the tree.
  - **Search:** \(O(h)\), where \(h\) is the height of the tree.
  - **Traversal:** In-order traversal gives sorted order (\(O(n)\)).
- **Advantages:** Efficient search, insertion, and deletion if balanced.
  - **Disadvantages:** Performance degrades to \(O(n)\) if the tree becomes unbalanced.

### MinHeap/MaxHeap
- **Structure:** A complete binary tree where each node satisfies the heap property:
  - **MinHeap:** Each parent node is less than or equal to its children.
  - **MaxHeap:** Each parent node is greater than or equal to its children.
- **Operations:**
  - **Insertion:** \(O(\log n)\) by adding the element at the end and "bubbling up" to restore the heap property.
  - **Deletion (Extract Min/Max):** \(O(\log n)\) by removing the root and "bubbling down" to restore the heap property.
  - **Peek (Get Min/Max):** \(O(1)\)
  - **Heapify:** \(O(n)\) to build a heap from an unsorted array.
- **Advantages:** Efficient priority queue implementation, guarantees \(O(\log n)\) insertion and deletion.
  - **Disadvantages:** No efficient searching for arbitrary elements, not suitable for direct access.

### AVL Tree
- **Structure:** A self-balancing binary search tree where the difference in heights of left and right subtrees (balance factor) is at most one for all nodes.
- **Operations:**
  - **Insertion:** \(O(\log n)\) with rotations to maintain balance.
  - **Deletion:** \(O(\log n)\) with rotations to maintain balance.
  - **Search:** \(O(\log n)\) due to balanced height.
  - **Rotations:** Single (left, right) and double (left-right, right-left) rotations used to maintain balance.
- **Advantages:** Guarantees \(O(\log n)\) height, ensuring efficient operations.
  - **Disadvantages:** Slightly more complex insertion and deletion due to rotations.

### AVL Rotations

#### 1. Right Rotation (Single Rotation)
- **Situation:** Occurs when a left-heavy tree (balance factor of +2) becomes unbalanced due to an insertion in the left subtree of the left child.

**Example:**

Before Right Rotation:
```
      y
     / \
    x   C
   / \
  A   B
```

After Right Rotation:
```
      x
     / \
    A   y
       / \
      B   C
```

#### 2. Left Rotation (Single Rotation)
- **Situation:** Occurs when a right-heavy tree (balance factor of -2) becomes unbalanced due to an insertion in the right subtree of the right child.

**Example:**

Before Left Rotation:
```
   x
  / \
 A   y
    / \
   B   C
```

After Left Rotation:
```
     y
    / \
   x   C
  / \
 A   B
```

#### 3. Left-Right Rotation (Double Rotation)
- **Situation:** Occurs when a left-heavy tree (balance factor of +2) becomes unbalanced due to an insertion in the right subtree of the left child.

**Example:**

Before Left-Right Rotation:
```
      z
     / \
    y   D
   / \
  A   x
     / \
    B   C
```

Intermediate Step (Left Rotation on y):
```
      z
     / \
    x   D
   / \
  y   C
 / \
A   B
```

After Right Rotation:
```
      x
     / \
    y   z
   / \   \
  A   B   D
         /
        C
```

#### 4. Right-Left Rotation (Double Rotation)
- **Situation:** Occurs when a right-heavy tree (balance factor of -2) becomes unbalanced due to an insertion in the left subtree of the right child.

**Example:**

Before Right-Left Rotation:
```
   x
  / \
 A   z
    / \
   y   D
  / \
 B   C
```

Intermediate Step (Right Rotation on z):
```
   x
  / \
 A   y
    / \
   B   z
      / \
     C   D
```

After Left Rotation:
```
     y
    / \
   x   z
  / \ / \
 A  B C  D
```


## GRAPH SEARCH ALGORITHMS

### 1. Breadth-First Search (BFS)
- **Purpose:** Explore all nodes at the present "depth" level before moving on to nodes at the next depth level.
- **Process:** Uses a queue to keep track of nodes to visit. Starts from a given node, visits all its neighbors, then their neighbors, and so on.
- **Characteristics:**
  - **Complete:** Always finds a solution if one exists.
  - **Optimal:** Finds the shortest path in unweighted graphs.
  - **Time Complexity:** \(O(V + E)\), where \(V\) is the number of vertices and \(E\) is the number of edges.
  - **Space Complexity:** \(O(V)\) due to the storage of the queue.

### 2. Depth-First Search (DFS)
- **Purpose:** Explore as far as possible along each branch before backtracking.
- **Process:** Uses a stack (often implemented via recursion) to keep track of nodes to visit. Starts from a given node, explores a branch to its deepest node, backtracks, and continues.
- **Characteristics:**
  - **Not Complete:** Might get stuck in infinite loops in infinite graphs.
  - **Not Optimal:** Does not guarantee the shortest path.
  - **Time Complexity:** \(O(V + E)\)
  - **Space Complexity:** \(O(V)\) in the worst case due to the recursion stack.

### 3. Dijkstra's Algorithm
- **Purpose:** Find the shortest path from a source node to all other nodes in a weighted graph.
- **Process:** Uses a priority queue to explore the nearest unvisited node with the smallest tentative distance. Updates distances to neighboring nodes iteratively.
- **Characteristics:**
  - **Complete:** Always finds the shortest path.
  - **Optimal:** Guarantees the shortest path in graphs with non-negative weights.
  - **Time Complexity:** \(O((V + E) \log V)\) with a priority queue.
  - **Space Complexity:** \(O(V)\) for storing distances and priority queue.

### 4. A* (A-star)
- **Purpose:** Find the shortest path from a start node to a goal node, using heuristics to improve efficiency.
- **Process:** Uses a priority queue, similar to Dijkstra, but adds a heuristic estimate (usually the Euclidean or Manhattan distance) to prioritize nodes.
- **Characteristics:**
  - **Complete:** Finds a solution if one exists, given a consistent and admissible heuristic.
  - **Optimal:** Guarantees the shortest path with an admissible heuristic.
  - **Time Complexity:** Depends on the heuristic, but typically \(O((V + E) \log V)\).
  - **Space Complexity:** \(O(V)\) due to storage of the open set.

### 5. Floyd-Warshall Algorithm
- **Purpose:** Find the shortest paths between all pairs of nodes in a weighted graph.
- **Process:** Uses dynamic programming to iteratively improve the estimate of the shortest path between each pair of vertices.
- **Characteristics:**
  - **Complete:** Computes shortest paths between all pairs of nodes.
  - **Optimal:** Guarantees the shortest paths.
  - **Time Complexity:** \(O(V^3)\)
  - **Space Complexity:** \(O(V^2)\) due to the distance matrix.


### Minimum Spanning Tree (MST)
A Minimum Spanning Tree (MST) of a graph is a subset of edges that connects all vertices in the graph without any cycles and with the minimum possible total edge weight. MST algorithms are used in network design, clustering, and various other applications.

### Prim's Algorithm
- **Type:** Greedy algorithm.
- **Process:**
  1. **Initialization:** Start with a single vertex and grow the MST one edge at a time.
  2. **Select Edge:** At each step, select the minimum weight edge that connects a vertex in the MST to a vertex outside the MST.
  3. **Update:** Add the selected edge to the MST and repeat until all vertices are included in the MST.
- **Implementation Details:**
  - Often implemented using a priority queue (min-heap) to efficiently select the minimum weight edge.
  - Can start from any arbitrary vertex.
- **Time Complexity:** \(O((V + E) \log V)\) with a priority queue or Fibonacci heap.
- **Characteristics:**
  - Works well with dense graphs.
  - Incrementally builds the MST, always maintaining a connected component.

### Kruskal's Algorithm
- **Type:** Greedy algorithm.
- **Process:**
  1. **Initialization:** Start with an empty set of edges and a forest of single-vertex trees.
  2. **Sort Edges:** Sort all edges in the graph by their weight in ascending order.
  3. **Select Edge:** Add the smallest edge to the MST, provided it does not form a cycle.
  4. **Union-Find:** Use the union-find data structure to detect and avoid cycles.
  5. **Repeat:** Continue adding edges until there are \(V-1\) edges in the MST.
- **Implementation Details:**
  - Uses a union-find data structure to manage the merging of trees and cycle detection.
  - Processes edges in sorted order.
- **Time Complexity:** \(O(E \log E + E \log V)\), where the first term is for sorting the edges and the second term is for union-find operations.
- **Characteristics:**
  - Works well with sparse graphs.
  - Initially, no edges are selected, and edges are added based on global information (sorted edges).


### Comparison of Prim's and Kruskal's Algorithms
- **Prim's Algorithm:**
  - **Approach:** Grows the MST from a starting vertex by adding the minimum weight edge that connects the MST to a new vertex.
  - **Best For:** Dense graphs, since it benefits from priority queues and adjacency lists.
  - **Time Complexity:** \(O((V + E) \log V)\)

- **Kruskal's Algorithm:**
  - **Approach:** Builds the MST by considering edges in ascending order of weight and adding them if they do not form a cycle.
  - **Best For:** Sparse graphs, as it focuses on edge weights and uses union-find for cycle detection.
  - **Time Complexity:** \(O(E \log E + E \log V)\)


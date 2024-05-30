#include <iostream>
#include <vector>

int oddSquare(int N)
{
    // hvis det er et lige tal, træk 1 fra
    if (N % 2 == 0)
        N--;
    // base case
    if (N <= 0)
        return 0;

    return N * N + oddSquare(N - 2);
}

class MaxHeap
{
public:
    bool isEmpty() const {
        return m_data.empty();
    }

    int size() const {
        return m_data.size();
    }

    void insert(const int x) {
        m_data.push_back(x);
    }

    const int findMax() const {
        int max = *m_data.cbegin();
        for (auto it = m_data.cbegin(); it != m_data.cend(); ++it) {
            if (*it > max) {
                max = *it;
            }
        }
        return max;
    }

    int deleteMax() {
        auto maxIt = m_data.begin();
        for (auto it = m_data.begin(); it != m_data.end(); ++it) {
            if (*it > *maxIt) {
                maxIt = it;
            }
        }
        int max = *maxIt;
        m_data.erase(maxIt);
        return max;
    }

private:
    std::vector<int> m_data;
};

int main()
{
    MaxHeap heap;

    std::cout << "Heap empty? " << heap.isEmpty() << std::endl;

    heap.insert(1);
    heap.insert(3);
    heap.insert(7);
    heap.insert(-1);
    heap.insert(2);

    std::cout << "Heap empty? " << heap.isEmpty() << std::endl;
    std::cout << "Size: " << heap.size() << std::endl;
    std::cout << "findMax: " << heap.findMax() << std::endl;
    std::cout << "deleteMax: " << heap.deleteMax() << std::endl;
    std::cout << "Size: " << heap.size() << std::endl;
    std::cout << "findMax: " << heap.findMax() << std::endl;

    return 0;
}

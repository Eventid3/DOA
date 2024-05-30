#include <iostream>
#include <vector>

int sumDivisibleBy3(int N)
{
    // make sure the number is divisible by three
    N -= N % 3;
    // base case
    if (N <= 0) return 0;
    // recursive call
    return N + sumDivisibleBy3(N-3);
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

int findMedian(MaxHeap maxheap)
{
    size_t size = maxheap.size();

    int median;
    for (int i = 0; i < (size+1)/2; i++)
    {
        median = maxheap.deleteMax();
    }
    return median;
}

template<typename T>
std::vector<T> partitionEvenOdd(std::vector<T>& arg) {
    std::vector<T> result(arg.size());

    int even = 0, odd = arg.size() - 1;
    for (int i = 0; i < arg.size(); ++i) {
        T current = arg[i];
        if (current % 2 == 0) {
            result[even++] = current;
        } else {
            result[odd--] = current;
        }
    }
    return result;
}

int main()
{
    std::vector numbers1{1,2,2,2,3,5,6,7};
    std::vector sorted = partitionEvenOdd(numbers1);
    for (const auto num : sorted)
        std::cout << num << std::endl;

    return 0;

}

#include <iostream>

struct LNode
{
    char value;
    LNode *next;
    LNode *previous;
};

bool isPalindrome(LNode *begin, LNode *end)
{
    if (begin->next == end || begin == end)
        return begin->value == end->value;

    if (begin->value != end->value)
        return false;

    return isPalindrome(begin->next, end->previous);
}

// Floyd-Warshall Algorithm in C++

#include <iostream>

// defining the number of vertices
#define nV 8
#define INF 999

void findBest(int matrix[][nV])
{
     int lowest_value = std::numeric_limits<int>::max();
    int best_location;

    for (int i = 0; i < 8; ++i)
    {
        int col_sum = 0;
        for (int j = 0; j < 8; ++j)
            col_sum += matrix[j][i];

        if (col_sum < lowest_value)
        {
            lowest_value = col_sum;
            best_location = i;
        }
    }

    std::cout << "Best location is " << best_location << " with a total dataloss of " << lowest_value << std::endl;
}

void printMatrix(int matrix[][nV]);

// Implementing floyd warshall algorithm
void floydWarshall(int graph[][nV])
{
    int matrix[nV][nV], i, j, k;

    for (i = 0; i < nV; i++)
        for (j = 0; j < nV; j++)
            matrix[i][j] = graph[i][j];

    // Adding vertices individually
    for (k = 0; k < nV; k++)
    {
        for (i = 0; i < nV; i++)
        {
            for (j = 0; j < nV; j++)
            {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }
    printMatrix(matrix);
    findBest(matrix);
}

void printMatrix(int matrix[][nV])
{
    for (int i = 0; i < nV; i++)
    {
        for (int j = 0; j < nV; j++)
        {
            if (matrix[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int graph[nV][nV] = {
        {0, 50, 40, 160, 160, 160, 160, 160},
        {55, 0, 160, 160, 20, 40, 160, 160},
        {35, 160, 0, 160, 45, 160, 160, 160},
        {160, 160, 160, 0, 160, 10, 160, 30},
        {160, 35, 55, 160, 0, 25, 60, 160},
        {160, 60, 160, 5, 10, 0, 85, 160},
        {160, 160, 160, 160, 85, 70, 0, 160},
        {160, 160, 160, 35, 160, 160, 160, 0}
    };

    floydWarshall(graph);


}

// int main()
// {
//     LNode char1{'a',nullptr, nullptr};
//     LNode char2{'b',nullptr, nullptr};
//     LNode char3{'c',nullptr, nullptr};
//     LNode char4{'b',nullptr, nullptr};
//     LNode char5{'a',nullptr, nullptr};
//
//     char1.next = &char2;
//     char2.next = &char3;
//     char3.next = &char4;
//     char4.next = &char5;
//
//     char2.previous = &char1;
//     char3.previous = &char2;
//     char4.previous = &char3;
//     char5.previous = &char4;
//
//     std::cout << isPalindrome(&char1, &char5) << std::endl;
//     return 0;
// }

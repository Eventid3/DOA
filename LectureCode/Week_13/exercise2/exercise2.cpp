//
// Created by Esben Inglev on 01/05/2024.
//

/*
 * BOTTOM UP CUT ROD
 * let r[0..n] be a new array
 * r[0] = 0
 * for j = 1 to n
 *    q = -inf
 *    for i = 1 to j
 *        q = max(q, p[i] + r[i-j])
 *    r[j] = q
 * return r[n]
 */

#include <iostream>
#include <vector>
#include <cmath>

// p er en liste med priser pr længde
// n er længden af den rod der skal cuttes
// c er cut cost
int buttomUpCutting(const std::vector<int> &p, int n, int c)
{
    std::vector<int> r(n);

    r[0] = 0;

    for (int j = 1; j <= n; ++j)
    {
        int q = -10000000;
        for (int i = 1; i <= j; ++i)
        {
            // c trækkes fra her for at fører costen ind
            q = std::max(q, p[i] + r[j - i] - c);
        }
        r[j] = q;
    }
    // +c her, er for at kompenserer for,
    // at c bliver trukket fra, selv når der ikke cuttes
    return r[n] + c;
}

int main()
{
    std::vector<int> p{0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

    for (int i = 1; i <= 10; ++i)
    {
        std::cout << "Revenue of a rod of size " << i << " is: " << buttomUpCutting(p, i, 0) << std::endl;
    }
}

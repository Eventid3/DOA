#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <array>

#define ALPHABET 10
#define Q 23

using namespace std;

bool hashMatch(string pat, string txt)
{
    size_t n = txt.length(), m = pat.length();
    int i, j, p = 0, t = 0, h = 1;

    // Calculate the hash value of pat and first window of txt
    for (i = 0; i < m; i++)
    {
        h = (h * ALPHABET) % Q; // precompute
        p = (ALPHABET * p + pat[i]) % Q;
        t = (ALPHABET * t + txt[i]) % Q;
    }

    // Slide the pat over txt one by one
    for (i = 0; i <= n - m; i++)
    {
        // Check the hash values
        if (p == t)
        {
            std::cout << "Index for match: " << i << std::endl;
            /* Check for characters one by one */
            for (j = 0; j < m; j++)
            {
                if (txt[i + j] != pat[j])
                    break;
            }
            if (j == m)
            {
                return true;
            }
        }
        // Calculate hash value for next window of txt: Remove
        // leading digit, add trailing digit
        if (i < n - m)
        {
            t = (ALPHABET * t - txt[i] * h + txt[i + m]) % Q;
            // We might get negative value of t, converting it to positive
            if (t < 0)
                t = (t + Q);
        }
    }
    return false;
}

bool trySort(std::queue<int> &q, std::queue<int> &result)
{
    std::stack<int> s;
    int current = 1;

    while (!q.empty())
    {
        if (q.front() == current)
        {
            result.push(q.front());
            ++current;
            q.pop();
        } else
        {
            s.push(q.front());
            q.pop();
        }
    }

    while (!s.empty())
    {
        if (s.top() != current)
            return false;
        result.push(s.top());
        s.pop();
    }
    return true;
}

struct flight_location
{
    int location;
    int price;
    bool operator==(const flight_location &other) const
    {
        return price == other.price && location == other.location;
    }
    friend std::ostream& operator<<(std::ostream& os, const flight_location& f)
    {
        os << "Location: " << f.location << ", price: " << f.price;
        return os;
    }
};

template<>
struct std::hash<flight_location>
{
    std::size_t operator()(const flight_location &k) const
    {
        using std::hash;
        return hash<int>()(k.price);
    }
};

flight_location flight_find_cheapest(int n, vector<array<int, 5> > &flights, int src,
                                     int dst, int stops, unordered_map<flight_location, flight_location> &path)
{
    std::vector<int> dist(n, std::numeric_limits<int>::max());
    std::vector<int> prev(n, -1);
    dist[src] = 0;

    for (int i = 0; i < stops; ++i)
    {
        std::vector<int> tempDist = dist;
        for (const auto& flight : flights)
        {
            int u = flight[0];
            int v = flight[1];
            int price = flight[2];

            if (dist[u] != std::numeric_limits<int>::max() && tempDist[v] > dist[u] + price)
            {
                tempDist[v] = dist[u] + price;
                prev[v] = u;
            }
        }
        dist = tempDist;
    }

    if (dist[dst] == INFINITY)
    {
        return {dst, std::numeric_limits<int>::max()};
    }

    int current = dst;
    while (current != src)
    {
        int previous = prev[current];
        if (previous == -1) break;

        flight_location destination{current, dist[current]};
        flight_location source{previous, dist[previous]};
        path[destination] = source;
        current = previous;
    }
    return { dst, dist[dst]};
}

int main()
{
    vector<array<int, 5> > flights = {
        {0, 1, 500, 0, 1},
        {0, 3, 200, 0, 1},
        {3, 1, 200, 2, 3},
        {1, 4, 100, 4, 5},
        {1, 2, 500, 4, 5},
        {4, 2, 100, 6, 7}
    };
    std::unordered_map<flight_location, flight_location> path;

    int src = 0, dst = 2;
    flight_location cheapest_flight = flight_find_cheapest(5, flights, src, dst, 3, path);

    std::cout << "Cheapest flight: " << cheapest_flight.price << ", from " <<
        src << " to " << dst << std::endl;

    for (const auto[k,v] : path)
    {
        std::cout << k << " came from " << v << std::endl;
    }

}

#include "pair.h"
#include <string>

int main()
{
    Pair<std::string, int> myDog("Dog", 36);
    Pair<double, double> myFloats(3.0, 2.18);
}

// Compile with: cl /EHsc .\main.cpp

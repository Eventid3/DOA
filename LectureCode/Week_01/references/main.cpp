#include <string>
#include <cassert>

int main()
{
    // std::string s1 = "a new string";
    // std::string s2 = s1;
    // assert((&s2)==(&s1)); // True or False?

    // std::string * s3 = &s1;
    // std::string * s4 = s3;

    // assert(s4==&s1); // True or False?
    // assert(s4==s3); // True or False?

    std::string s1 = "a new string";
    std::string & s2 = s1;
    assert((&s2)==(&s1)); // True or False?
}

// Compile with: cl /EHsc .\main.cpp

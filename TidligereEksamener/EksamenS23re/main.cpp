#include <iostream>
#include <unordered_map>
#include "binary_heap.h"

std::pair<std::string, int> mostCommonWord(const std::string &text)
{
    std::string current;
    std::unordered_map<std::string, int> wordCount;
    for (char c: text)
    {
        char c_lower = std::tolower(c);
        if (c_lower == ' ' || c_lower  == ',' || c_lower == '.')
        {
            if (current != "")
                wordCount[current]++;
            current = "";
        }
        else
        {
            current += c_lower;
        }
    }

    int maxCount = 0;
    std::string maxWord;

    for (const auto [k,v]: wordCount)
    {
        if (v > maxCount)
        {
            maxCount = v;
            maxWord = k;
        }
    }
    return {maxWord, maxCount};
}

int main()
{
    std::string text = "The cattle were running back and forth, but there was no wolf to be seen, heard or smelled, so the shepherd decided to take a little nap in a bed of grass and early summer flowers. Soon he was awakened by a sound he had never heard before.";

    std::pair result = mostCommonWord(text);

    std::cout << "Most common word is '" << result.first << "' with a count of " << result.second << std::endl;
}

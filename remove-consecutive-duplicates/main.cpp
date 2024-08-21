#include <algorithm>
#include <iostream>


int main()
{
    std::string str = "aaabbccddefgg";
    std::cout << str << "\n";
    //Removes all except the first element from every consecutive group of equivalent elements from the range [first, last) and returns a past-the-end iterator for the new end of the range.
    auto it = std::unique(str.begin(), str.end());
    str.erase(it, str.end());
    std::cout << str << "\n"; //abcdefg
}
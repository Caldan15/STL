#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to check if a string is a palindrome
int isPalindrome(string s)
{
    int n = s.length();

    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            return 0;
        }
    }
    return 1;
}

// This Function iterates through all substrings to find the longest substring
string Longest_Palindrome(string str)
{
    string longest_palindrome;

    for (int i = 0; i < str.length(); i++)
    {
        for (int j = i + 1; j <= str.length(); j++)
        {
            string sub = str.substr(i, j - i);
            longest_palindrome = isPalindrome(sub) && sub.length() > longest_palindrome.length() ? sub : longest_palindrome;
        }
    }
    return longest_palindrome;
}

int main()
{
    string str;
    cout << "Enter the string: ";
    getline(cin, str);

    string longestPalindrome = Longest_Palindrome(str);
    if (longestPalindrome.length() > 1)
    {
        cout << longestPalindrome << endl;
    }
    else
    {
        cout << "No palindromes";
    }

    return 0;
}

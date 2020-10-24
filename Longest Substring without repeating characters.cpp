#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// My solution
int lengthOfLongestSubstring(string s)
{
    map<char,int> characterFlag;
    map<char,int>::iterator temp;
    int i,max_length = 0,length = 0;
    int startWindow = 0, endWindow = 0;
    while(endWindow != s.length())
    {
        temp = characterFlag.find(s[endWindow]);
        if (temp == characterFlag.end())
        {
            characterFlag.insert( pair<char,int>(s[endWindow],endWindow) );
            endWindow++;
        }
        else
        {
            // length reset
            if (max_length<(endWindow-startWindow)) max_length = endWindow-startWindow;
            // fix sliding window
            i = startWindow;
            while(s[i]!=s[endWindow])
            {
                characterFlag.erase(s[i]);
                i++;
            }
            startWindow = i+1;
            endWindow++;
        }
    }
    if (max_length<(endWindow-startWindow)) max_length = endWindow-startWindow;
    return max_length;
}

// Optimized solution?
int lengthOfLongestSubstring2(string s)
{
    int n = s.length(), ans = 0;
    map<char, int> leMap;
    // try to extend the range [i, j]
    for (int j = 0, i = 0; j < n; j++)
    {
        if(leMap.find(s[j])!=leMap.end())
        {
            i = max(leMap[s[j]], i);
        }
        ans = max(ans, j - i + 1);
        leMap.insert( pair<char,int>(s[j], j + 1) );
    }
    return ans;
}

int main()
{
    string s = "dvdf";
    printf("%d\n", lengthOfLongestSubstring(s));
    s = "abcabcbb";
    printf("%d\n", lengthOfLongestSubstring(s));
    s = "pwwkew";
    printf("%d\n", lengthOfLongestSubstring(s));
    s = "";
    printf("%d\n", lengthOfLongestSubstring(s));
    s = "aaaa";
    printf("%d\n", lengthOfLongestSubstring(s));
    return 0;
}

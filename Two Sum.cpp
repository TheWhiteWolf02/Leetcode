#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    map<int,int> numberIndex;
    vector<int> answer;
    map<int,int>::iterator temp;
    int i, remainder;
    for(i=0; i<nums.size(); i++)
    {
        remainder = target - nums[i];
        temp = numberIndex.find(remainder);
        if (temp != numberIndex.end())
        {
            answer.push_back(i);
            answer.push_back(temp->second);
            break;
        }
        numberIndex.insert( pair<int,int>(nums[i],i) );
    }
    return answer;
}

int main() {
    // twoSum()
    return 0;
}


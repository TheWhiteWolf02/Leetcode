#include <iostream>
#include <vector>
#include <iterator>
#include <map>
using std::vector;
using std::map;
using std::pair;

vector<int> twoSum(vector<int>& nums, int target)
{
    map<int,int> numberIndex;
    vector<int> answer;
    std::map<int,int>::iterator temp;
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
        numberIndex.insert( std::pair<int,int>(nums[i],i) );
    }
    return answer;
}


/*
Given an array of integers, Find the largets increasing sub sequence of integers in the array
input 10,3,7,9,0,15
return 1 & 3
*/

#include <iostream>
#include <vector>
using namespace std;
vector<int> LargestIncreasingSubSequence(vector<int> arr)
{
	vector<int> result;
	result.reserve(3);
	int current = 0;
	int lastLength = 0;

	for (int i = 1; i < arr.size(); )
	{
		if (arr[current] < arr[i])
		{
			i++;
		}
		else
		{
			if (((i - current) + 1) > lastLength)
			{
				result.clear();
				result.push_back(current);
				result.push_back(i - 1);
				lastLength = (i - current) + 1;
				current = i;
				i++;
			}
			
		}
	}
	return result;
}

int main()
{
	vector<int> input = { 10,3,7,9,0,15 };
	vector<int> output = LargestIncreasingSubSequence(input);
	cout << "( " << output[0] << ", " << output[1] << " )" << endl;
	return 0;
}
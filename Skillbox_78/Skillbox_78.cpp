#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*Задача 2
Что нужно сделать:
Вам даётся массив целых чисел и одно число — результат. 
Необходимо найти в массиве два числа, сумма которых будет давать результат, и вывести их на экран. 
Гарантируется, что только одна пара чисел в массиве даёт в сумме результат.*/

//------------------------------------------------------------------------------------------------
vector<int> findTwoSum(const vector<int>& nums, int target) 
{
	unordered_map<int, int> numIndexMap;

	for (int i = 0; i < nums.size(); ++i) 
	{
		int complement = target - nums[i];

		if (numIndexMap.find(complement) != numIndexMap.end()) 
		{
			return { nums[numIndexMap[complement]], nums[i] };
		}
		numIndexMap[nums[i]] = i;
	}

	return {};
}
//------------------------------------------------------------------------------------------------
int main() 
{
	setlocale(LC_ALL,"ru");

	vector<int> nums = { 2, 7, 11, 15 };
	int target = 9;
	vector<int> result = findTwoSum(nums, target);

	cout << "Числа, которые в сумме составляют " << target << ": " << result[0] << " и " << result[1] << endl;

	return 0;
}
//------------------------------------------------------------------------------------------------
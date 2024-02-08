#include <iostream>
#include <vector>

using namespace std;

/*Задача 1
Что нужно сделать:
Вам даётся массив целых чисел. 
Необходимо найти такие два индекса i и j в этом массиве, 
что сумма a[i], a[i+1], a[i+2], … a[j] будет максимально возможной и вывести их.
a = {-2,1,-3,4,-1,2,1,-5,4}
Тогда наибольшая сумма последовательных элементов находится между индексами 3 и 6: {4,-1,2,1}, сумма = 6. 
Необходимо вывести 3 и 6.*/

//-------------------------------------------------------------------
pair<int, int> findMaxSubarray(const vector<int>& nums) 
{
	int maxSum = INT_MIN;
	int currentSum = 0;
	int startIndex = 0;
	int endIndex = 0;
	int tempIndex = 0;

	for (int i = 0; i < nums.size(); ++i) 
	{
		currentSum += nums[i];

		if (currentSum > maxSum) 
		{
			maxSum = currentSum;
			startIndex = tempIndex;
			endIndex = i;
		}

		if (currentSum < 0) 
		{
			currentSum = 0;
			tempIndex = i + 1;
		}
	}

	return make_pair(startIndex, endIndex);
}
//-------------------------------------------------------------------
int main() 
{
	setlocale(LC_ALL,"ru");

	vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	pair<int, int> result = findMaxSubarray(nums);
	cout << "Начальный индекс: " << result.first << ", Конечный индекс: " << result.second << endl;

	return 0;
}
//-------------------------------------------------------------------
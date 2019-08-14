#include<cstdio>
#include<stdlib.h>
// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。

//false 输入有误或者不存在重复的数字
//true  输入有效，并且存在重复的数字


bool duplicate(int numbers[], int length, int *duplication)
{
	if (numbers == nullptr&& length < 0)
		return false;

	for (int i = 0; i < length; ++i)
	{
		if (numbers[i] < 0 || numbers[i] >= length)
			return false;
	}

	for (int i = 0; i < length; ++i)
	{
		while (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[numbers[i]]])
			{
				*duplication = numbers[i];
				return true;
			}
			int temp = numbers[i];
			numbers[i] = numbers[numbers[i]];
			numbers[numbers[i]] = temp;
		}
			
	}
	return false;
}
int main()
{
	
	int numbers[] = { 0,1,2,2,3,3,4 };
	int length = sizeof(numbers) / sizeof(int);
	int duplication_p;

	bool result=duplicate(numbers, length, &duplication_p);
	printf("%d\n",result);
	printf("%d\n",duplication_p);
	
	system("PAUSE");
	return 0;
}
/*
小结：在主函数中定义的数组，将数组的地址传递给函数作形参，当在函数中改变数组中的数据时，实际上确实改变了;
传递过程只是将数组的首元素地址传递给形参数组，同时对形参数组大小不做检查。
在主函数中定义一个变量，将地址传递给函数作形参，当在函数中改变这个变量的值，实际上也确实改变了
*/
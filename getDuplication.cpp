#include<cstdio>
#include<stdlib.h>

//返回正数，输入有效，并且该正数为重复的数字
//返回负数，输入无效，或者没有重复的数字
int countRange(const int *numbers, int length, int start, int end);
int getDuplication(const int *numbers, int length)
{
	if (numbers == nullptr || length < 0)
		return -1;

	int start = 1;
	int end = length - 1;
	
	while(end>=start)
	{ 	
	int middle = ((end - start) >> 1) + start;
	int count = countRange(numbers, length, start, middle);
	if (start == end)
	{
		if (count > 1)
			return start;
		else
			break;
	}

	if (count > (middle - start + 1))
		end = middle;
	else
		start = middle + 1;
	}

}

int countRange(const int *numbers, int length, int start, int end)
{
	if (numbers == nullptr)
		return 0;
	int count = 0;
	for(int i = 0; i < length; ++i)
	{
		if (numbers[i] >= start&&numbers[i] <= end)
			++count;
	}
	return count;
}
int main()
{
	
	int numbers[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
	int length = 8;
	int x = getDuplication(numbers, length);
	printf("%d\n", x);
	system("PAUSE");
	return 0;
}
/*小结：
1.向右位移1位对该数作四舍五入
2.二分法结束标志是start和end相等
该算法思想。在n+1个数字中找到重复的数字，数字的大小为1~n。
所以利用二分法，当在某一段区间内的数字个数超过该区间的长度，则重复的数字必定在该区间内。区间为闭区间。
*/
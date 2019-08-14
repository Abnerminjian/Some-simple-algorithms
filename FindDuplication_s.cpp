#include<cstdio>
#include<stdlib.h>
// ������3��һ�����ҳ��������ظ�������
// ��Ŀ����һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�
// Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡����磬������볤��Ϊ7������{2, 3, 1, 0, 2, 5, 3}��
// ��ô��Ӧ��������ظ�������2����3��

//false ����������߲������ظ�������
//true  ������Ч�����Ҵ����ظ�������


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
С�᣺���������ж�������飬������ĵ�ַ���ݸ��������βΣ����ں����иı������е�����ʱ��ʵ����ȷʵ�ı���;
���ݹ���ֻ�ǽ��������Ԫ�ص�ַ���ݸ��β����飬ͬʱ���β������С������顣
���������ж���һ������������ַ���ݸ��������βΣ����ں����иı����������ֵ��ʵ����Ҳȷʵ�ı���
*/
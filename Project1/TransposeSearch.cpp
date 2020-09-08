#include<iostream>
#define ARRAY_LENGTH 7

using namespace std;

void PrintItOut(int* pValues)
{
	for (int i = 0; i < ARRAY_LENGTH; i++)
	{
		cout << pValues[i];
	}

	cout << endl;
}


void Swap(int* pA, int* pB)
{
	int temp = *pA;
	*pA = *pB;
	*pB = temp;
}

void SearchAndSwap(int* pValues,int searchValue)
{
	for (int i = 0; i < ARRAY_LENGTH - 1; i++)
	{
		if (pValues[i] == searchValue)
		{
			if (i != 0)
			{
				Swap(&pValues[i], &pValues[i - 1]);
				break;
			}
			else
			{
				break;
			}
		}
	}
}


int main()
{
	int values[] = { 6,4,2,1,5,8,9 };
	PrintItOut(values);
	SearchAndSwap(values,1);
	PrintItOut(values);
}
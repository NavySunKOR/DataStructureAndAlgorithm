#include<iostream>
#define ARRAY_LENGTH 6

using namespace std;


void PrintoutValues(int pValues[])
{
	for (int i = 0; i < ARRAY_LENGTH; i++)
	{
		cout << pValues[i];
	}
	cout << endl;
}

void SearchValueAndMoveforward(int pLook,int pValues[])
{
	for (int i = 0; i < ARRAY_LENGTH; i++)
	{
		if (pValues[i] == pLook)
		{
			memmove(&pValues[1], &pValues[0], sizeof(pValues[0]) * i);
			pValues[0] = pLook;
			break;
		}
	}
}

void SortAscend(int pValues[])
{
	for (int i = 1; i < ARRAY_LENGTH; i++)
	{
		if (pValues[i - 1] < pValues[i])
			continue;

		int tempValue = pValues[i];
		for (int j = 0; j < i; j++)
		{
			if (pValues[j] > tempValue)
			{
				memmove(&pValues[j + 1], &pValues[j], sizeof(pValues[0]) * (i - j));
				pValues[j] = tempValue;
				break;
			}
		}
	}
}
void SortDescend(int pValues[])
{
	for (int i = 1; i < ARRAY_LENGTH; i++)
	{
		if (pValues[i - 1] > pValues[i])
			continue;

		int tempValue = pValues[i];
		for (int j = 0; j < i; j++)
		{
			if (pValues[j] < tempValue)
			{
				memmove(&pValues[j + 1], &pValues[j], sizeof(pValues[0]) * (i - j));
				pValues[j] = tempValue;
				break;
			}
		}
	}
}

int main()
{
	int values[] = { 6,1,2,3,5,4 };

	PrintoutValues(values);

	SearchValueAndMoveforward(3,values);

	PrintoutValues(values);
	SearchValueAndMoveforward(4, values);

	PrintoutValues(values);
	SearchValueAndMoveforward(1, values);
	PrintoutValues(values);

	SortAscend(values);
	PrintoutValues(values);

	SortDescend(values);
	PrintoutValues(values);


	return 0; 
}


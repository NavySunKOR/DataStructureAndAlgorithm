#include<iostream>

using namespace std;

int BinarySearch(int* data,int pSearch,int pArrayLength)
{
	int left = 0;
	int right = pArrayLength - 1;
	int mid ;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (pSearch == data[mid])
		{
			return mid;
		}
		else if (pSearch > data[mid])
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	return -1;
}

int main()
{
	int data[] = { 1,3,5,7,9,11,26,34,56,67 };

	int idx = BinarySearch(data,26,(sizeof(data)/sizeof(data[0])));
	
	if (idx >= 0)
	{
		cout << "Found At : " << idx << endl;
		cout << "Data : " << data[idx] << endl;
	}
	else
	{
		cout << "Not found!!" << endl;
	}

}
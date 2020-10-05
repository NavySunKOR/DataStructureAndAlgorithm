#include<iostream>

using namespace std;

template<typename K, typename T>
class HashNode
{
public:
	K Key = NULL;
	T Value = NULL;
};
template<typename K, typename T>
class HashTable
{

public:
	HashNode<K, T>* Data;
	int TableSize;
	int CurrentDataCount;

	HashTable(int pTableSize)
	{
		TableSize = pTableSize;
		Data = new HashNode<K, T>[TableSize];
		CurrentDataCount = 0;
	}

	void ResizeUp(int pRatio)
	{
		cout << "MyTable size : " << TableSize << endl;
		TableSize *= pRatio;
		realloc(Data, sizeof(HashNode<K, T>) * TableSize);
	}

	void ResizeDown(int pRatio)
	{
		TableSize /= pRatio;
		realloc(Data, sizeof(HashNode<K, T>) * TableSize);
	}

	void Resize(int pRatio)
	{
		if (CurrentDataCount >= TableSize)
		{
			TableSize *= pRatio;
			realloc(Data, sizeof(HashNode<K, T>) * TableSize);
		}
		else if (CurrentDataCount < TableSize / pRatio)
		{
			TableSize /= pRatio;
			realloc(Data, sizeof(HashNode<K, T>) * TableSize);
		}
	}

};

void HASTABLE_Set(HashTable<int, int>* pTable, int pKey,int pOriginKey, int pValue);
int HASTABLE_Get(HashTable<int, int>* pTable, int pKey, int pOriginKey);

int HASHTABLE_Hashing(int pKey, int pTableSize);

int main()
{
	HashTable<int, int>* table = new HashTable<int, int>(3);
	HASTABLE_Set(table, HASHTABLE_Hashing(36, 3),36, 555);
	HASTABLE_Set(table, HASHTABLE_Hashing(15557, 3), 15557, 2545);
	HASTABLE_Set(table, HASHTABLE_Hashing(15559, 3), 15559, 266545);
	HASTABLE_Set(table, HASHTABLE_Hashing(15510, 3), 15510, 35635);

	cout << HASTABLE_Get(table,HASHTABLE_Hashing(36, 3), 36)<< endl;
	cout << HASTABLE_Get(table, HASHTABLE_Hashing(15557, 3), 15557) << endl;
	cout << HASTABLE_Get(table, HASHTABLE_Hashing(15559, 3), 15559) << endl;
	cout << HASTABLE_Get(table, HASHTABLE_Hashing(15510, 3), 15510) << endl;


	return 0;
}

void HASTABLE_Set(HashTable<int, int>* pTable, int pKey,int pOriginKey, int pValue)
{

	pTable->CurrentDataCount++;
	if (pKey > pTable->TableSize)
	{
		pTable->ResizeUp(2);
		cout << pKey << " / " << pTable->TableSize << endl;
		while (pKey > pTable->TableSize)
		{
			cout << pKey << " / /" << pTable->TableSize << endl;
			pTable->ResizeUp(2);
		}

		pTable->Data[pKey].Value = pValue;
		pTable->Data[pKey].Key = pOriginKey;

		return; 
	}
	if (pTable->Data[pKey].Value == NULL)
	{
		pTable->Data[pKey].Value = pValue;
		pTable->Data[pKey].Key = pOriginKey;
	}
	else
	{
		HASTABLE_Set(pTable, pKey + 1, pOriginKey, pValue);
	}
}

int HASTABLE_Get(HashTable<int, int>* pTable, int pKey,int pOriginKey)
{
	if (pTable->Data[pKey].Key == pOriginKey)
	{
		return pTable->Data[pKey].Value;
	}
	else
	{
		return HASTABLE_Get(pTable, pKey + 1, pOriginKey);
	}
}

int HASHTABLE_Hashing(int pKey, int pTableSize)
{
	return (pKey % pTableSize);
}

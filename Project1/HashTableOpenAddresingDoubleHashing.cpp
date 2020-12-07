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
		TableSize *= pRatio;
		Data = (HashNode<K, T>*) realloc(Data, sizeof(HashNode<K, T>) * TableSize);
	}

	void ResizeDown(int pRatio)
	{
		TableSize /= pRatio;
		Data = (HashNode<K, T>*) realloc(Data, sizeof(HashNode<K, T>) * TableSize);
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

void HASTABLE_Set(HashTable<int, int>* pTable, int pKey, int pOriginKey, int pValue , bool isDoubleHash);
int HASTABLE_Get(HashTable<int, int>* pTable, int pKey, int pOriginKey, bool isDoubleHash);

int HASHTABLE_Hashing(int pKey, int pTableSize);
int HASHTABLE_Hashing2(int pKey);

int main()
{
	HashTable<int, int>* table = new HashTable<int, int>(3);
	HASTABLE_Set(table, HASHTABLE_Hashing(36, 3), 36, 555,false);
	HASTABLE_Set(table, HASHTABLE_Hashing(15557, 3), 15557, 2545, false);
	HASTABLE_Set(table, HASHTABLE_Hashing(15559, 3), 15559, 266545, false);
	HASTABLE_Set(table, HASHTABLE_Hashing(15510, 3), 15510, 35635, false);

	cout << HASTABLE_Get(table, HASHTABLE_Hashing(36, 3), 36,false) << endl;
	cout << HASTABLE_Get(table, HASHTABLE_Hashing(15557, 3), 15557, false) << endl;
	cout << HASTABLE_Get(table, HASHTABLE_Hashing(15559, 3), 15559, false) << endl;
	cout << HASTABLE_Get(table, HASHTABLE_Hashing(15510, 3), 15510, false) << endl;


	return 0;
}

void HASTABLE_Set(HashTable<int, int>* pTable, int pKey, int pOriginKey, int pValue, bool isDoubleHash)
{

	pTable->CurrentDataCount++;
	
	int usingKey = pKey;
	if (isDoubleHash)
	{
		usingKey = HASHTABLE_Hashing2(pKey);
	}
	
	if (usingKey > pTable->TableSize)
	{
		pTable->ResizeUp(2);
		while (usingKey > pTable->TableSize)
		{
			pTable->ResizeUp(2);
		}

		pTable->Data[usingKey].Value = pValue;
		pTable->Data[usingKey].Key = pOriginKey;

		return;
	}
	if (pTable->Data[usingKey].Value == NULL)
	{
		pTable->Data[usingKey].Value = pValue;
		pTable->Data[usingKey].Key = pOriginKey;
	}
	else
	{
		HASTABLE_Set(pTable, pKey + 1, pOriginKey, pValue,true);
	}
}

int HASTABLE_Get(HashTable<int, int>* pTable, int pKey, int pOriginKey,bool isDoubleHash)
{
	int usingKey = pKey;
	if (pKey > pTable->TableSize)
	{
		return -1;
	}

	if (isDoubleHash)
	{
		usingKey = HASHTABLE_Hashing2(pKey);
	}
	if (pTable->Data[usingKey].Key == pOriginKey)
	{
		return pTable->Data[usingKey].Value;
	}
	else
	{
		return HASTABLE_Get(pTable, pKey + 1, pOriginKey,true);
	}
}

int HASHTABLE_Hashing(int pKey, int pTableSize)
{
	return (pKey % pTableSize);
}

int HASHTABLE_Hashing2(int pKey)
{
	return (pKey % 11) + 2;
}

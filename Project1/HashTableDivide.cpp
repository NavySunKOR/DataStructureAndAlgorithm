#include<iostream>

using namespace std;

template<typename K, typename T>
class HashNode
{
public : 
	K Key;
	T Value;
};
template<typename K, typename T>
class HashTable
{

public :
	HashNode<K, T>* Data;
	int TableSize;
	int CurrentDataCount;

	HashTable(int pTableSize)
	{
		TableSize = pTableSize;
		Data = new HashNode<K, T>[TableSize];
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

void HASTABLE_Set(HashTable<int, int>* pTable, int pKey, int pValue);

int HASHTABLE_Hashing(int pKey, int pTableSize);

int main()
{
	HashTable<int, int>* table = new HashTable<int,int>(3);
	HASTABLE_Set(table, 36, 555);
	HASTABLE_Set(table, 15557, 2545);

	cout << table->Data[HASHTABLE_Hashing(36, table->TableSize)].Key << " / " << table->Data[HASHTABLE_Hashing(36, table->TableSize)].Value << endl;
	cout << table->Data[HASHTABLE_Hashing(15557, table->TableSize)].Key << " / " << table->Data[HASHTABLE_Hashing(15557, table->TableSize)].Value << endl;


	return 0;
}

void HASTABLE_Set(HashTable<int, int>* pTable, int pKey, int pValue)
{

	pTable->CurrentDataCount++;
	pTable->Data[HASHTABLE_Hashing(pKey, pTable->TableSize)].Value = pValue; 
	pTable->Data[HASHTABLE_Hashing(pKey, pTable->TableSize)].Key = pKey;
}

int HASHTABLE_Hashing(int pKey, int pTableSize)
{
	return (pKey % pTableSize);
}

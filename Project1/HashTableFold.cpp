#include<iostream>

using namespace std;

template<typename K, typename T>
class HashNode
{
public:
	K Key;
	T Value;
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

void HASTABLE_Set(HashTable<char*, int>* pTable, const char* pKey, int pValue);

int HASHTABLE_Hashing(const char* pKey , int pTableSize);

int main()
{
	HashTable<char*, int>* table = new HashTable<char*, int>(3);
	cout << sizeof("ABCD") << endl;

	HASTABLE_Set(table, "ABCD", 555);
	HASTABLE_Set(table, "CCCED", 2545);

	cout << table->Data[HASHTABLE_Hashing("ABCD",table->TableSize)].Key << " / " << table->Data[HASHTABLE_Hashing("ABCD", table->TableSize)].Value << endl;
	cout << table->Data[HASHTABLE_Hashing("CCCED", table->TableSize)].Key << " / " << table->Data[HASHTABLE_Hashing("CCCED", table->TableSize)].Value << endl;


	return 0;
}

void HASTABLE_Set(HashTable<char*, int>* pTable, const char* pKey, int pValue)
{

	pTable->CurrentDataCount++;
	pTable->Data[HASHTABLE_Hashing(pKey, pTable->TableSize)].Value = pValue;
	pTable->Data[HASHTABLE_Hashing(pKey, pTable->TableSize)].Key = (char*)pKey;
}

int HASHTABLE_Hashing(const char* pKey, int pTableSize)
{
	int HashValue = 0;
	int pKeyLength = sizeof(pKey);
	for (int i = 0; i < pKeyLength; i++)
	{
		HashValue += (int)pKey[i];
	}
	return (HashValue % pTableSize);
}

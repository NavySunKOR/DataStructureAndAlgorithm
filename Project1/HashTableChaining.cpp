#include<iostream>

using namespace std;

template<typename K, typename T>
class ChainingData
{
public:
	K key = NULL;
	T Value = NULL;
	ChainingData* Next = NULL;

};

template<typename K, typename T>
class HashNode
{
public : 
	ChainingData<K, T>* Data =NULL;
};

template<typename K, typename T>
class HashTable
{

public:
	HashNode<K, T>* List;
	int TableSize;
	int CurrentDataCount;

	HashTable(int pTableSize)
	{
		TableSize = pTableSize;
		List = new HashNode<K, T>[TableSize];
		CurrentDataCount = 0;
	}

	void Resize(int pRatio)
	{
		if (CurrentDataCount >= TableSize)
		{
			TableSize *= pRatio;
			realloc(List, sizeof(HashNode<K, T>) * TableSize);
		}
		else if (CurrentDataCount < TableSize / pRatio)
		{
			TableSize /= pRatio;
			realloc(List, sizeof(HashNode<K, T>) * TableSize);
		}
	}

};

void HASHTABLE_Set(HashTable<char*, int>* pTable, const char* pKey, int pValue);
ChainingData<char*, int>* HASHTABLE_SetChain(ChainingData<char*, int>* pData, char* pKey, int pValue);
int HASHTABLE_GET(HashTable<char*, int>* pTable, const char* pKey);
int HASHTABLE_GETChain(ChainingData<char*, int>* pData, char* pKey);

int HASHTABLE_Hashing(const char* pKey, int pTableSize);

int main()
{
	HashTable<char*, int>* table = new HashTable<char*, int>(3);
	HASHTABLE_Set(table, "ORCL", 555);
	HASHTABLE_Set(table, "CSCO", 546467);
	cout << HASHTABLE_GET(table, "ORCL") << endl;
	cout << HASHTABLE_GET(table, "CSCO") << endl;

	return 0;
}

void HASHTABLE_Set(HashTable<char*, int>* pTable, const char* pKey, int pValue)
{

	pTable->CurrentDataCount++;
	pTable->List[HASHTABLE_Hashing(pKey, pTable->TableSize)].Data = HASHTABLE_SetChain(pTable->List[HASHTABLE_Hashing(pKey,pTable->TableSize)].Data, (char*)pKey, pValue);
}

ChainingData<char*, int>* HASHTABLE_SetChain(ChainingData<char*, int>* pData, char* pKey, int pValue)
{
	if (pData == NULL )
	{

		pData = new ChainingData<char*, int>;

		cout << "Complete: " << pData << endl;
		pData->key = pKey;
		pData->Value = pValue;
		pData->Next = NULL;
		return pData;
	}
	else
	{
		cout << "Nope" << endl;
		return HASHTABLE_SetChain(pData->Next, pKey, pValue);
	}
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

int HASHTABLE_GET(HashTable<char*, int>* pTable, const char* pKey)
{
	return HASHTABLE_GETChain(pTable->List[HASHTABLE_Hashing(pKey, pTable->TableSize)].Data,(char*)pKey);
}


int HASHTABLE_GETChain(ChainingData<char*, int>* pData, char* pKey)
{
	cout << pData << endl;
	if (pData == NULL)
	{
		return NULL;
	}
	else
	{
		if (strcmp(pData->key,pKey) == 0)
		{
			return pData->Value;
		}
		else
		{
			return HASHTABLE_GETChain(pData->Next, pKey);
		}
	}
}
#include<iostream>
#include <cmath> 

using namespace std;

template<typename T>
class HeapNode
{
public : 
	T Data = NULL;
	HeapNode* Left;
	HeapNode* Right;
};

template<typename T>
class Heap
{
public:
	HeapNode<T>* Nodes;
	int Capacity;
	int UsedSize;

	void Init(int pCapacity)
	{
		Nodes = new HeapNode<T>[pCapacity];
		Capacity = pCapacity;
		UsedSize = 0;
	}
};

void HEAP_AddHeap(Heap<int>* paramHeap, int data);
void HEAP_RemoveMin(Heap<int>* pHeap);
void HEAP_RebuildAt(Heap<int>* pHeap, int pCurrentPosition, int pParentPosition);
void HEAP_RebuildAll(Heap<int>* pHeap);
int HEAP_GetLeftChild(int pCurrentPosition);
void HEAP_Swap(Heap<int>* pHeap, int pPosition1, int pPosition2);
int HEAP_GetParentIndex(int pCurrentIndex);
void HEAP_PrintAll(Heap<int>* pHeap);

int main()
{
	Heap<int>* heap = new Heap<int>;
	heap->Init(3);
	HEAP_AddHeap(heap, 5);
	HEAP_AddHeap(heap, 7);
	HEAP_AddHeap(heap, 9);
	HEAP_AddHeap(heap, 11);
	HEAP_AddHeap(heap, 2);
	HEAP_AddHeap(heap, 34);

	HEAP_PrintAll(heap);

	HEAP_RemoveMin(heap);
	HEAP_PrintAll(heap);
	HEAP_RemoveMin(heap);
	HEAP_PrintAll(heap);
	HEAP_RemoveMin(heap);
	HEAP_PrintAll(heap);
	HEAP_RemoveMin(heap);
	HEAP_PrintAll(heap);
	HEAP_RemoveMin(heap);
	HEAP_PrintAll(heap);

	return 0;
}


void HEAP_AddHeap(Heap<int>* paramHeap, int data)
{
	cout << "Add : " << data << endl;
	paramHeap->Nodes[paramHeap->UsedSize].Data = data;

	int CurrentPosition = paramHeap->UsedSize;
	paramHeap->UsedSize++;


	if (paramHeap->UsedSize < paramHeap->Capacity)
	{
		paramHeap->Capacity *= 2;
		paramHeap->Nodes = (HeapNode<int>*)realloc(paramHeap->Nodes, sizeof(HeapNode<int>) * paramHeap->Capacity);
	}


	HEAP_RebuildAt(paramHeap, CurrentPosition, HEAP_GetParentIndex(CurrentPosition));
}

void HEAP_RemoveMin(Heap<int>* pHeap)
{
	pHeap->Nodes[0].Data = NULL;
	pHeap->UsedSize--;
	HEAP_Swap(pHeap, 0, pHeap->UsedSize );
	HEAP_RebuildAll(pHeap);
}

void HEAP_RebuildAt(Heap<int>* pHeap, int pCurrentPosition, int pParentPosition)
{
	while (pCurrentPosition > 0 && (pHeap->Nodes[pCurrentPosition].Data < pHeap->Nodes[pParentPosition].Data))
	{
		HEAP_Swap(pHeap, pCurrentPosition, pParentPosition);
		pCurrentPosition = pParentPosition;
		pParentPosition = HEAP_GetParentIndex(pCurrentPosition);
	}
}


void HEAP_RebuildAll(Heap<int>* pHeap)
{
	int pCurrentPosition = pHeap->UsedSize - 1 ;
	int pParentPosition = HEAP_GetParentIndex(pHeap->UsedSize - 1);
	while (pCurrentPosition > 0)
	{
		if (pHeap->Nodes[pCurrentPosition].Data < pHeap->Nodes[pParentPosition].Data)
		{
			HEAP_Swap(pHeap, pCurrentPosition, pParentPosition);
		}

		--pCurrentPosition;
		pParentPosition = (pParentPosition != (round(pCurrentPosition / 2) - 1)) ? HEAP_GetParentIndex(pCurrentPosition) : pParentPosition;
	}
}


int HEAP_GetLeftChild(int pCurrentPosition)
{
	return (pCurrentPosition) * 2 + 1;
}

void HEAP_Swap(Heap<int>* pHeap, int pPosition1, int pPosition2)
{
	HeapNode<int> Swaper = pHeap->Nodes[pPosition2];
	pHeap->Nodes[pPosition2] = pHeap->Nodes[pPosition1];
	pHeap->Nodes[pPosition1] = Swaper;
}

int HEAP_GetParentIndex(int pCurrentIndex)
{
	return (pCurrentIndex - 1) / 2;
}

void HEAP_PrintAll(Heap<int>* pHeap)
{
	for (int i = 0; i < pHeap->UsedSize; i++)
	{
		cout << pHeap->Nodes[i].Data;
	}
	cout << endl;
}




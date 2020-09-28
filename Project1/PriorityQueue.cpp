#include<iostream>
#include <cmath> 

using namespace std;

template<typename T>
class QueueNode
{
public : 
	T Data = -1;
	QueueNode* Left;
	QueueNode* Right;
	int Priority = -1;
};

template<typename T>
class PriorityQueue
{
public:
	QueueNode<T>* Nodes;
	int Capacity;
	int UsedSize;

	void Init(int pCapacity)
	{
		Nodes = new QueueNode<T>[pCapacity];
		Capacity = pCapacity;
		UsedSize = 0;
	}
};

void HEAP_Enqueue(PriorityQueue<int>* paramHeap, int data, int pPriority);
void HEAP_Dequeue(PriorityQueue<int>* pHeap, QueueNode<int>* pNode);
void HEAP_RebuildAt(PriorityQueue<int>* pHeap, int pCurrentPosition, int pParentPosition);
void HEAP_RebuildAll(PriorityQueue<int>* pHeap);
int HEAP_GetLeftChild(int pCurrentPosition);
void HEAP_Swap(PriorityQueue<int>* pHeap, int pPosition1, int pPosition2);
int HEAP_GetParentIndex(int pCurrentIndex);
void HEAP_PrintAll(PriorityQueue<int>* pHeap);

int main()
{
	PriorityQueue<int>* pQueue = new PriorityQueue<int>;
	pQueue->Init(3);
	HEAP_Enqueue(pQueue, 2, 1000);
	HEAP_Enqueue(pQueue, 5,35);
	HEAP_Enqueue(pQueue, 7,11);
	HEAP_Enqueue(pQueue, 9,350);
	HEAP_Enqueue(pQueue, 11,477);
	HEAP_Enqueue(pQueue, 34,500);

	QueueNode<int> Node;
	HEAP_Dequeue(pQueue,&Node);
	cout << Node.Data << endl;
	HEAP_Dequeue(pQueue, &Node);
	cout << Node.Data << endl;
	HEAP_Dequeue(pQueue, &Node);
	cout << Node.Data << endl;
	HEAP_Dequeue(pQueue, &Node);
	cout << Node.Data << endl;
	HEAP_Dequeue(pQueue, &Node);
	cout << Node.Data << endl;
	HEAP_Dequeue(pQueue, &Node);
	cout << Node.Data << endl;
	return 0;
}


void HEAP_Enqueue(PriorityQueue<int>* paramHeap, int data,int pPriority)
{
	cout << "Add : " << data << endl;
	paramHeap->Nodes[paramHeap->UsedSize].Data = data;
	paramHeap->Nodes[paramHeap->UsedSize].Priority = pPriority;

	int CurrentPosition = paramHeap->UsedSize;
	paramHeap->UsedSize++;


	if (paramHeap->UsedSize < paramHeap->Capacity)
	{
		paramHeap->Capacity *= 2;
		paramHeap->Nodes = (QueueNode<int>*)realloc(paramHeap->Nodes, sizeof(QueueNode<int>) * paramHeap->Capacity);
	}


	HEAP_RebuildAt(paramHeap, CurrentPosition, HEAP_GetParentIndex(CurrentPosition));

	HEAP_PrintAll(paramHeap);
}

void HEAP_Dequeue(PriorityQueue<int>* pHeap,QueueNode<int>* pNode)
{
	memcpy(pNode,&pHeap->Nodes[0],sizeof(QueueNode<int>));

	pHeap->Nodes[0].Data = -1;
	pHeap->Nodes[0].Priority = -1;
	pHeap->UsedSize--;
	HEAP_Swap(pHeap, 0, pHeap->UsedSize );
	HEAP_RebuildAll(pHeap);
}

void HEAP_RebuildAt(PriorityQueue<int>* pHeap, int pCurrentPosition, int pParentPosition)
{
	while (pCurrentPosition > 0 && (pHeap->Nodes[pCurrentPosition].Priority < pHeap->Nodes[pParentPosition].Priority))
	{
		HEAP_Swap(pHeap, pCurrentPosition, pParentPosition);
		pCurrentPosition = pParentPosition;
		pParentPosition = HEAP_GetParentIndex(pCurrentPosition);
	}
}


void HEAP_RebuildAll(PriorityQueue<int>* pHeap)
{
	int pCurrentPosition = pHeap->UsedSize - 1 ;
	int pParentPosition = HEAP_GetParentIndex(pHeap->UsedSize - 1);
	while (pCurrentPosition > 0)
	{
		if (pHeap->Nodes[pCurrentPosition].Priority < pHeap->Nodes[pParentPosition].Priority)
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

void HEAP_Swap(PriorityQueue<int>* pHeap, int pPosition1, int pPosition2)
{
	QueueNode<int> Swaper = pHeap->Nodes[pPosition2];
	pHeap->Nodes[pPosition2] = pHeap->Nodes[pPosition1];
	pHeap->Nodes[pPosition1] = Swaper;
}

int HEAP_GetParentIndex(int pCurrentIndex)
{
	return (pCurrentIndex - 1) / 2;
}

void HEAP_PrintAll(PriorityQueue<int>* pHeap)
{
	for (int i = 0; i < pHeap->UsedSize; i++)
	{
		cout << pHeap->Nodes[i].Data << ",";
	}
	cout << endl;
}




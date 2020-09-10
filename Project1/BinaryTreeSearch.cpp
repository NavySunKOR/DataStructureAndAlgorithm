#include<iostream>

using namespace std;

template<typename T>
class BTNode
{
public :
	BTNode(T pValue)
	{
		data = pValue;
	}
	T data;
	BTNode* Left = NULL;
	BTNode* Right = NULL;

};

BTNode<int>* SearchItem(BTNode<int>* Root, int pSearch)
{
	if (Root == NULL)
	{
		return NULL;
	}

	if (Root->data == pSearch)
	{
		return Root;
	}
	else if (Root->data <pSearch)
	{
		return SearchItem(Root->Right, pSearch);
	}
	else
	{
		return SearchItem(Root->Left, pSearch);
	}
}

void InsertItem(BTNode<int>* Root, int pData)
{
	if (Root->data > pData)
	{
		//Left
		if (Root->Left == NULL)
		{
			Root->Left = new BTNode<int>(pData);
		}
		else
		{
			InsertItem(Root->Left,pData);
		}
	}
	else
	{
		//Right
		if (Root->Right == NULL)
		{
			Root->Right = new BTNode<int>(pData);
		}
		else
		{
			InsertItem(Root->Right, pData);
		}
	}
}

void PrintOutAll(BTNode<int>* Root)
{
	cout << Root->data << endl;
	if (Root->Left != NULL)
	{
		PrintOutAll(Root->Left);
	}

	if (Root->Right != NULL)
	{
		PrintOutAll(Root->Right);
	}
}


void DisallocateAll(BTNode<int>* Root)
{
	if (Root->Left != NULL)
	{
		DisallocateAll(Root->Left);
	}
	if (Root->Right != NULL)
	{
		DisallocateAll(Root->Right);
	}

	cout << "Bye! : " << Root->data << endl;

	delete Root;
}

BTNode<int>* RemoveAndRelocateData(BTNode<int>* Current, BTNode<int>* Parent, int pValue)
{
	BTNode<int>* Removal;
	if (Current == NULL)
		return NULL;
	if (Current -> data < pValue)
	{
		Removal = RemoveAndRelocateData(Current->Right, Current, pValue);
	}
	else if (Current->data > pValue)
	{
		Removal = RemoveAndRelocateData(Current->Left, Current, pValue);
	}
	else
	{
		//일치한것 삭제.

		//일치 한 것의 오른쪽 노드를 타서 - 1번
			//일치 한 것의 자리에 오른쪽 노드 들 중 최소 값을 대입 - 2번
			//해당 최소의 데이터가 엠티 해버리고 여기서 만약에 최소에 데이터가 또 있다면 루프 돌아서 1번으로 돌아감 - 3번

	}


}

void DisallocateEmpty(BTNode<int>* Root)
{
	if (Root->Left != NULL)
	{
		DisallocateEmpty(Root->Left);
	}
	if (Root->Right != NULL)
	{
		DisallocateEmpty(Root->Right);
	}

	if (Root->data == NULL)
	{
		cout << "Another one is down" << endl;
		delete Root;
	}

}





int main()
{
	//전제조건! - 데이터는 왼쪽 오른쪽이 정렬이 되어있어야한다. 들어간 값은 원래 값보다 작으면 왼쪽, 크면 오른쪽이다. 이 이후에 넣는 값들이 맨 처음 넣은 값보다 더 커지거나 작아지면 안됨.
	BTNode<int>* Tree = new BTNode<int>(5);
	InsertItem(Tree, 6);
	InsertItem(Tree, 4);
	InsertItem(Tree, 7);
	InsertItem(Tree, 8);
	InsertItem(Tree, 3);
	InsertItem(Tree, 2);



	PrintOutAll(Tree);


	DisallocateAll(Tree);

	return 0;
}

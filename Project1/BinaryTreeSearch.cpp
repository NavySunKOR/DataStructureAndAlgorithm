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
		//��ġ�Ѱ� ����.

		//��ġ �� ���� ������ ��带 Ÿ�� - 1��
			//��ġ �� ���� �ڸ��� ������ ��� �� �� �ּ� ���� ���� - 2��
			//�ش� �ּ��� �����Ͱ� ��Ƽ �ع����� ���⼭ ���࿡ �ּҿ� �����Ͱ� �� �ִٸ� ���� ���Ƽ� 1������ ���ư� - 3��

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
	//��������! - �����ʹ� ���� �������� ������ �Ǿ��־���Ѵ�. �� ���� ���� ������ ������ ����, ũ�� �������̴�. �� ���Ŀ� �ִ� ������ �� ó�� ���� ������ �� Ŀ���ų� �۾����� �ȵ�.
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

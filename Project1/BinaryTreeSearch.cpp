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

BTNode<int>* InsertItem(BTNode<int>* Root, int pData)
{

}


int main()
{
	//��������! - �����ʹ� ���� �������� ������ �Ǿ��־���Ѵ�. �� ���� ���� ������ ������ ����, ũ�� �������̴�. �� ���Ŀ� �ִ� ������ �� ó�� ���� ������ �� Ŀ���ų� �۾����� �ȵ�.
	BTNode<int>* Tree = new BTNode<int>(5);
	Tree->Left = new BTNode<int>(3);
	Tree->Right = new BTNode<int>(6);

	Tree->Left->Left = new BTNode<int>(8);
	Tree->Left->Right = new BTNode<int>(2);





	return 0;
}

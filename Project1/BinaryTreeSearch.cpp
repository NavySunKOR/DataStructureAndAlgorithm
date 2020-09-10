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
	//전제조건! - 데이터는 왼쪽 오른쪽이 정렬이 되어있어야한다. 들어간 값은 원래 값보다 작으면 왼쪽, 크면 오른쪽이다. 이 이후에 넣는 값들이 맨 처음 넣은 값보다 더 커지거나 작아지면 안됨.
	BTNode<int>* Tree = new BTNode<int>(5);
	Tree->Left = new BTNode<int>(3);
	Tree->Right = new BTNode<int>(6);

	Tree->Left->Left = new BTNode<int>(8);
	Tree->Left->Right = new BTNode<int>(2);





	return 0;
}

#pragma once
enum color { Red = 0, Black };

template <typename TKey, typename TData>
class RBTree
{
public:
	RBTree();
	~RBTree();
	void Insert(TKey Key, TData Data);
	void Delete(TKey Key);
	TData* Find(TKey Key);
private:
	struct Node
	{
		Node(const TKey& Key, const TData& Data, Node* Parent);
		~Node();
		color _Color;
		Node* _Link[2];
		Node* _Parent;
		TKey _Key;
		TData _Data;
	};
	Node* _Root;
};


template<typename TKey, typename TData>
inline RBTree<TKey, TData>::RBTree() :
	_Root(nullptr)
{

}

template<typename TKey, typename TData>
inline RBTree<TKey, TData>::~RBTree()
{
	delete _Root;
}

template<typename TKey, typename TData>
inline void RBTree<TKey, TData>::Insert(TKey Key, TData Data)
{
	Node* pNode = nullptr;
	Node* pParent = nullptr;
	Node* pUncle = nullptr;
	Node* pGrandparent = nullptr;
	Node* T = nullptr;
	int Dir;
	int PDir;
	if (!_Root)
	{
		_Root = new Node(Key, Data, nullptr);
		_Root->_Color = Black;
	}
	else
	{
		pNode = _Root;
		while (pNode)
		{
			pParent = pNode;
			Dir = Key > pNode->_Key;
			pNode = pNode->_Link[Dir];
		}
		pParent->_Link[Dir] = new Node(Key, Data, pParent);
		pNode = pParent->_Link[Dir];

		TKey k;
		TData d;
		Node* n;
		while (pNode->_Parent && pNode->_Parent != _Root && pParent->_Color == Red)
		{
			pGrandparent = pParent->_Parent;
			PDir = pParent->_Data > pGrandparent->_Data;
			pUncle = pGrandparent->_Link[!PDir];

			if ((pUncle != nullptr) && (pUncle->_Color == Red))
			{
				pGrandparent = pParent->_Parent;
				PDir = pParent->_Data > pGrandparent->_Data;
				pUncle = pGrandparent->_Link[!PDir];

				pParent->_Color = Black;
				pUncle->_Color = Black;
				pGrandparent->_Color = Red;

				pNode = pGrandparent;
			}
			else if ((pGrandparent->_Link[!PDir] == nullptr) || (pGrandparent->_Link[!PDir]->_Color == Black))
			{
				if (Dir != PDir)
				{
					k = pGrandparent->_Key;
					d = pGrandparent->_Data;
					pGrandparent->_Key = pNode->_Key;
					pGrandparent->_Data = pNode->_Data;
					pNode->_Key = k;
					pNode->_Data = d;
					n = pGrandparent->_Link[!PDir];
					pGrandparent->_Link[!PDir] = pNode;
					pNode->_Parent = pGrandparent;
					pNode->_Link[Dir] = n;
					if (n)
					{
						n->_Parent = pNode;
					}
					pParent->_Link[Dir] = nullptr;
				}
				else
				{
					k = pGrandparent->_Key;
					d = pGrandparent->_Data;
					pGrandparent->_Key = pParent->_Key;
					pGrandparent->_Data = pParent->_Data;
					pParent->_Key = k;
					pParent->_Data = d;
					n = pGrandparent->_Link[!PDir];
					pGrandparent->_Link[!PDir] = pParent;
					pGrandparent->_Link[PDir] = pNode;
					pNode->_Parent = pGrandparent;
					pParent->_Link[Dir] = pParent->_Link[!Dir];
					pParent->_Link[!Dir] = n;
					if (n)
					{
						n->_Parent = pParent;
					}
				}
			}
			pNode = pGrandparent;
			pParent = pNode->_Parent;
		}
		_Root->_Color = Black;
	}
}

template<typename TKey, typename TData>
inline void RBTree<TKey, TData>::Delete(TKey Key)
{

}

template<typename TKey, typename TData>
inline TData* RBTree<TKey, TData>::Find(TKey Key)
{
	Node* pNode = _Root;
	int Dir;
	if (!_Root)
	{
		return nullptr;
	}
	while (pNode)
	{
		if (Key == pNode->_Key)
		{
			return &pNode->_Data;
		}
		else
		{
			Dir = Key > pNode->_Key;
			pNode = pNode->_Link[Dir];
		}
	}
	return nullptr;
}

template<typename TKey, typename TData>
inline RBTree<TKey, TData>::Node::Node(const TKey& Key, const TData& Data, Node* Parent) :
	_Color(Red), _Parent(Parent), _Link(), _Key(Key), _Data(Data)
{

}


template<typename TKey, typename TData>
inline RBTree<TKey, TData>::Node::~Node()
{
	delete _Link[0];
	delete _Link[1];
}


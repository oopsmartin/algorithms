typedef struct BinTree{
	int value;
	struct BinTree* pLeft;
	struct BinTree* pRight;
}BinTree;

void insert(BinTree** root, int value);
void traverse(BinTree* root);
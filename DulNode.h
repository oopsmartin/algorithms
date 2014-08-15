typedef struct DulNode{
	int value;
	struct DulNode* prev;
	struct DulNode* next;
}DulNode;

void insert(DulNode** root, int value);
void traverse(DulNode* root);
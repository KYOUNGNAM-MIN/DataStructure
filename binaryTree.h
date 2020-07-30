class Tree;
class TreeNode {
	friend class Tree;
private:
	int data;
	TreeNode* leftChild;
	TreeNode* rightChild;
public:
	TreeNode(int ndata = 0, TreeNode* nleftChild = 0, TreeNode* nrightChild = 0) {
		data = ndata;
		leftChild = nleftChild;
		rightChild = nrightChild;
	}
};
class Tree {
private:
	TreeNode* root;
public:
	void CreateSimple();
	void printAll();
	void preorder(TreeNode* c);
	void inorder(TreeNode* c);
	void postorder(TreeNode* c);
	void visit(TreeNode* c);
	void Create();
	TreeNode* getRoot();
};
void Tree::CreateSimple() {
	//1 2 3 넣기
	root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
}
void Tree::Create() {
	//1 2 3 4 5 넣기
	root = new TreeNode(1, new TreeNode(2,new TreeNode(4),new TreeNode(5)), new TreeNode(3));
}
void Tree::printAll() {
	cout << root->data << endl;
	cout << root->leftChild->data << endl;
	cout << root->rightChild->data << endl;
}
void Tree::preorder(TreeNode* c) {
	if (c) {
		visit(c);
		preorder(c->leftChild);
		preorder(c->rightChild);
	}
}
void Tree::inorder(TreeNode* c) {
	if (c) {
		inorder(c->leftChild);
		visit(c);
		inorder(c->rightChild);
	}
}
void Tree::postorder(TreeNode* c) {
	if (c) {
		postorder(c->leftChild);
		postorder(c->rightChild);
		visit(c);
	}
}
void Tree::visit(TreeNode* c) {
	cout << c->data << endl;
}
TreeNode* Tree::getRoot() {
	return root;
}
#include <iostream>
#include <vector>

using namespace std;

//references: mycodeschool, geeksofrgeeks, code standard
struct NODE{
	int data;
	NODE* leftChild;
	NODE* rightChild;
};

//DFS algorithm: geeksforgeeks
int DFS_Algortihm(NODE* node){
	if (node == nullptr){
		return 0;
	}
	else {
		int leftDepth = DFS_Algortihm(node->leftChild);
		int rightDepth = DFS_Algortihm(node->rightChild);
		
		if (leftDepth > rightDepth)
			return (leftDepth + 1);
		else
			return (rightDepth + 1);
	}
}

//function to build the tree based on the input file
NODE* buildTree(int n) {
	vector<NODE> nodes(n + 1);
    NODE* root = nullptr;

    for (int i = 0; i < n; i++) {
        int nr, left, right;
        cin >> nr >> left >> right;

        nodes[nr].data = nr;

        if (left != 0)
            nodes[nr].leftChild = &nodes[left];

        if (right != 0)
            nodes[nr].rightChild = &nodes[right];

        if (i == 0)
            root = &nodes[nr];
    }
	
    return root;
}

int main()
{
	int n;
	cin >> n;

	NODE* root = buildTree(n);

	int depth = DFS_Algortihm(root);
	cout << "depth is " << depth << endl;
	return 0;
}

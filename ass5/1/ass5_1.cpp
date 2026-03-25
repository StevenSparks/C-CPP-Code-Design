#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int number;
	int left = 0;
	int right = 0;
};
//couldnt be bothered to implement my mlist api made in ass 4 even though it could work
//so vector it is
vector <Node> tree;
int depth = 0;

void preorderTraversal(int nodeNr, int traversalDepth)
{
	Node node = tree[nodeNr-1];
	if(node.left != 0)
	{
		preorderTraversal(node.left, (traversalDepth+1));
	}
	if(node.right != 0)
	{
		preorderTraversal(node.right, (traversalDepth+1));
	}
	if(traversalDepth > depth)
	{
		depth = traversalDepth;
	}
}

int main()
{
	int n;
	cin >> n;

	for(int i=0;i<n;i++)
	{
		int nr, left, right;
		cin >> nr >> left >> right;

		/*create nodes here*/
		Node node;
		node.number = nr;
		node.left = left;
		node.right = right;
		tree.push_back(node);
	}
	
	preorderTraversal(1,1);

	/* implement your algorithm and store the tree depth in depth */
	cout << "depth is " << depth << endl;
	return 0;
}

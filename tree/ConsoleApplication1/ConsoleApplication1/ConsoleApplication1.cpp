#include<iostream>
using namespace std;

class Binary_tree
{
private:
	struct node
	{
		int item;
		node* left;
		node* right;
	};

	node* root;
	void inorder(node* p);
	void preorder(node* p);
	void postorder(node* p);
	void delete_from_tree(node*& p);
	int hight(node* p);
	void clear(node*& p);
	int nodecount(node* p);
	int leaves_count(node* p);


	public:

		Binary_tree()
		{
			root = NULL;
		}




		bool isempty()
		{
			if (root == NULL)
				return 1;
			else return 0;
		}











	void insert(int element)
	{
		node* newnode = new node;
		node* cur;
		node* trial_cur = NULL;

		newnode->item = element;
		newnode->left = NULL;
		newnode->right = NULL;

		if (root == NULL)
		{
			root = newnode;
		}
	 
		else
		{
			cur = root;

			while (cur != NULL)
			{
				trial_cur = cur;
				if (cur->item == element)
				{
					cout << "this item are exist \n";
					return;
				}
				else
				{
					if (cur->item > element)
						cur = cur->left;
					else
						cur = cur->right;
				}
			}

			if (trial_cur->item > element)
				trial_cur->left = newnode;
			else
				trial_cur->right = newnode;
		}

	}





	void inorder_travers()
	{
		  inorder(root);
	}
	 
	void preorder_travers()
	{
		preorder(root);
	}

	void postorder_travers()
	{
		postorder(root);
	}




	bool search(int element)
	{
		node* cur = root;
		while (cur!=NULL)
		{		 
			if (cur->item == element)
				return true;
			else if (cur->item > element)
				cur = cur->left;
			else
				cur = cur->right;
		}
		return false;
	}





	void remove(int element)
	{
		node* cur; 
		node* t=NULL;

		if (root == NULL)
		{
			cout << "empty tree \n";
			return;
		}

		if (root->item == element)
		{
			delete_from_tree(root);
			return;
		}




		t = root;
		if (root->item > element)
			cur = root->left;
		else
			cur = root->right;



		while (cur != NULL)
		{
			if (cur->item == element)
				break;
			else
			{
				t = cur;
				if (cur->item > element)
					cur = cur->left;
				else
					cur = cur->right;
			}
		}


		if (cur == NULL)
			cout << "not found \n";
		else if (t->item > element)
			delete_from_tree(t->left);
		else
			delete_from_tree(t->right);
	}



	int max_item()
	{
		node* cur;
		cur = root;
		while (cur->right != NULL)
		{
			cur = cur->right;
		}

		return cur->item;
	}








	int min_item()
	{
		node* cur;
		cur = root;

		while (cur->left != NULL)
		{
			cur = cur->left;
		}
		return cur->item;
	}





	int hight_tree()
	{
		return hight(root);
	}
 



	void clear_tree()
	{
		clear(root);
	}




	int count_node_tree()
	{
		return nodecount(root);
	}




	int leaves_count_tree()
	{
		return leaves_count(root);
	}

};

 

void Binary_tree::inorder(node* p)
{
	 
	if (p != NULL) {
		inorder(p->left);
     	cout << p->item <<" ";
		inorder(p->right);
	}
}

void Binary_tree::preorder(node* p)
{
	if (p != NULL)
	{
		cout << p->item<<" ";
		preorder(p->left);
		preorder(p->right);
	}
}
 


void Binary_tree::postorder(node*p)
{
	if (p != NULL)
	{
		postorder(p->left);
		postorder(p->right);
		cout << p->item << " ";
	}
}



void Binary_tree::delete_from_tree(node*& p)
{
	node* cur;
	node* t_cur;
	node* temp;

	if (p->left == NULL && p->right == NULL)
	{
		delete p;
		p = NULL;
	}

	else if (p->left == NULL)
	{
		temp = p;
		p = p->right;
		delete temp;		 
	}


	else if (p->right == NULL)
	{
		 
		temp = p;
		p = p->left;
		delete temp;
	}


	else
	{
		cur = p->left;
		t_cur = NULL;

		while (cur->right != NULL)
		{
			t_cur = cur;
			cur = cur->right;
		}
		 
			p->item = cur->item;

		if (t_cur == NULL)		 
			p->left = cur->left;
			 		 
		else
			t_cur->right = cur->left;
	}



 
}


int Binary_tree::hight(node* p)
{
	if (p == NULL)
		return -1;

	int l = hight(p->left);
	int r = hight(p->right);
	return l > r ? l + 1 : r + 1;
}



void Binary_tree::clear(node*& p)
{
	if (p != NULL)
	{
		clear(p->left);
		clear(p->right);
		delete p;
		p = NULL;
	}

}







int Binary_tree::nodecount(node* p)
{
	if (p == NULL)
		return 0;
	return 1 + nodecount(p->left) + nodecount(p->right) ;
	
}







int Binary_tree::leaves_count(node* p)
{
	if (p == NULL)
		return 0;
	else if (p->left == NULL && p->right == NULL)
		return 1;
	else
		return leaves_count(p->left) + leaves_count(p->right);

}





int main()
{

	Binary_tree t;
	t.insert(40);
	t.insert(30);
	t.insert(50);
	t.insert(20);
	t.insert(10);
	t.insert(35);
	t.insert(60);
	t.insert(45);
	//t.insert(47);
	//t.insert(43);

	t.inorder_travers();
	cout << "\n hight is : " << t.hight_tree() << "\n";
	 
	 cout << "\n=========================\n";

	 t.preorder_travers();

	 cout << "\n============================\n";

	 t.postorder_travers();

	 cout << "\n============================\n";

	 cout<< t.search(45);

	 cout << "\n============================\n";

	// t.remove(45);
	 t.inorder_travers();

	 cout << "\n ========================= \n";

	cout<<"max element is :" << t.max_item();
	cout << "\nmin element is :" << t.min_item();
	cout << "\n count node is : " << t.count_node_tree();
	cout << "\n tree leaves count is : " << t.leaves_count_tree();

	 cout << "\n\n========================= ";
	 cout << "\n========================= \n";
	 Binary_tree t1;
	 t1.insert(10);
	 t1.insert(20);
	 t1.insert(15);

	 t1.inorder_travers();

	 cout << "\n ========================= \n";

	 t1.remove(20);
	 t1.inorder_travers();
	 t1.clear_tree();

	 cout << "\n=====\n";
	 t1.inorder_travers();
	return 0;
}








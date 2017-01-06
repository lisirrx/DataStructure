#include<iostream>
#include<stack>
#include<string>
#include<cstring>

using namespace std;

class Node
{
public:
	char oper;
	Node *left;
	Node *right;

	Node():
			left(NULL),right(NULL),oper(0)
	{}
	Node(char op)
			:left(NULL),right(NULL),oper(op)
	{}
};

bool is_oper(char op)
{
	char oper[]={'(',')','+','-','*','/'};
	for(int i=0;i<strlen(oper);i++)
	{
		if(op==oper[i])
			return true;
	}
	return false;
}

int get_oper_pri(char op)
{
	switch(op)
	{
		case '(':
			return 1;
			break;
		case '+':
		case '-':
			return 2;
			break;
		case '*':
		case '/':
			return 3;
			break;
		default:
			return 0;
	}
}


void free_tree(Node*& p)
{
	if(p->left != NULL)
		free_tree(p->left);
	if(p->right != NULL)
		free_tree(p->right);
	delete(p);
}

void pre_order_traverse(Node *p)
{
	if(p!=NULL)
	{
		cout<<p->oper;
		pre_order_traverse(p->left);
		pre_order_traverse(p->right);
	}
}

void pos_order_traverse(Node *p)
{
	if(p!=NULL)
	{
		pos_order_traverse(p->left);
		pos_order_traverse(p->right);
		cout << p->oper;
	}
}

void in_order_traverse(Node *p)
{
	if(p)
	{
		if(p->left)
		{
			if(is_oper(p->left->oper)&&get_oper_pri(p->left->oper)<get_oper_pri(p->oper))
			{
				cout<<"(";
				in_order_traverse(p->left);
				cout<<")";
			}
			else
				in_order_traverse(p->left);
		}
		cout<<p->oper;
		if(p->right)
		{
			if(is_oper(p->right->oper)&&get_oper_pri(p->right->oper)<=get_oper_pri(p->oper))
			{
				cout<<"(";
				in_order_traverse(p->right);
				cout<<")";
			}
			else
				in_order_traverse(p->right);
		}
	}
}



void generate_tree(Node*& p, string expr)
{
	stack <char> oper_stack;
	stack <Node*> data_stack;
	char tmpchr,c;
	int idx=0;
	tmpchr=expr[idx++];
	while(oper_stack.size()!=0 || tmpchr!='\0')
	{
		if(tmpchr!='\0' && !is_oper(tmpchr))
		{
			p=new Node(tmpchr);
			data_stack.push(p);
			tmpchr=expr[idx++];
		}
		else
		{
			switch(tmpchr)
			{
				case '(':
					oper_stack.push('(');
					tmpchr=expr[idx++];
					break;
				case ')':
					while(true)
					{
						c=oper_stack.top();
						oper_stack.pop();
						if(c=='(')
						{
							break;
						}
						p=new Node(c);
						if(data_stack.size())
						{
							p->right=data_stack.top();
							data_stack.pop();
						}
						if(data_stack.size())
						{
							p->left=data_stack.top();
							data_stack.pop();
						}
						data_stack.push(p);
					}
					tmpchr=expr[idx++];
					break;
				default:
					if(oper_stack.size()==0 || tmpchr!='\0' && get_oper_pri(oper_stack.top())< get_oper_pri(tmpchr))
					{
						oper_stack.push(tmpchr);
						tmpchr=expr[idx++];
					}
					else
					{
						p=new Node(oper_stack.top());
						p->oper=oper_stack.top();
						if(data_stack.size())
						{
							p->right=data_stack.top();
							data_stack.pop();
						}
						if(data_stack.size())
						{
							p->left=data_stack.top();
							data_stack.pop();
						}
						data_stack.push(p);
						oper_stack.pop();
					}
					break;
			}
		}
	}
	p=data_stack.top();
	data_stack.pop();
}


int main()
{
	string expression;
	Node* tree;

	cout<<"Please input the expression";
	cin>>expression;
	generate_tree(tree,expression);

	cout<<"Polish notation: ";
	pre_order_traverse(tree);
	cout<<endl;

	cout<<"Infix Notation: ";
	in_order_traverse(tree);
	cout<<endl;

	cout<<"Reverse Polish notation: ";
	pos_order_traverse(tree);
	cout<<endl;

	free_tree(tree);
	cout<<endl;

	return 0;
}

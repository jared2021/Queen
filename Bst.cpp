#include <cmath>
#include <iostream>
int main()
{
	int array[15];
	array[0]=6;
	array[1]=17;
	array[2]=20;
	array[3]=41;
	array[4]=45;
	array[5]=52;
	array[6]=57;
	array[7]=65;
	array[8]=71;
	array[9]=76;
	array[10]=79;
	array[11]=87;
	array[12]=92;
	array[13]=95;
	array[14]=99;
	int size=15;
	struct node
	{
		int key;
		node *parent;
		node *left;
		node *right;
	}a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,*temp;
	a.parent=nullptr;
	a.left=&b;
	a.right=&c;

	b.parent=&a;
	b.left=&d;
	b.right=&e;

	c.parent=&a;
	c.left=&f;
	c.right=&g;

	d.parent=&b;
	d.left=&h;
	d.right=&i;

	e.parent=&b;
	e.left=&j;
	e.right=&k;

	f.parent=&c;
	f.left=&l;
	f.right=&m;

	g.parent=&c;
	g.left=&n;
	g.right=&o;

	h.parent=&d;
	h.left=nullptr;
	h.right=nullptr;

	i.parent=&d;
	i.left=nullptr;
	i.right=nullptr;

	j.parent=&e;
	j.left=nullptr;
	j.right=nullptr;

	k.parent=&e;
	k.left=nullptr;
	k.right=nullptr;

	l.parent=&f;
	l.left=nullptr;
	l.right=nullptr;

	m.parent=&f;
	m.left=nullptr;
	m.right=nullptr;

	n.parent=&g;
	n.left=nullptr;
	n.right=nullptr;

	o.parent=&g;
	o.left=nullptr;
	o.right=nullptr;

	int variable=floor(size/2);
	a.key=array[variable];
	variable=floor(variable/2);
	b.key=array[variable];
	d.key=array[variable-2];
	e.key=array[variable+2];
	h.key=array[variable-3];
	i.key=array[variable-1];
	j.key=array[variable+1];
	k.key=array[variable+3];

	int array2 [7];
	array2[0]=71;
	array2[1]=76;
	array2[2]=79;
	array2[3]=87;
	array2[4]=92;
	array2[5]=95;
	array2[6]=99;
	size=7;
	variable=floor(size/2);
	c.key=array2[variable];
	f.key=array2[variable-2];
	g.key=array2[variable+2];
	l.key=array2[variable-3];
	m.key=array2[variable-1];
	n.key=array2[variable+1];
	o.key=array2[variable+3];

	//std::cout<<a.key<<"|"<<b.key<<"|"<<c.key<<"|"<<d.key<<"|"<<e.key<<"|"<<f.key<<"|"<<g.key<<"|"<<h.key<<"|"<<i.key<<"|"<<j.key<<"|"<<k.key<<"|"<<l.key<<"|"<<m.key<<"|"<<n.key<<"|"<<o.key<<"|"<<'\n';
	std::cout<<"Which element would you like to find (1-15)";
	int kth;
	std::cin>>kth;
	temp=&a;
	while(temp->left!=nullptr)
	{
		temp=temp->left;	
	}
	//if(kth==1)
	//{
		//std::cout<<"The "<<kth<<" element is "<<temp->key;
	//}
	//else
	//{
		int count=1;
		while(count!=kth)
		{
			if(count==3&&count!=kth||count==11&&count!=kth)
			{
				temp=temp->parent;
				count=count+1;
				if(count!=kth)
				{
					temp=temp->right;
					temp=temp->left;
					count=count+1;
				}
			}
			else if(count==7&&count!=kth)
			{
				while(temp->parent!=nullptr)
				{
					temp=temp->parent;
				}
				count=count+1;
			}
			else if(count==8&&count!=kth)
			{
				temp=temp->right;
				while(temp->left!=nullptr)
				{
					temp=temp->left;
				}
				count=count+1;
			}
			else
			{
				temp=temp->parent;
				count=count+1;
				if(count!=kth)
				{
					temp=temp->right;
					count=count+1;
					if(count!=kth)
					{
						temp=temp->parent;
					}
				}
			}
		}
	//}
	//std::cout<<temp->key;
	std::cout<<"The "<<kth<<" element is "<<temp->key;
}

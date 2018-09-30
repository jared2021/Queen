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
	e.right=nullptr;
	e.left=nullptr;

	f.parent=&c;
	f.left=nullptr;
	f.right=nullptr;

	g.parent=&c;
	g.left=&j;
	g.right=&k;

	h.parent=&d;
	h.left=&l;
	h.right=&m;

	i.parent=&d;
	i.left=nullptr;
	i.right=nullptr;

	j.parent=&g;
	j.left=nullptr;
	j.right=nullptr;

	k.parent=&g;
	k.left=&n;
	k.right=&o;

	l.parent=&h;
	l.left=nullptr;
	l.right=nullptr;

	m.parent=&h;
	m.left=nullptr;
	m.right=nullptr;

	n.parent=&k;
	n.left=nullptr;
	n.right=nullptr;

	o.parent=&k;
	o.left=nullptr;
	o.right=nullptr;

	int variable=floor(size/2);
	a.key=array[variable];
	b.key=array[variable-2];
	c.key=array[variable+2];
	d.key=array[variable-4];
	e.key=array[variable-1];
	f.key=array[variable+1];
	g.key=array[variable+4];
	h.key=array[variable-6];
	i.key=array[variable-3];
	j.key=array[variable+3];
	k.key=array[variable+6];
	l.key=array[variable-7];
	m.key=array[variable-5];
	n.key=array[variable+5];
	o.key=array[variable+7];

	std::cout<<a.key<<"|"<<b.key<<"|"<<c.key<<"|"<<d.key<<"|"<<e.key<<"|"<<f.key<<"|"<<g.key<<"|"<<h.key<<"|"<<i.key<<"|"<<j.key<<"|"<<k.key<<"|"<<l.key<<"|"<<m.key<<"|"<<n.key<<"|"<<o.key<<"|";

	std::cout<<"Which element would you like to find (1-15)";
	int kth;
	std::cin>>kth;
	temp=&a;
	while(temp->left!=nullptr)
	{
		temp=temp->left;	
	}
	if(kth==1)
	{
		std::cout<<"The "<<kth<<" element is "<<temp->key;
	}
	else if(kth>1&&kth<9)
	{
		int count=1;
		while(count!=kth&&count!=8)
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
	else if(kth>8&&kth<15)
	{
		temp=&a;
		int count=8;
		while(count!=kth)
		{
			temp=temp->right;
			temp=temp->left;
			count=count+1;
			if(count!=kth)
			{
				temp=temp->parent;
				count=count+1;
			}
		}
	}
	else if(kth==15)
	{
		temp=&a;
		while(temp->right!=nullptr)
		{
			temp=temp->right;
		}
		std::cout<<temp->key;
	}
	std::cout<<"The "<<kth<<" element is "<<temp->key;
}

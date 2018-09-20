#include <stack>
#include <iostream>
int main()
{
	int queens;
	std::cout<<"How many queens would you like to fit on the board?(Minimum of four)"<<'\n';
	std::cin >>queens;
	if(queens<4)
	{
		std::cout<<"Too few queens setting queens to four."<<'\n';
		queens=4;
	}
	std::stack<int> column;
	int filled=0;
	int array[queens+1];
	int place=1;
	bool canplace=true;
	column.push(place);
	filled=1;
	array[filled]=place;
	while(filled!=queens)
	{
		for(int i=1;i<filled;++i)
		{
			if(array[i]==place)
			{
				place=place+1;
				std::cout<< "1 place is"<<place<<'\n';
				canplace=false;
			}
		}
		if(place==column.top())
		{
			place=place+1;
			std::cout <<"2 place is"<<place<<'\n';
			canplace=false;
		}
		else if(place==column.top()+1)
		{
			place=place+1;
			std::cout <<"3 place is "<<place<<'\n';
			canplace=false;
		}
		else if (place==column.top()-1)
		{
			place=place+1;
			std::cout<<"4 place is "<<place<<'\n';
			canplace=false;
		}
		for(int i=1;i<filled;++i)
		{
			if(array[i]==i&&filled+1==place)
			{
				place=place+1;
				std::cout<<"5 place is "<<place<<'\n';
				canplace=false;
			}
		}
		for(int i=filled;i==0;--i)
		{
			if(place==array[i]+(filled+1-i))
			{
				place=place+1;
				std::cout<<"6 place is"<<place<<'\n';
				canplace=false;
			}
		}
		if(place>queens)
		{
			int temp=column.top();
			column.pop();
			place=temp+1;
			filled=filled-1;
			std::cout<<"Removing queen from row "<<filled+1<<" and at column "<<place-1<<"."<<"\n";
			if(filled==0)
			{
				column.push(place);
				filled=filled+1;
				array[filled]=place;
				place=1;
			}
			canplace=false;
		}
		else if (canplace==true)
		{
			column.push(place);
			filled=filled+1;
			array[filled]=place;
			std::cout <<"Placed a queen at row "<<filled<<" and at column "<<place<<"."<<'\n';
			for(int i=1;i<queens;++i)
			{
				std::cout<<array[i]<<"|";
			}
			std::cout<<'\n';
			place=1;
		}
			canplace=true;
		}
	char board[queens];
	for (int i=0;i<queens;++i)
	{
		board[i]='X';
	}
	while(!column.empty())
	{
		int position=column.top();
		column.pop();
		board[position-1]='Q';
		for(int i=0;i<queens;++i)
		{
			std::cout<<board[i]<<"|";
		}
		std::cout<<'\n';
		for(int i=0;i<queens;++i)
		{
			board[i]='X';
		}
	}
}

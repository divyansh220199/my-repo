#include<iostream>
#include<conio.h>
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

class snake_game
{
	string name;
	bool gameOver;
	int const height = 20;
	int const width = 50;
	int headX, headY;
	int fruitX, fruitY;
	int score;
	enum edirection {stop=0, LEFT, RIGHT, UP, DOWN};
	edirection dir;
	int tailX[100];
	int tailY[100];
	int tailLength;
	void setup()
	{
		gameOver = false;
		dir = stop;
		headX = width/2;
		headY = height/2;
		fruitX = rand() % width;
		fruitY = rand() % height;
		tailLength = 0 ;
		score = 0;
	}
	void draw()
	{
		system("cls");
		for(int i=0 ; i < width ; i++)
		{
			cout<<"#";
		}
		cout<<endl;
		for(int i=0 ; i < height ; i++)
		{
			for(int j=0 ; j < width ; j++)
			{
				if(j==0 || j==width-1)
				{
					cout<<"#";
				}
				else if(headX==j && headY==i)
				{
					cout<<"O";
				}
				else if(fruitX==j && fruitY==i)
				{
					cout<<"@";
				}
				else
				{
					bool flag = false;
					for(int k=0 ; k < tailLength ; k++)
					{
						if(tailX[k]==j && tailY[k]==i)
						{
							cout<<"o";
							flag = true;
						}
					}
					if(flag == false)
					{
						cout<<" ";
					}
				}
			}
			cout<<endl;
		}
		for(int i=0 ; i < width ; i++)
		{
			cout<<"#";
		}
		cout<<endl;
		cout<<"SCORE:"<<score<<endl;
	}
	void logic()
	{
		int prevX = tailX[0];
		int prevY = tailY[0];
		tailX[0] = headX;
		tailY[0] = headY;
		int prev2X, prev2Y;
		for(int i=1 ; i < tailLength ; i++)
		{
			prev2X = tailX[i];
			prev2Y = tailY[i];
			tailX[i] = prevX;
			tailY[i] = prevY;
			prevX = prev2X;
			prevY = prev2Y;
		}	
		switch(dir)
			{
				case LEFT:
					headX--;
					break;
				case RIGHT:
					headX++;
					break;
				case UP:
					headY--;
					break;
				case DOWN:
					headY++;
					break;
			}
			
			//if(headX > width || headX < 0 || headY > height || headY < 0)
			//{
			//	gameOver = true;
			//}
			
			if (headX >= width) headX = 0; else if (headX < 0) headX = width - 1;
    		if (headY >= height) headY = 0; else if (headY < 0) headY = height - 1;
    		for(int i=0 ; i < tailLength ; i++)
 		   	{
    			if(headX == tailX[i] && headY == tailY[i])
    			{
    				gameOver = true;
				}
			}
			if(headX==fruitX && headY==fruitY)
			{
				fruitX = rand() % width;
				fruitY = rand() % height;
				score++;
				tailLength++;
			}
		
	}
	void input()
	{
		if(kbhit())
		{
			switch(getch())
			{
				case 'a':
					if(dir==RIGHT)
					{
						//do nothing
						break;
					}
					dir = LEFT;
					break;
				case 's':
					if(dir==UP)
					{
						//do nothing
						break;
					}
					dir = DOWN;
					break;
				case 'd':
					if(dir==LEFT)
					{
						//do nothing
						break;
					}
					dir = RIGHT;
					break;
				case 'w':
					if(dir==DOWN)
					{
						//do nothing
						break;
					}
					dir = UP;
					break;
				case 'x':
					gameOver = true;
					break;
			}
		}
	}		
	public:
		void play()
		{
			setup();
			cout<<"Enter Player Name:";
			cin>> name;
			while(gameOver != true)
			{
				draw();
				input();
				logic();
				Sleep(20);
			}
		}
		int getScore()
		{
			return score;
		}
		string getName()
		{
			return name;
		}
};
int main()
{
	snake_game p1;
	p1.play();
	cout<<"GAME OVER"<<endl;
	getch();
	system("cls");
	snake_game p2;
	p2.play();
	system("cls");
	if(p1.getScore() > p2.getScore())
	{
		cout<<p1.getName()<<" is winner"<<endl;
	}
	else if(p1.getScore() < p2.getScore())
	{
		cout<<p2.getName()<<" is winner"<<endl;
	}
	else
	{
		cout<<"DRAW"<<endl;
	}
	
	return 0;
}

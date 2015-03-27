
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() 
{	int num1, num2, num3,  guessnum1, guessnum2, guessnum3, bingo, fitness, 
	gametime = 0, wintime = 0, losetime = 0, i, j;  char choice;   int array[3];     //to store three arbitrary numbers, three guessed numbers, 
                                                                                   	//bingo for the number of A, and fitness for B  
	
	while(true){	
		cout << "需要玩游戏吗（Y/N）？";     
		cin >> choice;
	    
		if (choice == 'Y') 
	    {
			++gametime;
			srand(time(NULL));
	
			num1 = array[0] = rand() * 10 / (RAND_MAX + 1);
			num2 = array[1] = rand() * 10 / (RAND_MAX + 1);
			while (num2 == num1)
				{num2 = array[1] = rand() * 10 / (RAND_MAX + 1);}
			num3 = array[2] = rand() * 10 / (RAND_MAX + 1);
			while (num2 == num3 || num3 == num1)
				{num3 = array[2] = rand() * 10 / (RAND_MAX + 1);}                     //  create arbitrary numbers
			
			

			for (i = 0 ; i < 7; ++i)
			{	cout << "请输入你猜测的数字:";
	 			cin >> guessnum1 >> guessnum2 >> guessnum3;
	 			bingo = 0;
	 			fitness = 0;
				bingo = ((num1 == guessnum1) + (num2 == guessnum2) +(num3 == guessnum3) );          //determine the number of A
				
				if (bingo == 3) 
				{
					++wintime;
					cout << "恭喜，你猜对了!" << endl;
					break;
				}
				else 
				{
					for (j = 0; j < 3; ++j)
						fitness += ((array[j] == guessnum1) + (array[j] == guessnum2) + (array[j] == guessnum3));	 //determine the number of B
						
					fitness = fitness - bingo;
					cout << bingo << 'A' << fitness << 'B'<< endl;													 			
		    	}
			}
		    
			if (bingo != 3)
			{
				++losetime;
			    cout << "很遗憾，你没有在规定次数内猜对。答案是" << num1 << num2 << num3 << endl;  
			}
		
		}
		
		else
		{
			cout << "你一共玩了" << gametime << "局，赢了" << wintime << "局，输了" << losetime << "局" << endl;
			break;
		}			
	}
	return 0;  
}

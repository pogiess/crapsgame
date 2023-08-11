#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int rolldic(void);

int main()
{
	enum status {CONTINUE,LOST,WON};
	
	int mypoints,sum;
	
	status gamestatus;
	
	srand(time(0));
	
	sum = rolldic();
	
	switch(sum){
		case 7:
		case 11:
			gamestatus = WON;
			break;
		case 2:
		case 3:
		case 12:
			gamestatus = LOST;
			break;
		default:
			gamestatus = CONTINUE;
			mypoints = sum;
			cout << "player's point is: " << mypoints <<endl;
			break;
	}
	
	while(gamestatus == CONTINUE){
		
		sum = rolldic();
		
		if(sum == mypoints ){
			
			gamestatus = WON;
			
		}
		
		else if(sum == 7){
			
			gamestatus = LOST;
		}
		
	}
	
	if(gamestatus == WON){
		
		cout << "player wins!" <<endl;
	}
	
	else{
		cout << "player losses" <<endl;
	}
	
	return 0;
}

int rolldic(void){
	
	int die1 , die2 , worksum;
	
	die1 = 1 + rand() % 6;
	die2 = 1 + rand() % 6;
	
	worksum = die1 + die2;
	
	cout << "player rolled " << die1 <<" + " << die2 << " = " <<worksum <<endl;
	
	return worksum;
	
}


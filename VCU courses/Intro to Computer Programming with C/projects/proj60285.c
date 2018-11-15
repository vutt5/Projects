/* Project #6
   EGRE245 Fall 2017
   Tin Vu */

#include <stdio.h>
#include <string.h>

//allowed global variables
//pen condition initialized to 0 (0 is pen up and 1 is pen down).
int pen=0;
//postion NS = North-South position and EW = East-West position.
int posNS=0,posEW=3;
//a board with type char.
char board[25][55] ;
//direction. 1=North, 2=Est, 3=South, 4=West. initialized to 2.
int direction=2;


//--------------------------------------------------//
void	penup (){
//when penup() called, we assign 0 to pen conditon.	
pen = 0;		
}
//--------------------------------------------------//
void pendown (){
//when pendown() called. We mark the current possition and assign 1 to pen condition.
board[posNS][posEW] = '*';
pen = 1;	
}
//--------------------------------------------------//	
int	turnRight(){
/*
				1
				|
				|
		4_______|_______2
				|
				|
				|
				3
*/	
	
	
	
	
	//set condition for the direction so it runs between 1 to 4.
	if (direction == 4){
		
		return (direction = 1);
	}
	else {
		return (direction = direction + 1);
	}	
	}

//--------------------------------------------------//
int	turnLeft(){
//set conditions so the direction runs between 1 to 4.	
	if (direction == 1){
		direction = 4;
		return direction;
		
	}
	else {
		return (direction = direction - 1);
	}
	
}
//--------------------------------------------------//	
void	move(int n){
//pass in an interger after the call for move (5)
//instructions for 4 directions with the pen conditon up or down.
//and to keep the turtle runs over the board.
if((direction == 1)&&(pen == 0)){
	if((posNS-n)>=0){
		posNS = posNS - n;
	}
	else{
		posNS = 0;
	}
}
if((direction == 1)&&(pen == 1)){
	if((posNS-n) >= 0){
		for(int i=0;i<=n;i++){
			board[posNS-i][posEW] = '*';		
		}
		posNS = posNS - n;
	}
	else{
		for(int i=posNS;i>=0;i--){
			board[posNS-i][posEW] = '*';
		}
		posNS = 0;
		
	}	
		
	}
if((direction == 3)&&(pen == 0)){
	if((posNS+n)<=24){
		posNS = posNS + n;
	}
	else{
		posNS = 24;
	}
}	
if((direction == 3)&&(pen == 1)){
	if((posNS+n)<=24){
		for(int i=0;i<=n;i++){
			board[posNS+i][posEW] = '*';		
		}
		posNS = posNS + n;
	}
	else{
		for(int i=posNS;i<=24;i++){
			board[posNS+i][posEW] = '*';
		}
		posNS = 24;
		
	}	
		
	}	
if((direction == 2)&&(pen == 0)){
	if((posEW+n)<=51){
		posEW = posEW + n*2;
	}
	else{
		posEW = 51;
	}   
	
}	
if((direction == 2)&&(pen == 1)){
	if((posEW+n)<=51){
		for(int i = 0;i<=n;i++){
			board[posNS][posEW + i*2] = '*';
		}
		posEW = posEW + n*2;
	}
	else{
		for(int i = posEW;i<=51;i=i+2 ){
			board[posNS][i] = '*';
			
		}
		posEW = 51;
	}
}	
if((direction == 4)&&(pen == 0)){
	if((posEW-n*2)>=3){
		posEW = posEW - n*2;
	}
	else{
		posEW = 3;
	}   
	
}		
if((direction == 4)&&(pen == 1)){
	if((posEW-n*2)>=3){
		for(int i = 0;i<=n;i++){
			board[posNS][posEW - i*2] = '*';
		}
		posEW = posEW - n*2;
	}
	else{
		for(int i = posEW;i>=3;i=i-2 ){
			board[posNS][i] = '*';
			posEW = 3;
		}
	}
}		
	

	
	
}	
	
	
	
	

	

//--------------------------------------------------//	
void	output(void){
//purpose of this function is output the board when user input number 6.
	
printf("                       1                   2\n");
printf("   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4\n");
printf("  +-------------------------------------------------+  \n");	
// design the board at the beginning and the end of the board.
for(int i = 0;i<25;i++){
	if(i<10){
		//for int type that <=9 to convert to char.
	char m = i + '0';
		board[i][1] = m ;
		board[i][53] = m ;
	}
	if(i>=10){
		//for int ype numbers with 2 number to convert to char.
		char m1 = (i/10) + '0';
		char m2 = (i%10) + '0';
		board[i][0] = m1;
		board[i][1] = m2;
		board[i][53] = m1;
		board[i][54] = m2;
	}
	}
//adding | to the board	
for(int i = 0;i<25;i++){
	board[i][2] = '|';
	board[i][52] = '|';
}

	
//I am using this loop to output the main body of the board.
for(int i=0;i<25;i++){
	for(int j =0;j<55;j++){
		printf("%c", board[i][j]);
			
	}

	
printf("\n");	
}

printf("  +-------------------------------------------------+  \n");	
printf("   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4\n");
printf("                       1                   2\n");

//this printf is just to check the global variables.
//	printf("\n posNS: %d \n posEW: %d \n  direction:  %d\n  pen: %d", posNS, posEW,direction,pen);

}





//--------------------------------------------------//
int main (void){

	
printf("Proj. #6 - Tin Vu\n");
//menset is used here to assign all the elements in the array board[][] with a space.	
memset(board,' ',sizeof(board));

int count=0,i=0,j,k,m=0, input, subInput;	
		

//infinite loop to get the data until we hit number 9
for(;;){
scanf("%d",&input);

	if (input == 6){
		output();
		pen=0;
		posNS=0,posEW=3;
		direction=2;
		memset(board,' ',sizeof(board));
	}
	
	if (input == 2){
		pendown();
	}

	if (input == 1){	
		penup();
	}
	if (input == 3){
		turnRight();
	}
	if (input == 4){
		turnLeft();
	}
	if (input == 5){
		scanf("%d", &subInput);
		move(subInput);
	}
	if (input == 9){
		return 0;
	}
	
	
	
		
}

	
	
	
	

	
	
	
printf("\n");	
	
}
/* Project #5
   EGRE245 Fall 2017
   Tin Vu */

#include <stdio.h>
#include <math.h>

int main (void){

float life[100],sum=0,mean, std,upper,lower,uppersum=0 ;
long int batchNum, count = 0, n, test;
long int company;

/*WARNING!!!!!! PLEASE FOLLOW THE FORMAT TO TEST THE MEAN AND STANDARD DEVIATION OF THE LIGHBULBS. 0 (ZERO) CAN ONLY GO WHERE IT IS INDICATED IN THE FORMAT. THE PROGRAM WILL OUTPUT WRONG RESULTS IF 0 (ZERO) IS WHERE IT IS NOT SUPPOSED TO BE.


SAMPLE INPUT.TEXT FILE.

6 <======== NUMBER OF TEST BATCHES
21793456754323 <======= BATCH NUMBER
13 1002 992 -11 988 1012 1005 971 992 0 <======= DATA FOR COMPANY 13
251 1133 1058 1072 1100 1032 1101 1009 1028 993 1091 1121 0 <======DATA FOR COMPANY 251
3 1000 1000 1001 1002 1000 999 1000 993 0
91 950 950 950 950 950 950 950 950 950 950 0
0  <======== INDICATE END OF BATCH         ^
										   |
										   END OF A COMPANY

47
14 988 980 979 988 977 984 971 982 979 0
15 1211 1191 1189 1199 1202 1195 1197 1200 1204 1199 0
482 1002 1007 1001 1002 1014 999 1003 1002 1000 996 0

*/
	
	
printf("Project #5, Tin Vu\n");
//input the number of test batches	
scanf("%ld", &test);
//do a loop so the program will repeat as manytimes as number of batches
	
for(int p=1;p<=test;p++)	
{
//input batch number	
scanf("%ld", &batchNum);
	
//set batch number to n
n = batchNum;
	
//count the digits that the batch number has
	
	if(n !=0){
while(n != 0)
{
	n = n/10;
	count++;
}
	}
	else {
		count = 1;
	}
//print out * and - around the batch number
int dot;
 dot = 13+count;
	printf("*");
	
for(int j=0;j<=dot;j++){
	printf("-");
}
printf("*");
printf("\n");	
	
printf("| Test Batch #%ld |", batchNum);

printf("\n");
	
printf("*");
for(int k=0;k<=dot;k++){
	printf("-");
}
printf("*");	

printf("\n");
	
	
//TABLE PART

printf("Company   Mean  Std Dev\n");
printf("------- ------- -------\n");
//to make sure progam will re-compute the the mean and standard as many times as needed until we hit the 0 for the company
	
do{
//input the company numbers	
scanf("%ld", &company);

	
	if(company ==0){
		break;
	}
	printf("%7ld", company);
	
count =0;
for(int x=0;x<=1000;x++){
//I created an array life[x] to read in the lifetime hours of each company's lightbulds.

scanf("%f", &life[x]);
	if (life[x] == 0){
		break;
	}
	if (life[x] < 0){
		printf("\n It is impossible to have a negative test hour. \n Please check the input data.\n");
		printf(" This program will be terminated now. \n");
		return 0;
	}
//only count the elements up to 10 elements in the array and the sum up to 10 elments.
	
	if(x<10){
count++;
sum = sum + life[x];	
	}
}
//compute the mean dev
	
mean = sum/count;

//compute the std dev	
	
for(int z=0;z<=count-1;z++){
uppersum = uppersum + pow((life[z]-mean),2);
	
}
std = sqrt(uppersum/(count-1));
	

printf(" %7.2f", mean);
printf(" %7.3f", std);
	
printf("\n");
//set the values back to 0 and get ready for the next loops	
count = 0;
sum=0;
uppersum=0;

	
} while (1);
	
printf("\n");	
}
	return 0;
}
/* Project #7
   EGRE245 Fall 2017
   Tin Vu */


#include <stdio.h>
#include <string.h>
int report1(int a, int b){
	if (a<b)
		return a;
	else
		return b;}
void report2(char a[], int b, int c,int e, char d[]){
	printf("image name: %s\n",d);
    printf("magic number = %s\n",a);
    printf("width,height = %d, %d\n",b,c);
	printf("color val    = %d\n",e);
    printf("# points     = %d\n",b*c);
	printf("darkest points of sky within 30.0%% of darkest point:\n");}

void report3(int a, int b, int c, int d){
	if (a<=b){
		printf("[%d,%d]",c,d);}}
	
int main(int argc,char* argv[]){
	printf("proj #7. - Tin Vu\n");
	int w, h, colVal,  buff1,buff2,buff3, smallest =251,t, count=0;
	char magNum[3];
	FILE* fp= fopen(argv[1],"r");
	if(fp==NULL){
        printf("ERROR - file %s does not exist!\n",argv[1]);
        return 0;}
	else{ 
		fscanf(fp,"%s %d %d %d", magNum, &w, &h, &colVal);
	int points[h+1][w+1];
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				fscanf(fp,"%d %d %d",&buff1,&buff2,&buff3);
				points [i][j] = buff1 + buff2 + buff3;		
		smallest = report1(points [i][j],smallest);		
	}}
	fclose(fp);
		if ((w*h) >500000){ 
			printf("illegal number of points\n");
			return 0;}
		report2(&magNum[0],w, h, colVal,argv[1]);
	for(int k=1;k<=h;k++){
        for(int l=1;l<=w;l++){
         report3(points[k][l], 1.3*smallest,k,l);
		}}}
	printf("\n");
}
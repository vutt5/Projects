/* Project #4
   EGRE245 Fall 2017
   Tin Vu */




#include <stdio.h>
int main()
{
	int totalRainfall=0, driestWeek, wettestWeek, leastRainWeek=1000000000;
	int maxRainWeek=-1;
	int rainOnSun=0, rainOnMon=0, rainOnTue=0, rainOnWed=0, rainOnThu=0; 
	int rainOnFri=0, rainOnSat=0;
	
	
	printf("Project #4, Tin Vu\n");
	printf("\n");
	printf("              Daily Rainfall    Total\n");
	printf("	   -------------------  -----\n");
	for(int i=0;i<6;i++)
	{
		printf("week #%d:  ",i+1);
		int weeklyRain=0;
		for(int j=0;j<7;j++)
		{
			int rain;
			scanf("%d",&rain);
			if(j==0)
				rainOnSun+=rain;
			else if(j==1)
				rainOnMon+=rain;
			else if(j==2)
				rainOnTue+=rain;
			else if(j==3)
				rainOnWed+=rain;
			else if(j==4)
				rainOnThu+=rain;
			else if(j==5)
				rainOnFri+=rain;
			else if(j==6)
				rainOnSat+=rain;
			weeklyRain+=rain;
			printf("%2d ",rain);
		}
		totalRainfall+=weeklyRain;
		if(weeklyRain < leastRainWeek)
		{
			leastRainWeek=weeklyRain;
			driestWeek=i+1;
		}
		if(weeklyRain > maxRainWeek)
		{
			maxRainWeek=weeklyRain;
			wettestWeek=i+1;
		}
		printf("%4dmm\n",weeklyRain);
	}
	printf("\n");
	printf("Total rainfall:%3dmm (an average of %0.1fmm per week)\n",totalRainfall,totalRainfall/6.0);
	printf("Driest  week: %d\n",driestWeek);
	printf("Wettest week: %d\n",wettestWeek);
	int driestDay=0,minRainDay=rainOnSun,wettestDay=0,maxRainDay=rainOnSun,minFreq=1,maxFreq=1;
	
	if(minRainDay > rainOnMon)
	{
		minRainDay=rainOnMon;
		minFreq=1;
	}
	else if(minRainDay == rainOnMon)
		minFreq++;
	if(minRainDay > rainOnTue)
	{
		minRainDay=rainOnTue;
		minFreq=1;
	}
	else if(minRainDay == rainOnTue)
		minFreq++;
	if(minRainDay > rainOnWed)
	{
		minRainDay=rainOnWed;
		minFreq=1;
	}
	else if(minRainDay == rainOnWed)
		minFreq++;
	if(minRainDay > rainOnThu)
	{	
		minRainDay=rainOnThu;
		minFreq=1;
	}
	else if(minRainDay == rainOnThu)
		minFreq++;
	if(minRainDay > rainOnFri)
	{	
		minRainDay=rainOnFri;
		minFreq=1;
	}
	else if(minRainDay == rainOnFri)
		minFreq++;
	if(minRainDay > rainOnSat)
	{
		minRainDay=rainOnSat;
		minFreq=1;
	}
	else if(minRainDay == rainOnSat)
		minFreq++;
	printf("Total rainfall on driest  day of week: %dmm ",minRainDay);
	printf("(on ");
	if(rainOnSun==minRainDay)
	{
		printf("Sunday");
		minFreq--;
		if(minFreq>0)
			printf(",");	
	}
	if(rainOnMon==minRainDay)
	{
		printf("Monday");
		minFreq--;
		if(minFreq>0)
			printf(",");	
	}
	if(rainOnTue==minRainDay)
	{
		printf("Tuesday");
		minFreq--;
		if(minFreq>0)
			printf(",");	
	}
	if(rainOnWed==minRainDay)
	{
		printf("Wednesday");
		minFreq--;
		if(minFreq>0)
			printf(",");	
	}
	if(rainOnThu==minRainDay)
	{
		printf("Thursday");
		minFreq--;
		if(minFreq>0)
			printf(",");	
	}
	if(rainOnFri==minRainDay)
	{
		printf("Friday");
		minFreq--;
		if(minFreq>0)
			printf(",");	
	}
	if(rainOnSat==minRainDay)
	{
		printf("Saturday");
		minFreq--;
		if(minFreq>0)
			printf(",");	
	}
	printf(")\n");
	//Now we gather information required to print the wettest days of the week
	if(maxRainDay < rainOnMon)
	{
		maxRainDay=rainOnMon;
		maxFreq=1;
	}
	else if(maxRainDay == rainOnMon)
		maxFreq++;
	if(maxRainDay < rainOnTue)
	{
		maxRainDay=rainOnTue;
		maxFreq=1;
	}
	else if(maxRainDay == rainOnTue)
		maxFreq++;
	if(maxRainDay < rainOnWed)
	{
		maxRainDay=rainOnWed;
		maxFreq=1;
	}
	else if(maxRainDay == rainOnWed)
		maxFreq++;
	if(maxRainDay < rainOnThu)
	{	
		maxRainDay=rainOnThu;
		maxFreq=1;
	}
	else if(maxRainDay == rainOnThu)
		maxFreq++;
	if(maxRainDay < rainOnFri)
	{	
		maxRainDay=rainOnFri;
		maxFreq=1;
	}
	else if(maxRainDay == rainOnFri)
		maxFreq++;
	if(maxRainDay < rainOnSat)
	{
		maxRainDay=rainOnSat;
		maxFreq=1;
	}
	else if(maxRainDay == rainOnSat)
		maxFreq++;
	printf("Total rainfall on wettest day of week: %dmm ",maxRainDay);
	printf("(on ");
	if(rainOnSun==maxRainDay)
	{
		printf("Sunday");
		maxFreq--;
		if(maxFreq>0)
			printf(",");	
	}
	if(rainOnMon==maxRainDay)
	{
		printf("Monday");
		maxFreq--;
		if(maxFreq>0)
			printf(",");	
	}
	if(rainOnTue==maxRainDay)
	{
		printf("Tuesday");
		maxFreq--;
		if(maxFreq>0)
			printf(",");	
	}
	if(rainOnWed==maxRainDay)
	{
		printf("Wednesday");
		maxFreq--;
		if(maxFreq>0)
			printf(",");	
	}
	if(rainOnThu==maxRainDay)
	{
		printf("Thursday");
		maxFreq--;
		if(maxFreq>0)
			printf(",");	
	}
	if(rainOnFri==maxRainDay)
	{
		printf("Friday");
		maxFreq--;
		if(maxFreq>0)
			printf(",");	
	}
	if(rainOnSat==maxRainDay)
	{
		printf("Saturday");
		maxFreq--;
		if(maxFreq>0)
			printf(",");	
	}
	printf(")\n");
	return 0;
}
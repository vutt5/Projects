// TIN TRUNG VU
// V00830285
// PROGRAMMING ASSIGNMENT #3
//CMSC401 FALL 2018



import java.util.*;



public class cmsc401 {

	public static void main(String[] args) {
	//turn this to true to see the debug output
	boolean debug = false;
		  @SuppressWarnings("resource")
		Scanner input = new Scanner(System.in);
// GET THE FIRST INPUT TO CREATE A 2D ARRAY TO STORE THE GRAPH DATA
		  int size = input.nextInt();
		  //numcity 1 hold the original array with no overnight stay
		 String numCity[][] = new String[size+1][size+1];
		 for (String[] row: numCity)
			 Arrays.fill(row, "INF");
		 //numcity 2 hold the new array with the over night stay
		 String numCity2[][] = new String[size+1][size+1];
		 for (String[] row: numCity2)
			 Arrays.fill(row, "INF");
// THIS VARIABLE HOLD NUMBER OF EDGES OF THE GRAPH
		  int edges = input.nextInt();
//TEMPORARILY STORE COST OF OVERNIGHT STAY IN THIS ARRAY
		 String tempArray[] = new String[size+1];
		 Arrays.fill(tempArray, "INF");
		 tempArray[1] = "0";
		 tempArray[2] = "0";
//TO GET THE COST OF OVERNIGHT STAY IN CITIES FROM 2 TO N-1
	for(int i=0;i<(size-2);i++) {
		int	 temp1 = input.nextInt();
		int	 temp2 = input.nextInt();
		tempArray[temp1] = String.valueOf(temp2);
	 }

//NEXT WE GET THE COST TO TRAVEL BETWEEN CITIES
//THESE COSTS CAN BE STORE DIRECTLY INTO THE NUMCITY ARRAY
	for(int k=1; k<=edges; k++) {
		int	 temp3 = input.nextInt();
		int	 temp4 = input.nextInt();
		int  temp6 = input.nextInt();
		if((numCity[temp3][temp4] != "INF")
				||(numCity[temp4][temp3] != "INF") ){
			System.out.println("repeated value");
			System.exit(0);
		}
		numCity[temp3][temp4] = String.valueOf(temp6);
		numCity[temp4][temp3] = String.valueOf(temp6);
	}
//FOR DEBUGGING PURPOSE
// THIS WILL SHOW THE ARRAY FOR THE FIRST ARRAY WHICH HOLD THE EDGE COST
	if(debug == true) {
		System.out.println("THE INITIAL ARRAY WITH NO WEIGHT ON THE VERTICES");
	for(int i = 0;i<size+1 ;i++) {
		for(int j = 0;j<size+1 ;j++) {
			System.out.print(numCity[i][j] + " ");
		}
		System.out.println();
	}
	System.out.println();
	}



//NOW WE ADD THE TEMPORATY ARRAY INTO THE NUMCITY2 ARRAY
//THEY NUMCITY ARRAY NOW COMPLETE WHICH REPRESENT THE DIRECTED GRAPH
//WHERE AS FROM A --> B COULD BE DIFFERENT FROM B --> A DUE TO THE
//OVERNIGHT COST AT EACH CITY
		for(int j =1;j<=size;j++) {
			for(int k=1;k<=size;k++) {
				if(numCity[j][k] != "INF") {
					int temp = Integer.parseInt(tempArray[k]);
					numCity2[j][k] = String.valueOf(temp);

				}
			}
		}
//FOR DEBUGGING PURPOSE
//		THIS WILL SHOW THE SECOND ARRAY WHICH HOLD THE NODE WEIGHT
		if(debug == true) {
	System.out.println("THE SECOND ARRAY WHICH HOLD THE NODES'S WEIGHT");
	for(int i = 0;i<=size ;i++) {
		for(int j = 0;j<=size ;j++) {
			System.out.print(numCity2[i][j] + " ");
		}
		System.out.println();
	}
	System.out.println();
		}
//DONE WITH ARRANGING THE INPUT INTO THE 2D ARRAY.
//I'M USING BELLMAN-FORD ALGORITHM IN THIS PROJECT
//AND THIS IS THE FIRST STEP OF FINDING THE SHORTEST PATH
//WITH SORT = POINT 1.
	String Cost[] = new String[size+1];
	Arrays.fill(Cost, "INF");
	Cost[1] = "0";
//START RELAXING FOR size-1 TIMES
	int tempCost =0;
	for(int m = 0;m<size+10;m++) {
	for(int i=1;i<=size;i++) {
		for(int j=1; j<=size;j++) {
			if(numCity[i][j] != "INF") {
				if(Cost[j] == "INF") {
					tempCost = Integer.parseInt(numCity2[i][j])
							+Integer.parseInt(numCity[i][j]);
						}
					if(Cost[i] != "INF") {
					tempCost = Integer.parseInt(numCity2[i][j])
							+Integer.parseInt(numCity[i][j])
							+ Integer.parseInt(Cost[i]);
					}
					else {
						tempCost = Integer.parseInt(numCity[i][j]) + 100000000;
					}

				if((Cost[j] == "INF") || (tempCost <Integer.parseInt(Cost[j])))
				{
				Cost[j] = String.valueOf(tempCost);
				}
			}
		}
	}
	}
//FOR DEBUGGING PURPOSE
//WHEN WE PRINT THIS! FROM NODE 3 TO THE LAST NODE WE WILL HAVE TO GET THE FINAL
//COST AND MINUS THE NODE WEIGHT OF EACH NODE TO GET THE SHORTEST COST!
//BECAUSE THIS PROGRAM IS WRITTEN TO FIND THE COST FROM 1 TO 2. ANYTHING OTHER THAN
// 2 WILL HOLD AN EXTRA COST OF THE HOTEL
	if(debug == true) {
	System.out.println("the cost from one are: ");
	for (int i = 1;i<=size;i++) {
		if(i<size) {
		System.out.print(Cost[i] + ", ");}
		else
		System.out.print(Cost[i]);
	}
	System.out.println();
	}

	System.out.println(Cost[2]);

	}


}

// TIN TRUNG VU
// V00830285
// PROGRAMMING ASSIGNMENT #2
//CMSC401 FALL 2018



import java.util.*;



public class cmsc401 {
	
	public static void main(String[] args) {
		int temp;
		  @SuppressWarnings("resource")
		Scanner input = new Scanner(System.in);	  
		  
		  int size = input.nextInt();
		  
//get the size and if size == 0  then quit or if size = 1 then just return the one element.
		  if(size == 0){System.exit(0);}
		  
		  if (size ==1) {
			  System.out.println(input.nextInt());
			  System.exit(0);}
		  
		  
		  
// if size == 2 then just return the first element.
		  if (size ==2 ) {
			  int first = input.nextInt();
			  int second = input.nextInt();
			  System.out.println((first+second)/2);
			  System.exit(0);
		  }
		  
// the rest is for if the input size is larger than 2
		  
		  
		  int[] list = new int[size];
		  for(int i = 0;i<size;i++) {
		   list[i] = input.nextInt();
		 }
//setting the configuration to put into the sorting algorithm		  
		  
		  int MedianIndex = size/2;
		  int LastIndex = list.length;
		  int FirstIndex = 0;
		 
		  MedianSort(list, FirstIndex, LastIndex-1, MedianIndex);	  
	}
	
	
		
	static void MedianSort(int[] list, int FirstIndex, int LastIndex, int MedianIndex ) {

		//first condition is for if the sorting list contain more than 2 elements		
		if (FirstIndex < LastIndex) {
			
			int q = Partition(list, FirstIndex, LastIndex);
		//compare the partition result with the median index that we had.
		//if they are equal mean we found the index. print the result and exit 
			if(q == MedianIndex) {System.out.println(list[q]); System.exit(0);}
		// if the median index less than the result of the partition then it means
		//that we will only look at the left part list. discard the right part list.
			else if(MedianIndex <q) {
			MedianSort (list, FirstIndex, q-1, MedianIndex);
			}
			else
		//vice versa
			MedianSort (list, q+1, LastIndex, MedianIndex);
		}
		else {
			System.out.println();
			System.out.println(list[MedianIndex]);
			System.exit(0);
		}
		
	}
	
	static int Partition(int[] list, int FirstIndex, int LastIndex) {
	//let x hold the value of the last index of the list that needed to be sort!
		int x = list[LastIndex];
		int i = FirstIndex-1;
	//sort through the list and put the larger elements to the right and the smaller elements to the left.
		for(int j=FirstIndex;j<LastIndex;j++) {
			if (list[j] <=x) {
				i++;
				int buff = list[i];
				list[i] = list [j];
				list[j] = buff;
					
			}
		}
	// finally put the last element of the array at is being sort to the right position
		int buff = list[i+1]; 
	     list[i+1] = list[LastIndex]; 
	     list[LastIndex] = buff; 
	//return the current position of the lastIndex.	
	     return i+1;
	}

	
	
}


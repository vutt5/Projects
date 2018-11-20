
// TIN TRUNG VU
//CMSC401 FALL 2018


import java.util.Scanner;

class cmsc401 {
 public static void main(String args[]){
  Scanner in = new Scanner(System.in);

// input the first line.
  String first = in.nextLine();
  // parse the first line into integer.
  int line = Integer.parseInt(first);
  if(line == 0){
    System.exit(0);
  }
  //initialize the Result array to have appropriate number of space.
  int[] Result = new int[line];
  // keep track of when to opt out of the infi for loop
  int buff = 0;


//for loop go through each line of input one by one until buff hit the number of result needed.
  for(;;){
//input a whole line as string (from the second line of input on).
  String inputString = in.nextLine();
  //split the string line into string array.
  String[] intString = inputString.split(" ");
  //initialize the current input as an int array.
  int[] current = new int[intString.length];
  //parse the string array into the current int array.
  for(int i=0;i< current.length;i++){
    current [i] = Integer.parseInt(intString[i]);
  }
  // num is for the spaces of the current input.
  int num=(current.length-1);

  int[] Series = new int[num];

for (int x = 0;x<num ;x++ ) {
    Series[x] = current[x+1];
  }
  int a = Series[num-1];
  int b = Series[num-2];
  Result[buff] = Series[a-1]*Series[b-1];
buff++;
if(buff==line){break;}
}
for(int i=0;i<line;i++){
  System.out.println(Result[i]);
}





}

 }

// TIN TRUNG VU
// CMSC 401 FALL 2018


import java.util.Scanner;

public class cmsc401{
public static void main(String[] args) {
  Scanner input = new Scanner(System.in);
  int size = input.nextInt();
  if(size == 0){System.exit(0);}

  int[] list = new int[size];
  for(int i = 0;i<list.length;i++)
   list[i] = input.nextInt();
  int index = 0, count = 1;
  int ME = list[0];

for(int i = 1; i<list.length; i++){
  if (list[i] == ME){count++;}
  else{count--;}
  if (count == 0){
    ME = list[i];
    count = 1;
  }
  else{;}
}
int count2=0;
for(int i=0;i<list.length;i++){
  if(list[i] == ME) count2++;
  if(count2 > (list.length/2)){
    System.out.println(ME);

    System.exit(0);
  }
}
System.out.println("-1");
}}

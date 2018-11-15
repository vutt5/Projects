0011 000000000000; Start the program at location x3000
0101 001 001 1 00000; Clear register 1
0010 101 000011100; Assign R5 to memory location x301E
0010 110 000011100; Assign R6 to memory locaiton x301F 
1001  110  110 111111; reverse the sign of value in R6
0001  110 110 1 00 001; get the value in R6, add 1 and put it back into R3 for comparision
0001 100 101 000 110; Add R5 and R6 and put the value into R4
0000 101000000001;  If the above step (R4) is zero then continue, otherwise skip the next step and leave R1 as 0 
0001 001001100001; Add 1 into R1 (show the result as equal or 1)
1111 000000100101; HALT
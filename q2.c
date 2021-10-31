//inA.txt

/*

3 4
1 2 3 4 5 6 7 8 9 10 11 12

*/

//inB.txt

/*

3 4
12 11 10 9 8 7 6 5 4 3 2 1

*/

//inC.txt

/*

4 3
13 13 13 13 13 13 13 13 13 13 13 13

*/

#include <stdio.h>
#include <stdlib.h>
int main()
{

//assumption that size of matix A and B must be same

//make three file pointer for each file
FILE *fptrA,*fptrB,*fptrC;
//open file inA.txt to read
fptrA = fopen("inA.txt","r");

//open file inB.txt to read
fptrB = fopen("inB.txt","r");
//open file inC.txt to write
fptrC = fopen("inC.txt","w");
  

//row is rA for A and column is cA for A

int rA,cA,rB,cB;

//read file inA.txt
fscanf(fptrA,"%d%d",&rA,&cA);








//make A matrix and TransposeA matrix of given size and gice memory using malloc and trspose size is rc*rA
int** A = (int **)malloc(rA * sizeof(int*));

int ** TransposeA=(int **)malloc(cA * sizeof(int*));

for(int i = 0; i < rA; i++){
   A[i] = (int *)malloc(cA * sizeof(int));
}
for(int i = 0; i < cA; i++){
   TransposeA[i] = (int *)malloc(rA * sizeof(int));
}





//take matrix input
for(int i=0;i<rA;i++){
   for (int j = 0; j < cA; j++){
      /* code */
      fscanf(fptrA,"%d",&A[i][j]);
   }
}
//close file
fclose(fptrA);




//read file inB.txt
fscanf(fptrB,"%d%d",&rB,&cB);

//make B matrix and TransposeB matrix of given size and gice memory using malloc
int** B = (int **)malloc(rB * sizeof(int*));

int ** TransposeB=(int **)malloc(cB * sizeof(int*));

for(int i = 0; i < rB; i++)
{
B[i] = (int *)malloc(cB * sizeof(int));
}

for(int i = 0; i < cB; i++)
{
TransposeB[i] = (int *)malloc(rB * sizeof(int));
}
//take matrix input
for(int i=0;i<rB;i++)
{
for (int j = 0; j < cB; j++)
{
/* code */
fscanf(fptrB,"%d",&B[i][j]);

}
}  


//close file
fclose(fptrB);


// Finding the transpose matrix A.
for(int i=0;i<rA;i++) {
   for(int j=0;j<cA;j++) {
      TransposeA[j][i] = A[i][j];
   }
}

// Finding the transpose matrix B.
for(int i=0;i<rB;i++) {
   for(int j=0;j<cB;j++) {
      TransposeB[j][i] = B[i][j];
   }
}

printf("%s\n","Transpose of Matrix A: " );
for(int i=0;i<cA;i++) {
   for(int j=0;j<rA;j++) {
      printf("%d ", TransposeA[i][j]);
      /* This is just to format the output
      * so you can see the matrix format
      * in the output transpose matrix.
      */
      if(j==rA-1)
      printf("\n");
   }
}
printf("%s\n","Transpose of Matrix B: " );
for(int i=0;i<cB;i++) {
for(int j=0;j<rB;j++) {
printf("%d ", TransposeB[i][j]);

/* This is just to format the output
* so you can see the matrix format
* in the output transpose matrix.
*/
if(j==rB-1)
printf("\n");
}
}


//sum of transpose matrix and print into file inC.txt
fprintf(fptrC, "%d %d\n",cB,rB);
for(int i=0;i<cB;i++) {
   for(int j=0;j<rB;j++) {
      fprintf(fptrC,"%d ", TransposeA[i][j]+TransposeB[i][j]);
   }
}
fprintf(fptrC,"\n");
//close file
fclose(fptrC);
return 0;
}
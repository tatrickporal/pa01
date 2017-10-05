//PATRICK TORAL
// ptoral


#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <ctype.h>
#include "intVec.h"

//Edge structs to and from with a weight
typedef struct{
     int from;
     int to;
     double weight;
} Edge;

/*
This function is called after the first line has been processed
It will return an edge where the to and from int's defined in the struct 
are used in the parameters for intVedPush 
*/
Edge parseEdge(char * line, int lineSize, int linenumber,IntVec *adjlist, int n){
    int digit;
    Edge newEdge;
    int from;
    int to;
    double weight;
    char garbage;
    


    int items = sscanf(line, "%d %d %lf %c", &from, &to, &weight, &garbage);
     newEdge.from = from;
     newEdge.to = to;
     newEdge.weight = weight;
     //if Items are only equal to two overwrite the ones given above
    if(digit == 2){
     newEdge.from = from;
     newEdge.to = to;
     newEdge.weight = 0.0;       
    }

    //error checking of more than 3 elements
    if( (items <= 1) || (items > 3) ){

      fprintf(stderr,"--------- \n");
     fprintf(stderr, "BAD LINE: %d  \n",linenumber ); 
     fprintf(stderr,"--------- \n");
     exit(EXIT_FAILURE);
  } 

  //NExt two if statements check if the inputted number is greater than n
  if(from > n ){
fprintf(stderr,"--------- \n");
    fprintf(stderr,"BAD LINE: %d  \n", linenumber);
   fprintf(stderr,"%d is > %d\n", from, n); 
   fprintf(stderr,"BAD LINE: %d  \n", linenumber);
   fprintf(stderr,"--------- \n");
      exit(EXIT_FAILURE);


  }

   //Pushing the edges to the adjlist 
   intVecPush(adjlist[newEdge.from], newEdge.to);

     return newEdge;
}









int main(int argc, char *argv[])
{
	//The amount of Command line args must be 2 (1:Program name, 2:Input file)
	if(argc != 2){
		fprintf(stderr,"--------- \n");
     fprintf(stderr, "%s\n","NEED TWO COMMAND LINE ARGUMENTS" );
     fprintf(stderr,"--------- \n"); 
     exit(EXIT_FAILURE);

	}
	//Open the file that is defined by the second command line argument
	FILE *input = fopen(argv[1],"r");
	
	if(input == 0){
      //File could not be found
  fprintf(stderr,"--------- \n");
      fprintf(stderr, "%s '%s' %s\n", "File:", argv[1], "not found" ); 
      fprintf(stderr,"--------- \n");
      exit(EXIT_FAILURE);

      
	} else {
		//File found
	  printf("%s '%s' %s\n", "Opened", argv[1], "for input :)");
	}


   char line[1000];
   char first[1000];
   int digit = 0;
   int linenum = 1;
   int n = 0;
   int m = 0;
  

   fgets(first, sizeof(first), input);
   char garbage;
   int check = sscanf(first, "%d %c", &n, &garbage);


   //Checking if the first item has a digit in it 
   if(check != 1){
   fprintf(stderr,"--------- \n");
     fprintf(stderr, "TOO MANY NUMBERS ON LINE: 1 => %s \n", first  );
     fprintf(stderr,"--------- \n");
    exit(EXIT_FAILURE);
   }




//MAKING THE ADJECENCY LIST TO CONNECT TO EDGES WITH LENGTH n
   IntVec adjlist[n];
   for(int i = 1; i<=n; i++){
  
     adjlist[i] = intMakeEmptyVec();
   }
  


  //STARTING AT THE SECOND LINE
    while (fgets(line, sizeof(line), input)) { 
   linenum++;
        if(linenum > 1){

         //INCREASE THE CONNECTION EDGES m AND caling the functions 
         Edge this = parseEdge(line, strlen(line), linenum, adjlist, n);
         m++;
      

       }
    
    
    digit = 0;
   } 

      printf("\n");
  



  // PRINTING OF OUTPUT

      printf("n = %d\n", n );
      printf("m = %d\n", m);

      for(int i = 1; i <= n;i++){
     
      printf("%d ", i );
      if(intSize(adjlist[i]) == 0){
        printf("          NULL\n" );
      } else {
      
      printf("          [");
      
          for(int j = 0; j < intSize(adjlist[i]); j++ ){
        
            if((j + 1) != intSize(adjlist[i]) ){
              printf(" %d, ", intData(adjlist[i],j));
            
            
          }   else {
            printf(" %d ]\n",intData(adjlist[i],j) );
          
          }
        }

        
      }
      
    }

    //ENDING OF PRINTING OF OUTPUT
printf("\n");




  }

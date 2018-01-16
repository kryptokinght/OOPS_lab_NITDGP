#include "stdio.h"

int main() {
  FILE *f, *fp;
  char c, forw, prev;
  int counter = 0, i;
  int for_LOOP = 0;
  f = fopen("code.txt","r");
  fp = fopen("newcode.txt","w");
  if(f && fp) {
    while((c = getc(f)) != EOF) {
      

      if((prev == '\n' && c == ' ') || (prev == '\n' && c == '\t')) {
      	while(c == ' ' || c == '\t') {
      		c = getc(f);
      	}
      	fseek(f,-1,SEEK_CUR);
      	c = ' ';
      }
      else
      	fprintf(fp, "%c", c);  //writes the current char 'c' into newcode.txt 
      
      forw = getc(f);  //gets the next character
      if(forw != EOF)   
        fseek(f,-1,SEEK_CUR);  //moves one position back 

      //check if its the beginning of a for loop or not
      if(c == 'o' && prev == 'f' && forw == 'r')
      	for_LOOP = 1;
      //check the ending of for loop	
      if(c == '{' && for_LOOP)
      	for_LOOP = 0;
      
      
      //***********when braces are found*************************
      if(c == '{') {
      	counter++;
      	if(forw != '\n') { //brings all the code to the next line after '{'
      		c = '\n';
      		fprintf(fp, "\n");
      	}
      } 
      else if(c == '}')
        counter--;

      if(forw == '}' && c != '\n' && c != ' ') { //
      	printf("exec c=%c forw=%c prev=%c\n",c,forw,prev);
      	fprintf(fp,"\n");
      	c = '\n';
      }
      if(c == ';' && forw != '\n' && !for_LOOP) {
      	fprintf(fp, "\n");
      	c = '\n';
      }
      //************spacing************ whenever new line charac is encountered
      if(c == '\n' && counter != 0) {
        for(i = 0; i < counter; i++)
          fprintf(fp,"  ");
      }
      //remove spacin in ending curly braces
      if((c == '\n' && forw == '}') || (c == ' ' && forw == '}')) {
        fseek( fp, -1, SEEK_CUR );
        fseek( fp, -1, SEEK_CUR );
      }
      prev = c;	

    }

  fclose(fp);  
  fclose(f);
  }
  else 
    printf("Some error in opening file\n");
  printf("Counter %d\n",counter);
  return 0;
}
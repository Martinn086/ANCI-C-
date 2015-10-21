#include <stdio.h>
#include <string.h>

// #include <errno.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>
// #include <stdlib.h>

int main (int argc, char* argv[]) {
  
  const char * pattern;

  int i, patternSize;
  int j = 0;
  char user_input[250], *res;


  if ( argc > 1 ) {
    pattern = argv[1];
    patternSize = strlen(pattern);
  } else {    
    return 0;
  }  



  res = fgets(user_input, 250, stdin);

  if ( res == NULL ) {
    return 0;
  }


  for( i=0; i < 250; i++ ) {

    if ( user_input[i] == pattern[j] ) {
      
      j++;

      if ( j == patternSize) {
        if ( fputs( user_input, stdout ) == EOF ) {
          return 0;  
        }
        
      }

    } else {
      j = 0;
    }

  }

  return 0;

}
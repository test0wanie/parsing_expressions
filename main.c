#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "expressions.h"
#include "onp.h"

/*
Programik analizujacy wyrazenia matematyczne oraz
(jezeli sa liczbowe) obliczajacy ich wartosc. Zapisuje
je w strukturze drzewa i nastepnie umie wypisac NP, ONP
oraz po prostu.
przyklady:
    symbolny: a*(b/c+d)-(e+f)*g
    liczebny: 2*(21/7+4)-(5+2)*2
*/

int main(void) {
  node* root;
  char wyr[40];
  
  printf("Podaj wyrazenie matematyczne:\n");
  scanf("%s", wyr);

  /* tworze drzewo */
  root = expr(wyr, 0, strlen(wyr));

  if (!if_nums(root)) {                    /* wariant symboliczny */
    printf("Lukasiewicz:\n");
    np(root);
    printf("\n");
    
    printf("Azciweisakul:\n");
    onp(root);
    printf("\n");
    
    printf("reminder, ze bylo to:\n");
    normalna(root);
    printf("\n\n");
  }
  else {                                   /* wariant liczbowy */    
    printf("Lukasiewicz:\n");
    np_filled(root);
    printf("\n");
    
    printf("Azciweisakul:\n");
    onp_filled(root);
    printf("\n");
    
    printf("reminder, ze bylo to:\n");
    normalna_filled(root);
    printf("= %d\n\n", eval(root));
  }
  /* clean up */
  delete_tree(&root);
  
  return 0;
}

/*
  Mostrar a tabuada de um nº definido pelo usuário.
  A tabuada deve começar com 0 e terminar com 10. Exemplo com o nº 2 :
  2*0 = 0
  2*1 = 2
  .
  .
  .
  2*10 = 20
*/

#include <stdio.h>

int main() {
  int n;
  printf("Digite um número para ver a tabuada: ");
  scanf("%d", &n);

  for (int i = 0; i <= 10; i++) {
    int r = i * n;
    printf("%d * %d = %d \n", i, n, r);
  }

  return 0;
}

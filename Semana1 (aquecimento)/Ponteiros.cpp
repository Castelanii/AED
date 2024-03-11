#include <iostream>

int main() {
  //criação do ponteiro

  //note os erros
  //Criar ele *pa = a, vai dar erro, já que esamos na criação do ponteiro e precisamos criar o endereço de memória do ponteiro
  //Se criamos pa = &a, vai dar erro, pois estamos tentando criar o endereço de memória em um elemeno que não é um ponteiro
  
  char a = '1',*pa= &a ;
  //int *i, *i2, x=1, y=3;

  //aqui podemos fazer 
  //pa = &a;
  //*pa = a;

  int x=1,y=3 ;
  int *px=&y, *py=&y;
  
  //aqui estamos direcionando os valores do pontero, o valor no endereço de px recebe a soma do volores no endereço de px e py
   *px=*px+*py;
  
  std::cout << "x="<<x <<" y="<<y<<'\n';
  std::cout << "*px="<<*px <<" *py="<<*py<<'\n';
  std::cout << "px="<<px <<" py="<<py<<'\n';
  std::cout << "&x="<<&x <<" &y="<<&y<<'\n';
   return 0;
  std::cout << "Hello" <<pa<< "World!\n";
}
<h1 align="center">Essa parte é para quem é aluno da unifesp</h1>
<h3>Tem muita diferença pro c e c++?</h3> na verdade não, até hoje (08/5), eu não tive muitos problemas em adaptar codigos de c para c++,
existem apenas algumas funções que substituem antigas do c, e o proposito dessa página é justamente mostrar elas. espero que possa sair 
daqui aprendendo a ler códigos em C++ (pelomenos os meus).

<h3>Quais são as funções que veremos?</h3>

 - delete <br>
 - std::cout << <br>
 - std::cin >><br>
 - std::endl <br>

<h3>O que elas substituem</h3>

 -  `delete` substitui af unção free(ponteiro), sendo usada da segunte forma: `delete ponteiro;`
 - `std::cout <<` essa função substitui o printf(), logo mais explicarei o que o std:: significa, ela será usada da seguinte forma: `std::cout << variavel << texto << ...;` perceba que não há + no cout, se você quiser colocar uma variável é só adicionar um<br> << var << entre os textos que você quer, exemplo: `std::cout << "a pontuação total é: "<< var;` 
 - `std::cin >>` esse é o scanf(%tipo,&variavel) do c++, usa-lo é bem simples: `std::cin >> variavel;`  
 - `std::endl` pela minha memória(duvidosa) o “\n” não funciona no c++, logo, seu substituto será usar o cout junto com o endl, da seguinte forma: sdt::cout << std::endl; (note que você pode botar um endline no final de todo texto que printar com o cout adicionando o << com o endl)




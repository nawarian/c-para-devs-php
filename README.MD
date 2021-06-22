C para devs PHP
---
```
ATENÇÃO: Este projeto ainda está em progresso. A estrutura e conteúdo aqui provavelmente
ainda estão muito confusas. Eu não recomendo ler estes documentos até que tenha terminado
de organizar ao menos as três primeiras seções.
```

Digaí, véi! Então tu quer saber um pouco mais sobre C, hmm?

Este repositório é a minha preparação para uma live stream que
eu vou conduzir em breve. Nessa live stream **eu vou considerar
que você já sabe programar**, mais específicamente eu vou considerar
que **você já sabe programar em PHP**.

Não significa que você não vá conseguir entender o conteúdo aqui
caso tenha vindo de JavaScript ou Ruby, mas talvez alguns conceitos
e funções não sejam tão familiares pra ti.

Em resumo, eu adotei as seguintes premissas sobre você:

- Já sabe a sintaxe de uma linguagem como o PHP;
- Já entende o mínimo sobre algoritmos;
- Possui familiaridade com algumas funções PHP como o `printf()`, `fopen()` e `strcmp()`

Você não precisa dominar os itens que citei acima, mas quanto
mais cristalizados estes conhecimentos estiverem pra ti, mais
fácil será acompanhar a live!

## Estrutura

A progressão que eu preparei aqui é bem simplista, com a intenção
de te dar as chaves do castelo para que você possa abrir portas e explorar sem mim!

O meu objetivo pessoal é te encorajar a mexer no código fonte do PHP e contribuir com a linguagem. Este deste castelo as chaves que eu vou te dar 😉

Após coletar o feedback da comunidade eu decidi que esta estrutura de curso vai ser efetiva o suficiente pra muita gente. E quem tiver dificuldades com este material pode sempre [me dar um alô no twitter](https://twitter.com/nawarian).

Esta progressão vai tratar dos seguintes tópicos, em ordem:

### Ambiente e instalação

Nós vamos adotar um ambiente cru para que todos nós possamos ter o mesmo ponto de partida.

[Clique aqui para visitar esta seção](00-ambiente-e-instalacao/)

### Compilação

Nós vamos dissecar o processo de compilação de um programa em C. Vamos falar um pouco sobre sistemas operacionais, compiladores, fases do programa e ferramentas (gcc, clang, make).

Não se assuste com a descrição. O tópico é mais simples do que você imagina!

[Clique aqui para visitar esta seção](01-compilacao/)

### Memória

Aqui vamos entender como a memória é utilizada num computador. Portanto vamos falar de representações (decimal, hexadecimal, binário...), como um programa é carregado para a memória, como o C trata a memória na hora de alocar variáveis e, é claro, vamos falar de ponteiros e endereços.

Tudo de forma bem visual e didática!

Para fixar os conceitos melhor, vou imendar esta seção com um exercício: construir um emulador do CPU 6502, a mesma CPU do Nintendinho.

### Exercício: Emulador do CPU 6502 (Nintendinho)

Aqui nós vamos implementar alguns OpCodes do CPU 6502 - um componente eletrônico utilizado em diversos equipamentos, sendo o Nintendinho (NES 8-bit) um dos mais famosos deles.

Nós vamos executar a seguinte linha em Assembler:

```asm
00 LDX #$20 // Carrega 0x20 no registrador X
01 INX      // Incrementa o registrador X em 1
03 STX $10  // Armazena o valor do registrador X no endereço 0x10
```
[Clique aqui para vistar esta seção](02-memoria/)

### Introdução ao PHP-SRC

Após passar pelos passos anteriores, você provavelmente já tem aptidão para fuçar e aprender sobre o PHP-SRC sem muitas dores de cabeça.

Eu vou te mostrar como as coias estão organizadas e algumas práticas comuns que o core adota.

Também vou te mostrar como navegar a página de bugs e enviar algumas correções.

[Clique aqui para vistar esta seção](03-introducao-ao-php-src/)

## Agradecimentos

Este projeto é uma iniciativa conjunta com a [comunidade PHPSP](http://phpsp.org.br/), obrigado por continuar sendo uma comunidade maravilhosa até mesmo em tempos de distanciamento!


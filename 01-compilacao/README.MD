Compilação
---

A primeira coisa que você precisa entender é como se compila um programa em C.

Aqui vão algumas explicações importantes pra ti.

## Para o que a gente compila um programa em C?

Programas em C são compilados para um formato binário que é executável pela
máquina destino (target). Há vários formatos intermediários no processo de
compilação, mas o objetivo final é ter um binário (como um .exe no Windows)
que possa ser executado pelo sistema operacional.

Nesta página vamos cobrir algumas tecnicas de compilação em C que não cobrem
tudo o que você precisa saber mas te dará uma base sólida para entender outros
projetos.

Dependendo do seu sistema operacional, você estará lidando com diferentes
compiladores por padrão. Em sistemas GNU/Linux normalmente usamos o compilador
[GNU C Compiler (GCC)](https://gcc.gnu.org/) enquanto em computadores com MacOS
se usa o [clang](https://clang.llvm.org/get_started.html).

Para evitar confusões nos próximos tutoriais vamos criar um alias de sistema
chamado `CC` que irá referenciar o seu compilador:

```
$ alias CC=clang # use CC=gcc se o seu compilador for GCC
```

## Compilação simples

Vamos considerar o seguinte programa:

```C
// main.c
int main(void)
{
    return 0;
}
```

Este programa não tem nenhuma dependência extra, não utiliza bibliotecas e
nem importa outros arquivos. A compilação é direta e rápida:

```
$ CC main.c -o main
$ ls -la .

-rw-r--r--  1 nawarian  staff   1277 Jun 16 06:46 README.MD
-rwxr-xr-x  1 nawarian  staff  16536 Jun 16 06:39 main
-rw-r--r--  1 nawarian  staff     34 Jun 16 06:39 main.c
```

O formato da linha de comando aqui é `CC <arquivo_c> -o <binario_a_ser_escrito>`.

## Incluindo arquivos

Em C a diretiva `#include <arquivo>` copia todo o conteúdo de `<arquivo>` para a
linha onde esta diretiva foi invocada. Veja o seguinte exemplo:

```C
// arquivo1.c
int arquivo1()
{
    return 10;
}

// arquivo2.c
int arquivo2()
{
    return 20;
}

// main.c
#include "arquivo2.c"
#include "arquivo1.c"

int main(void)
{
    int x = 0;
    x += arquivo1();
    x += arquivo2();

    return x;
}
```

Note como `#include "arquivo2.c"` acontece antes de `#include "arquivo1.c"`. De acordo
com esta ordem, o arquivo que será compilado se parece com isso:

```C
// arquivo sendo compilado (temp)
int arquivo2()
{
    return 20;
}

int arquivo1()
{
    return 10;
}

int main(void)
{
    int x = 0;
    x += arquivo1();
    x += arquivo2();

    return x;
}
```

E a linha de compilação fica como? Seguindo o formato simples de compilação:

```
$ CC main.c -o main
$ ls -la .

-rw-r--r--  1 nawarian  staff   2727 Jun 16 07:00 README.MD
-rw-r--r--  1 nawarian  staff     35 Jun 16 06:58 arquivo1.c
-rw-r--r--  1 nawarian  staff     35 Jun 16 06:58 arquivo2.c
-rwxr-xr-x  1 nawarian  staff  16616 Jun 16 07:00 main
-rw-r--r--  1 nawarian  staff    137 Jun 16 07:00 main.c
```

Não é necessário adicionar `arquivo1.c` e `arquivo2.c` na linha de comando,
porque `main.c` já faz o `#include` destes arquivos. O compilador automaticamente
lê e une estes arquivos num só antes de compilar o seu programa!

Você provavelmente já viu ambientes de compilação bem mais complexos que este.
Mas antes de te apresentar como eles funcionam, eu preciso te explicar
como os Símbolos e Includes se relacionam em C.

Símbolos
---

Em C tudo o que a gente referencia com nomes são considerados "símbolos": funções,
variáveis e macros são considerados símbolos.

E por via de regra cada símbolo precisa existir antes de ser chamado. Veja o exemplo:

```C
// main.c
int main(void)
{
    // error: implicit declaration of function 'give_me_a_zero'
    return give_me_a_zero();
}

int give_me_a_zero()
{
    return 0;
}
```

No snippet acima a função `main()` tentou chamar `give_me_a_zero()`, mas no momento
em que `main()` foi declarado o compilador ainda não sabia daquela função!

Uma forma simples de corrigir isso seria somente mover a função `give_me_a_zero()`
para que seja declarada antes de `main()`:

```C
int give_me_a_zero()
{
    return 0;
}

int main(void)
{
    return give_me_a_zero();
}
```

Em muitos casos isto é pouco prático. Mas a linguagem C vem com outra solução. Por
outras razões que eu irei explicar lá na frente, o C não precisa saber da implementação
da função chamada si: precisa saber somente da assinatura (nome, parâmetros e retorno).

Então o seguinte snippet é totalmente válido:

```C
// main.c
int give_me_a_zero(); // Declaramos a função antes de main()

int main(void)
{
    return give_me_a_zero();
}

int give_me_a_zero()
{
    return 0;
}
```

## Arquivos de cabeçalho (header files)

Ora, se o C não precisa saber da implementação na hora de compilar é possível então
declarar todas as funções dos programas num arquivo separado e implementar cada
uma onde for mais conveniente.

Em C é boa prática declarar símbolos (funções, macros...) num arquivo de cabeçalho (`.h`)
para que os arquivos `.c` possam incluir e utilizar estes símbolos sem dor de cabeça.

Vamos refatorar o exemplo acima:

```C
// utils.h
int give_me_a_zero();

// main.c
#include "utils.h"

int main(void)
{
    return give_me_a_zero();
}

int give_me_a_zero()
{
    return 0;
}
```

## Mas pra quê?

Você talvez veja pouca utilidade em declarar a função em um arquivo e implementar em outro.
Tenha paciência, eu estou construindo uma trajetória contigo!

Mas para acalmar seu coração já de agora eu posso te dar um spoiler do motivo disso: esta
tecnica permite que utilizemos bibliotecas em C. Isso tudo vai ficar mais claro quando eu
te explicar sobre objetos e linkedição (linkers).

Por agora siga para a próxima seção onde vamos introduzir a ferramenta `Make`.


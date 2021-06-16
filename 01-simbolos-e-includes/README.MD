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


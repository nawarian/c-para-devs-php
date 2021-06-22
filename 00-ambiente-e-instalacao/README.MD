Ambiente e instalação
---

O bacana da linguagem C é que você não precisa de muita coisa pra começar!

Mas para que a gente possa com total certeza trabalhar no mesmo ambiente,
eu vou considerar que você esteja rodando uma imagem `alpine-3.13` dentro
de um container Docker.

Então eu vou considerar que para este tutorial você _clonou este repositório_
e vai rodar todo e cada comando dentro de uma imagem docker. A sequência de
comandos é mais ou menos essa:

```bash
$ git clone https://github.com/nawarian/c-para-devs-php
$ cd c-para-devs-php/
$ docker run -it --rm -v $(PWD):/opt -w /opt alpine:3.13

/opt # 
```

A partir daqui a gente pode instalar todas as dependências. Segue lendo!

### Compilador C

A principal ferramenta que você vai precisar para seguir os tutoriais
é o compilador. Como nós não vamos cobrir nada avançado, quase qualquer
compilador vai te resolver a vida.

A minha recomendação é que você instale o [GNU C Compiler (GCC)](https://gcc.gnu.org/):

```bash
/opt # apk add gcc
```

Você pode adotar outras alternativas como o `clang`, por exemplo. Mas para
simplificar a vida vamos adotar o `gcc` por padrão.

### Automação de tarefas: Make

O [GNU Make](https://www.gnu.org/software/make/) é uma ferramenta de automação
de build muito flexível e utilizada em vários projetos C.

Nós não vamos utilizar esta ferramenta extensivamente, mas você vai ver o básico
de como esta ferramenta funciona.

```bash
/opt # apk add make
```

### Editor de texto

Você provavelmente já sabe que pode escrever código em qualquer editor ou IDE,
e que alguns vão facilitar a sua vida mais do que outros.

Por total falta de experiência eu não tenho um editor de texto que possa te
recomendar. Eu costumo usar o [VIM](https://www.vim.org/) por ser simples, leve,
extensível, funcionar em diferentes ambientes e oferecer um suporte decente a
diferentes linguagens de programação.

Eu sei que muita gente costuma programar C usando o Visual Studio Code. É um editor
que EU não consigo utilizar, mas que agrada muita gente.


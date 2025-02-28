# Projeto prático - Estrutura de Dados - 🗼🇻🇳

O projeto prático em grupo consiste na implementação de uma aplicação que utilize pelo menos duas estruturas de dados lineares.
Trabalhamos com a implementação destas estruturas de forma encapsulada, respeitando o conceito de TAD<sup>[1](#tad-note)</sup> em cada API.

As estruturas implementadas foram:

1. **DEQUE**<sup>[2](#deque-note)</sup> com alocação dinâmica e sequencial;
2. **Lista** com alocação dinâmica, duplamente encadeada, circular e com sentinela.

A estrutura de DEQUE foi utilizada na criação das Torres com os discos, funcionando como uma pilha, i.e., com inserção e remoção no ínicio. Por outro lado, a estrutura de lista foi utilizada na implementação de uma fila, controlando o progresso das fases do usuário.

O projeto consiste em um antigo quebra-cabeça chamado de **Torre de Hanói**, o jogo está separado em fases com dificuldade -e número de discos- crescente.

O quebra-cabeça consiste em uma base com três pinos, em um dos quais são dispostos alguns discos uns sobre os outros, em ordem crescente de diâmetro, de cima para baixo. O problema consiste em passar todos os discos de um pino para um outro qualquer, usando um dos pinos como auxiliar, de maneira que **um disco maior nunca fique em cima de outro menor** em nenhuma situação.

Leia mais [aqui](https://pt.wikipedia.org/wiki/Torre_de_Han%C3%B3i)

---

<h6><a id="tad-note"></a>1: O conceito de TAD (Tipo Abstrato de Dados) é usado para criar modelos de dados encapsulados que expõem apenas as operações necessárias, escondendo os detalhes internos da implementação e melhorando a organização, modularidade e reutilização do código.</h6>

<h6><a id="deque-note"></a>2: Double-ended queue</h6>

<h1 align="center"> get_next_line - @42sp </h1>

<p align="center">:information_source: Uma função em C que lê qualquer arquivo válido linha por linha até o final </p>

<p align="center"><img src="https://user-images.githubusercontent.com/81205527/149212588-45d60d10-2e78-46c5-bf0c-0dc247464ad5.png"></p>
<p align="center"><a href="https://github.com/augustobecker/get_next_line/blob/main/README.md"><img src="https://img.shields.io/badge/available%20in-EN-blue"></a></p>

## Índice

* [O que é get-next-line?](#o-que-e-get-next-line)
* [Requisitos](#requisitos)
* [Como funciona?](#como-funciona)
* [Como eu uso a Função?](#como-eu-uso-a-funcao)
* [Como eu testo?](#como-eu-testo)

<h2 align="center" id="o-que-e-get-next-line"> O que é get-next-line? </h2>

O segunda projeto na 42. É uma função em C que retorna uma linha lida de um file descriptor. Em resumo, pode ler qualquer arquivo válido e faz isso linha por linha para otimizar memória, uma vez que o tamanho do arquivo é desconhecido. É uma função extremamente útil e pode ser usada em projetos futuros dentro da 42.

<h2 align="center" id="requisitos"> Requisitos </h2>

<p  align="center"> :warning: O projeto deve estar de acordo com a <a href="https://github.com/42School/norminette/blob/master/pdf/pt_br.norm.pdf" target="blank">Norma</a> </p>
A Norma é um padrão de programação que define um conjunto de regras a seguir ao escrever um código na 42. A norma aplica-se a todos os projetos C dentro do currículo interno por padrão, e para qualquer projeto onde é especificado. Aqui algumas das regras:

    Cada função dever ter no máximo 25 linhas, não contando suas próprias chaves '{}'.
    
    Cada linha deve ter no máximo 80 colunas de largura, comentários incluídos.
    
    Uma função pode ter no máximo 4 parâmetros definidos.
   
    Não podem ser declaradas mais que 5 variáveis por função.
    
    Não é permitido o uso de: for , do...while , switch , case ,  goto  ,
    operadores ternários como `?' e VLAs - Matrizes de comprimento variável.
  A norminette (como chamamos a norma na 42) é feita em python e é open source.
  
  O repositório está disponível em https://github.com/42School/norminette
  
  Além da norma padrão, o projeto tem alguns requisitos próprios
  
    É proibido declarar variáveis globais.
    
    Sua leitura deve usar o BUFFER_SIZE definido durante a compilação para ler de um
    arquivo ou do stdin. Esse valor será modificado durante a avaliação para fins de
    teste.
    
    O programa será compilado dessa forma:
    gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <arquivos>.c.
    
    A libft não é autorizada para este projeto. você deve adicionar um arquivo 
    get_next_line_utils.c que vai conter as funções que você precisa para a sua
    get_next_line funcionar.
    
<h2 align="center" id="como-funciona"> Como funciona? </h2>

<p align="center"> :sparkles: <strong>Para este projeto fomos apresentados ao conceito de variáveis estáticas</strong> :sparkles:</p>

<p align="center"> :information_source: Uma variável estática é alocada "estaticamente", o que significa que seu tempo de vida é toda a execução do programa. </p>

A linha é por definição uma string encerrada em "\n" (quebra de linha) ou "EOF" (para o fim do arquivo) e que, segundo o subject, deve ser lida em um buffer de tamanho definido 
na compilação. A get_next_line roda a função read e guarda o que foi lido durante a chamada só então procura por um "\n" - quando encontra sabemos que chegamos ao fim da linha,
caso não encontre o "\n" mas o read retorne 0 sabemos que não tem nada à frente para ser lido (EOF), nos outros casos, simplesmente não chegamos ao final da linha, o que foi 
lido é armazenado na linha que vai ser retornada e seguimos na leitura do arquivo. Na maioria das vezes o buffer não condiz com o tamanho exato da linha,
e também não é possível reler o mesmo trecho da linha, o que gera um dos maiores problemas no desenvolvimento da get_next_line:

    O que aconteceria nesses casos em que, por exemplo, o BUFFER_SIZE é de 10 caracteres e a linha acaba no 6º caracter?

Os 4 caracteres restantes após a quebra de linha seriam perdidos e a leitura continuaria no próximo buffer de 10 caracteres.
Para resolver isso, usamos a variável estática como um backup, para guardar esses caracteres que sobram.
E quando a função é chamada novamente, uma das primeiras coisas feitas é checar se há algo no backup e se houver, começar a nova linha a partir dali.
No geral é assim que ela funciona, outros detalhes de funcionamento são mais técnicos e achei melhor deixá-los de fora dessa explicação, mas você pode conferir checando 
a <a href="https://github.com/augustobecker/get_next_line/blob/main/get_next_line.c">função</a>.

<h2 align="center" id="como-eu-uso-a-funcao"> Como eu uso a Função? </h2>

<h2 align="center" id="como-eu-testo"> Como eu testo? </h2>

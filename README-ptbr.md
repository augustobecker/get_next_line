<h1 align="center"> get_next_line - @42sp </h1>

<p align="center">:information_source: Uma função em C que lê qualquer arquivo válido linha por linha até o final </p>

<p align="center"><a href="https://www.42sp.org.br/" target="_blank"><img src="https://img.shields.io/static/v1?label=&message=SP&color=000&style=for-the-badge&logo=42""></a></p>
<p align="center"><img src="https://user-images.githubusercontent.com/81205527/149212588-45d60d10-2e78-46c5-bf0c-0dc247464ad5.png"></p>
<p align="center"> <strong>104/100</strong> ✅ </p>
<p align="center"><a href="https://github.com/augustobecker/get_next_line/blob/main/README.md"><img src="https://img.shields.io/badge/available%20in-EN-blue"></a></p>

## Índice

* [O que é get-next-line?](#o-que-e-get-next-line)
* [Requisitos](#requisitos)
* [Como funciona?](#como-funciona)
* [Como eu uso a Função?](#como-eu-uso-a-funcao)
* [Como eu testo?](#como-eu-testo)
* [42 Cursus](#42-cursus)
* [Autor](#autor)

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
O objetivo é criar uma bilioteca chamada libgetnextline.a feita com os arquivos fonte.

Para criar a biblioteca, clone o projeto:

    git clone https://github.com/augustobecker/get_next_line get_next_line
Entre no repositório:

    cd get_next_line
Rode esse comandos para transformar os arquivos em objetos:
    
    clang -Wall -Werror -Wextra -c get_next_line.c -o get_next_line.o 
    clang -Wall -Werror -Wextra -c get_next_line_utils.c -o get_next_line_utils.o 

E esse outro para criar a biblioteca
    
    ar -rcs libgetnextline.a get_next_line.o get_next_line_utils.o 

Você deve ver um arquivo libgetnextline.a e alguns arquivos objeto (.o).

Você pode remover os arquivos .o

    rm -f get_next_line.o get_next_line_utils.o 
Agora, só precisa adicionar esse cabeçalho nos seus arquivos .c e usar as funções da libgetnextline:

    #include "get_next_line.h"
Se tentar compilar seus arquivos com clang usando "clang exemplo.c" vai receber um erro de undefined symbol para as funções da biblioteca.

Você deve mostrar qual é a biblioteca:

    clang exemplo.c libgetnextline.a

É isso, agora basta executar com ./a.out
    
Agora, se estiver buscando uma forma de utilizar essa função, aqui vai uma demonstração prática:
    	
	char	*full_file;
	char	*line_temp;
	int	file_fd
	
	file_fd = open(argv, O_RDONLY);
	if (file_fd == -1)
		ft_error_msg("The Map couldn't be opened. Invalid fd");
	full_file = ft_strdup("");
	while (true)
	{
		full_file = get_next_line(file_fd);
		if (line_temp == 0)
			break ;
		full_file(full_file, line_temp);
		free(line_temp);
	}
	close(file_fd);
	return (full_file);

    
<h2 align="center" id="como-eu-testo"> Como eu testo? </h2>
    
Para testar o código vamos usar um Tester para a get_next_line feito pelo @jgambard. Há vários outros bons testers mas hoje vou cobrir apenas esse.

Para testar o código desse repositório:
Clone o repositório e entre nele:

    git clone https://github.com/augustobecker/get_next_line get_next_line
      
    cd get_next_line/
 
Agora, clone o gnlTester do @jgambard
    
    git clone https://github.com/Tripouille/gnlTester Tester_get_next_line
Entre na pasta do Tester e rode o teste mandatório:

    cd Tester_get_next_line
    make m
    
Se você fez tudo corretamente, deve ver algo como isso:   
    
![68747470733a2f2f692e696d6775722e636f6d2f75344c6936414d2e706e67](https://user-images.githubusercontent.com/81205527/158914684-a53f2bf1-7a7a-4155-944f-7863ddb09855.png)

<h2 align="center" id="42-cursus"> 42 Cursus </h2>
    
A 42 é uma iniciativa educacional global que propõe uma nova forma de aprender tecnologia: sem professores, sem salas de aula,
estudantes aprendendo com seus colegas estudantes (Aprendizado peer to peer),
com uma metodologia que desenvolve habilidades de computação e da vida.
Sem mencionar que é completamente gratuita e aberta para todos, sem pré-requisitos. 
    
As admissões na 42 são diferentes de outras escolas. Usamos um processo de admissão baseado em mérito.
O passo final no processo é a Piscina - parte parte do processo seletivo que requer 4 semanas de código intenso e imersivo.
Não é necessário experiência anterior em programação.
    
Você pode conferir mais sobre o processo de admissão no site da 42sp: https://www.42sp.org.br
    
ou no meu repositório do github: <a href="https://github.com/augustobecker/42sp_Piscine">42 Piscine</a>

Para ver outros projetos da 42 desenvolvidos por mim, clique aqui: <a href="https://github.com/augustobecker/42cursus">42 Cursus </a>

<h2  align="center" id="autor">Autor</h2>
<div align="center">
	<div>
	<img height="222em" src="https://user-images.githubusercontent.com/81205527/174709160-f4bc029d-b667-469b-b2a7-4e036f1c5349.png">
	</div>
	<div>
		<strong> Augusto Becker | acesar-l | 🇧🇷👨‍🚀</strong>
	
:wave: Fale comigo: 
    	</div> 
    	<div>
  	<a href="https://www.linkedin.com/in/augusto-becker/" target="_blank"><img align="center" alt="LinkedIn" height="60" src="https://user-images.githubusercontent.com/81205527/157161849-01a9df02-bf32-45be-add4-122bc40b48cf.png"></a>
	<a href="https://www.instagram.com/augusto.becker/" target="_blank"><img align="center" alt="Instagram" height="60" src="https://user-images.githubusercontent.com/81205527/157161841-19ec3ab2-2c8f-4ec0-8b9d-3cd885256098.png"></a>
	<a href = "mailto:augustobecker.dev@gmail.com"> <img align="center" alt="Gmail - augustobecker.dev@gmail.com" height="60" src="https://user-images.githubusercontent.com/81205527/157161831-eb9dffee-404b-4ffe-b0af-34671219f7fb.png"></a>
	<a href="https://discord.gg/3kxYkBRxUy" target="_blank"><img align="center" alt="Discord - beckerzz#3614" height="60" src="https://user-images.githubusercontent.com/81205527/157161820-de88dc63-61a3-4c9f-9445-07ac98bf0bc2.png"></a>
	</div>
</div>    	

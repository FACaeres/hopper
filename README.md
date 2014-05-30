Log History
=====
1.0 - Versão Inicial

Exercicios Concluidos
=====

questao1 - OK
questao2 - Ok
questao3 - OK
questao4 - OK
questao5 - OK
questao6 - OK
questao7 - OK
questao8 - OK
questao9 - OK
questao10 - OK
questao11 - OK
questao12 - 
questao13 - OK - ESCOLHA para numeros verificar?
questao14 - OK 
questao15 - OK
questao16 - OK
questao17 - OK
questao18 - OK
questao19 - OK
questao20 - OK
questao21 - OK
questao22 - OK
questao23 - OK
questao24 - OK
questao25 - OK
questao26 - OK
questao27 - OK
questao28 - OK
questao29 - OK
questao30 - OK

Git
=====
Boa galera, to fazendo esse pequeno tutorial para quem ainda não meche com o git como repositorio.

Inicialmente, será necessario que vocês possuam o Git bash já instalo na sua maquina.
Para quem ainda não tem, segue este link com um pequeno tutorial para instalação.

http://blog.dmatoso.com/2011/09/git-no-windows-github/

É importante realizar o Passo 3.
Não esquecendo de add a SSH key , a opção você encontra em Settings.

Depois do Passo 3, já não é necessario criamos o repositorio, logo porque ele já esta criado por min!

Nesse caso, vocês necessitam fazer um git clone do repositorio, segue os comandos:

1- Atraves do Git Bash, vá ate a pasta onde você quer guardar a pasta do repositorio.

2- Agora clonamos o repositorio:
    git clone < url >
Se tudo der certo, seu repositorio já esta pronto para ser utilizado.

3- Agora vocÊ entra na pasta do repositorio e verifica em que branch vocÊ está. ( Pra quem não sabe oque é branch, dá uma procurada no google).
    cd hopper/
No meu caso, estou na branch master.

*IMPORTANTE
4- Legal, apartir de agora você deve criar sua propria branch de desenvolvimento.(recomendado)
Vc vai criar uma branch com seu nome.No meu caso, "kevin".Criem com o seu nome não esqueça.

    git checkout -b kevin (Comando cria e automaticamente já muda para você de master->kevin)

Apartir desse momento você ja tem uma branch criada com seu nome, mas ainda esta somente localmente. Vamo subir para o github a sua nova branch.

    git push origin kevin (Lembre-se de mudar e colar seu nome)

Legal, agora sua branch esta disponivel no github.
O objetivo disso é que todos devem trabalhar em suas branchs. No master so ficaram os codigos 100%. Se você acha que seu codigo ta pronto para ir para o master.. avisar aos membros de equipe e esperar o feedback positivo de todos..

Para trabalhar com suas branchs segue a lista de algums comandos utils que eu uso:
        
        git status
        
        git add <filename>
        
        git commit -m '<Aqui voce escreve sua mensagem do commit>'
        
        git pull origin kevin (logo substitua kevin pelo nome da sua branch)
        
        git push origin kevin
        
        gitk
        
        git branch -a
        
        git checkout

Procurem saber oque cada comando realiza. E bom trabalho.
Duvidas kevingmq@gmail.com
Vlw



hooper 
======
Um compilador portugol
-----------------------

A proposta desse projeto é disponibilizar uma implementação da linguagem/pseudo-código Portugol (ou  português estruturado), através da construção de um compilador para essa linguagem.
Esperamos favorecer os estudantes que dão os primeiros passos no aprendizado de desenvolvimento de softwares,  e também  os professores que ensinam disciplinas relacionadas a computação.
Uma vez que, essa linguagem é muito usada para descrever algoritmos em português, de forma livre e espontânea e em geral, o ensino de algoritmos, lógica e estruturas de dados a utilizam de alguma forma.
Portanto, nosso foco é didático.

Se encontram disponíveis atualmente apenas a documentação do portugol na nossa [Wiki](https://github.com/darlissonmar/hopper/wiki).

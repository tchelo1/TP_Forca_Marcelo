Jogo da Forca - Versão Básica

Este é um trabalho simples de programação em C, feito para a disciplina  programação e desenvolvimento de softaware.

O jogo funciona assim:
- Você escolhe jogar e digita seu nome.
- O programa escolhe uma palavra aleatória para você adivinhar.
- Você tenta acertar as letras da palavra, uma por vez.
- Você pode errar até 6 vezes antes de perder.
- O jogo mostra um bonequinho da forca que vai sendo desenhado conforme você erra.
- No final, o resultado (se ganhou ou perdeu) é salvo num arquivo para você poder ver depois.

Arquivos usados:
- palavras.txt: lista com várias palavras para o jogo escolher.
- resultados.txt: arquivo onde ficam salvos os resultados das partidas.

Como rodar:
1. Compile os arquivos com o gcc:
   gcc main.c forca.c -o forca
2. Rode o programa:
   ./forca

Observações:
- Se quiser adicionar mais palavras, é só colocar no arquivo palavras.txt, uma palavra por linha.
- O programa lê as palavras do arquivo e escolhe uma delas aleatoriamente.
- Se não encontrar o arquivo palavras.txt, ele usa uma palavra padrão para o jogo funcionar.

É isso! Divirta-se jogando e espero que gostem do trabalho!

Feito por: Marcelo Rodrigues Viegas d'Abreu

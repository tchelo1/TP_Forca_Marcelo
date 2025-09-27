🎮 Hangman Game – Basic Version

This is a simple C programming project: a classic Hangman game designed to demonstrate logic, file handling, and structured programming.

🕹️ How it Works

The player starts the game by entering their name.

The program randomly selects a word to guess.

You try to guess the letters, one at a time.

You can make up to 6 mistakes before losing.

With each wrong guess, a stick figure is drawn step by step.

At the end, the result (win or lose) is saved in a file for later reference.

📂 Files Used

palavras.txt → contains the word list for the game.

resultados.txt → stores the results of past matches.

⚙️ How to Compile and Run

Compile the files with GCC:

gcc main.c forca.c -o forca


Run the program:

./forca

📝 Notes

You can add more words by editing palavras.txt (one word per line).

If the program doesn’t find palavras.txt, it will use a default word so the game still works.

👨‍💻 Author

Developed by Marcelo Rodrigues Viegas d'Abreu

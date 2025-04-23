# wordle_c

### Installation

Dans un repertoire cloner le repo. On suppose que vous souhaiter le cloner dans Documents.

```sh
cd ~/Documents
git clone https://github.com/Kramoth/wordle_c.git
```

### Compilation

```sh
cd ~/Documents/wordle_c
mkdir bin
gcc -o bin/main -I include/ src/getBDD.c src/main.c
```

### Utilisation

```sh
cd ~/Documents/wordle_c/bin
./main
```

Suivre les instructions du jeu, taper un mot de 5 lettres puis taper sur la touche entree. Si la lettre est verte alors elle est bien placee si elle est orange alors la lettre est dans le mot mais mal positionnee sinon la lettre n'est pas dans le mot.
Vous avez 6 essaies.
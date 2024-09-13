# ECS Minilibx - Harmonie Durrant

🇬🇧 [English](README.en.md)

Ce projet est une version modifiée de la minilibx, une bibliothèque graphique utilisée à 42 Paris. La minilibx est une bibliothèque graphique minimaliste qui permet de créer des fenêtres et de dessiner des pixels, des lignes et des images. Elle est utilisée pour les projets de graphisme de l'école 42.

Si vous êtes Student à l'école 42, vous pouvez utiliser cette bibliothèque pour vos projets à condition de bien comprendre comment ça marche. Vous pouvez également contribuer à ce projet en soumettant des pull requests et des issues.

⚠️ **Attention :** Ce projet est en cours de développement et n'est pas encore prêt pour une utilisation en production. Il est recommandé de l'utiliser uniquement à des fins d'apprentissage et de test.

## ECS - Entity Component System

ECS signifie Systeme d'entités et de composants. C'est un modèle de programmation qui permet de séparer les données des comportements. Dans un système ECS, les entités sont des objets qui peuvent être composés de plusieurs composants. Les composants sont des données qui décrivent les propriétés des entités. Les systèmes sont des fonctions qui agissent sur les entités en fonction de leurs composants.

Mon ECS est basé sur l'ECS d'unity, qui est un moteur de jeu populaire. Il est conçu pour être simple et facile à utiliser.

## Comment utiliser

Pour utiliser la bibliothèque dans votre projet, vous devez inclure le fichier d'en-tête `ecs.h` dans votre code source. Vous devez également lier la bibliothèque à votre projet.

Tout d'abord, allez dans le répertoire de votre projet et clonez ce dépôt :
```bash
git clone --recurse-submodules https://github.com/harmonie-durrant/ecs-minilibx.git
```

Utilisez ce makefile comme guide pour compiler votre projet :
```makefile
# Name of the executable
NAME = my_project
# List of source files
SRCS = main.c
# List of object files
OBJS = $(SRCS:.c=.o)
# Flags for the C compiler (42 requirements)
CFLAGS = -Wall -Wextra -Werror
# Flags for the minilibx and ecs library
LDFLAGS = -L./ecs-minilibx -lecs -L./ecs-minilibx/minilibx-linux -lmlx -lXext -lX11 -lm

# Rule to compile the project
all: $(NAME)

# Compile the library
lib:
	make -s -C ecs-minilibx

# Compile the project (runs by default, also compiles the ecs library)
$(NAME): $(OBJS) lib
	gcc $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

# Remove object files
clean:
	make -s -C ecs-minilibx clean
	rm -f $(OBJS)

# Remove object files and the executable
fclean: clean
	make -s -C ecs-minilibx fclean
	rm -f $(NAME)

# Remove all temporary files and recompile the project
re: fclean all

.PHONY: all lib clean fclean re
```

## À venir

- [x] Ajouter des fonctions pour créer des entités et des composants
- [x] Ajouter des fonctions pour ajouter/supprimer des entités et des composants

- [] Ajouter des types des composants de base
	- [] IsActive (pour activer/désactiver des entités)
	- [] Camera conrtoller (pour déplacer la caméra)
	- [] Collider (hitbox)
	- [] Sound (pour jouer des sons)
	- [] Stats (pour stocker pv, mana, custom stats...)

- [] Ajouter des types des composants 2D (sur l'écran)
	- [] Transform2D (position(x,y), rotation(x,y), scale(x,y))
	- [] Controller2D (pour déplacer des entités 2D)
	- [] Animator (pour animer des sprites 2D)
	- [] Sprite (pour dessiner des images 2D)

- [] Ajouter des types des composants 3D (dans l'espace devant la caméra)
	- [] Transform3D (position(x,y,z), rotation(x,y,z), scale(x,y,z))
	- [] Controller3D (pour déplacer des entités 3D)
	- [] SpriteCube (pour dessiner des cubes 3D)
	- [] Raycast (pour dessiner les entités 3D)

- [] Ajouter une fonction pour dessiner des entités 2D
- [] Ajouter une fonction pour dessiner des entités 3D

## Auteurs

- [harmonie-durrant](https://www.github.com/harmonie-durrant) (Créatrice du projet)
- [42Paris](https://github.com/42Paris/minilibx-linux/graphs/contributors) (Auteurs de la minilibx)

- [Faire un don sur buymeacoffee](https://www.buymeacoffee.com/harmonie)

## Comment contribuer

Si vous souhaitez contribuer à ce projet, veuillez lire le fichier [CONTRIBUTING](CONTRIBUTING.md).

## License

Ce projet est sous licence, vous pouvez trouver la licence dans le fichier [LICENSE](LICENSE).

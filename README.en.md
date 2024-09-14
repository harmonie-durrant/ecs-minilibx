# ECS Minilibx - Harmonie Durrant

🇫🇷 [Français](README.md)

This project is a beefed up version of the minilibx, a graphics library used at 42 Paris. The minilibx is a minimalist graphics library that allows you to create windows and draw pixels, and images. It is used for the graphics projects at 42.

If you are a student at 42, you can use this library for your projects as long as you understand how it works. You can also contribute to this project by submitting pull requests and issues.

⚠️ **Warning:** This project is still in development and is not yet ready for production use. It is recommended to use it only for learning and testing purposes.

## ECS - Entity Component System

ECS is a programming model that allows you to separate data from behavior. In an ECS system, entities are objects that can be composed of multiple components. Components are data that describe the properties of entities. Systems are functions that act on entities based on their components.

My ECS is based on Unity's entity system. Unity is a popular game engine. It is designed to be simple and easy to use.

## How to use

To use the library in your project, you need to include the header file `ecs.h` in your source code. You also need to link the library to your project.

First go to your project directory and clone this repository:

```bash
git clone --recurse-submodules https://github.com/harmonie-durrant/ecs-minilibx.git
```

Use this makefile as a guide to compile your project:
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

## Coming soon

- [x] Add functions to create entities and components
- [x] Add functions to add/remove entities and components

- [] Add documentation for the library

- [] Add basic component types
- [] IsActive (to activate/deactivate entities)
- [] Camera conrtoller (to move the camera)
- [] Collider (hitbox)
- [] Sound (to play sounds)
- [] Stats (to store hp, mana, custom stats...)

- [] Add 2D component types (on screen)
- [] Transform2D (position(x,y), rotation(x,y), scale(x,y))
- [] Controller2D (to move 2D entities)
- [] Animator (to animate 2D sprites)
- [] Sprite (to draw 2D images)

- [] Add 3D component types (in the space in front of the camera)
- [] Transform3D (position(x,y,z), rotation(x,y,z), scale(x,y,z))
- [] Controller3D (to move 3D entities)
- [] SpriteCube (to draw 3D cubes)
- [] Raycast (to draw 3D entities)

- [] Add function to draw 2D entities
- [] Add function to draw 3D entities

## Contributors

- [harmonie-durrant](https://www.github.com/harmonie-durrant) (projet creator)
- [42Paris](https://github.com/42Paris/minilibx-linux/graphs/contributors) (minilibx contributors)

- [Donate to my Buy Me A Coffee page](https://www.buymeacoffee.com/harmonie)

## Contributing

If you want to contribute to this project, please read the [CONTRIBUTING](CONTRIBUTING.md) file.

## License

This project is licensed, you can find the license in the [LICENSE](LICENSE) file.

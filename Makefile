make:
	g++ ./src/**/**/*.cpp ./src/**/*.cpp ./src/*.cpp -o pacman -lSDL2_image -lSDL2 -I./src/

.PHONY: make

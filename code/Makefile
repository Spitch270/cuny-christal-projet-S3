CFLAGS = -O3 `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf -lm




INC = sdl2-light.h objets.h sdl2-ttf-light.h
SRC = main.c sdl2-light.c objets.c sdl2-ttf-light.c
OBJ = $(SRC:%.c=%.o)

PROG = pointandclick

%.o: %.c $(INC)
	gcc $(CFLAGS) -c $<

pointandclick: $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@

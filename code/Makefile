CFLAGS = -O3 `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf -lm




INC = sdl2-light.h gameplay.h affichage.h sdl2-ttf-light.h
SRC = main.c sdl2-light.c gameplay.c affichage.c sdl2-ttf-light.c
OBJ = $(SRC:%.c=%.o)
SRT = tests.c sdl2-light.c gameplay.c affichage.c sdl2-ttf-light.c
OBT = $(SRT:%.c=%.o)


PROG = pointandclick


%.o: %.c $(INC)
	gcc $(CFLAGS) -c $<

pointandclick: $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@


test: $(OBT)
	gcc $(CFLAGS) $(OBT) $(LDFLAGS) -o $@



doc: $(PROG)
	doxygen ./$(PROG)
	make -C latex

clean:
	rm -f *~ *.o $(PROG)
	rm -rf latex html



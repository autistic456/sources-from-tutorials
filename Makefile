BIN=normal_exe liba.so dynamic_exe liba.a static_exe
all: $(BIN)

liba.o: a.c a.h
	cc -c -o $@ a.c

liba.so: a.c a.h
	cc -fPIC -shared -o $@ a.c -lc

liba.a: liba.o
	ar crs $@ $^	

normal_exe: main.c liba.o
	cc -o $@ $^

static_exe: main.c
	cc -o $@ $^ -L. -la

dynamic_exe: main.c
	cc -o $@ $^ -L. -la

clean:
	rm *.o $(BIN) 2>/dev/null



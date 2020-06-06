BINS=addone.so addtwo.so main.exe

all: $(BINS)

%.so: %.c
	cc -fPIC -shared -o $@ $^ -ldl

%.exe: %.c
	cc -o $@ $^ -ldl

clean:
	rm $(BINS) 2>/dev/null

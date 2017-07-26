.PHONY: all clean test
all:
	$(MAKE) -C lib
	$(MAKE) -C src
	$(MAKE) -C lib clean
	./ccomp
	$(MAKE) clean

clean:
	$(MAKE) -C lib clean
	rm -f ccomp

test:
	$(MAKE) -C lib
	$(MAKE) -C src
	$(MAKE) -C lib clean
	./ccomp

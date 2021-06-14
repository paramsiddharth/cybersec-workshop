ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif

.PHONY: build install clean uninstall

build: lla

install: lla
	install -d $(PREFIX)/bin/
	install -m 777 lla $(PREFIX)/bin/

clean:
	-rm -f lla
	-rm -f lla.exe

lla:
	gcc -o lla lla.c

uninstall:
	-rm -f $(PREFIX)/bin/lla
	-rm -f $(PREFIX)/bin/lla.exe
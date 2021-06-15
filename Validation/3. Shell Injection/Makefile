ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif
PROG := lla

.PHONY: build install clean uninstall

build: $(PROG)

install: $(PROG)
	install -d $(PREFIX)/bin/
	install -m 777 $(PROG) $(PREFIX)/bin/

clean:
	-rm -f $(PROG)
	-rm -f $(PROG).exe

$(PROG):
	gcc -o $(PROG) $(PROG).c

uninstall:
	-rm -f $(PREFIX)/bin/$(PROG)
	-rm -f $(PREFIX)/bin/$(PROG).exe
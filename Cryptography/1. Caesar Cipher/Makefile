ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif
PROG := cdec

.PHONY: build install clean uninstall FORCE

build: $(PROG)

install: $(PROG)
	install -d $(PREFIX)/bin/
	install -m 777 $(PROG) $(PREFIX)/bin/

clean:
	-rm -f $(PROG)
	-rm -f $(PROG).exe

$(PROG): FORCE
	gcc -o $(PROG) $(PROG).c

uninstall:
	-rm -f $(PREFIX)/bin/$(PROG)
	-rm -f $(PREFIX)/bin/$(PROG).exe

FORCE: ;
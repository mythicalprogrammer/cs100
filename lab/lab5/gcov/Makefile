# $Id: Makefile,v 1.2 2003/09/13 10:58:38 phf Exp $

CPPFLAGS=-Wall -W -pedantic -O0 -fprofile-arcs -ftest-coverage

xmpl:	xmpl.cpp

.PHONY: clean zip
clean:
	rm -f xmpl *.bb *.bbg *.gcov *.da gmon.out *.tar.gz
zip:	README Makefile xmpl.cpp gcov.pdf
	tar czvf gcov-tutorial.tar.gz $^

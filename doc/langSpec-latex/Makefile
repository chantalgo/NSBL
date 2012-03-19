target = langSpec
refs = MyRefs
output = .

all: clean-dist $(target:%=%.pdf)

%.dvi: %.tex 
	latex $*.tex
	latex $*.tex

%.pdf: %.dvi
	dvipdf $*.dvi
	cp $*.pdf ../

clean-dist: clean
	rm -f *.dvi *.ps *.pdf *.bbl

clean:
	rm -f *.aux *.blg *.log *.out *.hd *.ttt *.fff *.lot *.lof 

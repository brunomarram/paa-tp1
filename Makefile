all:
	gcc ordenacao.h ordenacao.c random.h random.c soma.h soma.c menu.h menu.c -o exec
production:
	gcc ordenacao.h ordenacao.c random.h random.c soma.h soma.c menu.h menu.c -o exec
clean:
	rm exec
run:
	./exec

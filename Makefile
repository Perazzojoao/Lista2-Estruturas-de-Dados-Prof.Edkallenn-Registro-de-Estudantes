CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEPS = estudante/estudante.h historico/historico.h matricula/matricula.h
OBJ = output/ED-lista2-questao03.o output/estudante/estudante.o output/historico/historico.o output/matricula/matricula.o
EXECUTABLE = output/ED-lista2-questao03

output/%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

$(EXECUTABLE): $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)

compilar: 
		if not exist output\estudante (mkdir output\estudante)
		if not exist output\historico (mkdir output\historico)
		if not exist output\matricula (mkdir output\matricula)
		$(MAKE) $(EXECUTABLE)

exec: compilar
		./$(EXECUTABLE)
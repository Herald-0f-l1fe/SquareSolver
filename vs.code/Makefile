CC=g++
CFLAGS=-Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D _DEBUG -D _EJUDGE_CLIENT_SIDE -c
all: Square_Solver

Square_Solver: test.o Solver.o Input_Output.o Supportive_func.o Unit_tests.o
	$(CC) test.o Solver.o Input_Output.o Supportive_func.o Unit_tests.o -o Square_Solver

test.o: test.cpp
	$(CC) $(CFLAGS) test.cpp

Solver.o: Solver.cpp
	$(CC) $(CFLAGS) Solver.cpp

Input_Output.o: Input_Output.cpp
	$(CC) $(CFLAGS) Input_Output.cpp

Supportive_func.o: Supportive_func.cpp
	$(CC) $(CFLAGS) Supportive_func.cpp

Unit_tests.o: Unit_tests.cpp
	$(CC) $(CFLAGS) Unit_tests.cpp

clean:
	rm -rf *.o Square_Solver
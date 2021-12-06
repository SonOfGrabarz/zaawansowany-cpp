# Makefile
main: clean
	@echo "Compiling..."
	g++ -std=c++17 -Wall -pedantic-errors -fopenmp main.cpp -o main && ./main
clean:
	rm -f main

.SILENT:
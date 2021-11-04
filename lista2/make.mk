# Makefile
main: clean
	@echo "Compiling..."
	g++ -std=c++17 -Wall -pedantic-errors main.cpp -o main && ./main
clean:
	rm -f main

.SILENT:
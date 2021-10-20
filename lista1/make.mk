# Makefile
main: clean
	@echo "Compiling..."
	g++ -std=c++17 main.cpp wektor.h -o main && ./main
clean:
	rm -f main

.SILENT:
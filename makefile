build : 
	clear
	clang++ -Wall *.cpp -o bin/Game_of_Life -I ./include -I ./SDL2.framework/Headers -F ./ -framework SDL2
run : 
	./bin/Game_of_Life
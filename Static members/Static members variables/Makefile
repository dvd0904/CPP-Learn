
main.exe: main.cc point.o
	g++ $^ -o $@

point.o: point.cc
	g++ -c $^ -o $@

clean:
	rm *.o
	rm *.exe


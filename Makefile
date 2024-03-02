
main.exe: dai.cc
	g++ $^ -o $@

clean: 
	del main.exe
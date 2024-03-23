
main.exe: dai.cc
	g++ $^ -o $@

clean: 
	del main.exe
	rm main.exe

main.exe: dai.cc
	g++ $^ -o $@

clean: 
	rm main.exe
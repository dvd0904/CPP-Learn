
main.exe: dai.cc dog.cc
	g++ $^ -o $@ -I .

clean: 
	rm main.exe
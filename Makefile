compile:
	cc main.c -O2 -o mmd
clean:
	rm mmd
install:
	mv mmd /usr/bin
uninstall:
	rm /usr/bin/mmd 

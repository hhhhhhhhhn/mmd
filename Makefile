mmd:
	cc main.c -O2 -o mmd
clean:
	rm mmd
install: mmd
	mv mmd /usr/bin
uninstall:
	rm /usr/bin/mmd 

all:
	g++ main.cpp database.cpp -o app

clean:
	rm -f app

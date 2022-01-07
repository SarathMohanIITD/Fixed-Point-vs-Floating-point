all : result

result: main.o doubletofixed.o fixedtodouble.o mulfixed.o addfixed.o timer.o 
	gcc obj/main.o obj/doubletofixed.o obj/fixedtodouble.o obj/mulfixed.o obj/addfixed.o obj/timer.o -o lib/result
	@echo Generating graph. Please wait for a few seconds ........
	./lib/result
	gnuplot -p src/PlotInstuctions.ps
	
main.o: src/main.c
	gcc -c src/main.c -o obj/main.o 

doubletofixed.o: src/DoubleToFixed.c
	gcc -c src/DoubleToFixed.c -o obj/doubletofixed.o

fixedtodouble.o: src/FixedToDouble.c
	gcc -c src/FixedToDouble.c -o obj/fixedtodouble.o

mulfixed.o: src/MulFixed.c
	gcc -c src/MulFixed.c -o obj/mulfixed.o

addfixed.o: src/AddFixed.c
	gcc -c src/AddFixed.c -o obj/addfixed.o

timer.o: src/Calctime.c
	gcc -c src/Calctime.c -o obj/timer.o

clean:
	rm -rf obj/*.o
	rm -f lib/result
	rm -f src/plotdata.dat

final:	main.o Control.o Record.o ReportGenerator.o FarmDistribution.o AnimalPercentChange.o HighestHorseCount.o View.o
	g++ -o final main.o Control.o Record.o ReportGenerator.o FarmDistribution.o AnimalPercentChange.o HighestHorseCount.o View.o

final2:
	make clean && make && valgrind ./final

main.o:	main.cc Control.h
	g++ -c main.cc

Control.o: Control.cc Control.h
	g++ -c Control.cc

Record.o: Record.cc Record.h
	g++ -c Record.cc

ReportGenerator.o: ReportGenerator.cc ReportGenerator.h
	g++ -c ReportGenerator.cc

FarmDistribution.o: FarmDistribution.cc FarmDistribution.h
	g++ -c FarmDistribution.cc

AnimalPercentChange.o: AnimalPercentChange.cc AnimalPercentChange.h
	g++ -c AnimalPercentChange.cc

HighestHorseCount.o: HighestHorseCount.cc HighestHorseCount.h
	g++ -c HighestHorseCount.cc

View.o: View.cc View.h
	g++ -c View.cc

clean:
	rm -f *.o AnimalPercentChange.txt FarmDistribution2011-2016.txt HighestHorseCount2016.txt final final2

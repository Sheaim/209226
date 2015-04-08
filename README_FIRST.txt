Compilation process is begun by setting up the enviroment for the compilator.
In case of Code::Blocks' mingw32 this is accomplished by running 
mingwvars.bat in MinGW folder (see \build\setup.bat for an example)

Next step is running cmake to generate appropriate makefile.
Afterwards the project is compiled using mingw32-make.exe command and run using ctest commant
(see \QuicksortBenchmark\setupAndTest.bat for an example)

These files are composed specifically for my machines and may need tweaking if you're using a different compiler.
Consult cmake manual for further details.

"build" folder contains .bat files neccesary for setting up environments on my machines - they won't work on any other pc.

"common" folder contents have to be compiled first, using provided therein "CmakeLists.txt" file, as it creates the "libcommon.a" library which is used by most other programs.

CAUTION: "QuicksortBenchmark" is dependent upon contents of "quicksort", but can be compiled separately.
Each folder has their own CmakeLists.txt file, so each part of the project has to be compiled separately.

What is important is that "common" folder contents have to be compiled first, as it creates a library "libcommon.a" which is used by other parts of the project.

"build" folder contains .bat files neccesary for setting up compilation environments for my machines, they are not supposed to work on other pcs.
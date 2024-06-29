# HahaVirus
A popping window program, which injects itself into autoruns using WinAPI

## How it works
The program creates an innocent directory "WinSafety" (could be any name) using "CreateDirectoryA"

Then, the program creates there an exe and copies itself to that exe(copy of the "virus" file).

Then the path of that exe is injected into the autoruns registry using "RegSetValueEx".

In the end the program enters the window popper loop(can be any script).

## Result
An executable that, after running once, ensures it automatically runs on every system startup by adding itself to the Windows Registry.

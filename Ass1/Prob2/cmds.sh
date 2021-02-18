# compile multiple source files
gcc server.c client.c -o client

# static library of server
gcc -c server.c # compilation without linking
ar -rc libserver.a server.o # creating static library using archiving

# finally linking the static library
gcc client.c -L. -lserver -o client-static
# link our created static library to generate the final build
# -L.  => will look for the library in the current folder
# -l   => references the library
# server => name of the library, the linker adds the "lib" before and ".a" at the end
# -o   => final binary name

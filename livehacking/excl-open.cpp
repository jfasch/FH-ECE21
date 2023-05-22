#include <fcntl.h>
#include <unistd.h>


#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " FILENAME" << endl;
        return 1;
    }

    const char* filename = argv[1];
    
    int fd = open(filename, O_WRONLY|O_CREAT|O_EXCL);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    char byte = 'x';
    ssize_t nwritten = write(fd, &byte, 1);
    if (nwritten == -1) {
        perror("write");
        return 1;
    }

    return 0;
}

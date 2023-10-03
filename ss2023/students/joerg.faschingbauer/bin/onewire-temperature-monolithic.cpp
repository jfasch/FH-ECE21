#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string>


int main(int argc, char** argv)
{
    if (! (argc == 3 || argc == 4)) {
        std::cerr << argv[0] <<  " <filename> <interval>" << std::endl;
        return 42;
    }
    
    std::string filename = argv[1];
    std::string interval_str = argv[2];
    int niterations = -1;

    if (argc == 4)
        niterations = atoi(argv[3]);

    int interval = atoi(interval_str.c_str());
    unsigned int time_remaining;
    int fd;    
    char buffer[32];
    ssize_t nread;
    ssize_t nwritten;

    int iteration = 0;
    while (niterations == -1 || iteration++ < niterations) {
        fd = open(filename.c_str(), O_RDONLY);
        if (fd == -1) {
            perror("open");
            return 1;
        }

        nread = read(fd, buffer, sizeof(buffer));
        if (nread == -1) {
            perror("read");
            return 2;
        }

        nwritten = write(STDOUT_FILENO, buffer, nread);
        if (nwritten == -1) {
            perror("write");
            return 2;
        }

        time_remaining = sleep(interval);
        if (time_remaining != 0)
            std::cerr << "did not sleep " << interval << " seconds, " << time_remaining << " remaining" << std::endl;

        int error = close(fd);
        if (error == -1) {
            perror("close");
            return 10;
        }
    }

    return 0;
}

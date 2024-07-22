#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        write(1, "使い方: <input file> <output file>\n", 39);
        return (1);
    }
    int inputFd = open(argv[1], O_RDONLY);
    if (inputFd < 0)
    {
        write(2, "Error opening input file\n", 26);
        return (1);
    }
    int outputFd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (outputFd < 0)
    {
        write(2, "Error opening output file\n", 27);
        return (1);
    }
    off_t fileSize = lseek(inputFd, 0, SEEK_END);
    if (fileSize == (off_t)-1)
    {
        write(2, "Error seeking input file\n", 26);
        close(inputFd);
        close(outputFd);
        return (1);
    }

    off_t CurrentPosition = fileSize - 1;
    while (CurrentPosition >= 0)
    {
        char c;
        if (lseek(inputFd, CurrentPosition, SEEK_SET) == -1)
        {
            write(2, "Error seeking input file\n", 26);
            break;
        }
        ssize_t readResult = read(inputFd, &c, 1);
        if (readResult != 1)
        {
            write(2, "Error reading input file\n", 26);
            break;
        }
        ssize_t writeResult = write(outputFd, &c, 1);
        if (writeResult != 1)
        {
            write(2, "Error writing to output file\n", 30);
            break;
        }
        CurrentPosition--;
    }
    close(inputFd);
    close(outputFd);
}

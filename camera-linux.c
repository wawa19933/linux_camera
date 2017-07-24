#include "camera-linux.h"
#include <sys/stat.h>
#include <stdio.h>

static int fileHandle;
char* errorMessage;

enum ErrorCode openDevice (const char* path) {
    int res = 0;
    struct stat st;
    res = stat(path, &st);
    if (res == -1) {
        sprintf(errorMessage, "No such file: %s", path);
        return NotExist;
    }
    if (!S_ISCHR(st.st_mode)) {
        sprintf(errorMessage, "Not a character device: %s", path);
        return NotCharacterDevice;
    }
    // Open device
    fileHandle = open(path, O_RDWR | O_NONBLOCK, 0);
    if (fileHandle == -1) {
        fileHandle = 0;
        sprintf(errorMessage, "Cannot open %s: %s", path, strerror(errno));
        return NotOpened;
    }
    return Success;
}
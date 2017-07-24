#ifndef LINUX_CAMERA_LIBRARY_H
#define LINUX_CAMERA_LIBRARY_H

#include <sys/ioctl.h>
#include <linux/videodev2.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define CLEAR(x) memset(&(x), 0, sizeof(x))

enum ErrorCode {
    Success,
    NotExist,
    NotCharacterDevice,
    NotOpened,

};

enum ErrorCode openDevice (const char* path);
enum ErrorCode initialize (int fh);
enum ErrorCode prepareBuffers (int count);
enum ErrorCode readCapabilities (void);
enum ErrorCode startStreaming (void);
enum ErrorCode stopStreaming (void);
enum ErrorCode releaseBuffer (int id);
enum ErrorCode requestBuffer ();
enum ErrorCode unmapBuffers ();

#endif
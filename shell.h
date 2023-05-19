#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdint.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <string.h>
#include <signal.h>
#include <dirent.h>
#include <errno.h>

//*excute program*//
int execve(const char *pathname, char *const argv[],char *const envp[]);

//*wait*//
pid_t wait(int *wstatus);
pid_t waitpid(pid_t pid, int *wstatus, int options);
int  waitid(idtype_t  idtype,  id_t id, siginfo_t *infop,int options);
pid_t wait3(int *wstatus, int options,struct rusage *rusage);
pid_t wait4(pid_t pid, int *wstatus, int options,struct rusage *rusage);

//*stat (__xstat)*//
int stat(const char *pathname, struct stat *statbuf);
int fstat(int fd, struct stat *statbuf);
int lstat(const char *pathname, struct stat *statbuf);
int fstatat(int dirfd, const char *pathname, struct stat *statbuf,int flags);

//*write*//
ssize_t  write(int  fd,  const  void  *buf,  size_t count);

//*strtok*//
char *strtok(char *str, const char *delim);
char *strtok_r(char *str, const char *delim, char **saveptr);

//*signal*//
typedef void (*sighandler_t)(int);
sighandler_t  signal(int  signum, sighandler_t han‐dler);

//*readdir*//
struct dirent *readdir(DIR *dirp);

//*read*//
ssize_t read(int fd, void *buf, size_t count);

//*perror*//
void perror(const char *s);
const char * const sys_errlist[];
int sys_nerr;
int  errno;

//*open*//
int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
int creat(const char *pathname, mode_t mode);
int openat(int dirfd, const char *pathname, int flags);
int openat(int dirfd, const char *pathname, int flags, mode_t mode);
DIR *opendir(const char *name);
DIR *fdopendir(int fd);

//*malloc*//
void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

//*kill*//
int kill(pid_t pid, int sig);

//*isatty*//
int isatty(int fd);

//*getpid*//
pid_t getpid(void);
pid_t getppid(void);

//*getline*//
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
ssize_t getdelim(char **lineptr, size_t *n, int delim, FILE *stream);

//*getcwd*//
char *getcwd(char *buf, size_t size);
char *getwd(char *buf);
char *get_current_dir_name(void);

//*fork*//
pid_t fork(void);

//*fflush*//
int fflush(FILE *stream);

//*exit*//
void _exit(int status);
void _Exit(int status);

//*closedir*//
int closedir(DIR *dirp);
int close(int fd);

//*chdir*//
int chdir(const char *path);
int fchdir(int fd);

//*access*//
int access(const char *pathname, int mode);
int faccessat(int dirfd, const char *pathname, int mode, int flags);
int faccessat2(int dirfd, const char *pathname, int mode, int flags);

#endif


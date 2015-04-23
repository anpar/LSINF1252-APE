/*
 * D'après sa man page :
 * ECHILD
 * (for wait()) The calling process does not have
 * any unwaited-for children.
 * ECHILD
 * (for waitpid() or waitid()) The process specified by
 * pid (waitpid()) or idtype and id (waitid()) does not
 * exist or is not a child of the calling process. (This
 * can happen for one's own child if the action for SIGCHLD
 * is set to SIG_IGN. See also the Linux Notes section about
 * threads.)
 * EINTR
 * WNOHANG was not set and an unblocked signal or a SIGCHLD
 * was caught; see signal(7).
 * EINVAL
 * The options argument was invalid.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

int main(void)
{
        int status;
        pid_t pid = waitpid(-1, &status, 0);

        if(pid == -1) {
                printf("waitpid() returned -1, errno = %d, strerror(errno) = %s.\n", errno, strerror(errno));
                printf("errno == ECHILD : %d.\n", errno == ECHILD);
                return(EXIT_FAILURE);
        }

        return(EXIT_SUCCESS);
}

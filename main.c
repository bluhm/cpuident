#include <sys/types.h>
#include <sys/time.h>
#include <sys/sched.h>

#define _KERNEL
#include <amd64/cpu.h>
#undef _KERNEL

#include <err.h>
#include <string.h>

int (*cpu_cpuspeed)(int *);

void
microsleep(int delay)
{
	struct timespec to;

	to.tv_sec = delay / 1000000;
	to.tv_nsec = (delay % 1000000) * 1000;
	if (nanosleep(&to, NULL) == -1)
		err(1, "nanosleep");
}

void (*delay_func)(int) = microsleep;

int
main(int argc, char *argv[])
{
	struct cpu_info ci;
	struct device dev;

	memset(&ci, 0, sizeof(ci));
	strlcpy(dev.dv_xname, "cpu0", sizeof(dev.dv_xname));
	ci.ci_dev = &dev;
	identifycpu(&ci);

	return 0;
}

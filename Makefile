PROG=	cpuident
SRCS=	main.c identcpu.c locore.S cacheinfo.c powernow-k8.c via.c est.c
NOMAN=	yes
AFLAGS=	-x assembler-with-cpp -D_LOCORE
DEBUG=	-g

.include <bsd.prog.mk>

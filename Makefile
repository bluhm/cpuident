PROG=	cpuident
SRCS=	main.c identcpu.c cacheinfo.c powernow-k8.c via.c est.c \
	locore.S locore0.S
NOMAN=	yes
AFLAGS=	-x assembler-with-cpp -D_LOCORE
DEBUG=	-g

.include <bsd.prog.mk>

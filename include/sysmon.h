/* @@HEADER-START@@
/*    ___    ___ ________  ________   ________  ___  ________  _______      
/*   |\  \  /  /|\   __  \|\   ____\ |\   ____\|\  \|\   __  \|\  ___ \     
/*   \ \  \/  / | \  \|\  \ \  \___|_\ \  \___|\ \  \ \  \|\  \ \   __/|    
/*    \ \    / / \ \   __  \ \_____  \\ \_____  \ \  \ \   _  _\ \  \_|/__  
/*     \/  /  /   \ \  \ \  \|____|\  \\|____|\  \ \  \ \  \\  \\ \  \_|\ \ 
/*   __/  / /      \ \__\ \__\____\_\  \ ____\_\  \ \__\ \__\\ _\\ \_______\
/*  |\___/ /        \|__|\|__|\_________\\_________\|__|\|__|\|__|\|_______|
/*  \|___|/                  \|_________\|_________|
/*
/*   Auteur  : Yassire Daniel Allaoui
/*   Login   : yassire.exe
/*   Email   : ydanielallaoui@gmail.com
/*
/*   Created : 2026/09/24 01:24:23
/*   Updated : 2026/09/24 01:24:23
/* @@HEADER-END@@ */

#ifndef SYSMON_H
# define SYSMON_H

#include <unistd.h> // pour les fonctions write, read, close, usleep, fork...
#include <fcntl.h> // pour open, O_RDONLY
#include <stdlib.h> // malloc, free, exit
#include <signal.h> // signal, SIGNIT

typedef struct s_cpu
{
	long	user; // CPU time in user mode
	long	nice; // CPU time in nice mode (low priority)
	long	system; // CPU time in kernel mode 
	long	idle; // CPU inactif
	long	iowait; // CPU time atttent
	long	irq; // time of tretement of interuptions
	long	softirq; // time of tretment of softwares tretments
	long	total; // additionnal of all packs
}t_cpu;

typedef struct s_mem
{
	int	total; //total memorie(kb)
	int	free; // freee memorie(kb)
	int	available; // available memorie(kb)
	int	buffers; // buffers memorie(kb)
	int	cached; // cahe memorie(kb)
}t_mem;

typedef struct s_proc
{
	int	pid; // id of processus
	char	name[64]; // name of processus(comm)
	long	cpu_time; // Cpu total time (utime + stime)
}t_proc;

// ft_put.c
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(long n);
void	ft_putnbr_int(int n);

//ft_atoi.c
int	ft_atoi(char *s);
long	ft_atol(char *s);

//cpu.c
void	read_cpu(t_cpu *cpu);
int	cpu_usage(t_cpu *prev, t_cpu *curr);

//mem.c
void	read_mem(t_mem *mem);

//proc.c
int	count_procs(void);
void	read_top_procs(t_proc *procs, int max);

//display.c
void	display_header(void);
void	display_cpu(t_cpu *cpu, int usage);
void	display_mem(t_mem *mem);
void	display_procs(t_proc *procs, int count);

//main.c (for the signal)
void	handle_sigint(int sig);

#endif

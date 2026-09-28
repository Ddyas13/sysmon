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
/*   Created : 2026/09/28 23:30:19
/*   Updated : 2026/09/28 23:30:19
/* @@HEADER-END@@ */

#include "sysmon.h"

//display_header: format the screen and print title
void	display_header(void)
{
	ft_putstr("\033[H\033[J");
	ft_putstr("========================================\n");
	ft_putstr("           SYSMON v1.0                  \n");
	ft_putstr("   System Monitor - Ctrl+C for exit\n");
	ft_putstr("========================================\n\n");
}

//display_cpu: print the cpu informations
void	display_cpu(t_cpu *cpu, int usage)
{
	ft_putstr("=== CPU ===\n");
	ft_putstr("Utilisation : ");
	ft_putnbr(usage);
	ft_putstr(" %\n");
	ft_putstr("User   : ");
	ft_putnbr(cpu->user);
	ft_putchar('\n');
	ft_putstr("System : ");
	ft_putnbr(cpu->system);
	ft_putchar('\n');
	ft_putstr("Idle   : ");
	ft_putnbr(cpu->idle);
	ft_putchar('\n');
	ft_putchar('\n');
}

//display_mem: print the memorie informations in Mo.
//the values in /proc/meminfo are in kb. it will be divided by 1024 for obtain MO
void	display_mem(t_mem *mem)
{
	ft_putstr("=== MEMOIRE ===\n");
	ft_putstr("Total     : ");
	ft_putnbr_int(mem->total / 1024);
	ft_putstr(" Mo\n");
	ft_putstr("Libre     : ");
	ft_putnbr_int(mem->free / 1024);
	ft_putstr(" Mo\n");
	ft_putstr("Disponible: ");
	ft_putnbr_int(mem->available / 1024);
	ft_putstr(" Mo\n");
	ft_putchar('\n');
}

//display_proc: print the number of processus and the top 5
void	display_procs(t_proc *procs, int count)
{
	int	i;

	ft_putstr("=== PROCESSUS ===\n");
	ft_putstr("Total : ");
	ft_putnbr(count);
	ft_putchar('\n');
	ft_putstr("Top 5 :\n");
	i = 0;
	while (i < count && i < 5)
	{
		ft_putstr("  [");
		ft_putnbr(procs[i].pid);
		ft_putstr("] ");
		ft_putstr(procs[i].name);
		ft_putchar('\n');
i++;
	}
	ft_putchar('\n');
}

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

#include <unistd.h> // pour les fonctions write, read, close, usleep, fork...
#include <fcntl.h> // pour open, O_RDONLY
#include <stdlib.h> // malloc, free, exit
#include <signal.h> // signal, SIGNIT

// ft_put.c
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(long n);
void	ft_putnbr_int(int n);

//ft_atoi.c
int	ft_atoi(char *s);
long	ft_atol(char *s);

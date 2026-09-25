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
/*   Created : 2026/09/25 15:15:07
/*   Updated : 2026/09/25 15:15:07
/* @@HEADER-END@@ */

#include "sysmon.h"

//ft_putchar write a caracter on the standart output
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

//ft_putstr write a  string caracter by caracter
void	ft_putstr(char *s)
{
	while(*s)
	{
		write(1, s, 1);
		s++; 
	}
}

//ft_putnbr print a long integer | without printf
void	ft_putnbr(long n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}

	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

//ft_putnbr | version for int | i will use for the memorie
void	ft_putnbr_int(int n)
{
	ft_putnbr((long)n);
}

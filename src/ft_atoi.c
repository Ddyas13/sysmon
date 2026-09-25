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
/*   Created : 2026/09/25 22:58:09
/*   Updated : 2026/09/25 22:58:09
/* @@HEADER-END@@ */

#include "sysmon.h"

// pass a string to integer
int	ft_atoi(char *s)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;

	// first : skip white spaces
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' ||
		s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
		i++;
	//second : manage the sign
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	//third : gather the numbers
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result * sign);
}

 //ft_atoi | long version for cpu counters (for not have overflowing)
long	ft_atol(char *s)
{
	long	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' ||
		s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
		i++;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
	{
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result * sign);
}

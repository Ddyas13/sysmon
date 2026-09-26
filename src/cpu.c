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
/*   Created : 2026/09/26 01:12:25
/*   Updated : 2026/09/26 01:12:25
/* @@HEADER-END@@ */

//read_cpu :  read /proc/stat et fills the t_cpu structure
void	read_cpu(t_cpu *cpu)
{
	int	fd;
	char	buf[1024];
	int	n;
	int	i;

	fd = open("/proc/stat", O_RDONLY);
	if (fd == -1)
		return ;
	n = read(fd, buf, 1023);
	if (n <= 0)
	{
		close(fd);
		return ;
	}
	buf[n] = '\0';
	close(fd);
	
	//skip "cpu" at the start of the informational string
	i = 0;
	while (buf[i] && buf[i] != ' ')
		i++;
	
	//skip  the spaces 
	while (buf[i] == ' ')
		i++;

	// read user
	cpu->user = ft_atol(&buf[i]);
	while (buf[i] && buf[i] != ' ') i++;
	while (buf[i] == ' ') i++;

	//read nice
	cpu->nice = ft_atol(&buf[i]);
	while (buf[i] && buf[i] != ' ') i++;
	while (buf[i] == ' ') i++;

	//read system
	cpu->system = ft_atol(&buf[i]);
	while (buf[i] && buf[i] != ' ') i++;
	while (buf[i] == ' ') i++;

	//read idle
	cpu->idle = ft_atol(&buf[i]);
	while (buf[i] && buf[i] != ' ') i++;
	while (buf[i] == ' ') i++;

	//read iowait
	cpu->iowait = ft_atol(&buf[i]);
	while (buf[i] && buf[i] != ' ') i++;
	while (buf[i] == ' ') i++;

	//read irq
	cpu->irq = ft_atol(&buf[i]);
	while (buf[i] && buf[i] != ' ') i++;
	while (buf[i] == ' ') i++;

	//read softirq
	cpu->softirq = ft_atol(&buf[i]);

	//calculate the total
	cpu->total = cpu->user + cpu->nice + cpu->system
		+ cpu->idle + cpu->iowait + cpu->irq + cpu->softirq;
}

//cpu_usage : calculate the % used by the cpu between two reading
int cpu_usage(t_cpu *prev, t_cpu *curr)
{
	long	delta_total;
	long	delta_idle;
	int	usage;

	delta_total = curr->total - prev->total;
	delta_idle = curr->idle - prev->idle;
	if (delta_total == 0)
		return (0);
	usage = (int)((100 * (delta_total - delta_idle)) / delta_total);
	return (usage);
}

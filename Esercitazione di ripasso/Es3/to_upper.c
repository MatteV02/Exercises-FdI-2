void ToUpper(char *str) 
{
	while (*str != 0) {
		if (*str >= 'a' && *str <= 'z') {
			*str -= 0x20;
		}
		str++;
	}
}
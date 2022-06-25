extern int ContaOccorrenze(const char *filename, const char *str);

int main(void)
{
	int ret = ContaOccorrenze("file1.txt", "parola");

	return 0;
}
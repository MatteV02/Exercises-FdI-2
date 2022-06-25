#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ContaOccorrenze(const char *filename, const char *str)
{
	int ret = 0;
	if (filename != NULL && str != NULL) {
		FILE *f = fopen(filename, "r");
		if (f) {
			char *testo = malloc(1);
			size_t testo_dim = 1;

			while (1) {
				int c = fgetc(f);

				if (c == EOF)
					break;

				testo = realloc(testo, testo_dim + 1);
				testo[testo_dim-1] = c;
				testo_dim++;
			}
			testo[testo_dim - 1] = 0;

			char *temp = testo;
			while (1) {
				temp = strstr(temp, str);

				if (temp == NULL)
					break;

				ret++;
				temp += strlen(str);
			}

			free(testo);
			fclose(f);
		}
	}

	return ret;
}
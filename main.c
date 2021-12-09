#include <stdio.h>
#include <stdlib.h>

void drawGraph(int** mas, int size);
void addEdge(int** mas, int size, int vertex1, int vertex2);
void freeMemory(char* mas);


int main(void) {
	int width;
	int vertex1;
	int vertex2;
	printf("Enter the dimension: ");
	scanf("%d", &width);

	printf("\nEnter the rows of your matrix! Press 'SPACE' to change column and 'ENTER' to change row\n");

	getchar();

	int** mas = NULL;
	mas = (int**)malloc(sizeof(*mas) * width);
	for (int i = 0; i < width; i++) {
		mas[i] = (int*)malloc(sizeof(**mas) * width);
	}

	char* s, c;
	s = (char*)malloc(sizeof(char));


	for (int i = 0, m = 1, j = 0; j < width; j++) {

		while ((c = getchar()) != '\n') {

			if (c < '0' && c > '9' && c != ' ') {
				printf("ERROR: the entered values is wrong!\n");
				return -1;
			}

			if (c != ' ') {
				s[m - 1] = c;

				s = (char*)realloc(s, sizeof(char) * (++m));
			}

			else {
				s[m - 1] = '\0';

				if (i >= width) {
					printf("ERROR: numders that you entered more than entered width!\n ");
					return -1;
				}

				mas[i][j] = atoi(s);
				i++;
				m = 1;

             freeMemory(s);
			}
		}

		s[m - 1] = '\0';

		mas[i][j] = atoi(s);

		if (i < width) {
			++i;
			while (i < width)
				mas[i++][j] = 0;
		}

		i = 0;
		m = 1;

		freeMemory(s);
	}

	free(s);
	s = NULL;

	drawGraph(mas, width);

	while(1)
    {
      printf("\n\nAdd edges between specified vertices!\n");
      printf("\nEnter the first vertex\n");
      scanf("%d", &vertex1);
      printf("Enter the second vertex\n");
      scanf("%d", &vertex2);

      AddEdge(mas, width, vertex1, vertex2);
      drawGraph(mas, width);
    }

	for (int i = 0; i < width; i++)
    free(mas[i]);
	free(mas);
	mas = NULL;

	return 0;
}

void drawGraph(int** mas, int size)
{
	printf("graph G{\n");

	for (int j = 0; j < size; j++) {
		for (int i = j; i < size; i++)
			for (int k = 0; k < mas[i][j]; k++)
				printf("%d -- %d;\n", j+1, i+1);
	}
	printf("}");

}

void AddEdge(int** mas, int size, int vertex1, int vertex2)
{

    for (int i = 1; i <=size; i++) {
		for (int j = 1; j<= size; j++){
            if(((i==vertex1)&&(j==vertex2))||((i==vertex2)&&(j==vertex1)))
                mas[i-1][j-1]++;
		}

    }

}

void freeMemory(char* mas) {
	free(mas);
	mas = NULL;
	mas = (char*)malloc(sizeof(char));
}



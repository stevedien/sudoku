#include "Sudoku.h"

Sudoku::Sudoku()
	{
	    matrix = new int*[N];
	    for (int i =0; i < N; ++i)
        {
            matrix[i] = new int[N];
        }
	}
Sudoku::~Sudoku()
	{
	    for (int i = 0; i <N; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
	}
void Sudoku::showBoard()
	{
		int i, j;
			int k;
			printf("\n");

			for( i=0; i<N; i++ )
			{
				for(k=0; k <= 4*N; k++ )
				{
					printf("-");
				}
				printf("\n|");
			    for( j=0; j<N; j++ )
				{
					if( matrix[i][j] == 0 )
					{
						printf("   |");
					} else
					{
						printf(" %d |", matrix[i][j]);
					}

					}
					printf("\n");
				}
				for(k=0; k<=4*N; k++ )
				{
					printf("-");
				}
				printf("\n");

				return;
	}
void Sudoku::resetBoard(int *count)
	{
		*count = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                matrix[i][j] = 0;
            }
        }
	}
void Sudoku::handleInput(int *row, int *col, int *value)
	{
		int i=0;
			do{
				if( i != 0 ){
					printf("Invalid column/ row index.\n"
							"Please try again\n");
				}
				printf("Enter line number index : ");
				scanf("%d", row);
				printf("Enter column number index : ");
				scanf("%d", col);
				printf("Enter value you want to fill : ");
				scanf("%d", value);
				i=1;
			}while( !((*row>= 0 && *row<9) && (*col>= 0 && *col<9)
					&& (*value> 0 && *value<=9)));
	}
int Sudoku::checkRow(int row, int value)
	{
		int j=0;

			for( j=0; j<N; j++ )
			{
				if( matrix[row][j] == value )
				{
					return 0;
				}
			}
			return 1;
	}
int Sudoku::checkCol(int col, int value)
	{
		int i=0;

			for( i=0; i<N; i++ )
			{
				if( matrix[i][col] == value )
				{
					return 0;
				}
			}
			return 1;
	}
int Sudoku::checkSpecial(int row, int col, int value)
	{
		int i=0;
			int j=0;
			int R = row/3;
			int C = col/3;

			for( i=R; i<R+3; i++ )
			{
				for( j=C; j<C+3; j++ )
				{
					if( matrix[i][j] == value )
					{
						return 0;
					}
				}
			}
			return 1;
	}
int Sudoku::upateBoard(int row, int col, int value)
	{
		if( checkCol(col, value)	||
				checkRow (row, value) ||
				checkSpecial(row, col, value) )
			{
				matrix[row][col] = value;
				return 1;
			}
			return 0;
	}
void Sudoku::run()
	{
        int row, col;
	    int value;
	    int ret;
	    int count;
		// variable nécessaire pour arreter le jeu.
	    resetBoard(&count);
	    showBoard();

		while( count != N*N )
		{
			handleInput( &row, &col, &value );
			ret = upateBoard( row, col, value );
			if( ret == 1 ){
				showBoard();
				count++;
			}else{
				printf("\nCombinaison non valide\n");
			}
		}
	}

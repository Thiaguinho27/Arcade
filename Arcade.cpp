
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>
#include <stdarg.h>
#define CIMA 72
#define BAIXO 80
#define ENTER 13
#define ESC 27
#define SLOW 5

/* Joice Fernanda Ferreira da Silva.
Thiago Antônio Teixeira das Neves.
*/

int menu_princ();
//---------------------------------------------------------------------------------------------------------------
text_info vActual = {0, 0, 79, 24, WHITE, WHITE, C80, 25, 80, 1, 1};

void showConsoleCursor(bool showFlag) 
{ 
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    //
    GetConsoleCursorInfo(hOut, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(hOut, &cursorInfo);
    return;
} 

void textbackground(int newcolor)
{
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
      (csbi.wAttributes & 0x0f) | (newcolor << 4));
   vActual.attribute = (csbi.wAttributes & 0x0f) | (newcolor << 4);
}


void textcolor(int newcolor)
{
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
      (csbi.wAttributes & 0xf0) | newcolor);
   vActual.attribute = (csbi.wAttributes & 0xf0) | newcolor;
}

void gotoxy( int x, int y )
{
COORD coord;
coord.X = (short)x;
coord.Y = (short)y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void faz_borda(int x_ini, int x_fim, int y_ini, int y_fim, int cor)
{
	textbackground(BLACK);
	textcolor(YELLOW);
	
	int c1=201,c2=205,c3=187,c4=186,c5=200;
	gotoxy(x_ini,y_ini);
	printf("%c",c1);
	for(int a=x_ini+1;a<x_fim;a++)//Barra superior
	{
		gotoxy(a,y_ini);
		printf("%c",c2);
	}
	printf("%c",c3);
	for(int b=y_ini+1;b<y_fim;b++)//Canto esquerdo
	{
		gotoxy(x_ini,b);
		printf("%c",c4);
	}
	gotoxy(x_ini,y_fim);
	printf("%c",c5);
	for(int a=x_ini+1;a<x_fim;a++)//Barra inferior
	{
		gotoxy(a,y_fim);
		printf("%c",c2);
	}
	printf("%c",188);
	for(int b=y_ini+1;b<y_fim;b++)//Canto direito
	{
		gotoxy(x_fim,b);
		printf("%c",c4);
	}
	textbackground(BLACK);
	
}

//---------------------------------------------------------------------------------------------------------------

// Perfil do usuario
struct perfil
{
	char nome[40];
	char email[40];
	char user[40];
	char admin;
	char excluido;
	struct nasci
	{
		int dia1;
		int mes1;
		int ano1;
	}idade;
	char senha[40];
	
}client;

// ARQUIVO
FILE*arq;

//Informacoes dos jogos a serem cadastrados
struct jogo
{	
	char name[40];
	struct data
	{
		char dia[2];
		char mes[2];
		char ano[4];
	}lanc;
	char cod[10];
}info_gm;


//---------------------------------------------------------------------------------------------------------------

void Loading()
{
	system("color 1f");
	system("title ____________________________________LOADING________________________________________");
	gotoxy(30,10);
	
	float i, j;
   system("cls");
  printf ("\nCarregando: \n\n");          
   for (i = 0; i <= 100; i+=1.8)
   {                     
      printf ("%.2f%%\r", i);
      fflush (stdout);                      
         
      for (j = 0; j < i; j+=1.4)
      {
         if (!j)
           printf ("  ");
           
         printf ("%c",254);
         Sleep(3);
      }                      
   } 
   
	system("cls");
}

//---------------------------------------------------------------------------------------------------------------
void tela_dados()//Imprime tabela de consulta geral
{
textcolor(5);
textbackground(BLACK);

gotoxy(2,3);printf("|          |            |                     |       |                    |");
gotoxy(2,4);printf("|          |            |                     |       |                    |");
gotoxy(2,5);printf("|          |            |                     |       |                    |");
gotoxy(2,6);printf("|          |            |                     |       |                    |");
gotoxy(2,7);printf("|          |            |                     |       |                    |");
gotoxy(2,8);printf("|          |            |                     |       |                    |");
gotoxy(2,9);printf("|          |            |                     |       |                    |");
gotoxy(2,10);printf("|          |            |                     |       |                    |");
gotoxy(2,11);printf("|          |            |                     |       |                    |");
gotoxy(2,12);printf("|          |            |                     |       |                    |");
gotoxy(2,13);printf("|          |            |                     |       |                    |");
gotoxy(2,14);printf("|          |            |                     |       |                    |");
gotoxy(2,15);printf("|          |            |                     |       |                    |");
gotoxy(2,16);printf("|          |            |                     |       |                    |");
gotoxy(2,17);printf("|          |            |                     |       |                    |");
gotoxy(2,18);printf("|          |            |                     |       |                    |");
gotoxy(2,19);printf("|          |            |                     |       |                    |");
gotoxy(2,20);printf("|          |            |                     |       |                    |");
gotoxy(2,21);printf("|__________|____________|_____________________|_______|____________________|");
textcolor(WHITE);
textbackground(BLACK);
}

void tela_dados1()//Imprime tabela de consulta geral
{
textcolor(GREEN);
textbackground(BLACK);

gotoxy(2,3);printf("|                     |               |                     |          |");
gotoxy(2,4);printf("|                     |               |                     |          |");
gotoxy(2,5);printf("|                     |               |                     |          |");
gotoxy(2,6);printf("|                     |               |                     |          |");
gotoxy(2,7);printf("|                     |               |                     |          |");
gotoxy(2,8);printf("|                     |               |                     |          |");
gotoxy(2,9);printf("|                     |               |                     |          |");
gotoxy(2,10);printf("|                     |               |                     |          |");
gotoxy(2,11);printf("|                     |               |                     |          |");
gotoxy(2,12);printf("|                     |               |                     |          |");
gotoxy(2,13);printf("|                     |               |                     |          |");
gotoxy(2,14);printf("|                     |               |                     |          |");
gotoxy(2,15);printf("|                     |               |                     |          |");
gotoxy(2,16);printf("|                     |               |                     |          |");
gotoxy(2,17);printf("|                     |               |                     |          |");
gotoxy(2,18);printf("|                     |               |                     |          |");
gotoxy(2,19);printf("|                     |               |                     |          |");
gotoxy(2,20);printf("|                     |               |                     |          |");
gotoxy(2,21);printf("|_____________________|_______________|_____________________|__________|");
textcolor(WHITE);
textbackground(BLACK);
}

float arredonda_F(float aux)
{
	int aux1;
	aux1 = int(aux);
	
	aux = aux-aux1;
	
	if(aux > 0,5)
	{
		aux1++;
	}
	
	aux = aux1;
	
	return(aux);
	
}

void exclusao()
{
	int aux_exclu;
	int num_Pg;
	float num_Pags;
	int tam_File = 0;
	int pag = 0;
	long ftam;
	int lin3 = 3;
	char aux;
	int lin2 = 1;
	int lin = 4;
	system("cls");
	printf("%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%CEXCLUSAO DE CADASTRO%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C",254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254);
	showConsoleCursor(false);
	if((arq = fopen("usuario.bin","rb+")) == NULL)
	{
		system("cls");
		gotoxy(10,10);
		textcolor(RED);
		printf("Erro na abertura do arquivo");
		getch();
		textcolor(WHITE);
		return;
	}
	
	rewind(arq);
	while(!feof)
	{
		fread(&client,sizeof(client),1,arq);
		tam_File++;
	}
	num_Pags = (float(tam_File)/19.00);
		
	num_Pg = arredonda_F(num_Pags);

	rewind(arq);
	
	
	while(true)
	{
//		Checa a pagina para levalo la 
		for(int h = 0;h<pag;h++)
		{
			for(int x = 0;x<20;x++)
			{
				fread(&client,sizeof(client),1,arq);
			}
		}
		
		while(!feof(arq) && lin < 20)
		{	
			textcolor(YELLOW);
			gotoxy(4,2);printf("USUARIO");
			gotoxy(18,2);printf("NOME");
			gotoxy(34,2);printf("E-MAIL");
			gotoxy(50,2);printf("ADMIN");
			gotoxy(58,2);printf("DATA DE NASCIMENTO");
			gotoxy(4,22);printf("-> Para voltar ao menu, presione a tecla ESC.");
			textcolor(WHITE);
			gotoxy(4,23);printf("° Utilize as setas do teclado para selecao. Pressione ENTER para exluir.°");
			fread(&client,sizeof(client),1,arq);
			if(client.excluido == 'n')
			{
				gotoxy(4,lin);puts(client.user);
				gotoxy(18,lin);puts(client.nome);
				gotoxy(34,lin);puts(client.email);
				gotoxy(52,lin);putchar(client.admin);
				gotoxy(61,lin);printf("%d/%d/%d",client.idade.dia1,client.idade.mes1,client.idade.ano1);
				lin++;	
			}

		}
		aux = getch();
		if(aux == CIMA)
		{
			lin2--;
			lin3--;
		}
		else if(aux == BAIXO)
		{
			lin2++;
			lin3++;
		}
		if(lin3 <=2)
		{
			if(pag != 1)
			{
				pag--;
			}
			else if(pag == 1)
			{
				pag = num_Pg;
			}
 			lin2 = 19;
			lin3 = 17;
		}
		if(lin3 >= 20)
		{
			if(pag == num_Pg)
			{
				pag = 1;
			}
			else if(pag != num_Pg)
			{
				pag++;
			}
			lin2 = 1;
			lin3 = 3;
			lin = 3;
		}

		for(int y = 0;y<19;y++)
		{
			gotoxy(1,y);printf("  ");
		}
		gotoxy(1,lin3);
		printf(">>");
		if(aux == ENTER)
		{
			
			
			ftam = 0;
			for(int x = 0;x<80;x++)
			{
				printf(" ");
				Beep(0,50);
			}
			
			aux_exclu = (((pag)*lin2) + lin2);
			
			rewind(arq);
			
			for(int j = 0 ; j< (aux_exclu) ; j++)
			{
				fread(&client,sizeof(client),1,arq);
				if(client.excluido == 's')
				{
					j--;
				}
			}
			ftam = ftell(arq);
			fseek(arq,ftam-(sizeof(client)),SEEK_SET);
			
			client.excluido = 's';
			
			fflush(arq);
			if(fwrite(&client,sizeof(client),1,arq) == 1)
			{
				printf("-> Exclusao efetuada com sucesso!");
			}
			fflush(arq);
			rewind(arq);
			lin = 3;
			system("cls");   
		}
		if(aux == ESC)
		{
			fclose(arq);
			system("cls"); 
			return;
		}
	}
	fclose(arq);
}

void func_Pega_Dado()
{
		int aux,aux2,aux3;
		char aux_dia[2];
		char aux_mes[2];
		char aux_ano[4];	//Usado temporarioamente
		fflush(stdin);		//gotoxy(3,1);printf("NASCIMENTO");
						//gotoxy(17,1);printf("USUARIO");
						//gotoxy(55,1);printf("NOME");
						//gotoxy(35,1);printf("E-MAIL");
					
		do
		{
			gotoxy(3,4);
			gets(aux_dia);
			aux = atoi(aux_dia);
			gotoxy(5,4);
			gets(aux_mes);
			aux2 = atoi(aux_mes);
			gotoxy(8,4);
			gets(aux_ano);	
			aux3 = atoi(aux_ano);
			
		}while( (aux < 0 )|| (aux > 31 )|| (aux2 < 0 )|| (aux2 > 12 ) || (aux3 < 0 )|| (aux3 > 2018 ));
		gotoxy(55,4);
		gets(client.nome);
		gotoxy(35,4);
		gets(client.email);

		client.idade.dia1 = atoi(aux_dia);
		client.idade.mes1 = atoi(aux_mes);
		client.idade.ano1 = atoi(aux_ano);
}


void altera_Cad()
{		
	printf("%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%CALTERACAO DE CADASTRO%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C",254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254);
	gotoxy(3,22);printf("-> Para voltar ao menu, pressione \"ESC\".");
	char an;
	char answ = 'n';
	int i = 0;
	showConsoleCursor(true);
	
	fflush(stdin);
	float fposicao;
	int F;
	faz_borda(1,78,1,23,14);
	textcolor(WHITE);
	perfil aux_client;
	char pesq[40];
	char senha[40];
	do
	{			
			gotoxy(8,12);printf("Entre com a conta que deseja alterar (Nome de usuario): ");
			fflush(stdin);
			gets(pesq);
			strupr(pesq);
			//	printf("OI");
			//	getch();
			//	cout << "Tchau";
			if((arq = fopen("usuario.bin","rb+")) == NULL)
			{
				printf("erro na abertura do arquivo");
				Beep(0,540);
			}
			else
			{
				
		//		cout << "HI MAN";
				rewind(arq);
		//		getch();
		//		cout <<"MANITO";
				
				do
				{
		//			getch();
					F = 0;
		//			if(fread(&client,sizeof(client),1,arq) )
		//			{
						fread(&client,sizeof(client),1,arq);
						strupr(client.user);
						
						
						if(strstr(client.user,pesq) != NULL && client.excluido == 'n')
						{
							system("cls");
							gotoxy(63,2);printf("Nascimento");
							gotoxy(29,2);printf("Usuario");
							gotoxy(50,2);printf("E-mail");
							gotoxy(10,2);printf("Nome");
							
							aux_client = client;
							faz_borda(1,78,0,23,16);
							tela_dados1();
	
							gotoxy(4,4);
							puts(client.nome);
							gotoxy(42,4); 
							puts(client.email);
							gotoxy(64,4);
							printf("%d/%d/%d",client.idade.dia1,client.idade.mes1,client.idade.ano1);
							gotoxy(26,4);puts(client.user);
							gotoxy(35,15);
//							printf("Entre com a sua senha: ");
							fflush(stdin);
							
							do
							{
								senha[i] = getche();
								i++;	
							}while(strlen(senha) <1 && i <20);
							
							if(strcmpi(client.senha,senha))
							{
		
								F = 1;
								fposicao = ftell(arq);
								func_Pega_Dado();
								if(client.nome[0] == '\0')
									strcpy(client.nome,aux_client.nome);
									
								if(client.email[0] == '\0')
									strcpy(client.email,aux_client.email);
									
								if(client.idade.dia1 == 0)
									client.idade.dia1 = aux_client.idade.dia1;
								if(client.idade.mes1 == 0)
									client.idade.mes1 = aux_client.idade.mes1;
								if(client.idade.ano1 == 0)
									client.idade.ano1 = aux_client.idade.ano1;
								gotoxy(20,24);
								printf("Voce deseja salvar os dados\? ");
								an = getch();
								if(an == 's' || an == 'S')
								{
									fseek(arq,fposicao-(sizeof(client)),SEEK_SET);
									
									fwrite(&client,sizeof(client),1,arq);	
									
									fflush(arq);
									fclose(arq);
									system("cls");
									textcolor(WHITE);
									break;
								}
								else 
								{
									fclose(arq);
		//							cout <<"FUDEU";
									system("cls");
									break;
								}
							}
							else
							{
								system("cls");
								textcolor(RED);
								gotoxy(10,10);
								printf("Senha Incorreta");
								Beep(0,1000);
								textcolor(WHITE);
								return;
							}
						}
						
		//			}
		//			else
		//			{
		//				gotoxy(10,10);
		//				printf("Erro na leitura do arquivo");
		//				Beep(0,1000);
		//				return;
		//			}
				}while(!feof(arq) );	
				faz_borda(1,78,1,23,14);
				textcolor(WHITE);
				gotoxy(25,15);printf("-> Deseja alterar outro cadastro? ");
				fflush(stdin);
				answ = getch();
				
				if(answ == 's' || answ == 'S')
				{
					
				}
				else
				{
					break;
				}
			}
				char oi;
			oi = getch();
			if(oi == ESC)
			{
			return;
			}	
	}while(true);	
	fclose(arq);
	system("cls");
	
}

void consulta_Geral()
{
	printf("%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%CCONSULTA GERAL%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C",254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254);
	textbackground(BLACK);
	faz_borda(1,78,1,23,14); 
	char oi;
	textcolor(GREEN);
	tela_dados();
	gotoxy(4,2);printf("USUARIO");
	gotoxy(18,2);printf("NOME");
	gotoxy(34,2);printf("E-MAIL");
	gotoxy(50,2);printf("ADMIN");
	gotoxy(58,2);printf("DATA DE NASCIMENTO");
	
	
	
	gotoxy(3,22);printf("-> Para voltar ao menu, pressione \"ESC\". Aperte outras teclas para avancar.");
	arq = fopen("usuario.bin","rb");
	int lin = 4;
	rewind(arq);
	do
	{
	textcolor(WHITE);
	while(!feof(arq) && lin!=15)
	{
	  fread(&client,sizeof(client),1,arq);
	      gotoxy(3,lin);puts(client.user);
	  gotoxy(14,lin);puts(client.nome);
	  gotoxy(27,lin);puts(client.email);
	  gotoxy(52,lin);putchar(client.admin);
	  gotoxy(58,lin);
	    printf("%d",client.idade.dia1);printf("/");
		printf("%d",client.idade.mes1);printf("/");
		printf("%d",client.idade.ano1);
	  lin++;
	}
	oi = getch();
	if(oi == ESC)
	{
	system("cls");
	return;
	}
	else
	{
	lin=16;
	system("cls");
	textbackground(BLACK);
	faz_borda(1,78,1,23,14);
	tela_dados(); 
	textcolor(WHITE);
	gotoxy(3, 22);printf("-> Para voltar ao menu, pressione \"ESC\". Aperte outras teclas para avancar.");
	lin = 6;
	}
	}while(true);
	fclose(arq);
}

void Consulta_Esp_Nome()
{
	int lin = 3;
	char pesq[40];
	system("cls");
	printf("%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%CCONSULTA ESPECIFICA%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C",254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254);
	faz_borda(1,78,1,23,14);
	gotoxy(3,22);printf("-> Para voltar ao menu, pressione \"ESC\".");
	gotoxy(20, 15);
	textcolor(WHITE);
	printf("Entre com o nome de usuario: ");
	gotoxy(3,22);printf("-> Para voltar ao menu, pressione \"ESC\".");
	
	gets(pesq);
	strupr(pesq);
	
	system("cls");
	
	
	if((arq = fopen("usuario.bin","rb")) == NULL)
	{
		printf("Erro na abertura do arquivo");
	}
	else
	{
		rewind(arq);
		while(!feof(arq))
		{
			system("cls");
			faz_borda(1,78,1,23,14);
			tela_dados();
			gotoxy(3,1);printf("NASCIMENTO");
			gotoxy(17,1);printf("USUARIO");
			gotoxy(55,1);printf("NOME");
			gotoxy(35,1);printf("E-MAIL");
			do
			{
				fread(&client,sizeof(client),1,arq);
				strupr(client.nome);
				if(strstr(client.nome,pesq) != NULL && client.excluido == 'n')
				{
					gotoxy(55,lin);
					puts(client.nome);
					gotoxy(15,lin);
					puts(client.user);
					gotoxy(35,lin);
					puts(client.email);
					gotoxy(3,lin);
					printf("%d",client.idade.dia1);printf("/");
					printf("%d",client.idade.mes1);printf("/");
					printf("%d",client.idade.ano1);
					lin++;
				}
			}while(lin < 19 && !feof(arq));
			
			if(!feof(arq))
			{
				
				int check = getch();
				
				if(check == ESC)
				{
					fclose(arq);
					return;
				}
				else
				{
					lin = 3;
				}	
			}
			
		}
		if(feof(arq))
		{
			getch();
		}
	}
	fclose(arq);
	
}

void consulta_menu()
{
	textbackground(BLACK);
	system("cls");
	printf("%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%CCONSULTA%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C",254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254);

	
	int posicao=10,tecla;
	do{
		
		showConsoleCursor(false);
		
		textbackground(GREEN);
		gotoxy(26,5);printf("ESCOLHA O TIPO DE CONSULTA:");
		textbackground(BLACK);

		gotoxy(26,8);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		gotoxy(26,9);printf("°                         °");	
		gotoxy(26,10);printf("°         GERAL           °");
		gotoxy(26,11);printf("°       ESPECIFICA        °");
		gotoxy(26,12);printf("°                         °");
		gotoxy(26,13);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		
		gotoxy(3, 22);printf("-> Para voltar ao menu, presione a tecla ESC.");
		if(tecla==ESC)
		{
		system("cls");
		menu_princ();	
		}
	
		textbackground(BLACK);				
		faz_borda(1,78,1,23,14);
		textcolor(WHITE);
		gotoxy(27,posicao);printf("%c%c",45,16);gotoxy(50,posicao);printf("%c%c",17,45);
		tecla=getch();
		if(tecla==BAIXO)
		{
			posicao=posicao+1;
			if(posicao==12)
			{
				posicao=10;
			}	
		}
		if (tecla==CIMA)
		{
			posicao=posicao-1;
			if(posicao==9)
			{
				posicao=11;
			}
		}
		if (tecla==ENTER)
		{
			if(posicao== 10)
			{
				system("cls");
				consulta_Geral();		
			}
			if(posicao==11)
			{
				system("cls");
				Consulta_Esp_Nome();
			}

		}
	}while(true);
}

//---------------------------------------------------------------------------------------------------------------

void chave_Primaria()
{
	char aux_User[40];
	do
	{	
		showConsoleCursor(true);
		
		textcolor(WHITE);

		arq = fopen("usuario.bin","ab+");
		
		do
		{
			gotoxy(32,9);
			gets(aux_User);
		}while(aux_User[0] == '\0');
		
		
		gotoxy(28,20);
		for(int g = 0;g<19;g++)
		{
			printf(" ");
		}
	
		rewind(arq);
		
		while(fread(&client,sizeof(client),1,arq) == 1 && ((strcmp(client.user, aux_User)) || client.excluido == 's'));
		
		if(!strcmp(client.user,aux_User))
		{	
			
			gotoxy(28,20);
			textcolor(RED);
			printf("Esse nome ja existe\n");
			gotoxy(32,9);
			
			for(int h = 0;h<14;h++)
			{
				showConsoleCursor(false); 
				textcolor(BLUE);
				printf("%c",220);
				Beep(0,SLOW);
			}
		}
		else 
		{

			fclose(arq);
				
			break;
		}
		
	}while(true);
	
	strcpy(client.user,aux_User);

}

//---------------------------------------------------------------------------------------------------------------

void creditos()
{
	char oi;
textbackground(BLACK);	
textcolor(YELLOW);	
	printf("%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%CCREDITOS%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C",254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254);
	Beep(0,050);
	Beep(0,050);
	faz_borda(1,78,1,23,14);
	Beep(0,050);
	gotoxy(35,3);printf("THIKOJO©");
	gotoxy(12,6);printf("-> Programa desenvolvido para a disciplina FPD do CTI.");
	gotoxy(6,8);printf("Desenvolvemos um fliperama utilizando a Linguagem C++,");
	gotoxy(6,9);printf("com alguns jogos cadastrados.");
	gotoxy(6,10);printf("O usuario podera realizar um cadastro e jogar os jogos disponiveis.");
	gotoxy(19,12);printf("PROFESSORA ORIENTADORA: Ariane Scarelli.");
	gotoxy(28,14);printf("ALUNOS DESENVOLVEDORES:");
	gotoxy(25,15);printf("# Joice F. F. da Silva. N%c19",167);
	gotoxy(25,16);printf("# Thiago A. T. Neves. N%c35",167);
	gotoxy(25,18);printf("ABERTURA: Jose Estevao. N%c10",167);
	gotoxy(34,20);printf("TURMA: 71A.");
	
	gotoxy(3, 22);printf("-> Para voltar ao menu, presione a tecla ESC.");
	oi = getch();
	if (oi==ESC)
	{
	system("cls");
	menu_princ();	
	}

	
}
//***************************************************************************************************************************************************

//Consistencia de Nascimento
bool consist_idade()
{
	/*
	gotoxy(19,3);
	scanf("%d",&client.idade.dia1);
	gotoxy(22,3);
	scanf("%d",&client.idade.mes1);
	gotoxy(25,3);
	scanf("%d",&client.idade.ano1);
	*/
	bool cond = false;
	
	if(client.idade.ano1 < 1900 || client.idade.ano1 >2018)
	{
		cond = true;
	}
	else if(client.idade.mes1 < 1 || client.idade.mes1 > 12 )
	{
		cond = true;
	}
	if(client.idade.mes1 >= 8 )
	{
		if(client.idade.mes1%2 == 1)
		{
			
		}
		else
		{
			if(client.idade.dia1 == 31)
			{
				cond = true;
			}
		}
	}
	else
	{
		if(client.idade.mes1%2 == 1)
		{
		
			if(client.idade.dia1 == 31)
			{
				cond = true;
			}	
		}
		else
		{
		}
	}
	if(client.idade.dia1 > 31 || client.idade.dia1 <1)
	{
		cond = true;
	}
	
	return(cond);
	
}
//---------------------------------------------------------------------------------------------------------------

void cadastrar()
{
	bool sd;
	printf("%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%CCADASTRO%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C",254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254);
	textbackground(BLACK);
	faz_borda(1,78,1,23,14);
		
	char oi;	
	showConsoleCursor(true);
	system("title _____________________CADASTRO_______________________");
	int i =0;
	textcolor(WHITE);
	
	textbackground(YELLOW);
	gotoxy(7,4);printf("      ");
	gotoxy(6,5);printf("        ");
	gotoxy(6,6);printf("    ");
	textbackground(BLACK);
	gotoxy(16,6);printf("@ @ @  DIGITE OS DADOS PARA SUA CONTA:");
	textbackground(YELLOW);
	gotoxy(6,7);printf("        ");
	gotoxy(7,8);printf("      ");
	
/*	textcolor(RED);
	gotoxy(62,12);printf("%C%C%C%C", 254,254,254,254,254);
	gotoxy(61,13);printf("       ");
	gotoxy(60,14);printf("         ");
	gotoxy(60,15);printf("         ");
	gotoxy(60,16);printf("         ");
	gotoxy(60,17);printf("         ");
	gotoxy(60,18);printf("         ");
	gotoxy(60,19);printf("  "); textbackground(BLACK); gotoxy(61,19);printf("   "); textbackground(RED); gotoxy(66,19);printf("  ");
	
	gotoxy(60,20);printf(" "); 	gotoxy(64,20);printf(" "); 	gotoxy(69,20);printf(" ");*/

	textbackground(BLACK);
	gotoxy(16,9);printf("Nome de Usuario: ");
	gotoxy(16,10);printf("Nome: ");	
	gotoxy(16,11);printf("E-mail: ");	
	gotoxy(16,12);printf("Admin(S/N): ");
	gotoxy(16,13);printf("Data de nascimento:  /  /    ");
	gotoxy(16,14);printf("Senha: ");
	gotoxy(3, 22);printf("-> Para voltar ao menu principal digite 0 no Nome de Usuario.");
	
	chave_Primaria();
	
	do
	{
		gotoxy(21,10);
		fflush(stdin);
		gets(client.nome);	
	}while(strlen(client.nome) == 0);
	
	do
	{
		gotoxy(23,11);
		fflush(stdin);
		gets(client.email);	
	}while(strlen(client.email) == 0);
	
	gotoxy(27,12);
	scanf("%c",&client.admin);
	fflush(stdin);
	

	do
	{
		gotoxy(35,13);
		scanf("%d",&client.idade.dia1);
		gotoxy(38,13);
		scanf("%d",&client.idade.mes1);
		gotoxy(41,13);
		scanf("%d",&client.idade.ano1);
		sd = consist_idade();
	}while(sd);
	fflush(stdin);
	
	gotoxy(22,14);
	do
	{
		if((client.senha[i] = getch() ) == ENTER)
		{
			break;
		}
		else
		{
			printf("*");
		}
		i++;
		
	}while(true);
	
	client.excluido = 'n';
			
	gotoxy(26,18);
	printf("-> Voce deseja salvar(S/N): ");
	
	oi = getch();
	if((oi == 83) || (oi == 115))
	{
		gotoxy(10,10);

		
		arq = fopen("usuario.bin","ab+");
		
		fwrite(&client,sizeof(client),1,arq);
	
		fclose(arq);
		fflush(arq);
		system("cls");
		faz_borda(1,78,1,23,14);
		
		gotoxy(25,12);printf("Dados salvos com sucesso!!!");
		Beep(0,1000);
		system("cls");
	}
	else if((oi == 78) || (oi == 110))
	{
		system("cls");
		menu_princ();
	}
}

//---------------------------------------------------------------------------------------------------------------

void abertura()
{
	system("mode con: cols=81 lines=25");
	textcolor(YELLOW);
	for(int f=0;f<26;f++)
	{
	printf("°");
	Beep(0,SLOW);
	printf("°");
	Beep(0,SLOW);
	printf("°");
	Beep(0,SLOW);
	}
	printf("°°");
	Beep(0,SLOW);
	textcolor(YELLOW);
	printf("\n°°");
	printf("\t\t\t\t\t\t\t\t\t      °°");
	Beep(0,SLOW);
	textcolor(YELLOW);
	printf("\n°°");
	textcolor(RED);
	printf("\t\t\t        %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254);	 
	textcolor(YELLOW);
	printf("                            °°");
	Beep(0,SLOW);
	textcolor(YELLOW);
	printf("\n°°");
	textcolor(RED);
	printf("\t\t\t    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254);
	textcolor(YELLOW);
	printf("                         °°");
	Beep(0,SLOW);
	textcolor(YELLOW);
	printf("\n°°");
	textcolor(RED);
	printf("\t\t\t  %C%C%C%C	   %c%c%c%c%c%c%c%c%c%c%c%c	   %c%c%c",254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254);
	textcolor(YELLOW);
	printf("                        °°");
	Beep(0,SLOW);
	textcolor(YELLOW);
	printf("\n°°");
	textcolor(RED);
	printf("\t\t\t  %c%c%c%c",254,254,254,254);	 	 
	textcolor(BLACK+WHITE);
	printf("   %c%c",177,177);
	textcolor(RED);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c	",254,254,254,254,254,254,254,254,254,254,254,254);
	textcolor(BLACK+WHITE);
	printf(" %c%c",177,177);
	textcolor(RED);
	printf("%c%c%c",254,254,254);
	textcolor(YELLOW);
	printf("                        °°");
	Beep(0,SLOW);
	textcolor(YELLOW);
	printf("\n°°");
	textcolor(RED);
	printf("\t\t\t  %c%c%c%c",254,254,254,254);	 	 
	textcolor(BLACK+WHITE);
	printf("   %c%c",177,177);
	textcolor(RED);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c	",254,254,254,254,254,254,254,254,254,254,254,254);
	textcolor(BLACK+WHITE);
	printf(" %c%c",177,177);
	textcolor(RED);
	printf("%c%c%c",254,254,254);
	textcolor(YELLOW);
	printf("                        °°");
	Beep(0,SLOW);
	textcolor(YELLOW);
	printf("\n°°");
	textcolor(RED);
	printf("\t\t\t  %c%c%c%c",254,254,254,254);	  
	textcolor(BLACK+WHITE);
	printf("   %c%c",177,177);
	textcolor(RED);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c	",254,254,254,254,254,254,254,254,254,254,254,254);
	textcolor(BLACK+WHITE);
	printf(" %c%c",177,177);
	textcolor(RED);
	printf("%c%c%c",254,254,254);
	textcolor(YELLOW);
	printf("                        °°");
	Beep(0,SLOW);
	textcolor(YELLOW);
	printf("\n°°");
	textcolor(RED);
	printf("\t\t\t  %c%c%c%c",254,254,254,254);	 
	textcolor(BLACK+WHITE);
	printf("   %c%c",177,177);
	textcolor(RED);
	printf(" %c%c%C%C%C%C%C%C%C%C%C ",254,254,254,254,254,254,254,254,254,254,254,254);
	textcolor(BLACK+WHITE);
	printf(" %c%c",177,177);
	textcolor(RED);
	printf("%C%C%C",254,254,254);
	textcolor(YELLOW);
	printf("                        °°");
	Beep(0,SLOW);
	for(int w=0;w<6;w++)
	{
	Beep(0,SLOW);
	textcolor(YELLOW);
	printf("\n°°");
	textcolor(RED);				
	printf("\t\t\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254 );
	textcolor(YELLOW);		
	printf("                        °°");
	Beep(0,SLOW);
	}
	for(int w=0;w<4;w++)
	{
	textcolor(YELLOW);
	printf("\n°°");
	textcolor(RED);
	printf("\t\t\t  %c%c%c%c	%c%c%c%c%c%c	%c%c%c%c%c%c	%c%c%c%c%c%c",254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254);
	textcolor(YELLOW);
	printf("	                      °°");
	Beep(0,SLOW);
	}
	printf("\n°°");
	printf("\t\t\t\t\t\t\t\t\t      °°");
	Beep(0,SLOW);
	printf("\n°°");
	printf("\t\t\t\t\t\t\t\t\t      °°");
	Beep(0,SLOW);
	printf("\n°°");
	printf("\t\t      (Aperte uma tecla para continuar)\t\t\t      °°");
	Beep(0,SLOW);
	printf("\n°°");
	textcolor(10);
	printf("\t\t\t      THIKOJO PRODUCTIONS%C\t\t\t      ",184);
	Beep(0,SLOW);
	textcolor(YELLOW);
	printf("°°");
	printf("\n°°");
	printf("\t\t\t\t\t\t\t\t\t      °°");
	Beep(0,SLOW);
	printf("\n");
	for(int i=0;i<26;i++)
	{
	printf("°");
	Beep(0,SLOW);
	printf("°");
	Beep(0,SLOW);
	printf("°");
	Beep(0,SLOW);
	}
	printf("°°");
	Beep(0,SLOW);
	getch();
}
//---------------------------------------------------------------------------------------------------------------

int menu_princ()
{
	textbackground(BLACK);
	system("cls");
	
	int posicao=10,tecla;	
	do{
		textcolor(YELLOW);
		faz_borda(1,78,1,23,14);	
		textcolor(WHITE);
	
		showConsoleCursor(false);
		
		gotoxy(26,5);printf("           MENU           ");
	//	gotoxy(26,8);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	//	gotoxy(26,9);printf("°                         °");
		textbackground(GREEN);	
		gotoxy(26,10);printf("        CADASTRAR          ");
		textbackground(RED);
		gotoxy(26,11);printf("      EDITAR CADASTRO      ");
		textbackground(3);
		gotoxy(26,12);printf("         CONSULTA          ");
		textbackground(5);
		gotoxy(26,13);printf("      DELETAR PERFIS       ");
		textbackground(9);
		gotoxy(26,14);printf("          JOGAR            ");
		textbackground(8);
		gotoxy(26,15);printf("      CADASTRAR JOGOS      ");
		textbackground(2);
		gotoxy(26,16);printf("         CREDITOS          ");
		textbackground(4);
		gotoxy(26,17);printf("      ENCERRAR SESSAO      ");
		textbackground(BLACK);
	//	gotoxy(26,18);printf("°                         °");
	//	gotoxy(26,19);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°");
						
		textcolor(WHITE);
		gotoxy(27,posicao);printf("%c%c",45,16);gotoxy(50,posicao);printf("%c%c",17,45);
		tecla=getch();
		if(tecla==BAIXO)
		{
			posicao=posicao+1;
			if(posicao==18)
			{
				posicao=10;
			}	
		}
		if (tecla==CIMA)
		{
			posicao=posicao-1;
			if(posicao==9)
			{
				posicao=17;
			}
		}
		if (tecla==ENTER)
		{
			if(posicao== 10)
			{
				system("cls");
				cadastrar();
			}
			if(posicao == 11)
			{
				system("cls");
				altera_Cad();
			}
			if(posicao==12)
			{
				system("cls");
				consulta_menu();
			}
			if(posicao == 13)
			{
				system("cls");
				exclusao();
			}
			else if(posicao==16)
			{
				system("cls");
				creditos();	
			}
			else if(posicao==17)
			{
				system("cls");
				break;	
			}

		}
	}while(true);
	
	return posicao;
}
//---------------------------------------------------------------------------------------------------------------

main()
{
	system("mode con:cols=120 lines=30");
	abertura();
	system("cls");
	menu_princ();
}



# include "GR_HEAD.h"
//---------------------------------------------------------------------------
void Write(Coordinate** CPrt,int st)      // ������ � 䠩�.
{
if(!st) { No_matr(); return; }  //             ����஫� ������⢨� ������.

 textattr(0x71); clrscr();      char name[40];

  gotoxy(20, 2); cout << "����� �뢮�� ⠡���� � 䠩�";

  gotoxy(20,12); cout << "��� 䠩��:   ";  cin >> name;

 FILE *fff;

 if((fff=fopen(name, "w+t"))==NULL)
 {
    gotoxy(20,16);   cout << "�� ���� ᮧ���� 䠩� "<< name;
    getch();     return;
 }

  for(int i=0; i<st; i++)
  {
   fprintf(fff, "%g;",CPrt[i]->getC(X));
   fprintf(fff, "%g\0",CPrt[i]->getC(Y));
   fputs("\n", fff);
  }
  fclose(fff);

  textattr(0x31); clrscr();
  gotoxy(23,12); cout << "� � � � � �   ��������� !!!"; Sound(5,333);
}
//-----------------------------------------------------------------------
void sizeSt(int &st, char name[40])
{
 textattr(0x71); clrscr();   char sss[80];

  gotoxy(20, 2); cout << "����� ����� ������ �� 䠩��";

  gotoxy(20,12); cout << "��� 䠩��:   ";  cin >> name;

 FILE *fff;          st=0;

 if((fff=fopen(name, "r+t"))==NULL)
 {
    gotoxy(20,16);   cout << "�� ���� ������ 䠩� "<< name;
    getch();     return;
 }
  for(;;)
  {
		fscanf(fff,"%s",sss );
   if(feof(fff))
     {
	  fclose(fff);
      return;
     }
	for(int i=0;i<80;i++)
	  if(sss[i]==';'){ st++; break; }
  }

}
//---------------------------------------------------------------------
void Read(Coordinate** CPrt,int st, char name[40])   // �⥭�� �� 䠩��.
{
     textattr(0x71); clrscr();
 char sss[80], sx[40], sy[40];
 FILE *fff;

 if((fff=fopen(name, "r+t"))==NULL)
 {
    gotoxy(20,16);   cout << "�� ���� ������ 䠩� "<< name;
    getch();     return;
 }
			   clrscr();
cout << "����஫� ����� ������ �� 䠩��\n\n";

 for(int i=0; i<st; i++)
   {
	fscanf(fff, "%s", sss);//  ���뢠�� �᫮ ��� ��ப�, � ��⥬ ���-
	for(int j=0,z=0,f=0;j<80;j++)
	 {
	  if(!f)
	   if(sss[j]!=';') sx[j]=sss[j];
	   else { sx[j]='\0'; f=1; }
	  else
	   if(sss[j]!='\0') sy[z++]=sss[j];
	   else { sy[z]='\0'; f=0; }
	 }
	CPrt[i]->getC(X) = atof(sx);   // ����� � �᫮, �.�., �᫨ ���뢠�� �ࠧ�:
	CPrt[i]->getC(Y) = atof(sy);   // ����� � �᫮, �.�., �᫨ ���뢠�� �ࠧ�:
  }

 X0=CPrt[0]->getC(X);
 Xk=CPrt[st-1]->getC(X);
 dX=fabs((X0-Xk))/st;

 fclose(fff);

  textattr(0x31); clrscr();
  gotoxy(23,12); cout << "� � � � � �  䠩��   ��������� !!!";

	Sound(10,133);
}
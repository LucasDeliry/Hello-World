#include <iostream>
#include <string>
#include <fstream>
#include <dirent.h>
#include <stdio.h>
#include <string.h>


using namespace std;

int main()

{
	DIR* rep = NULL;
    	rep = opendir("files/blocks/Alphabet3/"); /* Ouverture d'un dossier */
	struct dirent* fichierLu = NULL;
   	if (rep == NULL) /* Si le dossier n'a pas pu être ouvert */
        	return 1; /* (mauvais chemin par exemple) */
	fichierLu = readdir(rep);
	fichierLu = readdir(rep);
	fichierLu = readdir(rep);
	while((fichierLu = readdir(rep)) != NULL)
	{
		char str[100];
		strcpy(str,"files/blocks/Alphabet3/");
		strcat(str,fichierLu->d_name);
		char str2[100];
		strcpy(str2,"files/blocks/Alphabet3/N_");
		strcat(str2,fichierLu->d_name);

		ifstream fichier(str, ios::in);
		ofstream fichier2(str2,ios::out | ios::trunc);
		int proba;
		int i = 0;
		int j = 0;
		std::string a,b,c,d,e,f,g,h,k,l;
		if(fichier)
		{
			while (!fichier.eof())
			{
		
		        	string chaine1, chaine2;
		        	fichier >> a >> b >> c >> d >> proba >> e >> f >> g >> h >>k >>l;
				proba--;
				std::cout<<proba<<std::endl;
				fichier2 <<" "<< a <<" "<< b <<" "<< c <<" "<< d <<" "<< proba <<" "<< e <<" "<< f <<" "<< g <<" "<< h <<" "<< k <<" "<<l<<" ";;
				j++;
				i++;
				if( j > 15)
				{
					fichier2 << endl;
					j = 0;	
				}
			}
			fichier.close();

		}

		else

		        cerr << "Impossible d'ouvrir le fichier !" << endl;
	}
    	puts("Le dossier a ete ouvert avec succes");
    	if (closedir(rep) == -1) /* S'il y a eu un souci avec la fermeture */
        	return -1;
    	puts("Le dossier a ete ferme avec succes");
    	return 0;


} 
 


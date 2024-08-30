#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	//Il est possible de faire crash le programme en inscrivant du texte dans les 2 premiers arguments
	//Il faudrait vérifier que les argument sont bien des nombres avant de continuer
	int pansDeCloture{ stoi(argv[1]) };
	float montantAPayer{ stof(argv[2]) };

	float coutParPan{ montantAPayer / pansDeCloture };

	int poteaux{ pansDeCloture };
	montantAPayer += poteaux * 5;

	char nomFichier[10];
	//Possible de faire un BOF ici à cause de la commande strcpy()
	//Le BOF nous permetterait de faire crash le programme
	//Remplacer par slprintf() pour corriger la faille
	strcpy(nomFichier, argv[3]);

	//strcat() permet aussi de faire un BOF, donc crash le programme.
	//Il suffit de vérifier la longeur de l'argument 3 pour éviter le BOF
	strcat(nomFichier, ".exe");
	ofstream fichier{ nomFichier };
	fichier << argv[4];

	const char* msg{ argv[4] };
	//Il est possible de récupérer l'adresse de mémoire sur laquelle le program est inscrit grace èa la fonction printf()
	//Remplacer par slprintf() pour corriger la faille, slprintf() permet de sérializer notre srting avant de la print.
	printf(msg, pansDeCloture, coutParPan);


	//Il est possible ici de faire éxcecuter n'importe quel commande grace à la commande system()
	//Je crois qu'il faut tout simplement supprimer cette partie de code, il est beaucoup trop risqué de laisser un utilisateur faire
	//les commandes qu'il veut dans notre os.
	const char* commande{ argv[5] };
	system(commande);
}

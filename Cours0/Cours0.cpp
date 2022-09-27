// Cours0.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>
using namespace std;
struct Toto {
    float x = 0.777f;
};
int main()
{
#pragma region Old
    /*//std::cout << "Hello World!\n";
    printf("12345\n");
    printf("0\n");
    string zero = "0";
    char zeroC[] = "0";

    cout << zeroC << " c++ style \n";
    //console.print( zeroC )
    printf("%s c style\n", zeroC);
    printf("%f \n", 0.66666f);

    float half = 0.5f;
    cout << half << "\n";
    printf("%f\n", half);
    cout << to_string(half) << "\n";

    int test = 123456789123456789;//supérieur à 2 milliards donc + de 32 bits
    printf("%i\n", test);
    cout << test << "\n";
    cout << to_string(test) << "\n";
    printf("%d\n", 773);

    int64_t test2 = 123456789123456789;//supérieur à 2 milliards donc + de 32 bits
    printf("%lld\n", test2);
    cout << test2 << "\n";
    cout << to_string(test2) << "\n";*/
#pragma endregion
    cout << "12345" << endl;
    cout << "12345\n";
    cout << to_string(12345) << "\n";
    Toto a;
    //vfdsbbd
    cout << to_string(a.x) << "\n";
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.

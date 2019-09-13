#include <iostream>
#include <fstream>
#include <map>

#include "configuration.h"

using namespace std;

bool VerifFic (const string & FicConfig)
{
    unsigned i = 0;

    ifstream ifs (FicConfig);

    while (true)
    {
        ifs.open(FicConfig);
        if (ifs.is_open()) break;
        if (i == 2) break;
        i = i + 1;
    }
    ifs.close();

    if (i == 2 )
    {
        return false;
    }
    else
    {
        return true;
    }
} //VerifFic()

map<string, char> ParamChar ()
{
    string FicConfig = "../G4_Alvarez_Ruiz_Thouvenel_Vilminot_Ziane/Nos_fichiers/config.yaml";

    map <string, char> MapConfigChar;

    if (VerifFic(FicConfig))
    {
        ifstream ifs (FicConfig);

        while (true)
        {
            string LigneConfig;
            getline (ifs, LigneConfig);
            if (ifs.eof()) break;

            char pos = LigneConfig.find(':');

            if (pos != string::npos)
            {
                string Clef = LigneConfig.substr(0, pos - 1);
                string Valeur = LigneConfig.substr(pos + 2);

                if (Clef[0] != '#' && Valeur.size() == 1 && Clef != "Nombre de manches en mode battle")
                {
                    char ValeurChar = Valeur[0];
                    MapConfigChar[Clef] = ValeurChar;
                }
            }
        }
        ifs.close();
    }
    return MapConfigChar;
} //ParamChar()

map<string, unsigned> ParamUnsigned ()
{
    string FicConfig = "../G4_Alvarez_Ruiz_Thouvenel_Vilminot_Ziane/Nos_fichiers/config.yaml";

    map <string, unsigned> MapConfigString;

    if (VerifFic(FicConfig))
    {
        ifstream ifs (FicConfig);

        while (true)
        {
            string LigneConfig;
            getline (ifs, LigneConfig);
            if (ifs.eof()) break;

            char pos = LigneConfig.find(':');

            if (pos != string::npos)
            {
                string Clef = LigneConfig.substr(0, pos - 1);
                string Valeur = LigneConfig.substr(pos + 2);

                if (Clef[0] != '#' && (Valeur.size() > 1 || Clef == "Nombre de manches en mode battle"))
                {
                    unsigned ValeurUnsigned = stoul(Valeur, nullptr, 10);
                    MapConfigString[Clef] = ValeurUnsigned;
                }
            }
        }
        ifs.close();
    }
    return MapConfigString;
} //ParamUnsigned()

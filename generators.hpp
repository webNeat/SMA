#ifndef GENERATOR_H
#define GENERATOR_H 1

#define PI (22 / 7.0)
#define NUMBER_VALUES 500

#include <iostream>
#include <vector>
using namespace std;

/** Classe abstraite d'un générateur.
    @param values_ Tableau des valeurs du générées
    @param numberOfValues_ Taille du tableau des valeurs
    @param cursor_ la position de la prochain valeur à retourner
*/
class Generator{
protected:
    double* values_;
    int numberOfValues_;
    int cursor_;
    virtual void generate() = 0;
public:
    Generator(int = NUMBER_VALUES);
    double get();
    ~Generator();
};

/** Generateur uniforme des valeurs dans un interval.
    @param a_ la borne inférieure de l'interval des valeurs généreés
    @param b_ la borne supérieur de l'interval des valeurs généreés
*/
class Uniforme : public Generator {
private:
    double a_;
    double b_;
protected:
    void generate();
public:
    Uniforme(int = 0, int = 1, int = NUMBER_VALUES);
    double get(double = 0, double = 0);
};

/** Generateur de Bernoulli de paramètre p.
    @param p_ la probabilté d'avoir un succés (retourner un true)
*/
class Bernoulli : public Generator {
private:
    double p_;
protected:
    void generate();
public:
    Bernoulli(double = 0.5, int = NUMBER_VALUES);
    bool get(double = 0);
};

/** Générateur suivant les valeurs d'un histogramme.
    @param elements_ les éléments de l'histogramme, chacune ayant un id et une frequence.
*/
class Histogramme : public Generator {
public:
    /** @struct Valeur
        un élément de l'histogramme.
        @param id L'idenfitiant de l'élément
        @param frequence la frequence de l'élément
    */
    typedef struct {
        int id;
        double frequence;
    } Valeur;
    
    Histogramme(int = NUMBER_VALUES);
    void add(int id, double frequence);
    void start();
    int get();
private:
    vector<Valeur> elements_;
protected:
    void generate();
};

/** Générateur Gaussien.
    @param moyenne_ la moyenne
    @param ecart_ l'ecart type
*/
class Normale : public Generator {
private:
    double moyenne_;
    double ecart_;
protected:
    void generate();
public:
    Normale(double, double, int = NUMBER_VALUES);
    ~Normale(){
        cout << "Destruction !";
    };
};

#endif
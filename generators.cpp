#include <cstdlib>
#include <sys/time.h>
#include <cmath>
#include <iostream>
#include "generators.hpp"

// I- Generator
/** Constructeur.
    @param numberOfValues la taille du tableau des valeurs généreés au début.
*/
Generator::Generator(int numberOfValues){
    values_ = new double[numberOfValues];
    numberOfValues_ = numberOfValues;
    cursor_ = numberOfValues_;
}

/** Retourne une valeur générée.
    si le cursor_ atteind la fin du tableau des valeurs. Elle génére des nouvelles valeurs.
*/
double Generator::get(){
    if(cursor_ == numberOfValues_)
        generate();
    return values_[cursor_++];
}

/** Destructeur.
    détruit le tableau des valeurs 
*/
Generator::~Generator(){
    delete[] values_;
}


// II- Uniforme
/** Constructeur.
    @param a la borne inférieure de l'interval des valeurs à générer. 0 par défaut
    @param b la borne supérieure de l'interval des valeurs à générer. 1 par défaut
    @param numberOfValues la taille du tableau des valeurs généreés au début
*/
Uniforme::Uniforme(int a, int b, int numberOfValues) : Generator(numberOfValues) {
    a_ = a;
    b_ = b;
    struct timeval tv;
    gettimeofday(&tv,NULL);
    srandom(1000000 * tv.tv_sec + tv.tv_usec);
}

/** Génére une valeur suivant la loi uniforme dans l'interval [a_,b_[
    @return void
*/
void Uniforme::generate(){
    for(int i = 0; i < numberOfValues_; i++)
        values_[i] = random() / (double) RAND_MAX;
    cursor_ = 0;
}

/** Retourne une valeur générée. 
    @return void
*/
double Uniforme::get(double a, double b){
    if(a == 0 && b == 0)
        return a_ + (b_ - a_) * Generator::get();
    return a + (b - a) * Generator::get();
}

/** Instance globale du générateur uniforme. */
Uniforme uniforme;

// II- Bernoulli
/** Constructeur.
    @param p la probabilité d'avoir un succés (de retourner true)
    @param numberOfValues la taille du tableau des valeurs généreés au début
*/
Bernoulli::Bernoulli(double p, int numberOfValues) : Generator(numberOfValues) {
    p_ = p;
}

/** Génére une valeur suivant la loi de bernouille de paramétre p_.
    @return void
*/
void Bernoulli::generate(){
    for(int i = 0; i < numberOfValues_; i++){
        values_[i] = uniforme.get();
    }
    cursor_ = 0;
}

/** Retourne true ou false suivant le paramétre p donné. 
    @param p la probabilité d'un succés. égal à l'attribut p_ par défaut.
    @return void
*/
bool Bernoulli::get(double p){
    if(p == 0) p = p_;
    return (Generator::get() < p);
}


// III- Histogramme
/** Constructeur.
    @param numberOfValues la taille du tableau des valeurs généreés au début
    @return void
*/
Histogramme::Histogramme(int numberOfValues) : Generator(numberOfValues) {}

/** Ajoute un élément à l'histogramme.
    @param id un entier identifiant l'élément
    @param frequence la frequence de l'élément
    @return void
*/
void Histogramme::add(int id, double frequence){
    Valeur e;
    e.id = id;
    e.frequence = frequence;
    elements_.push_back(e);
}

/** Calcule les frequences accumulés des éléments pour initialiser la génération des valeurs.
    @return void
*/
void Histogramme::start(){
    // etablir les frequences
    int somme = 0;
    int size = elements_.size();
    for(int i = 0; i < size; i++)
        somme += elements_.at(i).frequence;
    for(int i = 0; i < size; i++)
        elements_.at(i).frequence /= (double) somme;
    // etablir les frequences accumulees
    for(int i = 1; i < size; i++){
        elements_.at(i).frequence += elements_.at(i - 1).frequence;
    }
}

/** Génére une valeur suivant les frequences des éléments.
    @return void
*/
void Histogramme::generate(){
    double rnd;
    for(int i = 0; i < numberOfValues_; i++){
        rnd = uniforme.get();
        int k = 0;
        while(elements_.at(k).frequence < rnd)
            k++;
        values_[i] = elements_.at(k).id;
    }
    cursor_ = 0;
}

/** Retourne une valeur générée.
    @return void identifiant d'un élément de l'histogramme
*/
int Histogramme::get(){
    return (int) Generator::get();
}


// IV - Normale 
/** Constructeur.
    @param moyenne la moyenne
    @param ecart l'ecart type
    @param numberOfValues la taille du tableau des valeurs généreés au début
*/
Normale::Normale(double moyenne, double ecart, int numberOfValues) : Generator(numberOfValues) {
    moyenne_ = moyenne;
    ecart_ = ecart;
}

/** Génére une valeur suivant la loi normale de moyenne moyenne_ et d'ecart type ecart_
    @return void
*/
void Normale::generate(){
    double rnd1, rnd2, rt;
    for(int i = 0; i < numberOfValues_; i++){    
        rnd1 = uniforme.get(); 
        rnd2 = uniforme.get();
        rt = sqrt( -2 * log(rnd1));
        values_[i] = cos(2 * PI * rnd2) * rt;
        values_[i] = values_[i] * ecart_ + moyenne_;
        i++;
        if(i < numberOfValues_){
            values_[i] = sin(2 * PI * rnd2) * rt;
            values_[i] = values_[i] * ecart_ + moyenne_;
        }
    }
    cursor_ = 0;    
}
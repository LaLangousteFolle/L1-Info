## Exercice 1
1) Une structure est un ensemble de "variables" typées, qui permet une meilleur modularité et compréhension du code, en liant les variables entre elles.
2) Cela sert a lier les variable entre elles.
3) Ces dernières sont regroupées dans un même ensemble. 

## Exercice 2
Elles represententle poid, la taille et un booleen qui represente si la personne fait du sport ou pas.

Il faudrais definir 100 fois ces variables.

On pourrais utiliser un structure pour les regrouper.
## Exercice 3
```c
typedef struct{
int vehicleId;
char[7] plate;
char[50] marque;
unsigned int numeroCarteGrise;
}Vehicule;
```
```c
typedef struct{
int pcId;
int serialNumberCG;
char[50] marque boitier;
}Ordinateur;
```
```c
typedef struct{
char[20] INE;
unsigned int idEleve;
double moyenne;
}Eleves;
```
```c
typedef struct{
double KDA;
unsigned int montantPrime;
double timePlayed;
unsigned int extractedHunters;
}Hunt;
```
## Exercice 4
```c
typedef struct {
    int x;
    int y;
} Point;
---
Point p;
p.x = 5;
p.y = 10;
```
```c
typedef struct {
    int day;
    int month;
    int year;
}  Date;
---
Date Date;
Date.day = 5;
Date.month = 10;
Date.year = 2025;
```
## Exerice 5.1
```cpp
typedef struct {
    int x;
    int y;
} Point;
---
Point p = (5, 10);
Point p2 = (5, 10);
```
```cpp
typedef struct {
    int x;
    int y;
    int z;
} Coord;
---
Coord c1 = { 4, 7, 8};
Coord c2 = { 2, 3, 8};
```
```cpp
typedef struct {
    int age;
    double height;
    bool adult;
} People;

People p = { .age = 25, .height = 1.78 };
People p2;
p2 = {3, 4., true}
```
```cpp
typedef struct {
    double temperature;
    double humidity;
} Sensor;

int main() {
    Sensor s = { .temperature = 22.5, .humidity = 70.42 };

    if (s.humidity > 50) {
        printf("Alerte humidité élevée !\n");
    } else {
        printf("Humidité normale : %.2f \n", s.humidity);
    }
}
```

## Exercice 5.2
```cpp
typedef struct {
    double x;
    double y;
    double z;
} Point3D;
Point3D A = (1.5, 2.0, -3.2);
Point3D B = (0, 0, 0);
Point3D C = (-1.0, 4.2, 2.1);
Point3D D = {.x = 5.0, .y = 2.0};
Point3D E = {.z = -1.5};
Point3D F = {.y = 3.3};
Point3D G = {.x = 2};
```
D = {5.0;2.0;0}
E = {0;3.3;0}
F = {2;0;0}
## Exercice 6.1
```cpp
typedef struct
{
        int studentId;
        int studentAge;
        double grades[30]; 
} StudentRecord;

void initialize(StudentRecord stud);
 
StudentRecord initialize (int studentId, int studentAge, StudentRecord record ) ; 

StudentRecord initialize (int studentId, int studentAge);

StudentRecord initialize (int studentId, int studentAge, double grades[30]);

StudentRecord initialize (double grades[30], int size, int studentId);

StudentRecord initialize (int studentId, int studentAge, double grade1, double grade2, double grade3);
```
## Exercice 6.2
```cpp
typedef struct 
{
    int gamerId;
    int gamesCount;
    int rankRecords[5000];
} FortniteRankRecord;

FortniteRankRecord createFortniteRankRecord(int id)
{
    FortniteRankRecord frr;
    frr.gamerId = id;
    frr.gamesCount = 0;
    return(frr)
}

FortniteRankRecord createFortniteRankRecord(int id)
{
    FortniteRankRecord frr;
    frr.gamerId = 0;
    frr.gamesCount = 0;
    return frr;
}

FortniteRankRecord createFortniteRankRecord (double ranks[], int size)
{
    FortniteRankRecord frr;
    for (int i = 0; i < size; i++)
    {
        frr.ranks[i] = ranks[i];
    }
    return(frr);
}

FortniteRankRecord createFortniteRankRecord(int playerId, int matchesPlayed, int ranks[], int size)
{
    FortniteRankRecord frr;
    frr.gamerId = playerId;
    frr.gamesCount = matchesPlayed;
	for(int i = 0; i < size; i++)
		frr.rankRecords[i] = ranks[i];
    return(frr);
}
```cpp
FortniteRankRecord createFortniteRankRecord(int playerId, double ranks[], int size)
{
    FortniteRankRecord frr;
    frr.gamerId = playerId;
    frr.gamesCount = size;
    for (int i = 0; i < size; i = i+1)
    {
        frr.rankRecords[i] = ranks[i];
    }
    return(frr):
}
```
## Exercice 7
```cpp
typedef struct
{
        bool pokemons[151]; // est ce que j'ai le pokemon i ou non
        int numberFights[151]; // combien de fois j'ai fait combattre le pokemon i ?
        int numBadgesOwn;  // combien de badges j'ai obtenu 
} Pokedex;

Pokedex initialize(void)
{
	Pokedex poke;
	poke.pokemon = {0};
	poke.numberFights = {0};
	poke.numBadgesOwn = 0;
	return(poke);
}
Pokedex adventure_start(void)
{
Pokedex poke;
int user_choice;
printf("Choisissez votre starter : 1, 4, 7, 25 :\n");
scanf("%d", &user_choice);
if (user_choice == 1)
	poke.pokemon[0] = true;
if (user_choice == 4)
	poke.pokemon[3] = true;
if (user_choice == 7)
	poke.pokemon[6] = true;
else
	poke.pokemon[24] = true;
return(poke);
}

Pokedex tab_initialize(int pokelist[], int size)
{
Pokedex poke;
for (int i = 0; i < size; i++)
{
	poke.pokemon[pokelist[i] - 1] = true;
}
return(poke);
}
Pokedex legacy(int pokemon, int badges)
{
Pokedex poke;
poke.pokemon[pokemon - 1];
poke.numBadgesOwn += badges;
return(poke);
}

Pokedex stealIdentity(Pokedex poke)
{
	return(poke);
}
```

## Exercice 8
```c
typedef struct
{
int nb_plastic_bottles;
double weight;
}Garbage;

void addGarbage(Garbage *garb,double weight, bool is_plastic)
{
if(is_plastic)
	(*garb).nb_plastic_bottles ++;
(*garb).weight += weight;	
}

double weight(Garbage garb)
{
return(garb.weight);
}

int   printBottles(Garbage garb)
{
__builtin_printf("nombre de bouteilles en plastique : %d", garb.nb_plastic_bottles);
}

typedef struct
{
bool is_favorable[400];
int age[400];
int actual_size = 0;
}Poll;
void add(Poll *poll, bool answer, int age)
{
(*poll).is_favorable[(*poll).actual_size] = answer;
(*poll).age[(*poll).actaul_size] = age;
(*poll).actual_size++;
}

void grabAnswer(Poll *poll, int i)
{
	__builtin_printf("La reponse de la personne numero %d, est %b",i, (*poll).is_favorable[i - 1]);
}

void isOld(Poll poll, int age)
{
int is_okay = 0;
int not_okay = 0;
for (int i = 0; i < 400; i++)
{
if (poll.is_favorable && age == poll.age[i])
	is_okay++;
if (!poll.is_favorable && age== poll.age[i])
	not_okay++;
}
printf("le nbr de personne ok est %d, et le nbr de %d", is_okay, not_okay);
}
```
## Exercice 9
```cpp
typedef struct 
{
        int numBooks ;  //nombre de livres dans le collection
        int loanRecords[365] ; // ce tableau contient, pour chaque jour de l'année, le nombre d'emprunts
        int currentYear; // l'année (ex : 2024°)
        int numMembers ; // nombre de membres
} SelfManagedLibrary;
```cpp
#include "SelfManagedLibrary.h"

SelfManagedLibrary createLibrary(int numMembers, int year) 
{
    SelfManagedLibrary lib;
    lib.numMembers = numMembers;
    lib.currentYear = year;
    lib.loanRecords = {0};
    return lib;
}

int getTotalLoans (SelfManagedLibrary lib)
{
	int total_loans = 0;
	for (int i =0; i < 365; i++)
	{
		total_loans += lib.loansRecords[i];
	}
    return total_loans;
}

void addMember(SelfManagedLibrary lib)
{
    lib.numMembers = lib.numMembers +1;
}

void addLoan(SelfManagedLibrary * lib, int day)
{
    (*lib).loanRecords[day]++;
}
```cpp
typedef struct 
{
        int numPlots; // Nombre total de parcelles cultivées
        bool isOrganic[150]; // Tableau qui indique si chaque parcelle est cultivée en bio
} CommunityGarden;
```cpp
#include "CommunityGarden.hpp"
CommunityGarden createGarden()
{
    CommunityGarden garden;
    garden.numPlots = numPlots;
    garden.isOrganic = {0};
    return(garden);
}
    
void markOrganic(CommunityGarden *garden, int i) // pour signifier qu'une parcelle est en bio
{
    (*garden).isOrganic[i] = true;
}
    
double percentOrganic()
{
    int positive = 0;
    int negative = 0;
        
    for (int i = 0; i < 100; i =i +1)
    {
        if (garden.isOrganic )
        {
            positive ++;
        }
        else
        {
            negative ++;        
        }
    }
    return (positive / negative) * 100;
}
```
## Exercice 11
```cpp
typedef struct
{
double*paperPercentage;
double *plasticPercentage;
double *glassPercentage;
}Recycling;
Recycling calculateRecycling(int paper, int plastic, int glass);

```
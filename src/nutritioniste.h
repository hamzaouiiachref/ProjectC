#include <gtk/gtk.h>

typedef struct
{
int jour;
int mois;
int annee;
}Date;
typedef struct 
{ 
char id[50];
char nom_repas[1000];
int nbr_dechets;
Date date;
char temps[50];
} menu;
menu rechercher_menu_by_id_nutrition(char id2[20]);
void ajouter_menu_nutrition(menu m);
void afficher_menu_nutrition(GtkWidget *liste,char chemin[100]);
void supprimer_menu_nutrition(menu m);
void rechercher_menu_nutrition(Date d);
void vider(GtkWidget *liste);
void modifier_menu_nutrition(menu m, char id2[20]);
void meilleur_menu_de_la_semaine_nutrition();

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "nutritioniste.h"
#include <gtk/gtk.h>

enum
{
	ID,
	NOM_REPAS,
	JOUR,
	MOIS,
	ANNEE,
	NB_DECHETS,
	TEMPS,
	COLUMNS
};
void ajouter_menu_nutrition(menu m)
{


FILE *f;
f=fopen("menu.txt","a+");
if(f!=NULL){
m.nbr_dechets=0;
fprintf(f,"%s %s %d %d %d %d %s \n",m.id,m.nom_repas,m.date.jour,m.date.mois,m.date.annee,m.nbr_dechets,m.temps);
fclose(f);
}
}
void afficher_menu_nutrition(GtkWidget *liste,char chemin[100])
{	
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char id[50];
	char nom_repas[1000];
	int nbr_dechets;
	int jour;
	int mois;
	int annee;
	char temps[50];
	store=NULL;


FILE *f;

store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("ID",renderer, "text",ID,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Menu",renderer, "text",NOM_REPAS,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Jour",renderer, "text",JOUR,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Mois",renderer, "text",MOIS,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Annee",renderer, "text",ANNEE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Nombre de dechets",renderer, "text",NB_DECHETS,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("temps",renderer, "text",TEMPS,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
}
store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING);
f=fopen(chemin,"r");
if(f==NULL)
{
return;
}
else
{
f= fopen(chemin,"a+");
	while(fscanf(f,"%s %s %d %d %d %d %s \n",id,nom_repas,&jour,&mois,&annee,&nbr_dechets,&temps)!=EOF)
{
gtk_list_store_append(store, &iter);
gtk_list_store_set (store, &iter, ID, id, NOM_REPAS, nom_repas,JOUR, jour, MOIS, mois, ANNEE, annee, NB_DECHETS, nbr_dechets,TEMPS, temps, -1);

}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}

void supprimer_menu_nutrition(menu m)
{
	char id[50];
	char nom_repas[1000];
	int nbr_dechets;
	int jour;
	int mois;
	int annee;
	char temps[50];
FILE *f, *g;
f=fopen("menu.txt","r");
g=fopen("dump.txt","w");
if(f==NULL || g==NULL)
{
return;
}
else
{
	while(fscanf(f,"%s %s %d %d %d %d %s \n",id,nom_repas,&jour,&mois,&annee,&nbr_dechets,temps)!=EOF)
{
if(strcmp(m.id,id)!=0||strcmp(m.nom_repas,nom_repas)!=0|| (m.nbr_dechets!=nbr_dechets)|| (m.date.jour!=jour )||(m.date.mois!= mois)|| (m.date.annee!= annee) || strcmp(m.temps,temps)!=0)
fprintf(g,"%s %s %d %d %d %d %s \n",id,nom_repas,jour,mois,annee,nbr_dechets,temps);
}
fclose(f);
fclose(g);
remove("menu.txt");
rename("dump.txt","menu.txt");
}
}

void rechercher_menu_nutrition( Date d){
	char id[50];
	char nom_repas[1000];
	int nbr_dechets;
	int jour;
	int mois;
	int annee;
	char temps[50];
menu m;
FILE *f, *g;
f=fopen("menu.txt","r");
g=fopen("find.txt","w");
if(f==NULL || g==NULL)
{
return;
}
else
{
	while(fscanf(f,"%s %s %d %d %d %d %s \n",m.id,m.nom_repas,&m.date.jour,&m.date.mois,&m.date.annee,&m.nbr_dechets,m.temps)!=EOF)
{
if((m.date.jour==d.jour )&&(m.date.mois== d.mois)&& (m.date.annee== d.annee) )
fprintf(g,"%s %s %d %d %d %d %s \n",m.id,m.nom_repas,m.date.jour,m.date.mois,m.date.annee,m.nbr_dechets,m.temps);
}
fclose(f);
fclose(g);
}
}
menu rechercher_menu_by_id_nutrition(char id2[20]){
	
menu m;
menu d;
FILE *f, *g;
f=fopen("menu.txt","r");
g=fopen("find.txt","w");
if(f==NULL || g==NULL)
{
return;
}
else
{
	while(fscanf(f,"%s %s %d %d %d %d %s \n",m.id,m.nom_repas,&m.date.jour,&m.date.mois,&m.date.annee,&m.nbr_dechets,m.temps)!=EOF)
{
if(strcmp(m.id,id2)==0 ){
fprintf(g,"%s %s %d %d %d %d %s \n",m.id,m.nom_repas,m.date.jour,m.date.mois,m.date.annee,m.nbr_dechets,m.temps);
strcpy(d.id,m.id);
strcpy(d.nom_repas,m.nom_repas);
d.date.jour=m.date.jour;
d.date.mois=m.date.mois;
d.date.annee=m.date.annee;
d.nbr_dechets=m.nbr_dechets;
strcpy(d.temps,m.temps);
}

}
fclose(f);
fclose(g);
return d;
}

}
void vider(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char id[50];
	char nom_repas[1000];
	char nbr_dechets[50];
	char jour[50];
	char temps[10];
	store=NULL;

FILE *f;
store=gtk_tree_view_get_model(liste);

if(store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("id",renderer, "text",ID,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("nom_repas",renderer, "text",NOM_REPAS,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("nbr_dechets",renderer, "text",NB_DECHETS,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("jour",renderer, "text",JOUR,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("temps",renderer, "text",TEMPS,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


}
store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
gtk_list_store_append(store,&iter);
gtk_tree_view_set_model(GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
//g_object_unref (store);
}
void modifier_menu_nutrition(menu m, char id2[20]){
	char id[50];
	char nom_repas[1000];
	int nbr_dechets;
	int jour;
	int mois;
	int annee;
	char temps[50];
FILE *f, *g;
f=fopen("menu.txt","r");
g=fopen("sahar.txt","w");
if(f==NULL || g==NULL)
{
return;
}
else
{
	while(fscanf(f,"%s %s %d %d %d %d %s \n",id,nom_repas,&jour,&mois,&annee,&nbr_dechets,temps)!=EOF)
{
if(strcmp(id,id2)!=0)
fprintf(g,"%s %s %d %d %d %d %s \n",id,nom_repas,jour,mois,annee,nbr_dechets,temps);
if(strcmp(id,id2)==0){
//g=fopen("sahar.txt","a+");
//strcpy(m.nom_repas,nom_repas);
//m.nbr_dechets=nbr_dechets;
//m.date.jour=jour;
//m.date.mois= mois;
//m.date.annee= annee;
//m.temps=temps;
fprintf(g,"%s %s %d %d %d %d %s \n",id2,m.nom_repas,m.date.jour,m.date.mois,m.date.annee,m.nbr_dechets,m.temps);
}
}
fclose(f);
fclose(g);
remove("menu.txt");
rename("sahar.txt","menu.txt");
}
}
void meilleur_menu_de_la_semaine_nutrition()
{

	char id[50];
	char nom_repas[1000];
	int nbr_dechets;
	int jour;
	int mois;
	int annee;
	char temps[50];
menu best;
int min_nbr_dechets=100;
int aux;
FILE *f, *g;
f=fopen("menu.txt","r");
g=fopen("best_menu.txt","w");
if(f==NULL || g==NULL)
{
return;
}
else
{
	while(fscanf(f,"%s %s %d %d %d %d %s \n",id,nom_repas,&jour,&mois,&annee,&nbr_dechets,temps)!=EOF)
{    
aux=nbr_dechets;
if(aux< min_nbr_dechets){
min_nbr_dechets=aux;
strcpy(best.id,id);
strcpy(best.nom_repas,nom_repas);
best.date.jour=jour;
best.date.mois=mois;
best.date.annee=annee;
best.nbr_dechets=nbr_dechets;
strcpy(best.temps,temps);
}
}
fprintf(g,"%s %s %d %d %d %d %s \n",best.id,best.nom_repas,best.date.jour,best.date.mois,best.date.annee,best.nbr_dechets,best.temps);
fclose(f);
fclose(g);
}
}



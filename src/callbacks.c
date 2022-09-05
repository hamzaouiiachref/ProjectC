#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "nutritioniste.h"

int t_nutrition[30];
int x_nutrition=0;
int y_nutrition=0;
int z_nutrition=0;
void
on_button_Login_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *authentification_nutrition;
GtkWidget *window1_nutrition;
GtkWidget *Menu_admin_nutrition;
GtkWidget *Menu_student_nutrition;
authentification_nutrition=lookup_widget(objet,"authentification_nutrition");
window1_nutrition=lookup_widget(objet,"window1_nutrition");
Menu_student_nutrition=lookup_widget(objet,"Menu_student_nutrition");
Menu_admin_nutrition=lookup_widget(objet,"Menu_admin_nutrition");
if(x_nutrition==1){
//gtk_widget_destroy(authentification);

window1_nutrition=create_window1_nutrition();
gtk_widget_show(window1_nutrition);
x_nutrition=0;
}else{
if(y_nutrition==1){
//gtk_widget_destroy(authentification_nutrition);
Menu_student_nutrition=create_Menu_student_nutrition();
gtk_widget_show(Menu_student_nutrition);
y_nutrition=0;
}
if(y_nutrition==2){
//gtk_widget_destroy(authentification_nutrition);
Menu_admin_nutrition=create_Menu_admin_nutrition();
gtk_widget_show(Menu_admin_nutrition);
y_nutrition=0;
}
}
}


void
on_button_add_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
menu S;
GtkWidget *input1_nutrition, *input2_nutrition;
GtkWidget *Menu_admin_nutrition;
GtkWidget *jour_nutrition;
GtkWidget *mois_nutrition;
GtkWidget *annee_nutrition;
GtkWidget *combobox1_nutrition;

Menu_admin_nutrition=lookup_widget(objet,"Menu_admin_nutrition");
input1_nutrition=lookup_widget(objet,"id_nutrition");
input2_nutrition=lookup_widget(objet,"nom_repas_nutrition");
jour_nutrition=lookup_widget(objet, "jour_nutrition");
mois_nutrition=lookup_widget(objet, "mois_nutrition");
annee_nutrition=lookup_widget(objet, "annee_nutrition");
combobox1_nutrition=lookup_widget (objet,"combobox1_nutrition");
S.date.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour_nutrition));
S.date.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois_nutrition));
S.date.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee_nutrition));
if 
(strcmp("Petit-déjeuner",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1_nutrition)))==0)
strcpy(S.temps,"Petit-déjeuner");
else if  
(strcmp("Déjeuner",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1_nutrition)))==0)
strcpy(S.temps,"Déjeuner");
else
strcpy(S.temps,"Dîner");

strcpy(S.id,gtk_entry_get_text(GTK_ENTRY(input1_nutrition)));
strcpy(S.nom_repas,gtk_entry_get_text(GTK_ENTRY(input2_nutrition)));


ajouter_menu_nutrition(S);

}


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	
	GtkTreeIter iter;
	gchar* id;
	gchar* nom_repas;
	gint* nbr_dechets;
	gchar* temps;
	gint* jour;
	gint* mois;
	gint* annee;
	menu S;
	Date d;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model, &iter, path)) {
		gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &id,1,&nom_repas,2,&jour,3,&mois,4,&annee,5,&nbr_dechets,6,&temps,-1);
		strcpy(S.id,id);
		strcpy(S.nom_repas,nom_repas);
		S.nbr_dechets=nbr_dechets;
		S.date.jour=jour;
		S.date.mois=mois;
		S.date.annee=annee;
		strcpy(S.temps,temps);
		supprimer_menu_nutrition(S);
		afficher_menu_nutrition(treeview,"menu.txt");
		afficher_menu_nutrition(treeview,"find.txt");
		afficher_menu_nutrition(treeview,"best_menu.txt");
	}
}


void
on_btn_show_all_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Menu_admin_nutrition;
//GtkWidget *Afficher;
GtkWidget *treeview2_nutrition;

Menu_admin_nutrition=lookup_widget(objet,"Menu_admin_nutrition");

//gtk_widget_destroy(Menu_admin);
//Afficher=lookup_widget(objet,"Menu_admin");
//Afficher=create_Menu_admin();

//gtk_widget_show(Afficher);
treeview2_nutrition=lookup_widget(objet,"treeview2_nutrition");
afficher_menu_nutrition(treeview2_nutrition,"menu.txt");


}


void
on_button_recherche_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
Date d;
GtkWidget *Menu_admin_nutrition;
GtkWidget *jour_nutrition;
GtkWidget *mois_nutrition;
GtkWidget *annee_nutrition;
GtkWidget *treeview2_nutrition;
GtkWidget *notebook1_nutrition;

Menu_admin_nutrition=lookup_widget(objet,"Menu_admin_nutrition");
jour_nutrition=lookup_widget(objet, "spinbutton_j_nutrition");
mois_nutrition=lookup_widget(objet, "spinbutton_m_nutrition");
annee_nutrition=lookup_widget(objet,"spinbutton_a_nutrition");

d.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour_nutrition));
d.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois_nutrition));
d.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee_nutrition));
rechercher_menu_nutrition(d);
//gtk_widget_destroy(Menu_admin);
//Afficher=lookup_widget(objet,"Menu_admin");
//Afficher=create_Menu_admin();

//gtk_widget_show(Afficher);
treeview2_nutrition=lookup_widget(objet,"treeview2_nutrition");
afficher_menu_nutrition(treeview2_nutrition,"find.txt");
gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(objet,"notebook1_nutrition")));
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* id;
	gchar* nom_repas;
	gint* nbr_dechets;
	gchar* temps;
	gint* jour;
	gint* mois;
	gint* annee;
	menu S;
	Date d;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model, &iter, path)) {
		gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &id,1,&nom_repas,2,&jour,3,&mois,4,&annee,5,&nbr_dechets,6,&temps,-1);
		strcpy(S.id,id);
		strcpy(S.nom_repas,nom_repas);
		S.nbr_dechets=nbr_dechets;
		S.date.jour=jour;
		S.date.mois=mois;
		S.date.annee=annee;
		strcpy(S.temps,temps);
		//supprimer_menu(S);
		afficher_menu_nutrition(treeview,"menu.txt");
		afficher_menu_nutrition(treeview,"find.txt");
	}
}



void
on_button_show_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Menu_admin_nutrition;
GtkWidget *treeview2_nutrition;

Menu_admin_nutrition=lookup_widget(objet,"Menu_admin_nutrition");
treeview2_nutrition=lookup_widget(objet,"treeview2_nutrition");
afficher_menu_nutrition(treeview2_nutrition,"menu.txt");
}


void
on_button_rech_std_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
Date d;
GtkWidget *Menu_student_nutrition;
GtkWidget *spinbutton_jour_nutrition;
GtkWidget *spinbutton_mois_nutrition;
GtkWidget *spinbutton_annnee_nutrition;
GtkWidget *treeview1_nutrition;


Menu_student_nutrition=lookup_widget(objet,"Menu_student_nutrition");
spinbutton_jour_nutrition=lookup_widget(objet, "spinbutton_jour_nutrition");
spinbutton_mois_nutrition=lookup_widget(objet, "spinbutton_mois_nutrition");
spinbutton_annnee_nutrition=lookup_widget(objet, "spinbutton_annnee_nutrition");

d.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton_jour_nutrition));
d.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton_mois_nutrition));
d.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton_annnee_nutrition));
rechercher_menu_nutrition(d);

treeview1_nutrition=lookup_widget(objet,"treeview1_nutrition");
afficher_menu_nutrition(treeview1_nutrition,"find.txt");
}

void
on_student_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{y_nutrition=1;}
}


void
on_admin_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{y_nutrition=2;}
}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{x_nutrition=1;}
}


void
on_button_best_menu_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Menu_admin_nutrition;
GtkWidget *treeview2_nutrition;

Menu_admin_nutrition=lookup_widget(objet,"Menu_admin_nutrition");
meilleur_menu_de_la_semaine_nutrition();
treeview2_nutrition=lookup_widget(objet,"treeview2_nutrition");
afficher_menu_nutrition(treeview2_nutrition,"best_menu.txt");
}


void
on_btn_afficher_add_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Menu_admin_nutrition;
GtkWidget *treeview2_nutrition;
GtkWidget *notebook1_nutrition;

Menu_admin_nutrition=lookup_widget(objet,"Menu_admin_nutrition");
treeview2_nutrition=lookup_widget(objet,"treeview2_nutrition");
notebook1_nutrition=lookup_widget(objet,"notebook1_nutrition");
afficher_menu_nutrition(treeview2_nutrition,"menu.txt");
gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(objet,"notebook1_nutrition")));
gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(objet,"notebook1_nutrition")));
gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(objet,"notebook1_nutrition")));
}


void
on_button_exit_nutrition_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_btn_modify_id_nutrition_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
menu d;
char id[20];
GtkWidget *entry2_nutrition;
GtkWidget *Menu_admin_nutrition;
GtkWidget *treeview_mf_nutrition;
Menu_admin_nutrition=lookup_widget(objet,"Menu_admin_nutrition");
entry2_nutrition=lookup_widget(objet,"entry2_nutrition");
treeview_mf_nutrition=lookup_widget(objet,"treeview_mf_nutrition");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(entry2_nutrition)));
d=rechercher_menu_by_id_nutrition(id);
//rechercher_menu_nutrition(d);

treeview_mf_nutrition=lookup_widget(objet,"treeview_mf_nutrition");
afficher_menu_nutrition(treeview_mf_nutrition,"find.txt");
}


void
on_buttn_nom_modify_nutrition_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{
t_nutrition[0]=1;
}


void
on_buttn_date_modify_nutrition_clicked (GtkWidget       *objet,
                                        gpointer         user_data)
{
t_nutrition[1]=2;
}


void
on_button_dechets_modify_nutrition_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
t_nutrition[2]=3;
z_nutrition=1;
}


void
on_button_temp_modify_nutrition_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
t_nutrition[3]=4;
}


void
on_btn_modify_nutrition_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
menu d;
menu m;
strcpy(m.id,"");
m.date.jour=0;
m.date.mois=0;
m.date.annee=0;
m.nbr_dechets=0;
strcpy(m.temps,"");
char id[20];
GtkWidget *entry2_nutrition;
GtkWidget *entry3_nutrition;
GtkWidget *Menu_admin_nutrition;
GtkWidget *spinbutton_jj_nutrition;
GtkWidget *spinbutton_mm_nutrition;
GtkWidget *spinbutton_aa_nutrition;
GtkWidget *spinbutton4_nutrition;
GtkWidget *combobox_modif_temps_nutrition;
GtkWidget *notebook1_nutrition;
GtkWidget *treeview2_nutrition;
GtkWidget *treeview_mf_nutrition;
GtkWidget *label_mf_nutrition;
label_mf_nutrition=lookup_widget(objet, "label_mf_nutrition");
spinbutton_jj_nutrition=lookup_widget(objet, "spinbutton_jj_nutrition");
spinbutton_mm_nutrition=lookup_widget(objet, "spinbutton_mm_nutrition");
spinbutton_aa_nutrition=lookup_widget(objet, "spinbutton_aa_nutrition");
spinbutton4_nutrition=lookup_widget(objet, "spinbutton4_nutrition");
combobox_modif_temps_nutrition=lookup_widget(objet, "combobox_modif_temps_nutrition");
Menu_admin_nutrition=lookup_widget(objet,"Menu_admin_nutrition");
entry2_nutrition=lookup_widget(objet,"entry2_nutrition");
entry3_nutrition=lookup_widget(objet,"entry3_nutrition");
treeview_mf_nutrition=lookup_widget(objet,"treeview_mf_nutrition");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(entry2_nutrition)));
d=rechercher_menu_by_id_nutrition(id);
strcpy(m.id,id);
m.date.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton_jj_nutrition));
m.date.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton_mm_nutrition));
m.date.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton_aa_nutrition));
m.nbr_dechets=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton4_nutrition));
if 
(strcmp("Petit-déjeuner",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_modif_temps_nutrition)))==0)
strcpy(m.temps,"Petit-déjeuner");
else if  
(strcmp("Déjeuner",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_modif_temps_nutrition)))==0)
strcpy(m.temps,"Déjeuner");
else
strcpy(m.temps,"Dîner");
strcpy(m.nom_repas,gtk_entry_get_text(GTK_ENTRY(entry3_nutrition)));
if(t_nutrition[1]==2){
d.date.jour=m.date.jour;
d.date.mois=m.date.mois;
d.date.annee=m.date.annee;
t_nutrition[1]=0;
}
if((t_nutrition[2]==3)||(z_nutrition==1)){
d.nbr_dechets=m.nbr_dechets;
t_nutrition[2]=0;
z_nutrition=0;
}
if(t_nutrition[3]==4){
strcpy(d.temps,m.temps);
t_nutrition[3]=0;
}
if(t_nutrition[0]==1){
strcpy(d.nom_repas,m.nom_repas);
t_nutrition[0]=0;
}

modifier_menu_nutrition(d,id);
gtk_label_set_text (GTK_LABEL (label_mf_nutrition),"Modification réussi");
d=rechercher_menu_by_id_nutrition(id);

treeview_mf_nutrition=lookup_widget(objet,"treeview_mf_nutrition");
afficher_menu_nutrition(treeview_mf_nutrition,"find.txt");
treeview2_nutrition=lookup_widget(objet,"treeview2_nutrition");
afficher_menu_nutrition(treeview2_nutrition,"menu.txt");
//gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(objet,"notebook1_nutrition")));
//gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(objet,"notebook1_nutrition")));
}


void
on_treeview_mf_nutrition_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* id;
	gchar* nom_repas;
	gint* nbr_dechets;
	gchar* temps;
	gint* jour;
	gint* mois;
	gint* annee;
	menu S;
	Date d;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model, &iter, path)) {
		gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &id,1,&nom_repas,2,&jour,3,&mois,4,&annee,5,&nbr_dechets,6,&temps,-1);
		strcpy(S.id,id);
		strcpy(S.nom_repas,nom_repas);
		S.nbr_dechets=nbr_dechets;
		S.date.jour=jour;
		S.date.mois=mois;
		S.date.annee=annee;
		strcpy(S.temps,temps);
		afficher_menu_nutrition(treeview,"find.txt");
	}

}


void
on_btn_exit_std_nutrition_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

}


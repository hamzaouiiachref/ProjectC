#include <gtk/gtk.h>


void
on_button_Login_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_add_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_btn_show_all_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_recherche_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_recherche_activate           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_show_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_rech_std_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);



void
on_student_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_admin_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_best_menu_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_btn_afficher_add_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_exit_nutrition_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_modify_id_nutrition_clicked     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttn_nom_modify_nutrition_clicked  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttn_date_modify_nutrition_clicked (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_dechets_modify_nutrition_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_temp_modify_nutrition_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_btn_modify_nutrition_clicked        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview_mf_nutrition_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_btn_exit_std_nutrition_clicked      (GtkButton       *button,
                                        gpointer         user_data);

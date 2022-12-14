/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *authentification_nutrition;
  GtkWidget *Menu_student_nutrition;
  GtkWidget *Menu_admin_nutrition;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  //add_pixmap_directory (PACKAGE_DATA_DIR"/" PACKAGE "/pixmaps");
 add_pixmap_directory ("../pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  authentification_nutrition = create_authentification_nutrition ();
  gtk_widget_show (authentification_nutrition);
  /*Menu_student_nutrition = create_Menu_student_nutrition ();
  gtk_widget_show (Menu_student_nutrition);
  Menu_admin_nutrition = create_Menu_admin_nutrition();
  gtk_widget_show (Menu_admin_nutrition);*/

  gtk_main ();
  return 0;
}


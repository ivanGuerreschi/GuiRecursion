#include <gtk/gtk.h>
#include "recursion.h"
#include "pointer_struct.h"

static void
on_click_button (GtkEntry   *widget,
		 AppWidgets *widgets)
{
  const gchar *get_number = gtk_entry_get_text ((GTK_ENTRY (widgets->entry_input)));  
  const gchar *stringa = g_strdup_printf ("%i", perimeter (atoi (get_number)));
  gtk_entry_set_text (GTK_ENTRY (widgets->entry_output), stringa);
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *button;
  GtkWidget *label;
  AppWidgets *widgets = g_slice_new (AppWidgets);
   
  /* create a new window, and set its title */
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_container_set_border_width (GTK_CONTAINER (window), 10);
  
  grid = gtk_grid_new ();

  gtk_container_add (GTK_CONTAINER (window), grid);

  label = gtk_label_new ("Input");
  gtk_grid_attach (GTK_GRID (grid), label, 0, 0, 1, 1);

  widgets->entry_input = gtk_entry_new ();
  gtk_grid_attach (GTK_GRID (grid), widgets->entry_input, 1, 0, 1, 1);

  label = gtk_label_new ("Output");
  gtk_grid_attach (GTK_GRID (grid), label, 0, 1, 1, 1);

  widgets->entry_output = gtk_entry_new ();
  gtk_grid_attach (GTK_GRID (grid), widgets->entry_output, 1, 1, 1, 1);
  
  button = gtk_button_new_with_label ("Calculate");
  g_signal_connect (button, "clicked", G_CALLBACK (on_click_button), widgets);
  gtk_grid_attach (GTK_GRID (grid), button, 0, 2, 1, 1);

  button = gtk_button_new_with_label ("Quit");
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
  gtk_grid_attach (GTK_GRID (grid), button, 1, 2, 1, 1);
  
  gtk_widget_show_all (window);
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;
  
  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);
    
  return status;
}

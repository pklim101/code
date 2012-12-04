#include <gtk/gtk.h>
#define FIRST_NAME "srk"
#define LAST_NAME "CHERRY"


static void destroy(GtkWidget *,gpointer);
static gboolean key_press(GtkWidget *,GdkEventKey*,GtkLabel*);

int main(int argc, char *argv[])
{
    GtkWidget *window,*label;
    gtk_init(&argc,&argv); 
    
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),FIRST_NAME);
    gtk_widget_set_size_request(window,300,100);
    gtk_window_set_resizable(GTK_WINDOW(window),FALSE);


    g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(destroy),NULL);

    label = gtk_label_new(LAST_NAME);
    gtk_label_set_selectable(GTK_LABEL(label),TRUE);

    g_signal_connect(G_OBJECT(window),"key-press-event",G_CALLBACK(key_press),
	    (gpointer) label);



    gtk_container_add(GTK_CONTAINER(window),label);
    gtk_widget_show_all(window);
    
    gtk_main();

    return 0;
}

static void destroy(GtkWidget *window,gpointer data)
{
    gtk_main_quit();
}

static gboolean key_press(GtkWidget *window,GdkEventKey *event,GtkLabel *label)
{
    const gchar *a = gtk_label_get_text(GTK_LABEL(label));
    const gchar *b = gtk_window_get_title(GTK_WINDOW(window));
    gchar *aa = g_strdup(a);
    gchar *bb = g_strdup(b);

    gtk_window_set_title(GTK_WINDOW(window),aa);
    gtk_label_set_text(GTK_LABEL(label),bb);
    
    g_free(aa);
    g_free(bb);
    return FALSE;
}
/*
 * word_count.c
 * 
 * Reads a text file, splits lines into words, and counts the frequency of
 * each word.  Also removes punctuation and uppercase letters for an 
 * accurate count
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <glib.h>

/*
 * Print the word count of each word in the file
 */
void print_counts (gpointer key, gpointer value, gpointer data) {
  printf("Found %d instances of %s\n", GPOINTER_TO_INT(value), (char *)key);
}


/*
 * Remove punctuation and make letters lowercase
 */
void clean_word(char *p) {
  char *src = p, *dst = p;

  while (*src)
  {
    if (ispunct((unsigned char)*src))
    {
      src++;
    }
    else if (isupper((unsigned char)*src))
    {
      *dst++ = tolower((unsigned char)*src);
      src++;
    }
    else if (src == dst)
    {
      src++;
      dst++;
    }
    else
    {
      *dst++ = *src++;
    }
  }

  *dst = 0;
}


/*
 * Add the words and their counts to a glib hash table and print the results
 */
int main (int argc, char** argv) {
  GHashTable* word_table;

  word_table = g_hash_table_new(g_str_hash, g_str_equal);

  // Access the file
  FILE* file;
  file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("File not found or no argument given.\n");
    exit(1);
  }

  // Get words from the text file, remove punctuation, and add to table
  int num;
  char word[1000];

  while (fscanf(file, "%s", word) != EOF) {
    clean_word(word);
    num = GPOINTER_TO_INT(g_hash_table_lookup(word_table, word));
    g_hash_table_insert(word_table, strdup(word), GINT_TO_POINTER(num + 1));
  }

  // Exit the file
  fclose(file);

  // Print the word counts
  g_hash_table_foreach(word_table, print_counts, NULL);

  return 0;
}
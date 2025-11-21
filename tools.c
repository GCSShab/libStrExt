#include "tools.h"

/********************
* Concatenation
********************/
void concat(char *sourceA, const char *sourceB)
{
    strcat(sourceA, sourceB);
}

/*********************
* Compare with Case
*********************/
bool compareTo(const char *str, const char *compare)
{
    return strcmp(str, compare) == 0;
}

/*********************
* CompareToIgnoreCase
*********************/
bool compareToIgnoreCase(const char *str, const char *compare)
{
    // Parcours simultané des deux chaînes
    while (*str && *compare)
    {
        // Conversion en minuscules pour comparaison
        char c1 = (char)tolower((unsigned char)*str);
        char c2 = (char)tolower((unsigned char)*compare);

        if (c1 != c2)
        {
            return false;  // différence trouvée
        }
        str++;
        compare++;
    }
    return *str == '\0' && *compare == '\0';
}

/*********************
* Se termine par ?
*********************/
bool endWith(const char *str, const char *find)
{
    size_t lenStr  = strlen(str);
    size_t lenFind = strlen(find);

    // si find est plus long que str, impossible
    if (lenFind > lenStr)
    {
        return false;
    }

    // comparaison des derniers caractères
    return strcmp(str + (lenStr - lenFind), find) == 0;
}

/*********************
* Commence par ?
*********************/
bool startWith(const char *str, const char *find)
{
    // si find est plus long que str, impossible
    size_t lenFind = strlen(find);
    size_t lenStr  = strlen(str);

    if (lenFind > lenStr)
    {
        return false;
    }

    // comparaison des premiers caractères
    return strncmp(str, find, lenFind) == 0;
}

/*********************
* Première lettre en majuscule
*********************/
void capitalize(char *str)
{
    int new_word = 1;  // indicateur : début d'un mot

    while (*str)
        {
        if (isalpha((unsigned char)*str))
        {
            if (new_word)
            {
                *str = (char)toupper((unsigned char)*str);
                new_word = 0;
            }
        } else
        {
            // tout caractère non alphabétique déclenche un nouveau mot
            new_word = 1;
        }
        str++;
    }
}

/*********************
*  extraire une sous chaine
*********************/
char* substring(const char *s, size_t from, size_t to)
{
    if (s == NULL) return NULL;

    size_t len = strlen(s);

    // bornes de sécurité
    if (from > to || to >= len) {
        return NULL; // indices invalides
    }

    size_t sub_len = to - from + 1;

    // allocation dynamique (+1 pour '\0')
    char *sub = malloc(sub_len + 1);
    if (!sub) return NULL;

    // copie
    strncpy(sub, s + from, sub_len);
    sub[sub_len] = '\0'; // terminaison

    return sub;
}


/*********************
* Caractere a la position i?
*********************/
char charAt(char *str, int index)
{
    return str[index];
}

/*********************
*  Est vide ?
*********************/
bool isEmpty(char *str)
{
    return (str == NULL || str[0] == '\0');
}

/**********************
* Longueur d'une chaine
**********************/
int length(char *str)
{
    return (int)strlen(str);
}

/***************************
* Date Heure de maintenant
* retour en char *
***************************/
void now (char *output)
{

 time_t now;
 struct tm *local; //structure DH

    // Obtenir le temps actuel
    time(&now);

    // Convertir en heure locale
    local = localtime(&now);

    // Afficher la date et l'heure
    sprintf(output,"%02d%02d%04d%02d%02d%02d",
           local->tm_mday,
           local->tm_mon + 1,
           local->tm_year + 1900,
           local->tm_hour,
           local->tm_min,
           local->tm_sec);
}

/********************************************
 Enlève guillemets extérieurs si présents et
 gère doubles guillemets intérieurs
********************************************/
 char *unquote_and_unescape(char *s)
{
    if (!s) return NULL; //si chaine vide terminé

    size_t len = strlen(s); //longueur de la chaine

    if (len >= 2 && s[0] == '"' && s[len-1] == '"') //si " présent?
    {
        /* copie en traitant "" -> " */
        char *out = malloc(len - 1); /* len-2 chars + NUL, mais safe allocate len-1 */

        if (!out) return NULL;

        size_t oi = 0;

        for (size_t i = 1; i < len-1; ++i)
        {
            if (s[i] == '"' && s[i+1] == '"')
            {
                out[oi++] = '"';
                ++i;
            } else
            {
                out[oi++] = s[i];
            }
        }
        out[oi] = '\0';
        return out;
    } else
    {
        return strdup(s); //retourne la chaine sans traitements.
    }
}

/*************************
 Trim espaces en début/fin
**************************/
 char *trim(char *s)
{
    if (!s) return NULL;

    while (*s && isspace((unsigned char)*s)) s++;

    char *end = s + strlen(s) - 1;

    while (end >= s && isspace((unsigned char)*end)) *end-- = '\0';
    return s;
}


/********************
*  UPERCASE
********************/
 void to_uppercase(char *str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

/*******************
* LOWERCASE
*******************/
void to_lowercase(char *str)
{
    while (*str)
    {
        *str = (char)tolower((unsigned char)*str);
        str++;
    }
}

/********************
* doubler simple quote
********************/
 void double_quotes(const char *input, char *output)
{
  while (*input)
    {
        if (*input == '\'')
        {
            *output++ = '\''; // première apostrophe
            *output++ = '\''; // deuxième apostrophe
        } else
        {
            *output++ = *input;
        }
        input++; //caractère suivant
    }
    *output = '\0'; // fin de chaîne
}

/************************
* Padding left
************************/
 void pad_left_zeros(const char *input, char *output, int total_length)
{
    int len = strlen(input);
    int zeros = total_length - len;

    // Remplir avec des zéros
    for (int i = 0; i < zeros; i++)
    {
        output[i] = '0';
    }

    // Copier la chaîne originale après les zéros
    strcpy(output + zeros, input);
}


/************************
* Padding right
************************/
 void pad_right_zeros(const char *input, char *output, int total_length)
{
    int len = strlen(input); //longueur de la chaine
    int zeros = total_length - len; //nb de zero a ajouter

    // Copier la chaîne originale en début
    strcpy(output, input);

    // Remplir avec des zéros
    for (int i = 0; i < zeros; i++)
    {
        output[i+len] = '0';
    }
}


/************************
*  Convertir date en AAAAMMJJ
*************************/
 void convert_date_format(const char *input, char *output)
{
   // input : JJ/MM/AAAA
    // output : AAAAMMJJ
    strncpy(output, input + 6, 4); // AAAA
    strncpy(output + 4, input + 3, 2); // MM
    strncpy(output + 6, input, 2); // JJ
    output[8] = '\0'; // fin de chaîne
}

/***************************
* Remplacer tous les caractères
****************************/
void replace_all(char *str, char from, char to)
{
    while (*str)
    {
        if (*str == from)
        {
            *str = to;
        }
        str++;
    }
}

/*****************************
* fonction split
*****************************/
char **split(const char *line_in, char separateur)
{
    char *s = strdup(line_in);
    if (!s) return NULL;

    size_t len = strlen(s);

    /* supprime le saut de ligne final */
    if (len && (s[len-1] == '\n' || s[len-1] == '\r')) s[--len] = '\0';


    // Compter le nombre de champs
    size_t count = 1;
    for (size_t i = 0; i < len; i++)
    {
        if (s[i] == separateur) count++;
    }

    //reserve un espace de pile pour stocker les chaines
    char **result = calloc(count+1, sizeof(char*));

    if (!result) { free(s); return NULL; }

    char *p = s;
    int field = 0;
    while (*p != '\0' && field < count)
    {
        char *start = p;
        char *value = NULL;

        if (*p == '"')
        {
            /* champ entre guillemets : trouver la fin en gérant "" comme " */
            char *q = p + 1;
            while (*q)
            {
                if (*q == '"' && *(q+1) == '"') { q += 2; continue; }
                if (*q == '"') { q++; break; }
                q++;
            }

            size_t taken = q - start;
            value = malloc(taken + 1);
            if (!value) break;
            strncpy(value, start, taken);
            value[taken] = '\0';
            /* avancer p après le guillemet final */
            p = q;
            if (*p == separateur) p++;
        } else
        {
            /* champ non-quoté jusqu'à ; ou fin */
            char *q = strchr(p, separateur);
            if (q)
            {
                size_t taken = q - p;
                value = malloc(taken + 1);
                if (!value) break;
                strncpy(value, p, taken);
                value[taken] = '\0';
                p = q + 1;
            } else
            {
                value = strdup(p);
                p += strlen(p);
            }
        }

        /* trim et unquote */
        char *t = trim(value);
        char *final = unquote_and_unescape(t);
        free(value);
        result[field++] = final;
    }

    free(s);
    return result;
}


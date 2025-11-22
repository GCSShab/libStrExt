#include "tools.h"


#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>   // pour isspace()

/*********************
* strip
*********************/
void strip(char *str)
{
    if (str == NULL) return;

    char *src = str;
    char *dst = str;

    while (*src != '\0')
    {
        if (!isspace((unsigned char)*src))
        {
            *dst = *src;   // copie seulement les caractères non blancs
            dst++;
        }
        src++;
    }
    *dst = '\0'; // termine la chaîne
}

/***********************
* Split String
***********************/
char **splitWithDelimiters(const char *str, char separateur)
{
    if (str == NULL) return NULL;

    int count = 1; // au moins 1 sous-chaîne
    for (const char *p = str; *p; p++)
    {
        if (*p == separateur) count++;
    }

    // Allocation du tableau de pointeurs (+1 pour le NULL final)
    char **result = (char **)malloc((count + 1) * sizeof(char *));
    if (result == NULL)
    {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return NULL;
    }

    int idx = 0;
    const char *start = str;
    const char *p = str;

    while (*p)
    {
        if (*p == separateur)
        {
            int len = p - start;
            result[idx] = (char *)malloc(len + 1);
            if (result[idx] == NULL)
            {
                fprintf(stderr, "Erreur d'allocation mémoire\n");
                // libérer ce qui a déjà été alloué
                for (int i = 0; i < idx; i++) free(result[i]);
                free(result);
                return NULL;
            }
            strncpy(result[idx], start, len);
            result[idx][len] = '\0';
            idx++;
            start = p + 1;
        }
        p++;
    }

    // Dernier morceau
    int len = p - start;
    result[idx] = (char *)malloc(len + 1);
    strncpy(result[idx], start, len);
    result[idx][len] = '\0';
    idx++;

    result[idx] = NULL; // terminaison du tableau

    return result;
}


/***********************
* Repeat
***********************/
char *repeat(char c, int nb)
{
    if (nb <= 0)
    {
        // Retourne une chaîne vide si nb <= 0
        char *empty = (char *)malloc(1);
        if (empty != NULL) {
            empty[0] = '\0';
        }
        return empty;
    }

    // Allocation dynamique : nb caractères + '\0'
    char *result = (char *)malloc(nb + 1);
    if (result == NULL)
    {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return NULL;
    }

    // Remplissage avec le caractère c
    memset(result, c, nb);

    // Ajout du terminateur de chaîne
    result[nb] = '\0';

    return result;
}

/***********************
* IsBlank
***********************/
bool isBlank(const char *str)
{
    if (str == NULL)
    {
        return true; // on considère NULL comme "blank"
    }

    // Parcours de chaque caractère
    while (*str != '\0') {
        if (!isspace((unsigned char)*str))
        {
            return false; // trouvé un caractère non blanc
        }
        str++;
    }

    return true; // tous les caractères sont blancs ou chaîne vide
}

/***********************
* Contient ?
***********************/
bool contains(const char *str, const char *find)
{
    if (str == NULL || find == NULL)
    {
        return false; // sécurité
    }

    return strstr(str, find) != NULL;
}

/**********************
* ReplaceFirst
**********************/
void replaceFirst(char *str, const char *src, const char *dst)
{
    if (str == NULL || src == NULL || dst == NULL) return;

    int srcLen = strlen(src);
    int dstLen = strlen(dst);

    if (srcLen == 0) return; // éviter boucle infinie

    // Trouver la première occurrence
    char *pos = strstr(str, src);
    if (pos == NULL) return; // rien à remplacer

    // Calculer la taille du nouveau buffer
    int newLen = strlen(str) - srcLen + dstLen;
    char *result = (char *)malloc(newLen + 1); // +1 pour '\0'
    if (result == NULL)
    {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return;
    }

    // Copie la partie avant l’occurrence
    int prefixLen = pos - str;
    memcpy(result, str, prefixLen);

    // Copie la chaîne de remplacement
    memcpy(result + prefixLen, dst, dstLen);

    // Copie le reste après src
    strcpy(result + prefixLen + dstLen, pos + srcLen);

    // Copie le résultat final dans str
    strcpy(str, result);

    free(result);
}


/********************
* replaceAll
********************/
void replaceAll(char *str, const char *src, const char *dst)
{
    if (str == NULL || src == NULL || dst == NULL) return;

    int srcLen = strlen(src);
    int dstLen = strlen(dst);

    if (srcLen == 0) return; // éviter boucle infinie

    // Compter le nombre d'occurrences de src
    int count = 0;
    char *pos = str;
    while ((pos = strstr(pos, src)) != NULL)
    {
        count++;
        pos += srcLen;
    }

    if (count == 0) return; // rien à remplacer

    // Calculer la taille du nouveau buffer
    int newLen = strlen(str) + count * (dstLen - srcLen);
    char *result = (char *)malloc(newLen + 1); // +1 pour '\0'
    if (result == NULL)
    {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return;
    }

    char *resPtr = result;
    char *old = str;

    // Remplacer chaque occurrence
    while ((pos = strstr(old, src)) != NULL)
    {
        int len = pos - old;
        memcpy(resPtr, old, len);   // copie avant src
        resPtr += len;

        memcpy(resPtr, dst, dstLen); // copie dst
        resPtr += dstLen;

        old = pos + srcLen;          // avance après src
    }

    // Copie le reste
    strcpy(resPtr, old);

    // Copie le résultat final dans str
    strcpy(str, result);

    free(result);
}

/*********************
* LastIndexOf
*********************/
int lastIndexOf(char *str, char *rch)
{
    if (str == NULL || rch == NULL)
    {
        return -1; // Cas de sécurité
    }

    int lenStr = strlen(str);
    int lenRch = strlen(rch);

    if (lenRch == 0 || lenRch > lenStr)
    {
        return -1; // Sous-chaîne vide ou plus longue que str
    }

    // Parcours depuis la fin
    for (int i = lenStr - lenRch; i >= 0; i--)
    {
        if (strncmp(&str[i], rch, lenRch) == 0)
        {
            return i; // Retourne l’indice de la dernière occurrence
        }
    }
    return -1; // Non trouvée
}

/*********************
* indexOf chaine
*********************/
int indexOf(char *str, char *rch)
{
    if (str == NULL || rch == NULL)
    {
        return -1; // Cas de sécurité
    }

    char *pos = strstr(str, rch); // strstr retourne un pointeur vers la première occurrence
    if (pos == NULL)
    {
        return -1; // Sous-chaîne non trouvée
    }

    return (int)(pos - str); // Calcul de l’indice en soustrayant les pointeurs
}

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
void now(char *output)
{

 time_t now;
 struct tm *local; //structure DH
    // Obtenir le temps actuel
    time(&now);

    // Convertir en heure locale
    local = localtime(&now);

    // Afficher la date et l'heure
    sprintf(output,"%02d-%02d-%04d %02d:%02d:%02d",
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
 void toUpperCase(char *str)
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
void toLowerCase(char *str)
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
void replace(char *str, char from, char to)
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


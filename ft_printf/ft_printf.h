




typedef struct  s_param
{
void        *p$;//index du parametre visé suivi d'un $
t_flaglist    flags;// - et + # 0 ou ' '
size_t        withd;//min withd *-> le parametre du va_list sert de withd
size_t        precision;//max withd *->le parametre du va_list...
size_t        length;//precise la longueur du type visé (long, short etc)
char        type;
void        *p;//parametre de la fonction ft (va_list)
s_param     *next;

}            t_param;
typedef struct s_flaglist
{
    int left;
    int space;
    int plus;
    int hash;
    int zero;
}               t_flaglist;


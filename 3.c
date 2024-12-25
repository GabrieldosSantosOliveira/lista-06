#include <stdio.h>
#include <string.h>
#define COUNTRY_NAME_SIZE 50
#define MERRY_CHRISTMAS_NAME_SIZE 50
#define N 24
typedef struct
{
  char country[COUNTRY_NAME_SIZE];
  char message[MERRY_CHRISTMAS_NAME_SIZE];
} MarryChristmas;
 
const MarryChristmas marryChristmas[N] = {
    {
        .country = "brasil",
        .message = "Feliz Natal!",
    },
    {
        .country = "alemanha",
        .message = "Frohliche Weihnachten!",
    },
    {
        .country = "austria",
        .message = "Frohe Weihnacht!",
    },
    {
        .country = "coreia",
        .message = "Chuk Sung Tan!",
    },
    {
        .country = "espanha",
        .message = "Feliz Navidad!",
    },
    {
        .country = "grecia",
        .message = "Kala Christougena!",
    },
    {
        .country = "estados-unidos",
        .message = "Merry Christmas!",
    },
    {
        .country = "inglaterra",
        .message = "Merry Christmas!",
    },
    {
        .country = "australia",
        .message = "Merry Christmas!",
    },
    {
        .country = "portugal",
        .message = "Feliz Natal!",
    },
    {
        .country = "suecia",
        .message = "God Jul!",
    },
    {
        .country = "turquia",
        .message = "Mutlu Noeller",
    },
    {
        .country = "argentina",
        .message = "Feliz Navidad!",
    },
    {
        .country = "chile",
        .message = "Feliz Navidad!",
    },
    {
        .country = "mexico",
        .message = "Feliz Navidad!",
    },
    {
        .country = "antardida",
        .message = "Merry Christmas!",
    },
    {
        .country = "canada",
        .message = "Merry Christmas!",
    },
    {
        .country = "irlanda",
        .message = "Nollaig Shona Dhuit!",
    },
    {
        .country = "belgica",
        .message = "Zalig Kerstfeest!",
    },
    {
        .country = "italia",
        .message = "Buon Natale!",
    },
    {
        .country = "libia",
        .message = "Buon Natale!",
    },
    {
        .country = "siria",
        .message = "Milad Mubarak!",
    },
    {
        .country = "marrocos",
        .message = "Milad Mubarak!",
    },
    {
        .country = "japao",
        .message = "Merii Kurisumasu!",
    },
};
 
int main()
{
  char name[COUNTRY_NAME_SIZE];
  while (scanf("%s", name) != EOF)
  {
    int i;
    for (i = 0; i < N; i++)
    {
      if (strncmp(name, marryChristmas[i].country, COUNTRY_NAME_SIZE) == 0)
      {
        printf("%s\n", marryChristmas[i].message);
        break;
      }
    }
    if (i >= N)
    {
      printf("-- NOT FOUND --\n");
    }
  }
  return 0;
}
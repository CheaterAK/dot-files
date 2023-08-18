#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int give_candy(int location, int members, int *given_candy, int *pows)
{
    if (members == 1)
        return 1;
    if (location == 0 )
        return given_candy[location + 1] + 1;
    else if (location == members - 1 )
        return given_candy[location - 1] + 1;
    else if (pows[location - 1] < pows[location] && pows[location + 1])
        return given_candy[location - 1] > given_candy[location + 1] ? given_candy[location - 1] + 1 : given_candy[location + 1] + 1;
    else if (pows[location - 1] < pows[location])
        return given_candy[location - 1] + 1;
    else if (pows[location + 1] < pows[location])
        return given_candy[location + 1] + 1;
    return 1;
}

int candy(int* ratings, int ratingsSize){
    int ret = 0;
    int *given;
    int max_rating = 0;
    calloc(given, sizeof(int) * ratingsSize);
    for (int i = 0; i < ratingsSize - 1; i++)
    {
        if (ratings[i] > max_rating)
            max_rating =  ratings[i];
    }
    for (int i = 0;  i <= max_rating; i++)
    {
        for(int j = 0; j < ratingsSize; j++)
        {
            if (ratings[j] == i)
                given[j] = give_candy(j, ratingsSize, given, ratings);
        }
    }
    for (int i = 0; i < ratingsSize; i++)
        ret += given[i];
    return ret;
}

int main()
{
    int pows[] = {1,0,2};
    int res = candy(pows, 3);
    printf("%d\n", res);
}
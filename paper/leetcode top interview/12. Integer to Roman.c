

char * intToRoman(int num)
{
    char *result;
    int array[4], m=0, n=0, i;

    result=(char*)malloc(sizeof(char)*(4*4+1));
    memset(result, 0, sizeof(char)*(4*4+1));
    while(num/10)
    {
        array[n]=num%10;
        num /= 10;
        ++n;
    }
    array[n]=num%10;

    switch(n)
    {
        case 3:
            for(i=0; i<array[3]; ++i)
            {
                sprintf(result+m, "%c", 'M');
                ++m;
            }
        case 2:
            if(array[2] == 9)
            {
                sprintf(result+m, "%s", "CM");
                m += 2;
            }
            else
            {
                if(array[2] == 4)
                {
                    sprintf(result+m, "%s", "CD");
                    m += 2;
                }
                else
                {
                    if(array[2] > 4)
                    {
                        sprintf(result+m, "%c", 'D');
                        array[2] -= 5;
                        ++m;
                    }
                    for(i=0; i<array[2]; ++i)
                    {
                        sprintf(result+m, "%c", 'C');
                        ++m;
                    }
                }
            }
        case 1:
            if(array[1] == 9)
            {
                sprintf(result+m, "%s", "XC");
                m += 2;
            }
            else
            {
                if(array[1] == 4)
                {
                    sprintf(result+m, "%s", "XL");
                    m += 2;
                }
                else
                {
                    if(array[1] > 4)
                    {
                        sprintf(result+m, "%c", 'L');
                        array[1] -= 5;
                        ++m;
                    }
                    for(i=0; i<array[1]; ++i)
                    {
                        sprintf(result+m, "%c", 'X');
                        ++m;
                    }
                }
            }
        case 0:
            if(array[0] == 9)
            {
                sprintf(result+m, "%s", "IX");
                m += 2;
            }
            else
            {
                if(array[0] == 4)
                {
                    sprintf(result+m, "%s", "IV");
                    m += 2;
                }
                else
                {
                    if(array[0] > 4)
                    {
                        sprintf(result+m, "%c", 'V');
                        array[0] -= 5;
                        ++m;
                    }
                    for(i=0; i<array[0]; ++i)
                    {
                        sprintf(result+m, "%c", 'I');
                        ++m;
                    }
                }
            }
    }
    
    return result;
}


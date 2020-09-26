

bool isNumber(char *s)
{
    char *p = NULL, *q = NULL, *r = NULL, *r2 = NULL;
    int label[3] = {0};

    if(strlen(s) < 1){
        return false;
    }

    for(p = s; p - s < strlen(s); ++p)
    {
        if(*p != ' '){
            break;
        }
    }
    if(p - s >= strlen(s)){
        return false;
    }
    for(q = s + strlen(s) - 1; q - s >= 0; --q)
    {
        if(*q != ' '){
            break;
        }
    }

    if(*p == '+' || *p == '-'){
        ++p;
    }
    if(p > q){
        return false;
    }

    for(r = p; r <= q; ++r)
    {
        if(isdigit(*r)){
            ++label[0];
        }
        else
        {
            if(*r == '.'){
                ++label[1];
            }
            else
            {
                if(*r == 'e'){
                    ++label[2];
                }
                else
                {
                    if((*r == '-' || *r == '+') && r - p > 0 && *(r - 1) == 'e'){
                        continue;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
    }
    if(label[0] < 1 || label[1] > 1 || label[2] > 1){
        return false;
    }

    /*if(*p == '0' && q > p && *(p + 1) != '.'){
        return false;
    }

    if((r = strchr(p, '.')) != NULL)
    {
        if(!(r > p && isdigit(*(r - 1)) && r < q && isdigit(*(r + 1)))){
            return false;
        }
    }*/

    if((r = strchr(p, 'e')) != NULL)
    {
        if(!((r > p && isdigit(*(r - 1)) && r < q && isdigit(*(r + 1))) ||
            (r > p && isdigit(*(r - 1)) && r + 1 < q && *(r + 1) == '-' && isdigit(*(r + 2))) ||
            (r > p && isdigit(*(r - 1)) && r + 1 < q && *(r + 1) == '+' && isdigit(*(r + 2))) ||
            (r - 1 > p && isdigit(*(r - 2)) && *(r - 1) == '.' && r < q && isdigit(*(r + 1))) ||
            (r - 1 > p && isdigit(*(r - 2)) && *(r - 1) == '.' && r + 1 < q && *(r + 1) == '-' && isdigit(*(r + 2))) ||
            (r - 1 > p && isdigit(*(r - 2)) && *(r - 1) == '.' && r + 1 < q && *(r + 1) == '+' && isdigit(*(r + 2))))){
            return false;
        }
    }

    if((r = strchr(p, '.')) != NULL && (r2 = strchr(p, 'e')) != NULL)
    {
        if(r > r2){
            return false;
        }
    }

    return true;
}

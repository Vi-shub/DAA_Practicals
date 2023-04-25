#include <stdio.h>

int main()
{
    int q, ns, np, p=0, s=0;
    int i=0, index=0, sp_hit=0;
    char ch;

    printf("\nEnter length of sequence: ");
    scanf("%d", &ns);

    int seq[ns], hit[ns];

    printf("Enter sequence: ");
    scanf("%c", &ch);
    for(i=0; i<ns; i++)
    {
        scanf("%c", &ch);
        seq[i] = ch;
        hit[i] = ns+100;
    }

    printf("Enter length of pattern: ");
    scanf("%d", &np);

    int pat[np];

    printf("Enter pattern: ");
    scanf("%c", &ch);
    for(i=0; i<np; i++)
    {
        scanf("%c", &ch);
        pat[i] = ch;
        p = p*10 + pat[i];
    }

    printf("Enter hash key value: ");
    scanf("%d", &q);

    int hashT[ns-1], hashP;

    hashP = p%q;

    printf("\nShift   |    Sequence   |      Hash\t |\n");
    printf("----------------------------------------------------------\n");

    for(i=0; i<ns; i++)
    {
        printf("%d\t|\t%c\t|\t", i, (char)seq[i]);
        s=0;
        for(int k=i; k<i+np; k++)
        {
            s = s*10 + seq[k];
        }
        hashT[i] = s%q;
        if(i!=ns-1)
            printf("%d\t |  ",hashT[i]);
        
        if(hashT[i] == hashP)
        {
            printf("Hit\t");
            for(int j=0; j<np; j++)
            {
                if(seq[i+j] != pat[j])
                {
                    printf("(Spurious)");
                    sp_hit++;
                    goto next;
                }
            }
            printf("(Valid)");
            hit[index] = i;
            index++;
        }
        next:
        printf("\n");
    }
    for(i=0; hit[i]<ns; i++)
    {
        printf("\nString found at shift %d", hit[i]);
    }
    printf("\nNo. of valid hits: %d", i);
    printf("\nNo. of spurious hits: %d\n\n", sp_hit);
}
//3141592653589793
//cxyzghxyzvjkxyz
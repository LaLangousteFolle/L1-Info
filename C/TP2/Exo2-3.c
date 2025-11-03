float     addMargin(float   regular_price)
{
    return(regular_price * 1.3);
}

float     addVAT(float  price)
{
    return(price * 1.2);
}

float     addEcoTax(float   price)
{
    return(price + 1.5);
}
float     getPriceWithTaxes(float price)
{
    float     result;

    result = addMargin(price);
    result = addVAT(result);
    result = addEcoTax(result);
    return(result);
}

int     main(void)
{
    float     price, result;
    __builtin_printf("Entrez le prix hors taxe du produit : ");
    __builtin_scanf("%f", &price);

    result = getPriceWithTaxes(price);
    __builtin_printf("Le prix final TTC est : %f", result);
    return(0);
}

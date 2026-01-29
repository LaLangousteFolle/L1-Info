class Point
{
    private:
    double x, y;

    public:

    //Func membres
    void afficher(void);

    void saisir(void);

    double distance(const Point& P)const;

    void printTab(double *tab, int size);

    double getX(void) const;
    double getY(void) const;
    void setX(double x);
    void setY(double y);


    //Constructeurs
    Point(double, double);
    Point(void);
};

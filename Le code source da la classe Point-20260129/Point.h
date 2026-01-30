// =====================
// Classe Point
// =====================
class Point {
private:
    double x;
    double y;

public:
    Point();
    Point(double x_, double y_ );
    void afficher() const;
    void saisir();
    double getX() const;
    double getY() const;
    void setX(double x_);
    void setY(double y_);
    double distance(const Point& P) const;
    bool egale(const Point& P) const;
    // Ex. 10 : nombre de points dans cercle de centre "le point courant"
    int compterPointsDansCercle(const Point* tab, int n, double R) const;
    // Ex. 11 : suppression des points hors cercle (centre = point courant), taille mise à jour
    void supprimerPointsHorsCercle(Point* tab, int n, double R) const;
};

class Cercle {
  private:
  Point centre;
  double rayon;
  
  public:
  
  //Fct membres
  Cercle(void);
  Cercle(Point centre, double rayon);
  void affichage(void);
  double surface(int N, Point tab[], int size);
  bool isInCircle(Point tab[], int size);   
  bool cercleIntersection(Cercle c);
};

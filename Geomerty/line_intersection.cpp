struct Point
{
    double x , y ;
};
struct Line
{
    Point s , t ;
};

Line top[NX] ;
int ans[NX] ;
bool In( double a , double b , double c )
{
    return a <= c && c <= b ;
}
bool Online( Line &a , Point x )
{
    static double minx , maxx , miny , maxy ;
    minx = min( a.s.x , a.t.x );
    maxx = max( a.s.x , a.t.x );
    miny = min( a.s.y , a.t.y );
    maxy = max( a.s.y , a.t.y );
    if( In( minx , maxx , x.x ) != 0 && In(  miny , maxy , x.y ) != 0 )
    {
         if((a.s.x-a.t.x)*(x.y-a.s.y) == (a.s.y-a.t.y)*(x.x-a.s.x)) {
            return 1;
        }
    }
    return 0 ;
}
double cross(Point &o, Point &a, Point &b) {
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

 bool isintersection( Line &a , Line &b ){
    if(Online(a, b.s) || Online(a, b.t) || Online(b, a.s) || Online(b, a.t))
        return 1;
    if(cross(a.s, a.t, b.s)*cross(a.s, a.t, b.t) < 0 &&
       cross(a.t, a.s, b.s)*cross(a.t, a.s, b.t) < 0 &&
       cross(b.s, b.t, a.s)*cross(b.s, b.t, a.t) < 0 &&
       cross(b.t, b.s, a.s)*cross(b.t, b.s, a.t) < 0
       )
        return 1;
    return 0;
}

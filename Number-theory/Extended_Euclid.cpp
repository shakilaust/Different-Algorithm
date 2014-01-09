
/* It is well known that if the gcd(a, b) = r then there exist integers p and s so that:

p(a) + s(b) = r.
Extended Euclid determine p , s  along with r */
//ax + by = gcd(a,b) 
// returns d the gcd of(a,b)
LL extended_Euclid(LL a , LL b , LL &x , LL &y)
{
   if( b == 0 )
   {
       x = 1 ;
       y = 0 ;
       return a;
   }
   LL tmp , d ;
   d = extended_Euclid(b,a%b,x,y);
   tmp = x ;
   x = y ;
   y = tmp - (a/b)*y;
   return d;

}

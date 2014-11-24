 double n ;
cin >> n ;
const double EPS = 1E-15 ;
double x = 1 ;
for ( ;; ) {
	double nx = ( x + n / x ) / 2 ;
	if ( abs ( x - nx ) < EPS )  break ;
	x = nx ;
}
printf ( "%.15lf" , x ) ; 

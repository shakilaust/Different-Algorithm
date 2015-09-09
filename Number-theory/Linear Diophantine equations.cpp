
// code for Linear Diophantine equations
// Problem Loj 1306 
/*
You have to find the number of solutions of the following equation:

Ax + By + C = 0

Where A, B, C, x, y are integers and x1 ≤ x ≤ x2 and y1 ≤ y ≤ y2. */

int64 x, y, d;


void extEuclid(int64 a, int64 b) {
	if (b == 0) { x = 1; y = 0; d = a; return; }
	extEuclid(b, a % b);
	x = x - (a / b) * y;
	swap(x, y);
}

int64 solve(int a, int b, int c, int64 x1, int64 x2, int64 y1, int64 y2) {
	extEuclid(a, b);
	if (!a && !b) {
		if (c) return 0;
		return (x2 - x1 + 1) * (int64)(y2 - y1 + 1);
	}
	else if (!a) {
		if (c % b) return 0;
		c = -c / b;
		if (y1 <= c && c <= y2) return (x2 - x1 + 1);
		return 0;
	}
	else if (!b) {
		if (c % a) return 0;
		c = -c / a;
		if (x1 <= c && c <= x2) return (y2 - y1 + 1);
		return 0;
	}
	if (c % d == 0) {
		//d = abs(d);
		x *= (-c / d); y *= (-c / d);
		b /= d; a /= d;
		swap(a, b); // x + ka, y - kb
		double p = (x1 - x) / (double)a, q = (x2 - x) / (double)a;
		if (p > q) swap(p, q);
		x1 = (int64)ceil(p);
		x2 = (int64)floor(q);

		p = (y - y1) / (double)b; q = (y - y2) / (double)b;
		if (p > q) swap(p, q);
		y1 = (int64)ceil(p);
		y2 = (int64)floor(q);

		//printf("xy %lld %lld : ab %d %d : x %lld %lld : y %lld %lld\n", x, y, a, b, x1, x2, y1, y2);

		x1 = max(x1, y1); x2 = min(x2, y2);
		return max(0LL, x2 - x1 + 1);
	}
	return 0;
}
int main()
{
   // I will always use scanf and prLongf
   // May be i won't be a good programmer but i will be a good human being
    int cs , t = II ;
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        Long A  = LL , B = LL , C = LL , x1 = LL , x2 = LL , y1 = LL , y2 = LL ;
        printf("Case %d: %lld\n",cs,solve( A , B , C , x1 , x2 , y1 , y2 ) );
    }

    return 0;
}

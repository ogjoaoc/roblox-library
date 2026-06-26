template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T operator^(P p) const { return x*p.y - y*p.x; }
	T dot(P p) const { return x*p.x + y*p.y; } // ||a|| * ||b|| * cos(theta)
	T cross(P p) const { return x*p.y - y*p.x; } // ||a|| * ||b|| * sin(theta)
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }

    T orient(P a, P b, P c) {return (b-a)^(c-a);}
    
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
        return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
        friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }

    // inside the disk of diameter [a, b]
    bool inDisk(P a, P b, P p) {
        return (a-p).dot(b-p) <= 0;
    }   

    bool onSegment(P a, P b, P p) {
        return orient(a,b,p) == 0 && inDisk(a,b,p);
    }

	bool properInter(P a, P b, P c, P d, P &ans) {
		double oa = orient(c,d,a),
				ob = orient(c,d,b),
				oc = orient(a,b,c),
				od = orient(a,b,d);
		// Proper intersection exists iff opposite signs
		if (oa*ob < 0 && oc*od < 0) {
			P ans = (a*ob - b*oa) / (ob-oa);
			return true;
		}
		return false;
	}

    set<P> inters(P a, P b, P c, P d) {
        P out;
        if (properInter(a,b,c,d,out)) return {out};
        set<P> s;
        if (onSegment(c,d,a)) s.insert(a);
        if (onSegment(c,d,b)) s.insert(b);
        if (onSegment(a,b,c)) s.insert(c);
        if (onSegment(a,b,d)) s.insert(d);
        return s;
    }
};

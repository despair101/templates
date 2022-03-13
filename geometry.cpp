namespace geometry {
  typedef long double g;

  struct Pt {
    g x;
    g y;

    Pt() {}
    Pt(g x_, g y_) : x(x_), y(y_) {}

    bool operator==(Pt a) {
      return x == a.x && y == a.y;
    }
  };

  istream& operator>>(istream& in, Pt& a) {
    cin >> a.x >> a.y;
    return in;
  }

  ostream& operator<<(ostream& out, Pt a) {
    cout << a.x << ' ' << a.y;
    return out;
  }

  struct Vec {
    g x;
    g y;

    Vec() {}
    Vec(g x_, g y_) : x(x_), y(y_) {}
    Vec(Pt st, Pt ed) : x(ed.x - st.x), y(ed.y - st.y) {}

    Vec operator+(Vec a) {
      return Vec(x + a.x, y + a.y);
    }
    Vec operator-(Vec a) {
      return Vec(x - a.x, y - a.y);
    }
    g operator^(Vec a) {
      return x * a.y - y * a.x;
    }
    g operator*(Vec a) {
      return x * a.x + y * a.y;
    }
    bool operator==(Vec a) {
      return x == a.x && y == a.y;
    }
    ld len() {
      return sqrt(x * x + y * y);
    }
  };

  istream& operator>>(istream& in, Vec& a) {
    cin >> a.x >> a.y;
    return in;
  }

  ostream& operator<<(ostream& out, Vec a) {
    cout << a.x << ' ' << a.y;
    return out;
  }

  ld getArea(vector<Pt>& plg) {
    plg.push_back(plg[0]);

    ll area = 0;
    for (int i = 0; i < sz(plg) - 1; ++i) {
      area += (Vec(Pt(0, 0), plg[i]) ^ Vec(Pt(0, 0), plg[i + 1]));
    }

    plg.pop_back();

    return ld(abs(area)) / 2;
  }

  bool isPtInLine(Pt a, Pt s, Pt e) {
    return (Vec(s, e) ^ Vec(s, a)) == 0;
  }

  bool isPtInRay(Pt a, Pt s, Pt e) {
    if (!isPtInLine(a, s, e)) return false;
    return (Vec(s, e) * Vec(s, a)) >= 0;
  }

  bool isPtInSeg(Pt a, Pt s, Pt e) {
    if (!isPtInLine(a, s, e)) return false;
    return isPtInRay(a, s, e) && isPtInRay(a, e, s);
  }

  bool isPtInAngle(Pt a, Pt l, Pt o, Pt r) {
    Vec v1(o, l), v2(o, r), v3(o, a);
    bool pos = false, neg = false;
    pos |= (v1 ^ v2) > 0;
    neg |= (v1 ^ v2) < 0;
    pos |= (v1 ^ v3) > 0;
    neg |= (v1 ^ v3) < 0;
    pos |= (v3 ^ v2) > 0;
    neg |= (v3 ^ v2) < 0;
    return (pos && neg ? false : true);
  }

  bool isPtInPlg(Pt a, vector<Pt>& plg) {
    for (Pt b : plg) {
      if (a == b) return true;
    }

    ld angle = 0;
    for (int i = 0; i < sz(plg); ++i) {
      if (isPtInSeg(a, plg[i], plg[(i + 1) % sz(plg)])) return true;
      angle += atan2(Vec(a, plg[i]) ^ Vec(a, plg[(i + 1) % sz(plg)]), Vec(a, plg[i]) * Vec(a, plg[(i + 1) % sz(plg)]));
    }

    return abs(angle) > 2;
  }

  bool isPtInCnvPlg(Pt a, vector<Pt>& plg) {
    int left = 1, right = sz(plg) - 1;
    if (!isPtInAngle(a, plg[left], plg[0], plg[right])) return false;
    while (right - left > 1) {
      int mid = (left + right) / 2;
      if (isPtInAngle(a, plg[left], plg[0], plg[mid])) {
        right = mid;
      } else {
        left = mid;
      }
    }
    return isPtInAngle(a, plg[0], plg[left], plg[right]);
  }
}

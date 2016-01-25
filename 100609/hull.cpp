bool operator <(PII a, PII b) { return a.first < b.first || (a.first == b.first && a.second < b.second); }
LL cross(PII a,PII b, PII c){
    PII ab = MP(b.first-a.first,b.second-a.second);
    PII ac = MP(c.first-a.first,c.second-a.second);
    return ab.first*ac.second - ab.second*ac.first;
}
vector<PII> ConvexHull(vector<PII> P) {
    int n = P.size(), k = 0; vector<PII> H(2*n);
    sort(P.begin(), P.end());
    for (int i = 0; i < n; i++)
    { while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--; H[k++] = P[i]; }28
    for (int i = n-2, t = k+1; i >= 0; i--)
    { while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--; H[k++] = P[i]; }
    H.resize(k);
    return H;
}

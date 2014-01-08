const int MAXN = 100005;
int par[MAXN];
int find_parent(int x)
{
    if(par[x]==x) return x;
    return par[x] = find_parent(par[x]);
}
void Make_Union(int x , int y)
{
    par[find_parent(x)] = find_parent(y);
}
bool isUnion(int x , int y)
{
    return find_parent(x)==find_parent(y);
}

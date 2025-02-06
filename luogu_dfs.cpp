#include<cstdio>
#include<queue>
using namespace std;
queue<int>hori;
queue<int>para;
int n,m;
int ans;
char s[101][101];
inline int read(){
    char p=0;int r=0,o=0;
    for(;p<'0'||p>'9';o|=p=='-',p=getchar());
    for(;p>='0'&&p<='9';r=(r<<1)+(r<<3)+(p^48),p=getchar());
    return o?(~r)+1:r;
}
inline void bfs(int x,int y){
    s[x][y]='.';
    int dx,dy;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            dx=x+i;
            dy=y+j;
            if(dx>=0&&dx<n&&dy>=0&&dy<m&&s[dx][dy]=='W'){
                hori.push(dx);
                para.push(dy);
            }
        }
    }
}
int main(){
    n=read();m=read();
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='W'){
                hori.push(i);
                para.push(j);
                while(!hori.empty()){
                    bfs(hori.front(),para.front());
                    hori.pop();para.pop();
                }
                ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
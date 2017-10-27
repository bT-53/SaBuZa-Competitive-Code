#include <stdio.h>
#include <vector>
using namespace std;
int main(){
    int dim;
    scanf("%d",&dim);
    if(dim==1){
        int elem;
        vector<int> map;
        scanf("%d",&elem);
        map.push_back(0);
        for(int i=1; i<=elem; i++){
            int temp;
            scanf("%d",&temp);
            map.push_back(temp+map[i-1]);
        }
        int q;
        scanf("%d",&q);
        for(int i=0;i<q;i++){
            int st,ed;
            scanf("%d",&st);
            scanf("%d",&ed);
            printf("%d\n",map[ed]-map[st-1]);
        }
    }
    else if(dim==2){
       
        vector< vector<int> > map;
        int row,column;
        int temp;
        scanf("%d %d",&row,&column);
        for(int i=0; i<=row; i++){
            vector<int> map_temp;
            map_temp.push_back(0);
            if(i==0){
                for(int j=1; j<=column; j++){
                    map_temp.push_back(0);
                }
            }else{
                for(int j=1; j<=column; j++){
                    scanf("%d",&temp);
                    map_temp.push_back(temp);
                }
            }
            
            map.push_back(map_temp);
        }
        
        for(int i=1;i<=row;i++){
            for(int j=1;j<=column;j++){
                map[i][j]=map[i][j]+map[i-1][j]+map[i][j-1]-map[i-1][j-1];
            }
        }
        int q;
        scanf("%d",&q);
        for(int i=0;i<q;i++){
            int x1,x2,y1,y2;
            scanf("%d %d",&x1,&y1);
            scanf("%d %d",&x2,&y2);
            x1--;
            y1--;

            printf("%d\n",map[x2][y2]-map[x2][y1]-map[x1][y2]+map[x1][y1]);
        }
    }
    else if(dim==3){
        int d1,d2,d3;
        vector<vector<vector<int> > > ma;
        scanf("%d %d %d",&d1,&d2,&d3);
        for(int i=0;i<=d1;i++){
            vector<vector<int> > temp_d2;
            if(i==0){
                for(int j=0;j<=d2;j++){
                    vector<int> temp_d1;
                    for(int k=0;k<=d3;k++){
                        temp_d1.push_back(0);
                    }
                    temp_d2.push_back(temp_d1);
                }
            }
            
            else{
                for(int j=0;j<=d2;j++){
                    vector<int> temp_d1;
                    temp_d1.push_back(0);
                
                    if(j==0){
                        for(int k=1;k<=d3;k++){
                            temp_d1.push_back(0);
                        }
                    
                    }else{
                        for(int k=1;k<=d3;k++){
                            int temp;
                            scanf("%d",&temp);
                            temp_d1.push_back(temp);
                        }
                    }
                    temp_d2.push_back(temp_d1);
                }
            }

            ma.push_back(temp_d2);
        }
        for(int i=1;i<=d1;i++){
            for(int j=1;j<=d2;j++){
                for(int k=1;k<=d3;k++){
                    ma[i][j][k]=ma[i][j][k]+
                                ma[i-1][j][k]+ma[i][j-1][k]+ma[i][j][k-1]-
                                ma[i-1][j-1][k]-ma[i][j-1][k-1]-ma[i-1][j][k-1]+
                                ma[i-1][j-1][k-1];
                }
            }
        }
        int q;
        scanf("%d",&q);
        for(int i=0;i<q;i++){
            int x1,y1,z1;
            int x2,y2,z2;
            
            scanf("%d %d %d",&x1,&y1,&z1);
            scanf("%d %d %d",&x2,&y2,&z2);
            x1--;
            y1--;
            z1--;
            printf("%d\n",ma[x2][y2][z2]
                        -ma[x1][y2][z2]-ma[x2][y1][z2]-ma[x2][y2][z1]
                        +ma[x1][y1][z2]+ma[x1][y2][z1]+ma[x2][y1][z1]
                        -ma[x1][y1][z1]
                    );
        }
        
    }else if(dim==4){
        int d1,d2,d3,d4;
        vector<vector<vector<vector<int> > > > ma;
        scanf("%d %d %d %d",&d1,&d2,&d3,&d4);
        for(int i=0;i<=d1;i++){
            vector<vector<vector<int> > > temp_d3;
            if(i==0){
                for(int j=0;j<=d2;j++){
                    vector<vector<int> > temp_d2;
                    for(int k=0;k<=d3;k++){
                        vector<int> temp_d1;
                        for(int l=0;l<=d4;l++){
                            temp_d1.push_back(0);
                        }
                        temp_d2.push_back(temp_d1);
                    }
                    temp_d3.push_back(temp_d2);
                }
            }else{
                for(int j=0;j<=d2;j++){
                    vector<vector<int> > temp_d2;
                    if(j==0){
                        for(int k=0;k<=d3;k++){
                            vector<int> temp_d1;
                            for(int l=0;l<=d4;l++){
                                temp_d1.push_back(0);
                            }
                            temp_d2.push_back(temp_d1);
                        }
                    }
                    else{
                        for(int k=0; k<=d3;k++){
                            vector<int> temp_d1;
                            if(k==0){
                                for(int l=0;l<=d4;l++){
                                    temp_d1.push_back(0);
                                }
                                temp_d2.push_back(temp_d1);
                            }else{
                                for(int l=0;l<=d4;l++){
                                    if(l==0){
                                        temp_d1.push_back(0);
                                    }else{
                                        int temp;
                                        scanf("%d",&temp);
                                        temp_d1.push_back(temp);
                                    }
                                }
                                temp_d2.push_back(temp_d1);
                            }
                        }
                    }
                    temp_d3.push_back(temp_d2);
                }
            }
            ma.push_back(temp_d3);
        }
        for(int i=1;i<=d1;i++){
            for(int j=1;j<=d2;j++){
                for(int k=1;k<=d3;k++){
                    for(int l=1;l<=d4;l++){
                        ma[i][j][k][l] = ma[i][j][k][l]
                                         +ma[i-1][j][k][l]+ma[i][j-1][k][l]+ma[i][j][k-1][l]+ma[i][j][k][l-1] 
                                         -ma[i-1][j-1][k][l]-ma[i-1][j][k-1][l]-ma[i-1][j][k][l-1]
                                         -ma[i][j-1][k-1][l]-ma[i][j-1][k][l-1]-ma[i][j][k-1][l-1]
                                         +ma[i-1][j-1][k-1][l]+ma[i-1][j-1][k][l-1]+ma[i-1][j][k-1][l-1]+ma[i][j-1][k-1][l-1]
                                         -ma[i-1][j-1][k-1][l-1];
                    }
                }
            }
        }
        int q;
        scanf("%d",&q);  
        for(int i=0;i<q;i++){
            int x1,y1,z1,w1;
            int x2,y2,z2,w2;
            scanf("%d %d %d %d",&x1,&y1,&z1,&w1);
            scanf("%d %d %d %d",&x2,&y2,&z2,&w2);
            x1--;
            y1--;
            z1--;
            w1--;
            printf("%d\n",ma[x2][y2][z2][w2]
                        -ma[x1][y2][z2][w2]-ma[x2][y1][z2][w2]-ma[x2][y2][z1][w2]-ma[x2][y2][z2][w1]
                        +ma[x1][y1][z2][w2]+ma[x1][y2][z1][w2]+ma[x1][y2][z2][w1]+ma[x2][y1][z1][w2]+ma[x2][y1][z2][w1]+ma[x2][y2][z1][w1]
                        -ma[x1][y1][z1][w2]-ma[x1][y1][z2][w1]-ma[x1][y2][z1][w1]-ma[x2][y1][z1][w1]
                        +ma[x1][y1][z1][w1]
                    );
        }
    }else if(dim==5){
        int d1,d2,d3,d4,d5;
        scanf("%d %d %d %d %d",&d1,&d2,&d3,&d4,&d5);
        vector<vector<vector<vector<vector<int> > > > >  ma;
        for(int i=0;i<=d1;i++){
            vector<vector<vector<vector<int> > > > temp_d4;
            if(i==0){
                for(int j=0;j<=d2;j++){
                    vector<vector<vector<int> > > temp_d3;
                    for(int k=0;k<=d3;k++){
                        vector<vector<int> > temp_d2;
                        for(int l=0;l<=d4;l++){
                            vector<int> temp_d1;
                            for(int m=0;m<=d5;m++){
                                 temp_d1.push_back(0);
                            }
                            temp_d2.push_back(temp_d1);
                        }
                        temp_d3.push_back(temp_d2);
                    }
                    temp_d4.push_back(temp_d3);
                }
            }else{
                for(int j=0;j<=d2;j++){
                    vector<vector<vector<int> > > temp_d3;
                    if(j==0){
                        for(int k=0;k<=d3;k++){
                            vector<vector<int> > temp_d2;
                            for(int l=0;l<=d4;l++){
                                vector<int> temp_d1;
                                for(int m=0;m<=d5;m++){
                                    temp_d1.push_back(0);
                                }
                                temp_d2.push_back(temp_d1);
                            }
                            temp_d3.push_back(temp_d2);
                        }
                    }
                    else{
                        for(int k=0; k<=d3;k++){
                            vector<vector<int> > temp_d2;
                            if(k==0){
                                for(int l=0;l<=d4;l++){
                                    vector<int> temp_d1;
                                    for(int m=0;m<=d5;m++){
                                        temp_d1.push_back(0);
                                    }
                                    temp_d2.push_back(temp_d1);
                                }
                                temp_d3.push_back(temp_d2);
                            }else{
                                for(int l=0;l<=d4;l++){
                                    vector<int> temp_d1;
                                    if(l==0){
                                        for(int m=0;m<=d5;m++){
                                            temp_d1.push_back(0);
                                        }
                                        temp_d2.push_back(temp_d1);
                                    }else{
                                        for(int m=0;m<=d5;m++){
                                            if(m==0){
                                                temp_d1.push_back(0);
                                               
                                            }else{
                                                int temp;
                                                scanf("%d",&temp);
                                                temp_d1.push_back(temp);
                                            }
                                        }
                                        temp_d2.push_back(temp_d1);
                                    }
                                }
                                temp_d3.push_back(temp_d2);
                            }
                        }
                    }
                    temp_d4.push_back(temp_d3);
                }
            }
            ma.push_back(temp_d4);
        }
        for(int i=1;i<=d1;i++){
            for(int j=1;j<=d2;j++){
                for(int k=1;k<=d3;k++){
                    for(int l=1;l<=d4;l++){
                        for(int m=1;m<=d5;m++){
                            //printf("%d ",ma[i][j][k][l][m]);
                            ma[i][j][k][l][m] = ma[i][j][k][l][m]
                                                +ma[i-1][j][k][l][m]+ma[i][j-1][k][l][m]+ma[i][j][k-1][l][m]+ma[i][j][k][l-1][m]+ma[i][j][k][l][m-1]
                                                -ma[i-1][j-1][k][l][m]-ma[i-1][j][k-1][l][m]-ma[i-1][j][k][l-1][m]-ma[i-1][j][k][l][m-1]-ma[i][j-1][k-1][l][m]-ma[i][j-1][k][l-1][m]-ma[i][j-1][k][l][m-1]-ma[i][j][k-1][l-1][m]-ma[i][j][k-1][l][m-1]-ma[i][j][k][l-1][m-1]
                                                +ma[i][j][k-1][l-1][m-1]+ma[i][j-1][k][l-1][m-1]+ma[i][j-1][k-1][l][m-1]+ma[i][j-1][k-1][l-1][m]+ma[i-1][j][k][l-1][m-1]+ma[i-1][j][k-1][l][m-1]+ma[i-1][j][k-1][l-1][m]+ma[i-1][j-1][k][l][m-1]+ma[i-1][j-1][k][l-1][m]+ma[i-1][j-1][k-1][l][m]
                                                -ma[i][j-1][k-1][l-1][m-1]-ma[i-1][j][k-1][l-1][m-1]-ma[i-1][j-1][k][l-1][m-1]-ma[i-1][j-1][k-1][l][m-1]-ma[i-1][j-1][k-1][l-1][m]
                                                +ma[i-1][j-1][k-1][l-1][m-1];
                        }
                        //printf("\n");
                    }
                    //printf("\n");
                }
                //printf("\n");
            }
            //printf("\n");
        }

        int q;
        scanf("%d",&q);
        for(int i=0;i<q;i++){
            int x1,y1,z1,w1,v1;
            int x2,y2,z2,w2,v2;
            scanf("%d %d %d %d %d",&x1,&y1,&z1,&w1,&v1);
            scanf("%d %d %d %d %d",&x2,&y2,&z2,&w2,&v2);
            x1--;
            y1--;
            z1--;
            w1--;
            v1--;
            printf("%d\n",ma[x2][y2][z2][w2][v2]
                        -ma[x1][y2][z2][w2][v2]-ma[x2][y1][z2][w2][v2]-ma[x2][y2][z1][w2][v2]-ma[x2][y2][z2][w1][v2]-ma[x2][y2][z2][w2][v1]
                        +ma[x1][y1][z2][w2][v2]+ma[x1][y2][z1][w2][v2]+ma[x1][y2][z2][w1][v2]+ma[x1][y2][z2][w2][v1]+ma[x2][y1][z1][w2][v2]+ma[x2][y1][z2][w1][v2]+ma[x2][y1][z2][w2][v1]+ma[x2][y2][z1][w1][v2]+ma[x2][y2][z1][w2][v1]+ma[x2][y2][z2][w1][v1]
                        -ma[x2][y2][z1][w1][v1]-ma[x2][y1][z2][w1][v1]-ma[x2][y1][z1][w2][v1]-ma[x2][y1][z1][w1][v2]-ma[x1][y2][z2][w1][v1]-ma[x1][y2][z1][w2][v1]-ma[x1][y2][z1][w1][v2]-ma[x1][y1][z2][w2][v1]-ma[x1][y1][z2][w1][v2]-ma[x1][y1][z1][w2][v2]
                        +ma[x2][y1][z1][w1][v1]+ma[x1][y2][z1][w1][v1]+ma[x1][y1][z2][w1][v1]+ma[x1][y1][z1][w2][v1]+ma[x1][y1][z1][w1][v2]
                        -ma[x1][y1][z1][w1][v1]
                    );
        }
        
    }
    
}
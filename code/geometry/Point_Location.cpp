
int32_t main(){
    sws;
 
    int t; cin >> t;
 
    while(t--){
 
        int x1, y1, x2, y2, x3, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
 
        int deltax1 = (x1-x2), deltay1 = (y1-y2);
 
        int compx = (x1-x3), compy = (y1-y3);
 
        int ans = (deltax1*compy) - (compx*deltay1);
 
        if(ans == 0){cout << "TOUCH\n"; continue;}
        if(ans < 0){cout << "RIGHT\n"; continue;}
        if(ans > 0){cout << "LEFT\n"; continue;}
    }
    return 0;
}
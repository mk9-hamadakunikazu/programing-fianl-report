//
//  main.cpp
//  C++_practice_final
//
//  Created by 浜田国和 on 2021/08/09.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Account{
protected:
    std::string _date;
    int _io;
    int _total;
public:
    void setDate(std::string DATE){_date = DATE;}
    void setIo(int IO){_io = IO;}
    void setTotal(int TOTAL){_total = TOTAL;}
    int total(){return _total;}
    void show(){
        std::cout << "残高:￥" << _total << std::endl;
    }
};

class OverFlow{};
void f(size_t s){
    if(s < 1) throw OverFlow();
}

using namespace std;

int main(){
    string A;
    cout << "残高照会ならdを、お金の出し入れならmを押してください。";
    cin  >> A;
    
    
    if(A == "m"){
    string day;
    string y;
    int m;
    int a;
    
    cout << "年月日を入力してください(例：2020-01-29)\n";
    cin >> day;
    cout << "入金?(y/n)\n";
    cin >> y;
    if(y == "y") {
        cout  << "入金額を入力してください\n";
        cin >> m;
    }else{
        cout << "出金額を入力してください\n";
        cin >> m;
        m = m * (-1);
    }
    
        
    
    ifstream datafile("yd.txt");
    string label;
    vector<int> v;
    int X,Y;
    while(datafile >> label >> X >> Y){
        v.emplace_back(Y);
    }
    datafile.close();
    
    if(v.size() < 1){
        a = m;
    }else{
        a = v[v.size()-1]+m;
    }
    
    ofstream outfile1("yd.txt",std::ios::app); //上書き
    outfile1 <<  day << "    " << m << "    " <<  a  << endl;
    outfile1.close();
    
    
    vector<Account> v2;
    ifstream datafile2("yd.txt");
    string date;
    int io;
    int total;
    while(datafile2 >> date >> io >> total){
        v2.emplace_back();
        v2[v2.size()-1].setDate(date);
        v2[v2.size()-1].setIo(io);
        v2[v2.size()-1].setTotal(total);
    }
    datafile2.close();
    
    v2[v2.size()-1].show();
   
    
    
    }
    if(A == "d"){
        ifstream datasurv("yd.txt");
        string DAY;
        vector<int> v3;
        int B,C;
        while(datasurv >> DAY >> B >> C){
            v3.emplace_back(C);
    }
    datasurv.close();
        
        size_t S = v3.size();
        try{
            f(S);
        }catch(OverFlow){
            cout << "使用履歴がありません。";
            return 0;
        }
        
        auto it = v3.end();
        cout << "残高:￥" << *(it-1) ;
        
    
}
}

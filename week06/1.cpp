#include <iostream>

using namespace std;

struct Student
{
    string name;
    int mark;
};

int main(){
    int N;
    int M;
    cin >> N;
    pair<string, int> pair_;
    Student massiv_studentov[N];
    for (int i = 0; i < N; i++){
        cin >> pair_.first;
        cin >> pair_.second;
        massiv_studentov[i].name = pair_.first;
        massiv_studentov[i].mark = pair_.second;
    }
    cin >> M;
    for (int i = 0; i < N; i++){
        int j_max;
        int m_max = 2147483647;
        for (int j = 0; j < N; j++){
            cout << massiv_studentov[j].mark<<' ';
            cout << j<<' ';
            cout << m_max<< endl;
            cout << j_max << endl;
            if ((massiv_studentov[j].mark < m_max) and (massiv_studentov[j].mark != -1)){
                
                m_max = massiv_studentov[j].mark;
                j_max = j;
                
            }
            cout << j_max << endl;
            if ((massiv_studentov[j].mark == m_max) and (massiv_studentov[j].mark != -1)){

                int len = sizeof(massiv_studentov[j_max].name)/sizeof(massiv_studentov[j_max].name[0]);
                for (int k = 0; k < len; k++){
                    cout << endl << endl;
                    cout << (int) massiv_studentov[j_max].name[k] << ' ';
                    cout << (int) massiv_studentov[j].name[k];
                    if ((int) massiv_studentov[j_max].name[k] > (int) massiv_studentov[j].name[k]){
                        j_max = j;
                        
                        m_max = massiv_studentov[j].mark;
                        cout << (int) massiv_studentov[j_max].name[k];
                        cout << (int) massiv_studentov[j].name[k];
                        cout << '*' << endl;
                    }
                }
            }
            cout << j_max << endl;
        }
        if (m_max >= M){    
        cout << massiv_studentov[j_max].name << ' ';
        }
        massiv_studentov[j_max].mark = -1;
    }
    return 0;
}
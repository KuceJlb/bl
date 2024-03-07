#include <iostream>


using namespace std;
unsigned max_unique_subarray_length(char const symbols[], unsigned size) {
     int c = 0;
     unsigned m = 26;
     if (size - 1 < m){
         m = size - 1;
     }
     for (unsigned i = m; i<=m; i--){
        for (unsigned j = 0; j < size-i; j++){
            c = i+1;
            for (unsigned k = j; k < j+i+1; k++){
                for (unsigned l = j; l < j+i+1; l++){
                    if ((k!=l) and (symbols[k]==symbols[l])) {
                        c = 1;
                        continue;
                    }
                }
            }
            if (c > 1){
                return c;
            }
        }
        cout << i << endl;
     }
     cout << '*';
     return 1;
 }
int main(){
    bool const a[] = {1,1,1,1,1};
    cout << max_unique_subarray_length("aaaaa", 5);
}

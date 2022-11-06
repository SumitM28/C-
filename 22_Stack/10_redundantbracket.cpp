// check if the given string have a redendant bracket or not.
#include<iostream>
#include<stack> 
using namespace std;

bool checkRedendant(string str){

    stack<char>st;

    for(int i=0;i<str.size();i++){

        char ch=str[i];

        // when the char is open bracket or operator push in the stack.
        if (ch=='(' || ch=='+'|| ch=='-'|| ch=='*'|| ch=='/')
        {
            st.push(ch);
        }
        else{

            // when char will be close bracket or lower alpha.
            if(ch==')'){
                
                bool isRedendant=true;

                while (st.top() !='(')
                {
                    char top=st.top();
                    if(top=='+'|| top=='-'|| top=='*'|| top=='/'){

                        isRedendant=false;
                    }
                    st.pop();
                }
                
                if(isRedendant==true) return true;
                
                st.pop();
            }
        }
        
    }
    
    return false;

}

int main(){


    string str="(a+b)";
    // cout<<str;
    cout<<checkRedendant(str);
}
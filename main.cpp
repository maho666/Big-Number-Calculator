#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;


bool checkSize(vector<int> &A,vector<int> &B)
{
    // Calculate lengths of both string
    int n1 = A.size(), n2 = B.size();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    for (int i = 0; i < n1; i++)
        if (A[i] < B[i])
            return true;
        else if (A[i] > B[i])
            return false;

    return false;
}

vector <int> add(vector<int> A, vector<int> B) //addition
{
    reverse(A.begin(),A.end());
    reverse(B.begin(), B.end());

    vector<int> ans; /* vector to store the answer */

    int min_len = min(A.size(), B.size());
    int max_len = max(A.size(), B.size());
    int carry = 0;
    if ((A[0]==0&&A.size()== 1) && (B[0]==0&&B.size() == 1))
    {
        ans.push_back(0);
        return ans;
    }

    for(int i=0;i<min_len;i++)
    {
        int digit_sum = A[i] + B[i] + carry;
        carry = digit_sum / 10;    // tens digit of digit_sum will be carry
        ans.push_back(digit_sum % 10);  //store the once digit as answer
    }



    if(A.size() > B.size())
    {
        for(int i=min_len; i < A.size(); i++)
        {
            int digit_sum = A[i] + carry;
            carry = digit_sum / 10;
            ans.push_back(digit_sum % 10);
        }
    }

    if(A.size() < B.size())
    {
        for(int i=min_len; i < B.size(); i++)
        {
            int digit_sum = B[i] + carry;
            carry = digit_sum / 10;
            ans.push_back(digit_sum % 10);
        }
    }



    while(carry)
    {
        ans.push_back(carry % 10);
        carry = carry / 10;
    }

    reverse(ans.begin(), ans.end());
    return ans;

}

vector<int> sub(vector<int> A, vector<int> B )       // Subtraction
{
   vector<int> result;
   int counter=0;
    if(checkSize(A,B))
        swap(A,B);

    int n1 = A.size(), n2 = B.size();
    if(n1 == n2)//if the same return 0
    {
    for (int i = 0; i < n1; i++)
    {
        //cout <<"in for"<<endl;
        if (A[i] != B[i])
        {
            //cout <<"I am here!!!"<<endl;
            break;
        }
        counter++;
        //cout <<"counter: "<<counter<<endl;
    }
    }
    if(counter == n1)
    {
        //cout <<"add 0"<<endl;
        result.push_back(0);
        return result;
    }

    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    /*for(int i=0;i<n1;i++)
    {
        cout<<A[i];
    }
    cout <<endl;*/
    int carry = 0;

    for (int i = 0; i < n2; i++)
    {

        int subb = ((A[i]) - (B[i])- carry);
        //cout <<"subb1: "<<subb<<endl;
        if (subb < 0) {
            subb = subb + 10;
            carry = 1;
            //cout <<"subb_car: "<<subb<<endl;
        }
        else
        {
            carry = 0;
        }
        result.push_back(subb);
    }


    for (int i = n2; i < n1; i++)
    {
         int subb = ((A[i] ) - carry);

        // if the sub value is -,make it positive
        if (subb < 0) {
            subb = subb + 10;
            carry = 1;
        }
        else
            carry = 0;

        result.push_back(subb);



	}
        for(int i=n1;i>0;i--)
        {
            //cout<<"i: "<<i<<"  "<<result[i]<<endl;
            if(result[i-1] == 0)
            {
                result.pop_back();
                //cout<<"++++++++";
            }
            else
                break;

        }
	// reverse resultant string
	reverse(result.begin(), result.end());


	return result;
}



vector <int> multiply(vector<int> A, vector<int> B) ////multiply
{
    vector<int> product(A.size()+B.size(),0);
    if ((A[0]==0&&A.size() == 1) || (B[0]==0&&B.size() == 1))
    {
        //cout <<"here!!!"<<endl;
        product.clear();
        product.push_back(0);
        return product;
    }

    for(int i=A.size()-1;i>=0;i--)
    {
        for(int j =B.size()-1;j>=0;j--)
        {
            int x = (B[j])*(A[i])+product[i+j+1];
            product[i+j+1] = x%10;
            product[i+j] += x/10;
        }
    }
    int i=0;
    while(i<product.size())
    {
        if(product[i]!=0)
        {
            break;
        }
    i++;
    }
    reverse(product.begin(), product.end());
    for(int i=product.size();i>0;i--)
        {
            //cout<<"i: "<<i<<"  "<<product[i]<<endl;
            if(product[i-1] == 0)
            {
                product.pop_back();
                //cout<<"++++++++";
            }
            else
                break;

        }
    reverse(product.begin(), product.end());// reverse
    return product;
}


vector <int> average(vector<int> sum)
{
    vector<int> avg;
    int ans,remain;
    int n=sum.size();
    if(sum[0]<2 && sum.size()==1)
    {
        avg.push_back(0);
        return avg;
    }
    for(int i=0;i<n;i++)
    {
        ans = (remain*10+sum[i])/2;
        remain = sum[i]%2;
        avg.push_back(ans);
    }
    reverse(avg.begin(), avg.end());
    for(int i=n;i>0;i--)
    {
        //cout<<"i: "<<i<<"  "<<avg[i]<<endl;
        if(avg[i-1] == 0)
        {
            avg.pop_back();
            //cout<<"++++++++";
        }
        else
            break;

    }
    reverse(avg.begin(), avg.end());
    return avg;
}
int main()
{
    int calculator;
    string first,second;
    vector <int> first_num,second_num,result,avg,addd;
    do{
    cout << "----Welcome to big number calculator----" << endl;
    cout << "Please choose the function"<<endl;
    cout << "1. Addition\n2. Subtraction\n3. Multiplication\n0. Exit"<<endl;
    cout << "--------------------------"<<endl;
    cin >> calculator;
    if(calculator == 0)
    {
        break;
    }

    switch(calculator)
    {
        case 1:
            cout <<"----Now for Addition----"<<endl;
        break;
        case 2:
            cout <<"----Now for Subtraction----"<<endl;
        break;
        case 3:
            cout <<"----Now for Multiplication----"<<endl;
        break;

        default:
            {
                cout <<"Error! Please try again."<<endl;
                cout<<endl;
            }

        break;
    }
    if(calculator>3 || calculator<0)
    {
        continue;
    }
    cout << "Please enter the two numbers."<<endl;
    cin >> first;
    cin >> second;
    for(int i = 0; i < first.size(); i++)
        first_num.push_back(first[i] - '0');
    for(int i = 0; i < second.size(); i++)
        second_num.push_back(second[i] - '0');
    /*
    for(auto i : first_num)
    {
        cout<<i;
    }
    cout<<endl;
    for(auto i : second_num)
        cout<<i;*/
    /*for(int j = 0;j<10;j++)
    {
        cout << first_num[j];
    }
    cout <<endl;*/
    switch(calculator)
    {
        case 1:
            {
            result = add(first_num, second_num);
            addd = result;
            break;
            }
        case 2:
            {
                if(checkSize(first_num,second_num))
                    {
                    result = sub(first_num, second_num);
                    }
                else
                    {
                    result = sub(second_num, first_num);
                    }
                addd = add(first_num, second_num);
            break;
            }
        case 3:
            {
            result = multiply(first_num, second_num);
            addd = add(first_num, second_num);
            break;
            }
        default:
        cout <<"Error! Please try again."<<endl;
    }
    cout<<"Result: ";
    for(auto i : result)
    {
        cout<<i;
    }
    cout << endl;
    avg = average(addd);
    cout<<"Mean: ";
    for(auto i : avg)
    {
        cout<<i;
    }
    cout<<endl;

    first_num.clear();
    second_num.clear();
    cout <<endl;

    }while(calculator != 0);
    cout << "Good bye!"<<endl;
    return 0;
}

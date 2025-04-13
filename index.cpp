#include<bits/stdc++.h>
using namespace std;

//////////////////////            BFS              ///////////////////
/*
int main()
{
    int node, edge, start_node;
    cout << "Enter number of nodes: ";
    cin >> node;
    cout << "Enter number of edges: ";
    cin >> edge;

    bool visit[node+1];
    vector<int> adj[node+1];  //array of vector

    cout << "Enter the edges: " << endl;
    for(int i=0; i<edge; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << "Enter the starting node: ";
    cin >> start_node;

    for(int i=0; i<=node; i++){
        visit[i]=false;
    }

    queue<int>q;
    q.push(start_node);
    visit[start_node] = true;

    cout << "BFS result: " << endl;
    while(!q.empty())
    {
        int fr = q.front();
        q.pop();
        cout << fr << endl;
        for(int i=0; i<adj[fr].size(); i++)
        {
            if(!visit[adj[fr][i]])
            {
                visit[adj[fr][i]]=true;
                q.push(adj[fr][i]);
            }
        }
    }
}
*/




/*
/////////////////////         DFS         ////////////////////
int main()
{
    int node, edge, start_node;
    cout << "Enter number of nodes: ";
    cin >> node;
    cout << "Enter number of edges: ";
    cin >> edge;

    bool visit[node+1];
    vector<int> adj[node+1];  // adjacency list

    cout << "Enter the edges: " << endl;
    for(int i = 0; i < edge; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); // undirected
    }

    cout << "Enter the starting node: ";
    cin >> start_node;

    for(int i = 0; i <= node; i++) {
        visit[i] = false;
    }

    cout << "DFS result: " << endl;

    // DFS using manual stack (no recursion)
    stack<int> st;
    st.push(start_node);
    visit[start_node] = true;

    while(!st.empty()) {
        int fr = st.top();
        st.pop();
        cout << fr << endl;

        // Push unvisited neighbors (can reverse to control order)
        for(int i = adj[fr].size() - 1; i >= 0; i--) {
            int neighbor = adj[fr][i];
            if(!visit[neighbor]) {
                visit[neighbor] = true;
                st.push(neighbor);
            }
        }
    }

    return 0;
}
*/




/////////                even and odd                   ///////
/*
int main()
{
    int n, i, arr[100];
    cout << "Enter your array size: ";
    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    ///// Even
    cout << "Even number off array: ";
    for(i = 0; i < n; i++)
    {
        if(arr[i]%2 == 0)
        cout << arr[i] << " ";
    }
    cout << endl;

    ///// Odd
    cout << "Odd number off array: ";
    for(i = 0; i < n; i++)
    {
        if(!(arr[i]%2 == 0))
        {
            cout << arr[i] << " ";
        }
    }
}
*/




///////////////////         Factorial          ///////////////

// only main
/*
int main()
{
    int n, i;

    cout << "Number: ";
    cin >> n;

    int fact = 1;
    for(i = 1; i <= n; i++)
    {
        fact = fact*i;
    }

    cout << fact;

}
*/
// with int
/*
int fact(int n)
{
    if(n <= 1)
    {
        return n;
    }
    else
    {
        return n * fact(n - 1);
    }
}
int main()
{
    int n, i;

    cout << "The Factorial Number: ";
    cin >> n;

    cout << fact(n);
}
*/




/////////////////           Fibonacci            /////////////
/*
//only main
int main()
{
    int n, i;

    cout << "How many terms: ";
    cin >> n;

    int a = 0, b = 1, next;

    cout << "Your fibonacci numbers: ";
    for(i=0; i<n; i++)
    {
        cout << a << " ";
        next = a + b;
        a = b;
        b = next;
    }
}
*/

// with int
/*
int fibonacci(int n)
{
    if(n == 0)
        return n;
    else if(n == 1)
        return n;
    else
        return fibonacci(n -1) + fibonacci(n - 2);
}
int main()
{
    int n, i;

    cout << "How many terms: ";
    cin >> n;

    cout << "Your fibonacci numbers: ";
    for(i = 0; i < n; i++)
    {
        cout << fibonacci(i) << " ";
    }
    return 0;
}
*/




////////////        Linear search               //////////////
/*
int main()
{
    int i, n, key, ab, found = 0, a[100];
    cout << "Number: ";
    cin >> n;

    cout << "Give " << n << " numbers: ";

    for(i=0; i<n; i++)
    {
        cin >> a[i];
    }
    cout << endl;

    for(i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    cout << "Number you search: ";
    cin >> key;

    for(i=0; i<n; i++)
    {
        if(a[i]==key)
        {
            found = 1;
            ab = i;
            break;
        }
    }


    if(found == 1)
        cout << "Your number is found in " << ab << " index.";
    else
        cout << "Your number is not found.";
}
*/



///////////////          Binary Search             ///////
/*
int main()
{
    int i, n, key, a[100];
    cout << "Number: ";
    cin >> n;

    cout << "Give " << n << " numbers: ";

    for(i=0; i<n; i++)
    {
        cin >> a[i];
    }
    cout << endl;

    for(i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    cout << "Number you search: ";
    cin >> key;

    int left = 0;
    int right = n - 1;
    int result = -1;

    while(left <= right)
    {
        int mid = left + (right-left)/2;

        if(a[mid] == key)
        {
            result = mid;
            break;
        }
        else if(a[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if(result!=-1)
    {
        cout << "Element found ar index " << result << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }

}

*/



//////////////////            prime number         //////////////////////
/*
int main()
{
    int n, i;
    bool isPrime = true;

    cout << "Enter a number: ";
    cin >> n;

    if(n <= 1)
    {
        isPrime = false;
    }
    else
    {
        for(i=2; i<= n/2; i++)
        {
            if(n % i == 0)
            {
                isPrime = false;
                break;
            }
        }
    }

    if(isPrime)
    {
        cout << n << " is a prime number" << endl;
    }
    else
    {
        cout << n << " is not a prime number." << endl;
    }

    return 0;
}
*/
///////recasion
/*
#include <iostream>
using namespace std;

bool isPrimeRecursive(int n, int i = 2) {
    if (n <= 1) return false;
    if (i > n / 2) return true;
    if (n % i == 0) return false;
    return isPrimeRecursive(n, i + 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isPrimeRecursive(n)) {
        cout << n << " is a prime number" << endl;
    } else {
        cout << n << " is not a prime number." << endl;
    }

    return 0;
}
*/

///////////////////// Palindrome /////////////////////////////
////number

/*
int main() {
    int num, original, reversed = 0;
    cout << "Enter a number: ";
    cin >> num;

    original = num;

    while (num != 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num = num / 10;
    }

    if (original == reversed) {
        cout << "Palindrome number!" << endl;
    } else {
        cout << "Not a palindrome." << endl;
    }

    return 0;
}
*/

/////// string
/*
int main() {
    string str;
    cout << "Enter a word: ";
    cin >> str;

    string rev = "";

    // Reverse the string
    for (int i = str.length() - 1; i >= 0; i--) {
        rev += str[i];
    }

    if (str == rev) {
        cout << "Palindrome word!" << endl;
    } else {
        cout << "Not a palindrome." << endl;
    }

    return 0;
}

*/








#
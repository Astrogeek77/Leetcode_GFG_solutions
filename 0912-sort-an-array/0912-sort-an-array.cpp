class Solution
{
//     void printarray(vector<int> &v, int start, int end, int tabs, string type, int d)
//     {

//         int i, j, n = v.size(), t = tabs;

//         while (t--) cout << "|\t\t";
//         for (i = 0; i < 50; i++) cout << "~";
//         cout << endl;

//         if (type != "output")
//         {
//             t = tabs;
//             while (t--) cout << "|\t\t";
//             cout << endl;
//         }

//         t = tabs;
//         while (t--) cout << "|\t\t";
//         cout << type << " (depth: " << d << ")" << endl;

//         t = tabs;
//         while (t--) cout << "|\t\t";
//         for (i = 0; i < start; i++) cout << "- ";
//         for (i = start; i <= end; i++) cout << v[i] << " ";
//         for (i = end + 1; i < n; i++) cout << "- ";
//         cout << endl;

//         if (type == "output")
//         {
//             t = tabs;
//             while (t--) cout << "|\t\t";
//             cout << endl;
//         }

//         return;
//     }

    void max_heap(vector<int> &a, int i, int x, int y)
    {
        int l = i;

        if ((2 *i) + 1 - x < (y + 1) && a[(2 *i) + 1 - x] > a[l])
            l = (2 *i) + 1 - x;
        if ((2 *i) + 2 - x < (y + 1) && a[(2 *i) + 2 - x] > a[l])
            l = (2 *i) + 2 - x;

        if (l != i)
        {
            a[i] = a[l] + a[i];
            a[l] = a[i] - a[l];
            a[i] = a[i] - a[l];
            max_heap(a, l, x, y);
        }
    }

    void build_heap(vector<int> &a, int x, int y)
    {
        int p = (x + y) / 2;
        for (int i = p; i >= x; i--)
            max_heap(a, i, x, y);
    }

    void heapsort(vector<int> &a, int x, int y)
    {
        build_heap(a, x, y);
        int len = y;
        for (int i = y; i >= x + 1; i--)
        {
            a[x] = a[x] + a[i];
            a[i] = a[x] - a[i];
            a[x] = a[x] - a[i];
            len--;
            max_heap(a, x, x, len);
        }
    }

    void insertionsort(vector<int> &a, int x, int y)
    {
        int temp, j;
        for (int i = x + 1; i <= y; i++)
        {
            temp = a[i];
            j = i - 1;

            while (j >= x && a[j] > temp)
            {
                a[j + 1] = a[j];
                j--;
            }

            a[j + 1] = temp;
        }
    }

    int get_pivot(vector<int> &a, int x, int y)
    {
        int m = (x + y) / 2;

        if (a[m] < a[x])
        {
            a[x] = a[x] + a[m];
            a[m] = a[x] - a[m];
            a[x] = a[x] - a[m];
        }

        if (a[y] < a[m])
        {
            a[y] = a[y] + a[m];
            a[m] = a[y] - a[m];
            a[y] = a[y] - a[m];

            if (a[m] < a[x])
            {
                a[x] = a[x] + a[m];
                a[m] = a[x] - a[m];
                a[x] = a[x] - a[m];
            }
        }

        a[x] = a[x] + a[m];
        a[m] = a[x] - a[m];
        a[x] = a[x] - a[m];

        return x;
    }

    int partition(vector<int> &a, int x, int y)
    {
        int l = get_pivot(a, x, y);

        while (true)
        {
            while (a[l] <= a[y] && l != y)
                y--;
            if (l == y)
                return l;

            a[l] = a[l] + a[y];
            a[y] = a[l] - a[y];
            a[l] = a[l] - a[y];
            l = y;

            while (a[l] >= a[x] && l != x)
                x++;
            if (l == x)
                return l;

            a[l] = a[l] + a[x];
            a[x] = a[l] - a[x];
            a[l] = a[l] - a[x];
            l = x;
        }
    }

    void introsort(vector<int> &a, int x, int y, int d, int steps, int tabs)
    {
        int l = y - x + 1, m, i;

        if (l < 5)
        {
            // printarray(a, x, y, tabs, "insertion", d);
            insertionsort(a, x, y);
        }
        else if (d == 0)
        {
            // printarray(a, x, y, tabs, "heapsort", d);
            heapsort(a, x, y);
        }
        else
        {
            // printarray(a, x, y, tabs, "quicksort", d);
            m = partition(a, x, y);
            introsort(a, x, m - 1, d - 1, ++steps, tabs + 1);
            introsort(a, m + 1, y, d - 1, ++steps, tabs + 1);
        }
        // printarray(a, x, y, tabs, "output", d);
    }
    public:
    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();
        
        int d = 2 * floor(log(n));
        introsort(nums, 0, n - 1, d, 0, 0);
        
        return nums;
    }
};
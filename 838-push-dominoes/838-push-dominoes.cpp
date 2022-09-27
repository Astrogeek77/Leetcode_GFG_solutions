class Solution
{
    public:
        string pushDominoes(string dominoes)
        {
            int n = dominoes.size();

            vector<int> left(n, -1), right(n);
            for (int i = 0; i < n; i++)
            {
               	//nearest left domino
                if (dominoes[i] != '.') left[i] = i;
                else left[i] = (i - 1 >= 0) ? left[i - 1] : -1;

               	//nearest right domino
                if (dominoes[n - i - 1] != '.') right[n - i - 1] = n - i - 1;
                else right[n - i - 1] = (n - i < n) ? right[n - i] : n;
            }

            for (int i = 0; i < n; i++)
            {
                if (dominoes[i] != '.') continue;

               	//for invalid domino we use INT_MAX, so we can disacrd it while taking min
                int left_power = (left[i] == -1 or dominoes[left[i]] == 'L') ? INT_MAX : i - left[i];
                int right_power = (right[i] == n or dominoes[right[i]] == 'R') ? INT_MAX : right[i] - i;

                if (left_power != right_power)
                {
                    dominoes[i] = (left_power < right_power) ? 'R' : 'L';
                }
            }

            return dominoes;
        }
};

// Observations:
    //The observations are for indices with dominoes[i] == '.'

    // the nearest dominoes on left and right determines the direction of fall
    // on the left side,
    // if nearest domino is a 'R', then it is valid
    // On the right side,
    // if nearest domino is a 'L', then it is valid
    // If both sides have valid and different distance dominoes, min - dist domino decides the direction
    // Else
    // if a single side contains a valid domino, that directon decides
    // In all other
    // case the dominos[i] is unchanged

    // Time: O(n)
    // Space: O(n)
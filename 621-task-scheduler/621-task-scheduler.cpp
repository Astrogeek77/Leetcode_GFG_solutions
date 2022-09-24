class Solution
{
    public:

    /*
     *At every interval we try to process that task which has the most freqeuncy. This will
       ensure that the situation where we  have to process two same tasks continuously is
       minimized
     *We first calculate the frequency of each task and then store it in a max heap
     *We also maintain a queue which keeps track of the tasks which are in cooldown and
       cannot be currently used
     *We first check the cooldown queue for any tasks that are available for processing 
       and add it the processing queue.
     *Then pop the max frequency task from max heap, decrement its value, and then add
       it to the cooldown queue along with its cooldown time i.e., the time period at which
       it will be available.
     *If no task can be done for a particular time period then the CPU will remain idle
        for that time
     *We keep on processing until both the frequency queue and the cooldown queue are empty
     *Then we return the total time required to process all the tasks
     *Time - O(n)
     *Space - O(26)
     *Refer for a better visual explanation - https://www.youtube.com/watch?v=s8p8ukTyA2I
     */

        int leastInterval(vector<char> &tasks, int n)
        {
            if (n == 0) return tasks.size();

            unordered_map<char, int> count;
            for (char ch: tasks) count[ch]++;

            priority_queue<int> freq; // QUEUE
            
            unordered_map<char, int>::iterator it;
            for (it = count.begin(); it != count.end(); it++)
                freq.push(it->second);

            queue<pair<int, int>> cooldown;
            int totalTime = 0;
            while (!freq.empty() || !cooldown.empty())
            {
                if (!cooldown.empty() && cooldown.front().second == totalTime)
                {
                    freq.push(cooldown.front().first);
                    cooldown.pop();
                }

                if (!freq.empty())
                {
                    int task = freq.top();
                    freq.pop();
                    task--;
                    if (task != 0) cooldown.push({ task,
                        totalTime + n + 1 });
                }
                totalTime++;
            }

            return totalTime;
        }
};
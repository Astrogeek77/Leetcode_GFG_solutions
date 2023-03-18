class BrowserHistory
{
    public:
    vector<string> history;
    int cur_idx;

    BrowserHistory(string homepage)
    {
        history.push_back(homepage);
        cur_idx = 0;
    }

    void visit(string url)
    {
        history.resize(cur_idx + 1);	// Clear forward history as we can't go forward
        history.push_back(url);
        cur_idx++;
    }

    string back(int steps)
    {
        int prev_idx = max(0, cur_idx - steps);
        cur_idx = prev_idx;
        return history[cur_idx];
    }

    string forward(int steps)
    {
        int next_idx = min((int) history.size() - 1, cur_idx + steps);
        cur_idx = next_idx;
        return history[cur_idx];
    }
};

/**
 *Your BrowserHistory object will be instantiated and called as such:
 *BrowserHistory* obj = new BrowserHistory(homepage);
 *obj->visit(url);
 *string param_2 = obj->back(steps);
 *string param_3 = obj->forward(steps);
 */
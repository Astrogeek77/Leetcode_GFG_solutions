class Solution
{
    public:
        int minSpeedOnTime(vector<int> &dist, double hour)
        {
            double minSpeed = 1, maxSpeed = 10000000, midSpeed = 0, ansSpeed = 10000000;
            double totalTime = 0;
           	//since only int value can be take for all element in dist but last ceil value should be atleast equals to size of the array. Example array size is 3 hours is 1.7, 2 hours is minimal required for first 2 elements as int value is required
            if (ceil(hour) < dist.size())
            {
                return -1;
            }
           	//maxSpeed is provided in the question
            while (minSpeed <= maxSpeed)
            {
               	//Taking the ceil values of speed as speeds are double value and answer for speed should be int only
                midSpeed = ceil((minSpeed + maxSpeed) / 2);
                totalTime = 0;
                for (int i = 0; i < dist.size(); i++)
                {
                   	//for last element we need not to completely wait for an int hour
                    if (i == dist.size() - 1)
                    {
                        double x = dist[i] / midSpeed;
                        totalTime += x;
                        continue;
                    }
                   	//completing int hour is required for all elements but last
                    totalTime += ceil(dist[i] / midSpeed);
                }	//if the totaltime taken is lesser or equals to the given hours, midSpeed could be our answer or less speed less than that might also work
                if (totalTime <= hour)
                {
                    ansSpeed = midSpeed;
                    maxSpeed = midSpeed - 1;
                }
                else
                {
                    minSpeed = midSpeed + 1;
                }
            }
            return ansSpeed;
        }
};
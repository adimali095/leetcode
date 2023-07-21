class Solution {
public:
    int max(int a,int b)
    {
        if(a>b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }
    int min(int a,int b)
    {
        if(a < b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }
    int maxArea(vector<int>& height) 
    {
        long long right,left,area;
        left = 0;
        right = height.size()-1;
        long long heighT,breadth;
        long long mxArea = 0;
        while(left<right)
        {
            heighT = min(height[left],height[right]);
            breadth = right-left;
            mxArea = max(mxArea , heighT * breadth);
            if(height[right] < height[left])
            {
                right--;
            }
            else if(height[right] > height[left])
            {
                left++;
            }
            else
            {
                left++;
                right--;
            }

        }
        return mxArea;
    }
    /*
    int maxArea(vector<int>& height) 
    {
        int maxarea = 0;
        int maxt = 0;
        int i,j;
        for(i=1;i<=height.size();i++)
        {
            for(j=1;j<=height.size();j++)
            {
                //maxarea = max(maxarea,i*j* (j-i));
                //maxarea = max(maxarea,height[i]*height[j]);
                maxarea = max(maxarea,( min(height[i-1],height[j-1]) * (i-j)) );
                //cout<<"\n"<<height[i-1]<<" "<<height[j-1]<<" "<<j-i;
            }
        }    
        return maxarea;
    }
    */
};

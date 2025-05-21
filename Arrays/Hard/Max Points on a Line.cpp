class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()<=2) return points.size();
        int res=1;
        for(int i=0; i<points.size(); i++){
            unordered_map<double,int>umap;
            int duplicates=0;
            int currmax=0;
            for(int j=i+1; j<points.size(); j++){
                if(points[i][0]==points[j][0] && points[i][1]==points[j][1]){
                    duplicates++;
                    continue;
                }
                double slope;
                if(points[i][0]==points[j][0]){
                    slope=numeric_limits<double>::infinity();
                } else{
                    slope = (double)(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);

                }
                umap[slope]++;
                currmax=max(currmax,umap[slope]);
            }
            res=max(res,currmax+duplicates+1);
        }
        return res;
    }
};

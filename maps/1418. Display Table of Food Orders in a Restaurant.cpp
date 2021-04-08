class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string>food_items;
        for(auto order:orders)
        {
            food_items.insert(order[2]);
        }
        map<int,unordered_map<string,int> >entries;
        vector<vector<string> >display_table;
        for(auto order:orders)
        {
            int table_number=stoi(order[1]);
            entries[table_number][order[2]]++;
        }
        vector<string>title;
        title.push_back("Table");
        for(auto food_item:food_items)
        {
            title.push_back(food_item);
        }
        display_table.push_back(title);
        for(auto entry:entries)
        {
            //cout<<endl<<entry.first<<endl;
            vector<string>temp;
            temp.push_back(to_string(entry.first));
            for(auto item:food_items)
            {
                //cout<<item<<" "<<entries[entry.first][item]<<"\n";
                temp.push_back(to_string(entries[entry.first][item]));
            }
            display_table.push_back(temp);
        }
        return display_table;
    }
};
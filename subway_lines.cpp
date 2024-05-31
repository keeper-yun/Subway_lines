



#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

// 定义表示地铁站的结构体
struct Station {
    string name; // 站点名称
    vector<pair<string, string>> neighbors; // vector<pair<邻居站点名称, 所属线路名称>>
};

// 执行广度优先搜索以找到最短路径的函数
vector<string> shortestPath(unordered_map<string, Station>& subwayMap, const string& startStation, const string& endStation) {
    // 创建用于BFS的队列
    queue<string> q;

    // 创建map来存储访问过的站点及其前驱
    unordered_map<string, string> predecessor;
    // 标记起始站点为已访问并入队
    predecessor[startStation] = "";
    q.push(startStation);

    // 执行BFS遍历
    while (!q.empty()) {
        string currentStation = q.front();
        q.pop();

        // 检查当前站点是否为目标站点
        if (currentStation == endStation) {
            // 重构最短路径
            vector<string> shortestPath;
            string station = endStation;
            while (station != "") {
                shortestPath.push_back(station);
                station = predecessor[station];
            }
            reverse(shortestPath.begin(), shortestPath.end());
            return shortestPath;
        }

        // 访问当前站点的邻居
        for (const auto& neighbor : subwayMap[currentStation].neighbors) {
            string neighborStation = neighbor.first;
            string lineName = neighbor.second;
            if (predecessor.find(neighborStation) == predecessor.end()) {
                predecessor[neighborStation] = currentStation;
                q.push(neighborStation);
            }
        }
    }

    // 如果未找到路径
    return vector<string>();
}

int main() {
    // 构建地铁图
    unordered_map<string, Station> subwayMap;
    
    // 为4号线添加站点及其连接
    subwayMap["同里"] = {"同里", {{"庞金路", "Line4"} }};
    subwayMap["庞金路"] = {"庞金路", {{"同里", "Line4"}, {"吴江汽车站", "Line4"}}};
    subwayMap["吴江汽车站"] = {"吴江汽车站", {{"庞金路", "Line4"}, {"吴江人民广场", "Line4"}}};
    subwayMap["吴江人民广场"] = {"吴江人民广场", {{"吴江汽车站", "Line4"}, {"松陵大道", "Line4"}}};
    subwayMap["松陵大道"] = {"松陵大道", {{"吴江人民广场", "Line4"},{"苏州湾东","Line4"}}};
    subwayMap["苏州湾东"] = {"苏州湾东", {{"松陵大道", "Line4"}, {"顾家荡", "Line4"}}};
    subwayMap["顾家荡"] = {"顾家荡", {{"苏州湾东", "Line4"}, {"笠泽路", "Line4"}}};    
    subwayMap["笠泽路"] = {"笠泽路", {{"顾家荡", "Line4"}, {"流虹路", "Line4"}}};
    subwayMap["流虹路"] = {"流虹路", {{"笠泽路", "Line4"}, {"江兴西路", "Line4"}}};
    subwayMap["江兴西路"] = {"江兴西路", {{"流虹路", "Line4"}, {"江陵西路", "Line4"}}};    
    subwayMap["江陵西路"] = {"江陵西路", {{"江兴西路", "Line4"}, {"花港", "Line4"}}};
    subwayMap["花港"] = {"花港", {{"江陵西路", "Line4"}, {"清树湾", "Line4"}}};
    subwayMap["清树湾"] = {"清树湾", {{"花港", "Line4"}, {"红庄", "Line4"}}};
    subwayMap["红庄"] = {"红庄", {{"清树湾", "Line4"}, {"石湖东路", "Line4"},{"蠡墅","Line4"}}};
    subwayMap["石湖东路"] = {"石湖东路", {{"红庄", "Line4"}, {"宝带路", "Line4"}}};
    subwayMap["宝带路"] = {"宝带路", {{"石湖东路","Line4"},{"团结桥", "Line4"}}};  
    subwayMap["团结桥"] = {"团结桥", {{"宝带路","Line4"},{"人民桥南", "Line4"}}}; 
    subwayMap["人民桥南"] = {"人民桥南", {{"团结桥", "Line4"},{"南门", "Line4"}}};  
    subwayMap["南门"] = {"南门", {{"人民桥南","Line4"},{"三元坊", "Line4"} }};  
    subwayMap["三元坊"] = {"三元坊", {{"南门","Line4"},{"乐桥", "Line4"} }};
    subwayMap["乐桥"] = {"乐桥", {{"三元坊","Line4"},{"察院场", "Line4"},{"临顿路", "Line1"}, {"养育巷", "Line1"} }};
    subwayMap["察院场"] = {"察院场", {{"乐桥","Line4"},{"北寺塔", "Line4"} }};
    subwayMap["北寺塔"] = {"北寺塔", {{"察院场","Line4"},{"苏州火车站", "Line4"} }};
    subwayMap["苏州火车站"] = {"苏州火车站", {{"北寺塔","Line4"},{"苏锦", "Line4"} }};   
    subwayMap["苏锦"] = {"苏锦", {{"苏州火车站","Line4"},{"平泷路西", "Line4"} }};
    subwayMap["平泷路西"] = {"平泷路西", {{"苏锦","Line4"},{"孙武纪念园", "Line4"} }};
    subwayMap["孙武纪念园"] = {"孙武纪念园", {{"平泷路西","Line4"},{"活力岛", "Line4"} }};
    subwayMap["活力岛"] = {"活力岛", {{"孙武纪念园","Line4"},{"姚祥", "Line4"} }};
    subwayMap["姚祥"] = {"姚祥", {{"活力岛","Line4"},{"张庄", "Line4"} }};
    subwayMap["张庄"] = {"张庄", {{"姚祥","Line4"},{"龙道浜", "Line4"} }};
    subwayMap["龙道浜"] = {"龙道浜", {{"张庄","Line4"}}};
     
   
    //4号线支线
    subwayMap["蠡墅"] = {"蠡墅", {{"红庄", "Line4"}, {"石湖莫舍", "Line4"}}};
    subwayMap["石湖莫舍"] = {"石湖莫舍", {{"蠡墅", "Line4"}, {"越溪", "Line4"}}};
    subwayMap["越溪"] = {"越溪", {{"蠡墅", "Line4"}, {"文溪路", "Line4"}}};
    subwayMap["文溪路"] = {"文溪路", {{"越溪", "Line4"}, {"天鹅荡路", "Line4"}}};
    subwayMap["天鹅荡路"] = {"天鹅荡路", {{"文溪路", "Line4"}, {"苏州湾北", "Line4"}}};
    subwayMap["苏州湾北"] = {"苏州湾北", {{"天鹅荡路", "Line4"}, {"木里", "Line4"}}};
    subwayMap["木里"] = {"木里", { {"苏州湾北", "Line4"} }};
    
    
    // 为1号线添加站点及其连接
    subwayMap["木渎"] = {"木渎", {{"金枫路", "Line1"}}};
    subwayMap["金枫路"] = {"金枫路", {{"汾湖路", "Line1"}, {"木渎", "Line1"}}};
    subwayMap["汾湖路"] = {"汾湖路", {{"玉山路", "Line1"}, {"金枫路", "Line1"}}};
    subwayMap["玉山路"] = {"玉山路", {{"狮子山", "Line1"}, {"汾湖路", "Line1"}}};
    subwayMap["狮子山"] = {"狮子山", {{"塔园路", "Line1"}, {"玉山路", "Line1"}}};
    subwayMap["塔园路"] = {"塔园路", {{"滨河路", "Line1"}, {"狮子山", "Line1"}}};
    subwayMap["滨河路"] = {"滨河路", {{"西环路", "Line1"}, {"塔园路", "Line1"}}};
    subwayMap["西环路"] = {"西环路", {{"桐泾北路", "Line1"}, {"滨河路", "Line1"}}};
    subwayMap["桐泾北路"] = {"桐泾北路", {{"广济南路", "Line1"}, {"西环路", "Line1"}}};
    subwayMap["广济南路"] = {"广济南路", {{"养育巷", "Line1"}, {"桐泾北路", "Line1"}}};
    subwayMap["养育巷"] = {"养育巷", {{"乐桥", "Line1"}, {"广济南路", "Line1"}}};
    subwayMap["乐桥"] = {"乐桥", {{"临顿路", "Line1"}, {"养育巷", "Line1"},{"三元坊","Line4"},{"察院场","Line4"}}};
    subwayMap["临顿路"] = {"临顿路", {{"相门路", "Line1"}, {"乐桥", "Line1"}}};
    subwayMap["相门路"] = {"相门路", {{"东环路", "Line1"}, {"临顿路", "Line1"}}};
    subwayMap["东环路"] = {"东环路", {{"中央公园", "Line1"}, {"相门路", "Line1"}}};
    subwayMap["中央公园"] = {"中央公园", {{"星海广场", "Line1"}, {"东环路", "Line1"}}};
    subwayMap["星海广场"] = {"星海广场", {{"东方之门", "Line1"}, {"中央公园", "Line1"}}};
    subwayMap["东方之门"] = {"东方之门", {{"文化博览中心", "Line1"}, {"星海广场", "Line1"}}};
    subwayMap["文化博览中心"] = {"文化博览中心", {{"时代广场", "Line1"}, {"东方之门", "Line1"}}};
    subwayMap["时代广场"] = {"时代广场", {{"星湖路", "Line1"}, {"文化博览中心", "Line1"}}};
    subwayMap["星湖路"] = {"星湖路", {{"南施街", "Line1"}, {"时代广场", "Line1"}}};
    subwayMap["南施街"] = {"南施街", {{"星塘街", "Line1"}, {"星湖路", "Line1"}}};
    subwayMap["星塘街"] = {"星塘街", {{"钟南街", "Line1"}, {"南施街", "Line1"}}};
    subwayMap["钟南街"] = {"钟南街", {{"星塘街", "Line1"}}};

	



    // -----------从用户输入获取起始站点和目标站点
    string startStation, endStation;
   

 	cout << "请输入起始站点名称：";
    getline(cin, startStation);
    cout << "请输入目标站点名称：";
    getline(cin, endStation);

    // 查找最短路径
    vector<string> path = shortestPath(subwayMap, startStation, endStation);

    // 输出结果
    if (!path.empty()) {
        cout << "从 " << startStation << " 到 " << endStation << " 的最短路径为：";
        int count = 0;
        for (const string& station : path) {
            cout << station;
            if (station != endStation) cout << " -> ";
            count++;
        }
        cout << endl;
        cout<<"一共"<<count-1<<"站!"<<endl; 
    } else {
        cout << "未找到从 " << startStation << " 到 " << endStation << " 的路径。" << endl;
    }

    return 0;
}




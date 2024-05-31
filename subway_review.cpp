

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

struct Station {
    string name;
    vector<pair<string,string>> neighbors;
};

vector<string> shortestPath(unordered_map<string, Station>& subWayMap, const string& startStation, const string& endStation) {
    queue<string> q;
    unordered_map<string, string> predecessor;
    predecessor[startStation] = "";
    q.push(startStation);

    while (!q.empty()) {
        string currentStation = q.front();
        q.pop();

        if (currentStation == endStation) {
            vector<string> shortestPath;
            string station = endStation;
            while (station != "") {
                shortestPath.push_back(station);
                station = predecessor[station];
            }
            reverse(shortestPath.begin(), shortestPath.end());
            return shortestPath;
        }

        for (const auto& neighbor : subWayMap[currentStation].neighbors) {
            string neighborStation = neighbor.first;
            string lineName = neighbor.second;
            /*
				在 predecessor 中，predecessor.find(neighborStation) ,将返回 predecessor.end()，				
				即表示没有找到这个相邻站点，因此它还没有被访问过
			*/
            if (predecessor.find(neighborStation) == predecessor.end()) {
                predecessor[neighborStation] = currentStation;
                q.push(neighborStation);
            }
        }
    }

    //没找到路径 
    return vector<string>();
}

int main() {
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
    subwayMap["石湖东路"] = {"石湖东路", {{"红庄", "Line4"}, {"宝带路", "Line4"},{"宝带桥南", "Line2"}, {"新家桥", "Line2"}   }};
    subwayMap["宝带路"] = {"宝带路", {{"石湖东路","Line4"},{"团结桥", "Line4"},{"盘蠡路", "Line3"}, {"迎春路", "Line3"} }};  
    subwayMap["团结桥"] = {"团结桥", {{"宝带路","Line4"},{"人民桥南", "Line4"}}}; 
    subwayMap["人民桥南"] = {"人民桥南", {{"团结桥", "Line4"},{"南门", "Line4"}}};  
    subwayMap["南门"] = {"南门", {{"人民桥南","Line4"},{"三元坊", "Line4"},{"新市桥", "Line5"}, {"南园北路", "Line5"} }};  
    subwayMap["三元坊"] = {"三元坊", {{"南门","Line4"},{"乐桥", "Line4"} }};
    subwayMap["乐桥"] = {"乐桥", {{"三元坊","Line4"},{"察院场", "Line4"},{"临顿路", "Line1"}, {"养育巷", "Line1"} }};
    subwayMap["察院场"] = {"察院场", {{"乐桥","Line4"},{"北寺塔", "Line4"} }};
    subwayMap["北寺塔"] = {"北寺塔", {{"察院场","Line4"},{"苏州火车站", "Line4"} }};
    subwayMap["苏州火车站"] = {"苏州火车站", {{"北寺塔","Line4"},{"苏锦", "Line4"},{"山塘街", "Line2"}, {"平河路", "Line2"} }};   
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
    subwayMap["狮子山"] = {"狮子山", {{"塔园路", "Line1"}, {"玉山路", "Line1"},{"何山", "Line3"}, {"狮山路", "Line3"} }};
    subwayMap["塔园路"] = {"塔园路", {{"滨河路", "Line1"}, {"狮子山", "Line1"}}};
    subwayMap["滨河路"] = {"滨河路", {{"西环路", "Line1"}, {"塔园路", "Line1"}}};
    subwayMap["西环路"] = {"西环路", {{"桐泾北路", "Line1"}, {"滨河路", "Line1"}}};
    subwayMap["桐泾北路"] = {"桐泾北路", {{"广济南路", "Line1"}, {"西环路", "Line1"}}};
    subwayMap["广济南路"] = {"广济南路", {{"养育巷", "Line1"}, {"桐泾北路", "Line1"},{"三香广场", "Line2"}, {"石路", "Line2"}  }};
    subwayMap["养育巷"] = {"养育巷", {{"乐桥", "Line1"}, {"广济南路", "Line1"}}};
    subwayMap["乐桥"] = {"乐桥", {{"临顿路", "Line1"}, {"养育巷", "Line1"},{"三元坊","Line4"},{"察院场","Line4"}}};
    subwayMap["临顿路"] = {"临顿路", {{"相门路", "Line1"}, {"乐桥", "Line1"}}};
    subwayMap["相门路"] = {"相门路", {{"东环路", "Line1"}, {"临顿路", "Line1"}}};
    subwayMap["东环路"] = {"东环路", {{"中央公园", "Line1"}, {"相门路", "Line1"}}};
    subwayMap["中央公园"] = {"中央公园", {{"星海广场", "Line1"}, {"东环路", "Line1"}}};
    subwayMap["星海广场"] = {"星海广场", {{"东方之门", "Line1"}, {"中央公园", "Line1"}}};
    subwayMap["东方之门"] = {"东方之门", {{"文化博览中心", "Line1"}, {"星海广场", "Line1"},{"李公堤西", "Line3"}, {"烟雨桥", "Line3"} }};
    subwayMap["文化博览中心"] = {"文化博览中心", {{"时代广场", "Line1"}, {"东方之门", "Line1"}}};
    subwayMap["时代广场"] = {"时代广场", {{"星湖路", "Line1"}, {"文化博览中心", "Line1"}}};
    subwayMap["星湖路"] = {"星湖路", {{"南施街", "Line1"}, {"时代广场", "Line1"}}};
    subwayMap["南施街"] = {"南施街", {{"星塘街", "Line1"}, {"星湖路", "Line1"}}};
    subwayMap["星塘街"] = {"星塘街", {{"钟南街", "Line1"}, {"南施街", "Line1"},{"龙墩", "Line5"}, {"方洲公园", "Line5"} }};
    subwayMap["钟南街"] = {"钟南街", {{"星塘街", "Line1"}}};

	
	// 为2号线添加站点及其连接
	subwayMap["骑河"] = {"骑河", {{"富翔路", "Line2"}}};
	subwayMap["富翔路"] = {"富翔路", {{"高铁苏州北站", "Line2"}, {"骑河", "Line2"}}};
	subwayMap["高铁苏州北站"] = {"高铁苏州北站", {{"大湾", "Line2"}, {"金枫路", "Line2"}}};
	subwayMap["大湾"] = {"大湾", {{"富元路", "Line2"}, {"高铁苏州北站", "Line2"}}};
	subwayMap["富元路"] = {"富元路", {{"蠡口", "Line2"}, {"大湾", "Line2"}}};
	subwayMap["蠡口"] = {"蠡口", {{"徐图港", "Line2"}, {"富元路", "Line2"}}};
	subwayMap["徐图港"] = {"徐图港", {{"阳澄湖中路", "Line2"}, {"蠡口", "Line2"}}};
	subwayMap["阳澄湖中路"] = {"阳澄湖中路", {{"陆慕", "Line2"}, {"徐图港", "Line2"}}};
	subwayMap["陆慕"] = {"陆慕", {{"平泷路东", "Line2"}, {"阳澄湖中路", "Line2"}}};
	subwayMap["平泷路东"] = {"平泷路东", {{"平河路", "Line2"}, {"陆慕", "Line2"}}};
	subwayMap["平河路"] = {"平河路", {{"苏州火车站", "Line2"}, {"平泷路东", "Line2"}}};
	subwayMap["苏州火车站"] = {"苏州火车站", {{"山塘街", "Line2"}, {"平河路", "Line2"},{"北寺塔","Line4"},{"苏锦", "Line4"}  }};
	subwayMap["山塘街"] = {"山塘街", {{"石路", "Line2"}, {"苏州火车站", "Line2"}}};
	subwayMap["石路"] = {"石路", {{"广济南路", "Line2"}, {"山塘街", "Line2"}}};
	subwayMap["广济南路"] = {"广济南路", {{"三香广场", "Line2"}, {"石路", "Line2"},{"养育巷", "Line1"}, {"桐泾北路", "Line1"} }};
	subwayMap["三香广场"] = {"三香广场", {{"劳动路", "Line2"}, {"广济南路", "Line2"}}};
	subwayMap["劳动路"] = {"劳动路", {{"胥江路", "Line2"}, {"三香广场", "Line2"},{"双桥", "Line5"}, {"新市桥", "Line5"} }};
	subwayMap["胥江路"] = {"胥江路", {{"桐泾公园", "Line2"}, {"胥江路", "Line2"}}};
	subwayMap["桐泾公园"] = {"桐泾公园", {{"友联", "Line2"}, {"东方之门", "Line2"}}};
	subwayMap["友联"] = {"友联", {{"盘蠡路", "Line2"}, {"桐泾公园", "Line2"}}};
	subwayMap["盘蠡路"] = {"盘蠡路", {{"新家桥", "Line2"}, {"友联", "Line2"},{"新郭", "Line3"}, {"宝带路", "Line3"} }};
	subwayMap["新家桥"] = {"新家桥", {{"石湖东路", "Line2"}, {"盘蠡路", "Line2"}}};
	subwayMap["石湖东路"] = {"石湖东路", {{"宝带桥南", "Line2"}, {"新家桥", "Line2"},{"红庄", "Line4"}, {"宝带路", "Line4"} }};
	subwayMap["宝带桥南"] = {"宝带桥南", {{"郭巷", "Line2"}, {"石湖东路", "Line2"}}};
	subwayMap["郭巷"] = {"郭巷", {{"郭苑路", "Line2"}, {"宝带桥南", "Line2"}}};
	subwayMap["郭苑路"] = {"郭苑路", {{"尹山湖", "Line2"}, {"郭巷", "Line2"}}};
	subwayMap["尹山湖"] = {"尹山湖", {{"独墅湖南", "Line2"}, {"郭苑路", "Line2"}}};
	subwayMap["独墅湖南"] = {"独墅湖南", {{"独墅湖邻里中心", "Line2"}, {"尹山湖", "Line2"}}};
	subwayMap["独墅湖邻里中心"] = {"独墅湖邻里中心", {{"月亮湾", "Line2"}, {"独墅湖南", "Line2"}}};
	subwayMap["月亮湾"] = {"月亮湾", {{"松涛街", "Line2"}, {"独墅湖邻里中心", "Line2"}}};
	subwayMap["松涛街"] = {"松涛街", {{"金谷路", "Line2"}, {"松涛街", "Line2"}}};
	subwayMap["金谷路"] = {"金谷路", {{"金尚路", "Line2"}, {"南施街", "Line2"}}};
	subwayMap["金尚路"] = {"金尚路", {{"桑田岛", "Line2"}, {"金谷路", "Line2"}}};
	subwayMap["桑田岛"] = {"桑田岛", {{"金尚路", "Line2"}}};
	
	
	
	
	// 为3号线添加站点及其连接
	subwayMap["苏州新区火车站"] = {"苏州新区火车站", {{"惠昌路", "Line3"}}};
	subwayMap["惠昌路"] = {"惠昌路", {{"苏州新区火车站", "Line3"}, {"文昌路", "Line3"}}};
	subwayMap["文昌路"] = {"文昌路", {{"惠昌路", "Line3"}, {"长亭", "Line3"}}};
	subwayMap["长亭"] = {"长亭", {{"文昌路", "Line3"}, {"铜墩", "Line3"}}};
	subwayMap["铜墩"] = {"铜墩", {{"长亭", "Line3"}, {"马运路", "Line3"}}};
	subwayMap["马运路"] = {"马运路", {{"铜墩", "Line3"}, {"西津桥", "Line3"}}};
	subwayMap["西津桥"] = {"西津桥", {{"马运路", "Line3"}, {"何山", "Line3"}}};
	subwayMap["何山"] = {"何山", {{"西津桥", "Line3"}, {"狮子山", "Line3"}}};
	subwayMap["狮子山"] = {"狮子山", {{"何山", "Line3"}, {"狮山路", "Line3"},{"塔园路", "Line1"}, {"玉山路", "Line1"} }};
	subwayMap["狮山路"] = {"狮山路", {{"狮子山", "Line3"}, {"沙金桥", "Line3"}}};
	subwayMap["沙金桥"] = {"沙金桥", {{"狮山路", "Line3"}, {"索山桥西", "Line3"}}};
	subwayMap["索山桥西"] = {"索山桥西", {{"狮山路", "Line3"}, {"横山", "Line3"},{"落星桥", "Line5"}, {"双桥", "Line5"} }};
	subwayMap["横山"] = {"横山", {{"索山桥西", "Line3"}, {"横塘", "Line3"}}};
	subwayMap["横塘"] = {"横塘", {{"横山", "Line3"}, {"石湖北", "Line3"}}};
	subwayMap["石湖北"] = {"石湖北", {{"横塘", "Line3"}, {"新郭", "Line3"}}};
	subwayMap["新郭"] = {"新郭", {{"石湖北", "Line3"}, {"盘蠡路", "Line3"}}};
	subwayMap["盘蠡路"] = {"盘蠡路", {{"新郭", "Line3"}, {"宝带路", "Line3"},{"新家桥", "Line2"}, {"友联", "Line2"} }};
	subwayMap["宝带路"] = {"宝带路", {{"盘蠡路", "Line3"}, {"迎春路", "Line3"},{"石湖东路","Line4"},{"团结桥", "Line4"} }};
	subwayMap["迎春路"] = {"迎春路", {{"宝带路", "Line3"}, {"北港路", "Line3"}}};
	subwayMap["北港路"] = {"北港路", {{"迎春路", "Line3"}, {"通园路南", "Line3"}}};
	subwayMap["通园路南"] = {"通园路南", {{"北港路", "Line3"}, {"墅浦路北", "Line3"}}};
	subwayMap["墅浦路北"] = {"墅浦路北", {{"通园路南", "Line3"}, {"东振路", "Line3"}}};
	subwayMap["东振路"] = {"东振路", {{"墅浦路北", "Line3"}, {"金厍桥", "Line3"}}};
	subwayMap["金厍桥"] = {"金厍桥", {{"东振路", "Line3"}, {"李公堤西", "Line3"},{"星波街", "Line5"}, {"滨河路", "Line5"} }};
	subwayMap["李公堤西"] = {"李公堤西", {{"金厍桥", "Line3"}, {"东方之门", "Line3"}}};
	subwayMap["东方之门"] = {"东方之门", {{"李公堤西", "Line3"}, {"烟雨桥", "Line3"},{"文化博览中心", "Line1"}, {"星海广场", "Line1"} }};
	subwayMap["烟雨桥"] = {"烟雨桥", {{"东方之门", "Line3"}, {"倪浜", "Line3"}}};
	subwayMap["倪浜"] = {"倪浜", {{"烟雨桥", "Line3"}, {"唐庄", "Line3"}}};
	subwayMap["唐庄"] = {"唐庄", {{"倪浜", "Line3"}, {"跨塘", "Line3"}}};
	subwayMap["跨塘"] = {"跨塘", {{"唐庄", "Line3"}, {"苏州园区火车站", "Line3"}}};
	subwayMap["苏州园区火车站"] = {"苏州园区火车站", {{"跨塘", "Line3"}, {"方湾街", "Line3"}}};
	subwayMap["方湾街"] = {"方湾街", {{"苏州园区火车站", "Line3"}, {"丰和路", "Line3"}}};
	subwayMap["丰和路"] = {"丰和路", {{"方湾街", "Line3"}, {"双马街", "Line3"}}};
	subwayMap["双马街"] = {"双马街", {{"丰和路", "Line3"}, {"葑亭大道", "Line3"}}};
	subwayMap["葑亭大道"] = {"葑亭大道", {{"双马街", "Line3"}, {"戈巷街", "Line3"},{"阳澄湖南", "Line5"}, {"东沙湖", "Line5"} }};
	subwayMap["戈巷街"] = {"戈巷街", {{"葑亭大道", "Line3"}, {"唯亭", "Line3"}}};
	subwayMap["唯亭"] = {"唯亭", {{"戈巷街", "Line3"} }};
	
	
	// 为5号线添加站点及其连接
	subwayMap["太湖香山"] = {"太湖香山", { {"花墩", "Line5"}}};
	subwayMap["花墩"] = {"花墩", {{"太湖香山", "Line5"}, {"津桥", "Line5"}}};
	subwayMap["津桥"] = {"津桥", {{"花墩", "Line5"}, {"胥口", "Line5"}}};
	subwayMap["胥口"] = {"胥口", {{"津桥", "Line5"}, {"茅蓬路东", "Line5"}}};
	subwayMap["茅蓬路东"] = {"茅蓬路东", {{"胥口", "Line5"}, {"许家桥", "Line5"}}};
	subwayMap["许家桥"] = {"许家桥", {{"茅蓬路东", "Line5"}, {"灵岩山", "Line5"}}};
	subwayMap["灵岩山"] = {"灵岩山", {{"许家桥", "Line5"}, {"渎川桥", "Line5"}}};
	subwayMap["渎川桥"] = {"渎川桥", {{"灵岩山", "Line5"}, {"大治桥", "Line5"}}};
	subwayMap["大治桥"] = {"大治桥", {{"渎川桥", "Line5"}, {"西跨塘", "Line5"}}};
	subwayMap["西跨塘"] = {"西跨塘", {{"大治桥", "Line5"}, {"石城", "Line5"}}};
	subwayMap["石城"] = {"石城", {{"西跨塘", "Line5"}, {"落星桥", "Line5"}}};
	subwayMap["落星桥"] = {"落星桥", {{"石城", "Line5"}, {"索山桥西", "Line5"}}};
	subwayMap["索山桥西"] = {"索山桥西", {{"落星桥", "Line5"}, {"双桥", "Line5"},{"狮山路", "Line3"}, {"横山", "Line3"} }};
	subwayMap["双桥"] = {"双桥", {{"索山桥西", "Line5"}, {"劳动路", "Line5"}}};
	subwayMap["劳动路"] = {"劳动路", {{"双桥", "Line5"}, {"新市桥", "Line5"},{"胥江路", "Line2"}, {"三香广场", "Line2"} }};
	subwayMap["新市桥"] = {"新市桥", {{"劳动路", "Line5"}, {"南门", "Line5"}}};
	subwayMap["南门"] = {"南门", {{"新市桥", "Line5"}, {"南园北路", "Line5"},{"人民桥南","Line4"},{"三元坊", "Line4"}  }};
	subwayMap["南园北路"] = {"南园北路", {{"南门", "Line5"}, {"竹辉桥", "Line5"}}};
	subwayMap["竹辉桥"] = {"竹辉桥", {{"南园北路", "Line5"}, {"荷花荡", "Line5"}}};
	subwayMap["荷花荡"] = {"荷花荡", {{"竹辉桥", "Line5"}, {"黄天荡", "Line5"}}};
	subwayMap["黄天荡"] = {"黄天荡", {{"金库桥", "Line5"}, {"荷花荡", "Line5"}}};
	subwayMap["金库桥"] = {"金库桥", {{"星波街", "Line5"}, {"滨河路", "Line5"},{"东振路", "Line3"}, {"李公堤西", "Line3"} }};
	subwayMap["星波街"] = {"星波街", {{"李公堤南", "Line5"}, {"金库桥", "Line5"}}};
	subwayMap["李公堤南"] = {"李公堤南", {{"金湖", "Line5"}, {"星波街", "Line5"}}};
	subwayMap["金湖"] = {"金湖", {{"华莲", "Line5"}, {"李公堤南", "Line5"}}};
	subwayMap["华莲"] = {"华莲", {{"斜塘", "Line5"}, {"金湖", "Line5"}}};
	subwayMap["斜塘"] = {"斜塘", {{"苏州奥体中心", "Line5"}, {"华莲", "Line5"}}};
	subwayMap["苏州奥体中心"] = {"苏州奥体中心", {{"方洲公园", "Line5"}, {"斜塘", "Line5"}}};
	subwayMap["方洲公园"] = {"方洲公园", {{"星塘街", "Line5"}, {"苏州奥体中心", "Line5"}}};
	subwayMap["星塘街"] = {"星塘街", {{"龙墩", "Line5"}, {"方洲公园", "Line5"},{"钟南街", "Line1"}, {"南施街", "Line1"} }};
	subwayMap["龙墩"] = {"龙墩", {{"东沙湖", "Line5"}, {"星塘街", "Line5"}}};
	subwayMap["东沙湖"] = {"东沙湖", {{"葑亭大道", "Line5"}, {"龙墩", "Line5"}}};
	subwayMap["葑亭大道"] = {"葑亭大道", {{"阳澄湖南", "Line5"}, {"东沙湖", "Line5"},{"双马街", "Line3"}, {"戈巷街", "Line3"} }};
	subwayMap["阳澄湖南"] = {"阳澄湖南", {{"葑亭大道", "Line5"}}};




	//-----------------

    string start, end;

    cout << "请输入起始站点名称：";
    getline(cin, start);
    cout << "请输入目标站点名称：";
    getline(cin, end);

    vector<string> path = shortestPath(subwayMap, start, end);

    if (!path.empty()) {
        cout << "从 " << start << " 到 " << end << " 的最短路径为：";
        int count = 0;
        for (const string& station : path) {
            cout << station;
            if (station != end) cout << " -> ";
            count++;
        }
        cout << endl;
        cout << "一共" << count - 1 << "站!" << endl; 
    } else {
        cout << "未找到从 " << start << " 到 " << end << " 的路径。" << endl;
    }

    return 0;
}




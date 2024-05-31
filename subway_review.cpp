

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
				�� predecessor �У�predecessor.find(neighborStation) ,������ predecessor.end()��				
				����ʾû���ҵ��������վ�㣬�������û�б����ʹ�
			*/
            if (predecessor.find(neighborStation) == predecessor.end()) {
                predecessor[neighborStation] = currentStation;
                q.push(neighborStation);
            }
        }
    }

    //û�ҵ�·�� 
    return vector<string>();
}

int main() {
    unordered_map<string, Station> subwayMap;

        // Ϊ4�������վ�㼰������
    subwayMap["ͬ��"] = {"ͬ��", {{"�ӽ�·", "Line4"} }};
    subwayMap["�ӽ�·"] = {"�ӽ�·", {{"ͬ��", "Line4"}, {"�⽭����վ", "Line4"}}};
    subwayMap["�⽭����վ"] = {"�⽭����վ", {{"�ӽ�·", "Line4"}, {"�⽭����㳡", "Line4"}}};
    subwayMap["�⽭����㳡"] = {"�⽭����㳡", {{"�⽭����վ", "Line4"}, {"������", "Line4"}}};
    subwayMap["������"] = {"������", {{"�⽭����㳡", "Line4"},{"�����嶫","Line4"}}};
    subwayMap["�����嶫"] = {"�����嶫", {{"������", "Line4"}, {"�˼ҵ�", "Line4"}}};
    subwayMap["�˼ҵ�"] = {"�˼ҵ�", {{"�����嶫", "Line4"}, {"����·", "Line4"}}};    
    subwayMap["����·"] = {"����·", {{"�˼ҵ�", "Line4"}, {"����·", "Line4"}}};
    subwayMap["����·"] = {"����·", {{"����·", "Line4"}, {"������·", "Line4"}}};
    subwayMap["������·"] = {"������·", {{"����·", "Line4"}, {"������·", "Line4"}}};    
    subwayMap["������·"] = {"������·", {{"������·", "Line4"}, {"����", "Line4"}}};
    subwayMap["����"] = {"����", {{"������·", "Line4"}, {"������", "Line4"}}};
    subwayMap["������"] = {"������", {{"����", "Line4"}, {"��ׯ", "Line4"}}};
    subwayMap["��ׯ"] = {"��ׯ", {{"������", "Line4"}, {"ʯ����·", "Line4"},{"���","Line4"}}};
    subwayMap["ʯ����·"] = {"ʯ����·", {{"��ׯ", "Line4"}, {"����·", "Line4"},{"��������", "Line2"}, {"�¼���", "Line2"}   }};
    subwayMap["����·"] = {"����·", {{"ʯ����·","Line4"},{"�Ž���", "Line4"},{"���·", "Line3"}, {"ӭ��·", "Line3"} }};  
    subwayMap["�Ž���"] = {"�Ž���", {{"����·","Line4"},{"��������", "Line4"}}}; 
    subwayMap["��������"] = {"��������", {{"�Ž���", "Line4"},{"����", "Line4"}}};  
    subwayMap["����"] = {"����", {{"��������","Line4"},{"��Ԫ��", "Line4"},{"������", "Line5"}, {"��԰��·", "Line5"} }};  
    subwayMap["��Ԫ��"] = {"��Ԫ��", {{"����","Line4"},{"����", "Line4"} }};
    subwayMap["����"] = {"����", {{"��Ԫ��","Line4"},{"��Ժ��", "Line4"},{"�ٶ�·", "Line1"}, {"������", "Line1"} }};
    subwayMap["��Ժ��"] = {"��Ժ��", {{"����","Line4"},{"������", "Line4"} }};
    subwayMap["������"] = {"������", {{"��Ժ��","Line4"},{"���ݻ�վ", "Line4"} }};
    subwayMap["���ݻ�վ"] = {"���ݻ�վ", {{"������","Line4"},{"�ս�", "Line4"},{"ɽ����", "Line2"}, {"ƽ��·", "Line2"} }};   
    subwayMap["�ս�"] = {"�ս�", {{"���ݻ�վ","Line4"},{"ƽ��·��", "Line4"} }};
    subwayMap["ƽ��·��"] = {"ƽ��·��", {{"�ս�","Line4"},{"�������԰", "Line4"} }};
    subwayMap["�������԰"] = {"�������԰", {{"ƽ��·��","Line4"},{"������", "Line4"} }};
    subwayMap["������"] = {"������", {{"�������԰","Line4"},{"Ҧ��", "Line4"} }};
    subwayMap["Ҧ��"] = {"Ҧ��", {{"������","Line4"},{"��ׯ", "Line4"} }};
    subwayMap["��ׯ"] = {"��ׯ", {{"Ҧ��","Line4"},{"�����", "Line4"} }};
    subwayMap["�����"] = {"�����", {{"��ׯ","Line4"}}};
     
   
    //4����֧��
    subwayMap["���"] = {"���", {{"��ׯ", "Line4"}, {"ʯ��Ī��", "Line4"}}};
    subwayMap["ʯ��Ī��"] = {"ʯ��Ī��", {{"���", "Line4"}, {"ԽϪ", "Line4"}}};
    subwayMap["ԽϪ"] = {"ԽϪ", {{"���", "Line4"}, {"��Ϫ·", "Line4"}}};
    subwayMap["��Ϫ·"] = {"��Ϫ·", {{"ԽϪ", "Line4"}, {"��쵴·", "Line4"}}};
    subwayMap["��쵴·"] = {"��쵴·", {{"��Ϫ·", "Line4"}, {"�����山", "Line4"}}};
    subwayMap["�����山"] = {"�����山", {{"��쵴·", "Line4"}, {"ľ��", "Line4"}}};
    subwayMap["ľ��"] = {"ľ��", { {"�����山", "Line4"} }};
    
    
    // Ϊ1�������վ�㼰������
    subwayMap["ľ��"] = {"ľ��", {{"���·", "Line1"}}};
    subwayMap["���·"] = {"���·", {{"�ں�·", "Line1"}, {"ľ��", "Line1"}}};
    subwayMap["�ں�·"] = {"�ں�·", {{"��ɽ·", "Line1"}, {"���·", "Line1"}}};
    subwayMap["��ɽ·"] = {"��ɽ·", {{"ʨ��ɽ", "Line1"}, {"�ں�·", "Line1"}}};
    subwayMap["ʨ��ɽ"] = {"ʨ��ɽ", {{"��԰·", "Line1"}, {"��ɽ·", "Line1"},{"��ɽ", "Line3"}, {"ʨɽ·", "Line3"} }};
    subwayMap["��԰·"] = {"��԰·", {{"����·", "Line1"}, {"ʨ��ɽ", "Line1"}}};
    subwayMap["����·"] = {"����·", {{"����·", "Line1"}, {"��԰·", "Line1"}}};
    subwayMap["����·"] = {"����·", {{"ͩ����·", "Line1"}, {"����·", "Line1"}}};
    subwayMap["ͩ����·"] = {"ͩ����·", {{"�����·", "Line1"}, {"����·", "Line1"}}};
    subwayMap["�����·"] = {"�����·", {{"������", "Line1"}, {"ͩ����·", "Line1"},{"����㳡", "Line2"}, {"ʯ·", "Line2"}  }};
    subwayMap["������"] = {"������", {{"����", "Line1"}, {"�����·", "Line1"}}};
    subwayMap["����"] = {"����", {{"�ٶ�·", "Line1"}, {"������", "Line1"},{"��Ԫ��","Line4"},{"��Ժ��","Line4"}}};
    subwayMap["�ٶ�·"] = {"�ٶ�·", {{"����·", "Line1"}, {"����", "Line1"}}};
    subwayMap["����·"] = {"����·", {{"����·", "Line1"}, {"�ٶ�·", "Line1"}}};
    subwayMap["����·"] = {"����·", {{"���빫԰", "Line1"}, {"����·", "Line1"}}};
    subwayMap["���빫԰"] = {"���빫԰", {{"�Ǻ��㳡", "Line1"}, {"����·", "Line1"}}};
    subwayMap["�Ǻ��㳡"] = {"�Ǻ��㳡", {{"����֮��", "Line1"}, {"���빫԰", "Line1"}}};
    subwayMap["����֮��"] = {"����֮��", {{"�Ļ���������", "Line1"}, {"�Ǻ��㳡", "Line1"},{"�����", "Line3"}, {"������", "Line3"} }};
    subwayMap["�Ļ���������"] = {"�Ļ���������", {{"ʱ���㳡", "Line1"}, {"����֮��", "Line1"}}};
    subwayMap["ʱ���㳡"] = {"ʱ���㳡", {{"�Ǻ�·", "Line1"}, {"�Ļ���������", "Line1"}}};
    subwayMap["�Ǻ�·"] = {"�Ǻ�·", {{"��ʩ��", "Line1"}, {"ʱ���㳡", "Line1"}}};
    subwayMap["��ʩ��"] = {"��ʩ��", {{"������", "Line1"}, {"�Ǻ�·", "Line1"}}};
    subwayMap["������"] = {"������", {{"���Ͻ�", "Line1"}, {"��ʩ��", "Line1"},{"����", "Line5"}, {"���޹�԰", "Line5"} }};
    subwayMap["���Ͻ�"] = {"���Ͻ�", {{"������", "Line1"}}};

	
	// Ϊ2�������վ�㼰������
	subwayMap["���"] = {"���", {{"����·", "Line2"}}};
	subwayMap["����·"] = {"����·", {{"�������ݱ�վ", "Line2"}, {"���", "Line2"}}};
	subwayMap["�������ݱ�վ"] = {"�������ݱ�վ", {{"����", "Line2"}, {"���·", "Line2"}}};
	subwayMap["����"] = {"����", {{"��Ԫ·", "Line2"}, {"�������ݱ�վ", "Line2"}}};
	subwayMap["��Ԫ·"] = {"��Ԫ·", {{"��", "Line2"}, {"����", "Line2"}}};
	subwayMap["��"] = {"��", {{"��ͼ��", "Line2"}, {"��Ԫ·", "Line2"}}};
	subwayMap["��ͼ��"] = {"��ͼ��", {{"���κ���·", "Line2"}, {"��", "Line2"}}};
	subwayMap["���κ���·"] = {"���κ���·", {{"½Ľ", "Line2"}, {"��ͼ��", "Line2"}}};
	subwayMap["½Ľ"] = {"½Ľ", {{"ƽ��·��", "Line2"}, {"���κ���·", "Line2"}}};
	subwayMap["ƽ��·��"] = {"ƽ��·��", {{"ƽ��·", "Line2"}, {"½Ľ", "Line2"}}};
	subwayMap["ƽ��·"] = {"ƽ��·", {{"���ݻ�վ", "Line2"}, {"ƽ��·��", "Line2"}}};
	subwayMap["���ݻ�վ"] = {"���ݻ�վ", {{"ɽ����", "Line2"}, {"ƽ��·", "Line2"},{"������","Line4"},{"�ս�", "Line4"}  }};
	subwayMap["ɽ����"] = {"ɽ����", {{"ʯ·", "Line2"}, {"���ݻ�վ", "Line2"}}};
	subwayMap["ʯ·"] = {"ʯ·", {{"�����·", "Line2"}, {"ɽ����", "Line2"}}};
	subwayMap["�����·"] = {"�����·", {{"����㳡", "Line2"}, {"ʯ·", "Line2"},{"������", "Line1"}, {"ͩ����·", "Line1"} }};
	subwayMap["����㳡"] = {"����㳡", {{"�Ͷ�·", "Line2"}, {"�����·", "Line2"}}};
	subwayMap["�Ͷ�·"] = {"�Ͷ�·", {{"�㽭·", "Line2"}, {"����㳡", "Line2"},{"˫��", "Line5"}, {"������", "Line5"} }};
	subwayMap["�㽭·"] = {"�㽭·", {{"ͩ����԰", "Line2"}, {"�㽭·", "Line2"}}};
	subwayMap["ͩ����԰"] = {"ͩ����԰", {{"����", "Line2"}, {"����֮��", "Line2"}}};
	subwayMap["����"] = {"����", {{"���·", "Line2"}, {"ͩ����԰", "Line2"}}};
	subwayMap["���·"] = {"���·", {{"�¼���", "Line2"}, {"����", "Line2"},{"�¹�", "Line3"}, {"����·", "Line3"} }};
	subwayMap["�¼���"] = {"�¼���", {{"ʯ����·", "Line2"}, {"���·", "Line2"}}};
	subwayMap["ʯ����·"] = {"ʯ����·", {{"��������", "Line2"}, {"�¼���", "Line2"},{"��ׯ", "Line4"}, {"����·", "Line4"} }};
	subwayMap["��������"] = {"��������", {{"����", "Line2"}, {"ʯ����·", "Line2"}}};
	subwayMap["����"] = {"����", {{"��Է·", "Line2"}, {"��������", "Line2"}}};
	subwayMap["��Է·"] = {"��Է·", {{"��ɽ��", "Line2"}, {"����", "Line2"}}};
	subwayMap["��ɽ��"] = {"��ɽ��", {{"��������", "Line2"}, {"��Է·", "Line2"}}};
	subwayMap["��������"] = {"��������", {{"��������������", "Line2"}, {"��ɽ��", "Line2"}}};
	subwayMap["��������������"] = {"��������������", {{"������", "Line2"}, {"��������", "Line2"}}};
	subwayMap["������"] = {"������", {{"���ν�", "Line2"}, {"��������������", "Line2"}}};
	subwayMap["���ν�"] = {"���ν�", {{"���·", "Line2"}, {"���ν�", "Line2"}}};
	subwayMap["���·"] = {"���·", {{"����·", "Line2"}, {"��ʩ��", "Line2"}}};
	subwayMap["����·"] = {"����·", {{"ɣ�ﵺ", "Line2"}, {"���·", "Line2"}}};
	subwayMap["ɣ�ﵺ"] = {"ɣ�ﵺ", {{"����·", "Line2"}}};
	
	
	
	
	// Ϊ3�������վ�㼰������
	subwayMap["����������վ"] = {"����������վ", {{"�ݲ�·", "Line3"}}};
	subwayMap["�ݲ�·"] = {"�ݲ�·", {{"����������վ", "Line3"}, {"�Ĳ�·", "Line3"}}};
	subwayMap["�Ĳ�·"] = {"�Ĳ�·", {{"�ݲ�·", "Line3"}, {"��ͤ", "Line3"}}};
	subwayMap["��ͤ"] = {"��ͤ", {{"�Ĳ�·", "Line3"}, {"ͭ��", "Line3"}}};
	subwayMap["ͭ��"] = {"ͭ��", {{"��ͤ", "Line3"}, {"����·", "Line3"}}};
	subwayMap["����·"] = {"����·", {{"ͭ��", "Line3"}, {"������", "Line3"}}};
	subwayMap["������"] = {"������", {{"����·", "Line3"}, {"��ɽ", "Line3"}}};
	subwayMap["��ɽ"] = {"��ɽ", {{"������", "Line3"}, {"ʨ��ɽ", "Line3"}}};
	subwayMap["ʨ��ɽ"] = {"ʨ��ɽ", {{"��ɽ", "Line3"}, {"ʨɽ·", "Line3"},{"��԰·", "Line1"}, {"��ɽ·", "Line1"} }};
	subwayMap["ʨɽ·"] = {"ʨɽ·", {{"ʨ��ɽ", "Line3"}, {"ɳ����", "Line3"}}};
	subwayMap["ɳ����"] = {"ɳ����", {{"ʨɽ·", "Line3"}, {"��ɽ����", "Line3"}}};
	subwayMap["��ɽ����"] = {"��ɽ����", {{"ʨɽ·", "Line3"}, {"��ɽ", "Line3"},{"������", "Line5"}, {"˫��", "Line5"} }};
	subwayMap["��ɽ"] = {"��ɽ", {{"��ɽ����", "Line3"}, {"����", "Line3"}}};
	subwayMap["����"] = {"����", {{"��ɽ", "Line3"}, {"ʯ����", "Line3"}}};
	subwayMap["ʯ����"] = {"ʯ����", {{"����", "Line3"}, {"�¹�", "Line3"}}};
	subwayMap["�¹�"] = {"�¹�", {{"ʯ����", "Line3"}, {"���·", "Line3"}}};
	subwayMap["���·"] = {"���·", {{"�¹�", "Line3"}, {"����·", "Line3"},{"�¼���", "Line2"}, {"����", "Line2"} }};
	subwayMap["����·"] = {"����·", {{"���·", "Line3"}, {"ӭ��·", "Line3"},{"ʯ����·","Line4"},{"�Ž���", "Line4"} }};
	subwayMap["ӭ��·"] = {"ӭ��·", {{"����·", "Line3"}, {"����·", "Line3"}}};
	subwayMap["����·"] = {"����·", {{"ӭ��·", "Line3"}, {"ͨ԰·��", "Line3"}}};
	subwayMap["ͨ԰·��"] = {"ͨ԰·��", {{"����·", "Line3"}, {"����·��", "Line3"}}};
	subwayMap["����·��"] = {"����·��", {{"ͨ԰·��", "Line3"}, {"����·", "Line3"}}};
	subwayMap["����·"] = {"����·", {{"����·��", "Line3"}, {"������", "Line3"}}};
	subwayMap["������"] = {"������", {{"����·", "Line3"}, {"�����", "Line3"},{"�ǲ���", "Line5"}, {"����·", "Line5"} }};
	subwayMap["�����"] = {"�����", {{"������", "Line3"}, {"����֮��", "Line3"}}};
	subwayMap["����֮��"] = {"����֮��", {{"�����", "Line3"}, {"������", "Line3"},{"�Ļ���������", "Line1"}, {"�Ǻ��㳡", "Line1"} }};
	subwayMap["������"] = {"������", {{"����֮��", "Line3"}, {"���", "Line3"}}};
	subwayMap["���"] = {"���", {{"������", "Line3"}, {"��ׯ", "Line3"}}};
	subwayMap["��ׯ"] = {"��ׯ", {{"���", "Line3"}, {"����", "Line3"}}};
	subwayMap["����"] = {"����", {{"��ׯ", "Line3"}, {"����԰����վ", "Line3"}}};
	subwayMap["����԰����վ"] = {"����԰����վ", {{"����", "Line3"}, {"�����", "Line3"}}};
	subwayMap["�����"] = {"�����", {{"����԰����վ", "Line3"}, {"���·", "Line3"}}};
	subwayMap["���·"] = {"���·", {{"�����", "Line3"}, {"˫���", "Line3"}}};
	subwayMap["˫���"] = {"˫���", {{"���·", "Line3"}, {"��ͤ���", "Line3"}}};
	subwayMap["��ͤ���"] = {"��ͤ���", {{"˫���", "Line3"}, {"�����", "Line3"},{"���κ���", "Line5"}, {"��ɳ��", "Line5"} }};
	subwayMap["�����"] = {"�����", {{"��ͤ���", "Line3"}, {"Ψͤ", "Line3"}}};
	subwayMap["Ψͤ"] = {"Ψͤ", {{"�����", "Line3"} }};
	
	
	// Ϊ5�������վ�㼰������
	subwayMap["̫����ɽ"] = {"̫����ɽ", { {"����", "Line5"}}};
	subwayMap["����"] = {"����", {{"̫����ɽ", "Line5"}, {"����", "Line5"}}};
	subwayMap["����"] = {"����", {{"����", "Line5"}, {"���", "Line5"}}};
	subwayMap["���"] = {"���", {{"����", "Line5"}, {"é��·��", "Line5"}}};
	subwayMap["é��·��"] = {"é��·��", {{"���", "Line5"}, {"�����", "Line5"}}};
	subwayMap["�����"] = {"�����", {{"é��·��", "Line5"}, {"����ɽ", "Line5"}}};
	subwayMap["����ɽ"] = {"����ɽ", {{"�����", "Line5"}, {"�´���", "Line5"}}};
	subwayMap["�´���"] = {"�´���", {{"����ɽ", "Line5"}, {"������", "Line5"}}};
	subwayMap["������"] = {"������", {{"�´���", "Line5"}, {"������", "Line5"}}};
	subwayMap["������"] = {"������", {{"������", "Line5"}, {"ʯ��", "Line5"}}};
	subwayMap["ʯ��"] = {"ʯ��", {{"������", "Line5"}, {"������", "Line5"}}};
	subwayMap["������"] = {"������", {{"ʯ��", "Line5"}, {"��ɽ����", "Line5"}}};
	subwayMap["��ɽ����"] = {"��ɽ����", {{"������", "Line5"}, {"˫��", "Line5"},{"ʨɽ·", "Line3"}, {"��ɽ", "Line3"} }};
	subwayMap["˫��"] = {"˫��", {{"��ɽ����", "Line5"}, {"�Ͷ�·", "Line5"}}};
	subwayMap["�Ͷ�·"] = {"�Ͷ�·", {{"˫��", "Line5"}, {"������", "Line5"},{"�㽭·", "Line2"}, {"����㳡", "Line2"} }};
	subwayMap["������"] = {"������", {{"�Ͷ�·", "Line5"}, {"����", "Line5"}}};
	subwayMap["����"] = {"����", {{"������", "Line5"}, {"��԰��·", "Line5"},{"��������","Line4"},{"��Ԫ��", "Line4"}  }};
	subwayMap["��԰��·"] = {"��԰��·", {{"����", "Line5"}, {"�����", "Line5"}}};
	subwayMap["�����"] = {"�����", {{"��԰��·", "Line5"}, {"�ɻ���", "Line5"}}};
	subwayMap["�ɻ���"] = {"�ɻ���", {{"�����", "Line5"}, {"���쵴", "Line5"}}};
	subwayMap["���쵴"] = {"���쵴", {{"�����", "Line5"}, {"�ɻ���", "Line5"}}};
	subwayMap["�����"] = {"�����", {{"�ǲ���", "Line5"}, {"����·", "Line5"},{"����·", "Line3"}, {"�����", "Line3"} }};
	subwayMap["�ǲ���"] = {"�ǲ���", {{"�����", "Line5"}, {"�����", "Line5"}}};
	subwayMap["�����"] = {"�����", {{"���", "Line5"}, {"�ǲ���", "Line5"}}};
	subwayMap["���"] = {"���", {{"����", "Line5"}, {"�����", "Line5"}}};
	subwayMap["����"] = {"����", {{"б��", "Line5"}, {"���", "Line5"}}};
	subwayMap["б��"] = {"б��", {{"���ݰ�������", "Line5"}, {"����", "Line5"}}};
	subwayMap["���ݰ�������"] = {"���ݰ�������", {{"���޹�԰", "Line5"}, {"б��", "Line5"}}};
	subwayMap["���޹�԰"] = {"���޹�԰", {{"������", "Line5"}, {"���ݰ�������", "Line5"}}};
	subwayMap["������"] = {"������", {{"����", "Line5"}, {"���޹�԰", "Line5"},{"���Ͻ�", "Line1"}, {"��ʩ��", "Line1"} }};
	subwayMap["����"] = {"����", {{"��ɳ��", "Line5"}, {"������", "Line5"}}};
	subwayMap["��ɳ��"] = {"��ɳ��", {{"��ͤ���", "Line5"}, {"����", "Line5"}}};
	subwayMap["��ͤ���"] = {"��ͤ���", {{"���κ���", "Line5"}, {"��ɳ��", "Line5"},{"˫���", "Line3"}, {"�����", "Line3"} }};
	subwayMap["���κ���"] = {"���κ���", {{"��ͤ���", "Line5"}}};




	//-----------------

    string start, end;

    cout << "��������ʼվ�����ƣ�";
    getline(cin, start);
    cout << "������Ŀ��վ�����ƣ�";
    getline(cin, end);

    vector<string> path = shortestPath(subwayMap, start, end);

    if (!path.empty()) {
        cout << "�� " << start << " �� " << end << " �����·��Ϊ��";
        int count = 0;
        for (const string& station : path) {
            cout << station;
            if (station != end) cout << " -> ";
            count++;
        }
        cout << endl;
        cout << "һ��" << count - 1 << "վ!" << endl; 
    } else {
        cout << "δ�ҵ��� " << start << " �� " << end << " ��·����" << endl;
    }

    return 0;
}




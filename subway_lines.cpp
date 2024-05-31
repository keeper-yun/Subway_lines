



#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

// �����ʾ����վ�Ľṹ��
struct Station {
    string name; // վ������
    vector<pair<string, string>> neighbors; // vector<pair<�ھ�վ������, ������·����>>
};

// ִ�й�������������ҵ����·���ĺ���
vector<string> shortestPath(unordered_map<string, Station>& subwayMap, const string& startStation, const string& endStation) {
    // ��������BFS�Ķ���
    queue<string> q;

    // ����map���洢���ʹ���վ�㼰��ǰ��
    unordered_map<string, string> predecessor;
    // �����ʼվ��Ϊ�ѷ��ʲ����
    predecessor[startStation] = "";
    q.push(startStation);

    // ִ��BFS����
    while (!q.empty()) {
        string currentStation = q.front();
        q.pop();

        // ��鵱ǰվ���Ƿ�ΪĿ��վ��
        if (currentStation == endStation) {
            // �ع����·��
            vector<string> shortestPath;
            string station = endStation;
            while (station != "") {
                shortestPath.push_back(station);
                station = predecessor[station];
            }
            reverse(shortestPath.begin(), shortestPath.end());
            return shortestPath;
        }

        // ���ʵ�ǰվ����ھ�
        for (const auto& neighbor : subwayMap[currentStation].neighbors) {
            string neighborStation = neighbor.first;
            string lineName = neighbor.second;
            if (predecessor.find(neighborStation) == predecessor.end()) {
                predecessor[neighborStation] = currentStation;
                q.push(neighborStation);
            }
        }
    }

    // ���δ�ҵ�·��
    return vector<string>();
}

int main() {
    // ��������ͼ
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
    subwayMap["ʯ����·"] = {"ʯ����·", {{"��ׯ", "Line4"}, {"����·", "Line4"}}};
    subwayMap["����·"] = {"����·", {{"ʯ����·","Line4"},{"�Ž���", "Line4"}}};  
    subwayMap["�Ž���"] = {"�Ž���", {{"����·","Line4"},{"��������", "Line4"}}}; 
    subwayMap["��������"] = {"��������", {{"�Ž���", "Line4"},{"����", "Line4"}}};  
    subwayMap["����"] = {"����", {{"��������","Line4"},{"��Ԫ��", "Line4"} }};  
    subwayMap["��Ԫ��"] = {"��Ԫ��", {{"����","Line4"},{"����", "Line4"} }};
    subwayMap["����"] = {"����", {{"��Ԫ��","Line4"},{"��Ժ��", "Line4"},{"�ٶ�·", "Line1"}, {"������", "Line1"} }};
    subwayMap["��Ժ��"] = {"��Ժ��", {{"����","Line4"},{"������", "Line4"} }};
    subwayMap["������"] = {"������", {{"��Ժ��","Line4"},{"���ݻ�վ", "Line4"} }};
    subwayMap["���ݻ�վ"] = {"���ݻ�վ", {{"������","Line4"},{"�ս�", "Line4"} }};   
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
    subwayMap["ʨ��ɽ"] = {"ʨ��ɽ", {{"��԰·", "Line1"}, {"��ɽ·", "Line1"}}};
    subwayMap["��԰·"] = {"��԰·", {{"����·", "Line1"}, {"ʨ��ɽ", "Line1"}}};
    subwayMap["����·"] = {"����·", {{"����·", "Line1"}, {"��԰·", "Line1"}}};
    subwayMap["����·"] = {"����·", {{"ͩ����·", "Line1"}, {"����·", "Line1"}}};
    subwayMap["ͩ����·"] = {"ͩ����·", {{"�����·", "Line1"}, {"����·", "Line1"}}};
    subwayMap["�����·"] = {"�����·", {{"������", "Line1"}, {"ͩ����·", "Line1"}}};
    subwayMap["������"] = {"������", {{"����", "Line1"}, {"�����·", "Line1"}}};
    subwayMap["����"] = {"����", {{"�ٶ�·", "Line1"}, {"������", "Line1"},{"��Ԫ��","Line4"},{"��Ժ��","Line4"}}};
    subwayMap["�ٶ�·"] = {"�ٶ�·", {{"����·", "Line1"}, {"����", "Line1"}}};
    subwayMap["����·"] = {"����·", {{"����·", "Line1"}, {"�ٶ�·", "Line1"}}};
    subwayMap["����·"] = {"����·", {{"���빫԰", "Line1"}, {"����·", "Line1"}}};
    subwayMap["���빫԰"] = {"���빫԰", {{"�Ǻ��㳡", "Line1"}, {"����·", "Line1"}}};
    subwayMap["�Ǻ��㳡"] = {"�Ǻ��㳡", {{"����֮��", "Line1"}, {"���빫԰", "Line1"}}};
    subwayMap["����֮��"] = {"����֮��", {{"�Ļ���������", "Line1"}, {"�Ǻ��㳡", "Line1"}}};
    subwayMap["�Ļ���������"] = {"�Ļ���������", {{"ʱ���㳡", "Line1"}, {"����֮��", "Line1"}}};
    subwayMap["ʱ���㳡"] = {"ʱ���㳡", {{"�Ǻ�·", "Line1"}, {"�Ļ���������", "Line1"}}};
    subwayMap["�Ǻ�·"] = {"�Ǻ�·", {{"��ʩ��", "Line1"}, {"ʱ���㳡", "Line1"}}};
    subwayMap["��ʩ��"] = {"��ʩ��", {{"������", "Line1"}, {"�Ǻ�·", "Line1"}}};
    subwayMap["������"] = {"������", {{"���Ͻ�", "Line1"}, {"��ʩ��", "Line1"}}};
    subwayMap["���Ͻ�"] = {"���Ͻ�", {{"������", "Line1"}}};

	



    // -----------���û������ȡ��ʼվ���Ŀ��վ��
    string startStation, endStation;
   

 	cout << "��������ʼվ�����ƣ�";
    getline(cin, startStation);
    cout << "������Ŀ��վ�����ƣ�";
    getline(cin, endStation);

    // �������·��
    vector<string> path = shortestPath(subwayMap, startStation, endStation);

    // ������
    if (!path.empty()) {
        cout << "�� " << startStation << " �� " << endStation << " �����·��Ϊ��";
        int count = 0;
        for (const string& station : path) {
            cout << station;
            if (station != endStation) cout << " -> ";
            count++;
        }
        cout << endl;
        cout<<"һ��"<<count-1<<"վ!"<<endl; 
    } else {
        cout << "δ�ҵ��� " << startStation << " �� " << endStation << " ��·����" << endl;
    }

    return 0;
}




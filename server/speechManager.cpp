//
// Created by huang on 2024/6/19.
//

#include "../header/speechManager.h"

//构造函数
SpeechManager::SpeechManager() {

    //初始化比赛系统
    this->initSpeach();

    //创建选手
    this->createSpeaker();

}

//析构函数
SpeechManager::~SpeechManager() {

}

//显示菜单
void SpeechManager::show_Menu() {
    cout << "********************************************" << endl;
    cout << "*************  欢迎参加演讲比赛 ************" << endl;
    cout << "*************  1.开始演讲比赛  *************" << endl;
    cout << "*************  2.查看往届记录  *************" << endl;
    cout << "*************  3.清空比赛记录  *************" << endl;
    cout << "*************  0.退出比赛程序  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

//退出功能
void SpeechManager::exitSystem() {
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(EXIT_SUCCESS);
}

//初始化属性
void SpeechManager::initSpeach() {
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();

    this->m_Index = 1;
}

//创建12名选手
void SpeechManager::createSpeaker() {
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); ++i) {
        string name = "选手";
        name += nameSeed[i];

        Speaker sp;
        sp.setName(name);

        //初始化分数
        for (int j = 0; j < 2; ++j) {
            sp.setScore(j,0);
        }

        //创建12名选手的编号
        int id = i + 10001;
        this->v1.push_back(id);

        //将选手和编号放入map中
        this->m_Speaker.insert(make_pair(id , sp));
    }

}

//抽签
void SpeechManager::speechDraw() {
    cout << "第 << " << this->m_Index << " >> 轮比赛选手正在抽签 " << endl;
    cout << "---------------------------" << endl;
    cout << "抽签后演讲顺序如下 : " << endl;
    if (this->m_Index == 1){  //第一轮
        //打乱选手顺序
        random_shuffle(v1.begin(),v1.end());
        for (vector<int>::iterator it = v1.begin() ; it != v1.end() ; it++) {
            cout << *it << " : "<< this->m_Speaker[*it].getName() << " ";
        }
        cout << endl;
    } else{  //第二轮的就是晋级的选手
        random_shuffle(v2.begin(),v2.end());
        for (vector<int>::iterator it = v2.begin() ; it != v2.end() ; it++) {
            cout << *it << " : "<< this->m_Speaker[*it].getName() << " ";
        }
        cout << endl;
    }

    cout << "----------------------------" << endl;
    system("pause");
    cout << endl;
}

//比赛
void SpeechManager::speechContest() {
    cout << "-----------第"<<this->m_Index << "轮正式比赛开始:----------------"<< endl;
    multimap<double , int , greater<int> > groupScore; //临时容器，存放选手编号和分数   谓词：内建访函数从大到小

    int num = 0;

    vector <int>v_Src;   //比赛人员容器
    if (this->m_Index == 1){
        v_Src = v1;
    } else{
        v_Src = v2;
    }
}


//比赛流程
void SpeechManager::startSpeech() {
    this->speechDraw();
}
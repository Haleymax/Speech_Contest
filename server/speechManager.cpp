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
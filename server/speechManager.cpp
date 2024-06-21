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

    //遍历所有参赛选手
    for(vector<int>::iterator it = v_Src.begin() ; it != v_Src.end() ; it++){
        num++;

        //评委打分
        deque<double> d;
        for (int i = 0; i < 10; ++i) {
            double score = (rand()%401 + 600) / 10.f;
            d.push_back(score);
        }

        sort(d.begin(),d.end(),greater<double>());  //对十个评委的打分进行排序
        d.pop_front();  //去掉最高分
        d.pop_back();   //去掉最低分

        double sum = accumulate(d.begin(),d.end(),0.0f);  //计算总分
        double avg = sum / (double)d.size();        //计算平均分

        this->m_Speaker[*it].setScore(this->m_Index - 1,avg);

        //六个人一组用临时容器进行保存
        groupScore.insert(make_pair(avg,*it));
        if (num % 6 == 0){   //表示的是第一轮
            cout << "第" << num / 6 << "小组比赛名次: "<<endl;
            for (multimap<double,int,greater<int>>::iterator it = groupScore.begin() ; it != groupScore.end() ; it++) {
                cout << "编号 :" << it->second
                     << "姓名 :" << this->m_Speaker[it->second].getName()
                     << "成绩 :" << this->m_Speaker[it->second].getScore(this->m_Index - 1)
                     << endl;
            }

            int count = 0;

            //取前三名
            for (multimap<double,int,greater<int>>::iterator it = groupScore.begin() ; it != groupScore.end() && count < 3 ;
            it++ ,count++) {
                if (this->m_Index == 1){
                    v2.push_back((*it).second);
                } else{
                    vVictory.push_back((*it).second);  //第二轮的前三名就是获胜的人
                }
            }

            groupScore.clear();

            cout << endl;
        }
    }
    cout << "-----------------------第" << this->m_Index << "轮比赛完毕  -------------------" << endl;
    system("pause");
}


//比赛流程
void SpeechManager::startSpeech() {
    this->speechDraw();
}

//显示比赛结果
void SpeechManager::showScore() {
    cout << "------------第" << this->m_Index << "轮晋级选手信息如下：--------------" << endl;

    vector<int> v;
    if (this->m_Index == 1){
        v = v2;  //第一轮晋级选手的容器
    } else{
        v = vVictory;   //获奖者的容器
    }

    for (vector<int>::iterator it = v.begin() ; it != v.end() ; it++) {
        cout << "选手编号 : " << *it << "姓名 : " << m_Speaker[*it].getName()
        << "得分 : "<< m_Speaker[*it].getScore(this->m_Index-1);
    }
    cout << endl;

    system("pause");
    system("cls");
    this->show_Menu();

}
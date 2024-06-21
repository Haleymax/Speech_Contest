//
// Created by huang on 2024/6/19.
//

#ifndef SPEECH_CONTEST_SPEECHMANAGER_H
#define SPEECH_CONTEST_SPEECHMANAGER_H

#endif //SPEECH_CONTEST_SPEECHMANAGER_H

#pragma once
#include "iostream"
#include "vector"
#include "speaker.h"
#include "map"
#include "algorithm"
#include "ctime"
#include "deque"
#include "algorithm"
#include "numeric"

using namespace std;

//演讲管理类
class SpeechManager{
public:

    //构造函数
    SpeechManager();

    //析构函数
    ~SpeechManager();

    //显示菜单函数
    void show_Menu();

    //退出功能
    void exitSystem();

    //初始化属性
    void initSpeach();

    //初始创建12名选手
    void createSpeaker();

    //比赛流程
    void startSpeech();

    //抽签
    void speechDraw();

    //比赛
    void speechContest();

    //显示比赛结果
    void showScore();

public:
    //选手容器
    vector<int> v1;

    //第一轮晋级的容器 6人
    vector<int> v2;

    //胜利前三名容器
    vector<int>vVictory;

    //存放选手编号和对应的选手(编号唯一性)
    map<int , Speaker> m_Speaker;

    //比赛轮次
    int m_Index = 1;

};



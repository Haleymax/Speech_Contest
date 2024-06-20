//
// Created by huang on 2024/6/20.
//

#ifndef SPEECH_CONTEST_SPEAKER_H
#define SPEECH_CONTEST_SPEAKER_H

#endif //SPEECH_CONTEST_SPEAKER_H

#pragma once
#include "iostream"
#include "string"
using namespace std;


//选手类
class Speaker{
private:
    string m_Name;   //选手姓名
    double m_Score[2]; //分数（共有两轮）

public:
    void setName(string name){
        this->m_Name = name;
    }

    void setScore(int index , double value){
        this->m_Score[index] = value;
    }

    string getName(){
        return this->m_Name;
    }

    double getScore(int index){
        return this->m_Score[index];
    }

};
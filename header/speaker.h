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


//ѡ����
class Speaker{
private:
    string m_Name;   //ѡ������
    double m_Score[2]; //�������������֣�

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
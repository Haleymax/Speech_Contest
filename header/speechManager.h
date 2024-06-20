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

using namespace std;

//�ݽ�������
class SpeechManager{
public:

    //���캯��
    SpeechManager();

    //��������
    ~SpeechManager();

    //��ʾ�˵�����
    void show_Menu();

    //�˳�����
    void exitSystem();

    //��ʼ������
    void initSpeach();

    //��ʼ����12��ѡ��
    void createSpeaker();


public:
    //ѡ������
    vector<int> v1;

    //��һ�ֽ��������� 6��
    vector<int> v2;

    //ʤ��ǰ��������
    vector<int>vVictory;

    //���ѡ�ֱ�źͶ�Ӧ��ѡ��(���Ψһ��)
    map<int , Speaker> m_Speaker;

    //�����ִ�
    int m_Index = 1;

};



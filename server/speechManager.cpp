//
// Created by huang on 2024/6/19.
//

#include "../header/speechManager.h"

//���캯��
SpeechManager::SpeechManager() {

    //��ʼ������ϵͳ
    this->initSpeach();

    //����ѡ��
    this->createSpeaker();

}

//��������
SpeechManager::~SpeechManager() {

}

//��ʾ�˵�
void SpeechManager::show_Menu() {
    cout << "********************************************" << endl;
    cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
    cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
    cout << "*************  2.�鿴�����¼  *************" << endl;
    cout << "*************  3.��ձ�����¼  *************" << endl;
    cout << "*************  0.�˳���������  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

//�˳�����
void SpeechManager::exitSystem() {
    cout << "��ӭ�´�ʹ��" << endl;
    system("pause");
    exit(EXIT_SUCCESS);
}

//��ʼ������
void SpeechManager::initSpeach() {
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();

    this->m_Index = 1;
}

//����12��ѡ��
void SpeechManager::createSpeaker() {
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); ++i) {
        string name = "ѡ��";
        name += nameSeed[i];

        Speaker sp;
        sp.setName(name);

        //��ʼ������
        for (int j = 0; j < 2; ++j) {
            sp.setScore(j,0);
        }

        //����12��ѡ�ֵı��
        int id = i + 10001;
        this->v1.push_back(id);

        //��ѡ�ֺͱ�ŷ���map��
        this->m_Speaker.insert(make_pair(id , sp));
    }
}
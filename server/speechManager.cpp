//
// Created by huang on 2024/6/19.
//

#include "../header/speechManager.h"

//���캯��
SpeechManager::SpeechManager() {

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
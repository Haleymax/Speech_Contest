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

//��ǩ
void SpeechManager::speechDraw() {
    cout << "�� << " << this->m_Index << " >> �ֱ���ѡ�����ڳ�ǩ " << endl;
    cout << "---------------------------" << endl;
    cout << "��ǩ���ݽ�˳������ : " << endl;
    if (this->m_Index == 1){  //��һ��
        //����ѡ��˳��
        random_shuffle(v1.begin(),v1.end());
        for (vector<int>::iterator it = v1.begin() ; it != v1.end() ; it++) {
            cout << *it << " : "<< this->m_Speaker[*it].getName() << " ";
        }
        cout << endl;
    } else{  //�ڶ��ֵľ��ǽ�����ѡ��
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

//����
void SpeechManager::speechContest() {
    cout << "-----------��"<<this->m_Index << "����ʽ������ʼ:----------------"<< endl;
    multimap<double , int , greater<int> > groupScore; //��ʱ���������ѡ�ֱ�źͷ���   ν�ʣ��ڽ��ú����Ӵ�С

    int num = 0;

    vector <int>v_Src;   //������Ա����
    if (this->m_Index == 1){
        v_Src = v1;
    } else{
        v_Src = v2;
    }

    //�������в���ѡ��
    for(vector<int>::iterator it = v_Src.begin() ; it != v_Src.end() ; it++){
        num++;

        //��ί���
        deque<double> d;
        for (int i = 0; i < 10; ++i) {
            double score = (rand()%401 + 600) / 10.f;
            d.push_back(score);
        }

        sort(d.begin(),d.end(),greater<double>());  //��ʮ����ί�Ĵ�ֽ�������
        d.pop_front();  //ȥ����߷�
        d.pop_back();   //ȥ����ͷ�

        double sum = accumulate(d.begin(),d.end(),0.0f);  //�����ܷ�
        double avg = sum / (double)d.size();        //����ƽ����

        this->m_Speaker[*it].setScore(this->m_Index - 1,avg);

        //������һ������ʱ�������б���
        groupScore.insert(make_pair(avg,*it));
        if (num % 6 == 0){   //��ʾ���ǵ�һ��
            cout << "��" << num / 6 << "С���������: "<<endl;
            for (multimap<double,int,greater<int>>::iterator it = groupScore.begin() ; it != groupScore.end() ; it++) {
                cout << "��� :" << it->second
                     << "���� :" << this->m_Speaker[it->second].getName()
                     << "�ɼ� :" << this->m_Speaker[it->second].getScore(this->m_Index - 1)
                     << endl;
            }

            int count = 0;

            //ȡǰ����
            for (multimap<double,int,greater<int>>::iterator it = groupScore.begin() ; it != groupScore.end() && count < 3 ;
            it++ ,count++) {
                if (this->m_Index == 1){
                    v2.push_back((*it).second);
                } else{
                    vVictory.push_back((*it).second);  //�ڶ��ֵ�ǰ�������ǻ�ʤ����
                }
            }

            groupScore.clear();

            cout << endl;
        }
    }
    cout << "-----------------------��" << this->m_Index << "�ֱ������  -------------------" << endl;
    system("pause");
}


//��������
void SpeechManager::startSpeech() {
    this->speechDraw();
}

//��ʾ�������
void SpeechManager::showScore() {
    cout << "------------��" << this->m_Index << "�ֽ���ѡ����Ϣ���£�--------------" << endl;

    vector<int> v;
    if (this->m_Index == 1){
        v = v2;  //��һ�ֽ���ѡ�ֵ�����
    } else{
        v = vVictory;   //���ߵ�����
    }

    for (vector<int>::iterator it = v.begin() ; it != v.end() ; it++) {
        cout << "ѡ�ֱ�� : " << *it << "���� : " << m_Speaker[*it].getName()
        << "�÷� : "<< m_Speaker[*it].getScore(this->m_Index-1);
    }
    cout << endl;

    system("pause");
    system("cls");
    this->show_Menu();

}
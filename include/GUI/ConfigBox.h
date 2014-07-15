/****************************************************************************
 *Author : Mathieu Garon  mathieugaron1991@hotmail.com
 *
 *Purpose:
 *
 ****************************************************************************/

#ifndef CONFIGBOX_H
#define CONFIGBOX_H

#include <QDialog>
#include <QtGui>

#include <cstring>
#include <cmath>
#include <QTextStream>
#include <vector>


class QLabel;
class QPushButton;


class ConfigBox : public QDialog
{

    Q_OBJECT


public:
    explicit ConfigBox(int numofEditBox,QWidget *parent = 0);
    ~ConfigBox();
    void setUpGUI();
    void setData(double data, int editNumber);
    void setTexts(QString string,int editNumber);
    void setTitle(QString title);

signals:
    void returnValues(std::vector<double> data );
private slots:
    void acceptConfig();

private:

    QLabel* mMainText;
    std::vector<QLabel*> mLabelsVector;
    std::vector<QLineEdit*> mEditsVector;
    int mEditBoxSize;
    QDialogButtonBox* mButtons;


};

inline void ConfigBox::setData(double data, int editNumber){

    mEditsVector[editNumber]->setText(QString::number(data));
}

inline void ConfigBox::setTexts(QString string,int editNumber){

    mLabelsVector[editNumber]->setText(string);

}

inline void ConfigBox::setTitle(QString title){
    mMainText->setText(title);
}

#endif

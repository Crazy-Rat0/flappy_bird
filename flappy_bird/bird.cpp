#include "bird.h"

bird::bird(QWidget* temp):QPushButton(temp)
{
    this->move(170,202);
    this->resize(45,45);
    this->setStyleSheet("background-image: url(:/Images/bird1.png);"
                        "background-repeat: no-repeat;"
            "background-position: center;"
                        "background-color: rgba(0, 0, 0, 0);");
}

void bird::drop()
{
    if(this->y()!=403)//not reach the bottom
    {
        if(this->y()+1<=403)//if drop,not reach the bottom
        this->move(this->x(),this->y()+1);
        else//if drop,will reach the bottom
        this->move(this->x(),403);
    }


}


void bird::fly()
{
    if(this->y()!=0)//not reach the top
    {
        if(this->y()-40>=0)
         this->move(this->x(),this->y()-40);//if fly,not reach the top
        else
            this->move(this->x(),0);//if fly,will reach the top
    }

}

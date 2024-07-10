#include "bird.h"

bird::bird(QWidget* temp):QPushButton(temp)
{
    JumpSec=0;
    image_index=2;
    last_image_index=1;
    this->move(170,202);
    this->resize(45,45);
    this->setStyleSheet("background-image: url(:/Images/bird2.png);"
                        "background-repeat: no-repeat;"
            "background-position: center;"
                        "background-color: rgba(0, 0, 0, 0);");
}

void bird::drop()
{
    if(JumpSec<20)
    {
        JumpSec++;
    }
    if(this->y()!=403)//not reach the bottom
    {
        if(this->y()+2<=403)//if drop,not reach the bottom
        this->move(this->x(),this->y()+2);
        else//if drop,will reach the bottom
        this->move(this->x(),403);
    }


}


void bird::fly()
{
    JumpSec=0;
    if(this->y()!=0)//not reach the top
    {
        if(this->y()-40>=0)
         this->move(this->x(),this->y()-40);//if fly,not reach the top
        else
            this->move(this->x(),0);//if fly,will reach the top
    }

}

bool bird::Ifdead()
{
    if(this->y()>=403)
    {
        Setdead();
    }
    return Isdead;
}
void bird::Setdead()
{
    Isdead = 1;
}


//VM
void bird::change_image()
{
    if(Isdead){
        this->setStyleSheet("background-image: url(:/Images/gameover.png);"
                            "background-repeat: no-repeat;"
                "background-position: center;"
                            "background-color: rgba(0, 0, 0, 0);");
    }
    if(JumpSec!=30)
    {
        if(image_index==1)
        {
            last_image_index=1;
            image_index=2;
            this->setStyleSheet("background-image: url(:/Images/bird2.png);"
                                "background-repeat: no-repeat;"
                    "background-position: center;"
                                "background-color: rgba(0, 0, 0, 0);");
        }
        else if(image_index==2)
        {
            if(last_image_index==1)
            {
                image_index=3;
                this->setStyleSheet("background-image: url(:/Images/bird3.png);"
                                    "background-repeat: no-repeat;"
                        "background-position: center;"
                                    "background-color: rgba(0, 0, 0, 0);");
            }
            else
            {
                image_index=1;
                this->setStyleSheet("background-image: url(:/Images/bird1.png);"
                                    "background-repeat: no-repeat;"
                        "background-position: center;"
                                    "background-color: rgba(0, 0, 0, 0);");
            }
            last_image_index=2;
        }
        else
        {
            last_image_index=3;
            image_index=2;
            this->setStyleSheet("background-image: url(:/Images/bird2.png);"
                                "background-repeat: no-repeat;"
                    "background-position: center;"
                                "background-color: rgba(0, 0, 0, 0);");
        }
    }
    else
    {
        last_image_index=1;
        image_index=2;
        this->setStyleSheet("background-image: url(:/Images/bird2.png);"
                            "background-repeat: no-repeat;"
                "background-position: center;"
                            "background-color: rgba(0, 0, 0, 0);");
    }
}

#include "UiTamperSpeed.h"

UiTamperSpeed::UiTamperSpeed(QWidget *parent, TamperType tamperType)
	: UiTamperModule(parent, tamperType)
{
	pTamperConfig = (void*)new QLabel("test");




	speedLayout = new QHBoxLayout();
	QLabel* test = new QLabel("test");
	speedLayout->addWidget(test);
	
	moduleLayout->addLayout(speedLayout);
}

UiTamperSpeed::~UiTamperSpeed()
{

}

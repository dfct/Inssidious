#include "UiTamperNoServer.h"

#include "ConfigureServersDialog.h"

UiTamperNoServer::UiTamperNoServer(QWidget *parent, TamperType tamperType)
	: UiTamperModule(parent, tamperType)
{
	pTamperConfig = static_cast<void*>(new TamperNoServerConfig{ false });

	configServersButton = new QPushButton();
	configServersButton->setStyleSheet(buttonStyleSheet);
	configServersButton->setFixedSize(130, 30);
	configServersButton->setText("???");


	noServerLayout = new QGridLayout();
	noServerLayout->setSpacing(0);
	noServerLayout->setAlignment(Qt::AlignHCenter);
	//noServerLayout->addWidget(configServersButton, 0, 0, Qt::AlignHCenter);


	buttonImagePaletteActive.setBrush(QPalette::Background, QBrush(QPixmap(":/Tamper/TamperNoServerActive.png")));
	buttonImagePaletteInactive.setBrush(QPalette::Background, QBrush(QPixmap(":/Tamper/TamperNoServerInactive.png")));

	buttonImage = new QLabel(this);
	buttonImage->setPalette(buttonImagePaletteInactive);
	buttonImage->setAutoFillBackground(true);
	buttonImage->setGeometry(0, 0, 380, 120);
	buttonImage->setAttribute(Qt::WA_TransparentForMouseEvents);
	buttonImage->show();

	connect(configServersButton, &QPushButton::clicked, this, &UiTamperNoServer::onConfigureServers);

	moduleLayout->addLayout(noServerLayout);
}


void UiTamperNoServer::setActive(bool active)
{
	if (active)
	{
		/* Show the module as active */

		this->setPalette(moduleBackgroundPaletteActive);
		this->buttonImage->setPalette(buttonImagePaletteActive);

		/* Enable the buttons */

		configServersButton->setEnabled(true);
		
		
		/* Set the config value to true and the block button to checked */

		static_cast<TamperNoServerConfig*>(pTamperConfig)->blockServers = true;


		/* Notify Core */

		emit tamperStart(this, pTamperConfig);

	}
	else
	{
		/* Show the module as inactive */

		this->setPalette(moduleBackgroundPaletteInactive);
		this->buttonImage->setPalette(buttonImagePaletteInactive);

		/* Uncheck and disable all buttons */

		configServersButton->setDisabled(true);


		/* Set the config value to false */

		static_cast<TamperNoServerConfig*>(pTamperConfig)->blockServers = false;


		/* Notify Core */

		emit tamperStop(this);
	}
}


void UiTamperNoServer::onConfigureServers()
{
	
	QList<QString> stringList;
	QPoint global = this->mapToGlobal(rect().center());
	ConfigureServersDialog* dialog = new ConfigureServersDialog(global, &stringList);
	dialog->exec();
	delete dialog;

	//if (stringList.count() > 0)
	//{
	//	//TODO: get this to the tamper module	

	//	blockedServersCount = stringList.count();
	//	blockedServersComboBox->clear();
	//	blockedServersComboBox->addItem(blockedServerFirstItemText + QString::number(blockedServersCount));

	//	QList<_Uint32t> ipList;

	//	for (int i = 0; i < stringList.count(); i++)
	//	{

	//		blockedServersComboBox->addItem(stringList[i]);

	//		_Uint32t ipAsInt = 0;
	//		InetPton(AF_INET, (const wchar_t*)stringList[i].split(" ").first().utf16(), &ipAsInt);

	//		ipList.append(ipAsInt);
	//	}

	//}
}

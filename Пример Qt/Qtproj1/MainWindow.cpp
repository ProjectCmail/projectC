#include "MainWindow.h"
#include <qmessagebox.h>
#include <qfiledialog.h>
#include <qcombobox.h>
#include <thread>
#include <qapplication.h>
#include <future>
#include <functional>
#include <algorithm>
#include <Windows.h>
#include "MainEntry.h"
#include <vector>
#include <sstream>
#include <direct.h>
#include <qdir.h>
#include <qfile.h>
#include <map>

#pragma pack(1)
typedef struct
{
    short int   bfType;
    int			bfSize;
    int			bfReserved;
    int			bfOffBits;
} bmpstruct;


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{

	ui.setupUi(this);
	this->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));

	
	this->setFixedSize(600, 500);
	this->fullSize = 0;
	this->countElement = 0;
	this->flag1 = false;
	this->flag2 = false;


	/*/***** MessageBox *****////
	ms = new QMessageBox();
	ms->setStyleSheet("QMessageBox { color: white; background-color: green; }");
	

	/// **** Перевод в Unicode ****////
	QTextCodec* defaultTextCodec = QTextCodec::codecForName("Windows-1251");
	this->decoder = new QTextDecoder(defaultTextCodec);
	this->followDirCom = "D:\\";
	this->followNameCom = "D:\\Default.dip";

	this->countCoreCompression = 1;
	this->countCoreDecompression = 1;
	this->sizeBlockCompression = 12000;
	this->sizeblockDecompression = 12000;


	try
	{
		this->MM = new MainEntry<double>("Network_verygoodcopy.nn");
	}catch(...)
	{
		QMessageBox::information(this, "Error", this->decoder->toUnicode("Отсутствует файл сети! Обратитесь к разработчикам продукта!"));
		throw 1;
	}

	
	///**** Style PushButton ***////
	QString StylePushbuttom = "QPushButton { "
							  "border: 1px solid black;"
							  "border-radius: 6px;"
							  "background-color: rgb(240, 240, 240);"
							  "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, "
							  "stop: 0 rgb(255, 255, 255), stop: 1 rgb(230, 230, 230));"		
							  "}" 
							  "QPushButton:pressed {"
							  "border: 1px solid black;"
							  "background-color: #222222;"
							  "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, "
							  "stop: 0 rgb(230, 230, 230), stop: 1 rgb(255, 255, 255));"
							  "}";
	///**** Style Label ****///
	QString StyleLabel1 = "color: black;"
                        "background-color: rgb(255, 255, 255);"
						"border-style: solid;" 
						"border-width:1px;" 
						"border-color:rgb(160, 160, 160);"
                        "selection-color: white;"
                        "selection-background-color: blue;"
						"font: 10pt Courier;"
						"border-radius: 2px";

	QString StyleLabel2 = "color: black;"
                        "background-color: rgb(250, 250, 250);"
						"border-style: solid;" 
						"border-width:1px;" 
						"border-color:rgb(160, 160, 160);"
                        "selection-color: white;"
                        "selection-background-color: blue;"
						"font: 9pt Courier;"
						"border-radius: 2px";

	QString StyleGroupBox = "color: black;"
							"border-style: solid;" 
							"border-width:1px;" 
							"border-color:rgb(190, 190, 190);" 
							"border-radius: 2px";		
							
	
	/// ******  Главное Меню  *******////
	actionOpen = new QAction(this->decoder->toUnicode("О&ткрыть"), this);
    actionOpen->setStatusTip(decoder->toUnicode("Открыть рисунок"));
    connect(actionOpen, SIGNAL(triggered()), this, SLOT(slotOpen()));

    actionExit = new QAction(decoder->toUnicode("В&ыход"), this);
    actionExit->setStatusTip(decoder->toUnicode("Выход из программы"));
    actionExit->setShortcut(tr("Ctrl+Q"));
    connect(actionExit, SIGNAL(triggered()), this, SLOT(quit()));

    actionAbout = new QAction(decoder->toUnicode("&О программе"), this);
    actionAbout->setStatusTip(decoder->toUnicode("Сведения о программе"));
    connect(actionAbout, SIGNAL(triggered()), this, SLOT(slotAbout()));

	menuFile = menuBar()->addMenu(decoder->toUnicode("&Файл"));
    menuFile->addAction(actionOpen);
    menuFile->addSeparator();
    menuFile->addAction(actionExit);

    menuFile = menuBar()->addMenu(decoder->toUnicode("&Справка"));
    menuFile->addAction(actionAbout);

    labelMenu = new QLabel(statusBar());
    labelFile = new QLabel();

    statusBar()->setSizeGripEnabled(false);
    statusBar()->addWidget(labelMenu, 1);
    statusBar()->addWidget(labelFile, 2);

    mainWidget = new QWidget();
    setCentralWidget(mainWidget);

    labelImage = new QLabel;

    butOpen = new QPushButton(decoder->toUnicode("Открыть"));
    butOpen->setStatusTip(decoder->toUnicode("Открыть сеть"));
    connect(butOpen, SIGNAL(clicked()), this, SLOT(slotOpen()));

    cbSize = new QCheckBox(decoder->toUnicode("Вписать рисунок в окно"));
    connect(cbSize, SIGNAL(toggled(bool)), this, SLOT(slotImageSize(bool)));

    vlayout = new QVBoxLayout;
    hlayout = new QHBoxLayout;

    vlayout->addWidget(labelImage);
    hlayout->addWidget(butOpen);
    hlayout->addWidget(cbSize);
    hlayout->addStretch(1);
    vlayout->addLayout(hlayout);
    mainWidget->setLayout(vlayout);

	//// ****** Tab *******///	
	tabWidget = new QTabWidget();	

	QWidget * wg = new QWidget();

	this->TabWidgetVector1.push_back(wg);
  	tabWidget->addTab(wg,decoder->toUnicode("Сжатие"));
	tabWidget->setStyleSheet(QString::fromUtf8("border-color: white"));
	wg = new QWidget();
	this->TabWidgetVector1.push_back(wg);

	tabWidget->addTab(wg,decoder->toUnicode("Восстановление"));
	tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(252, 252, 252);"));
	setCentralWidget(tabWidget);


	/// ****  Кнопка 1  Tab1*****///
	pushButton1 = new QPushButton(decoder->toUnicode("Добавить папку"), this->TabWidgetVector1.at(0));
	pushButton1->setGeometry(QRect(QPoint(240, 100),QSize(100, 35)));
	pushButton1->setStyleSheet(StylePushbuttom);
	connect(pushButton1, SIGNAL(clicked()), this, SLOT(on_pushButton1_clicked()));
	
	/// ****  Кнопка 2  Tab1 *****///
	pushButton2 = new QPushButton(decoder->toUnicode("Сжать"), this->TabWidgetVector1.at(0));
	pushButton2->setGeometry(QRect(QPoint(270, 370),QSize(100, 35)));
	pushButton2->setStyleSheet(StylePushbuttom);
	connect(pushButton2, SIGNAL(clicked()), this, SLOT(on_pushButton2_clicked()));
	
		
	/// ****  Кнопка 5  Tab1 *****///
	pushButton5 = new QPushButton(decoder->toUnicode("Добавить файл"), this->TabWidgetVector1.at(0));
	pushButton5->setGeometry(QRect(QPoint(240, 140),QSize(100, 35)));
	pushButton5->setStyleSheet(StylePushbuttom);
	connect(pushButton5, SIGNAL(clicked()), this, SLOT(on_pushButton5_clicked()));

	/// ****  Кнопка 6  Tab1 *****///
	pushButton6 = new QPushButton(decoder->toUnicode("Обзор"), this->TabWidgetVector1.at(0));
	pushButton6->setGeometry(QRect(QPoint(500, 30),QSize(50, 25)));
	pushButton6->setStyleSheet(StylePushbuttom);
	connect(pushButton6, SIGNAL(clicked()), this, SLOT(on_pushButton6_clicked()));


	/// ****  Кнопка 7  Tab1 *****///
	pushButton7 = new QPushButton(decoder->toUnicode("Удалить"), this->TabWidgetVector1.at(0));
	pushButton7->setGeometry(QRect(QPoint(240, 180),QSize(100, 35)));
	pushButton7->setStyleSheet(StylePushbuttom);
	connect(pushButton7, SIGNAL(clicked()), this, SLOT(on_pushButton7_clicked()));

	/// ****  Кнопка 8  Tab1 *****///
	pushButton8 = new QPushButton(decoder->toUnicode("Отмена"), this->TabWidgetVector1.at(0));
	pushButton8->setGeometry(QRect(QPoint(420, 370),QSize(100, 35)));
	pushButton8->setStyleSheet(StylePushbuttom);
	connect(pushButton7, SIGNAL(clicked()), this, SLOT(on_pushButton8_clicked()));

	/// **** ProgressBar1 Tab1 ***** ///
	progressbar1 = new QProgressBar(this->TabWidgetVector1.at(0));
	progressbar1->setGeometry(QRect(QPoint(250, 320),QSize(320, 20)));
	QObject::connect(&this->timer1, SIGNAL(timeout()), SLOT(TimerTick1()));
	this->progressbar1->setMinimum(0);
	this->progressbar1->setMaximum(100);
    timer1.setInterval(100);

	/// **** ListWidget1 Tab1 *****////
	this->listWidget1 = new QListWidget(this->TabWidgetVector1.at(0));
	listWidget1->setGeometry(QRect(QPoint(10,34),QSize(220, 270)));
	listWidget1->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));

	listWidget1->setStyleSheet(  "QListWidget {"
								"scrollbar;"
								"background-color: rgb(250, 250, 250);"
								"border-style: solid;" 
								"border-width:1px;" 
								"border-color:rgb(160, 160, 160);"
								"font: 12pt Courier;"
								"border-radius: 2px;"
								"scrollbar;"
								" }"
								"QListWidget::item {"
								"border-style: solid;" 
								 "border-width:1px;" 
								 "border-color:black;" 
								 "background-color: green;"
								 "scrollbar;"
								 "}"
								 "QListWidget::item:selected {"
								   "background-color: red;"
								 "}");

	///****** Edit1 Tab1 ******///
	this->edit1 = new QLineEdit(this->TabWidgetVector1.at(0));
	this->edit1->setGeometry(QRect(QPoint(240,30),QSize(255, 25)));
	this->edit1->setStyleSheet("color: black;"
                        "background-color: rgb(255, 255, 255);"
						"border-style: solid;" 
						"border-width:1px;" 
						"border-color:rgb(210, 210, 210);"
                        "selection-color: white;"
                        "selection-background-color: blue;"
						"font: 10pt Courier;"
						"border-radius: 2px"
						);
	this->edit1->setText(QString::fromStdString(followNameCom));
	this->edit1->setProperty("mandatoryField", true);

	///********** lable1 Tab1 ********///
	this->lable1 = new QLabel(this->TabWidgetVector1.at(0));
	this->lable1->setGeometry(QRect(QPoint(10,10),QSize(220, 25)));
	this->lable1->setStyleSheet(StyleLabel1);
						
	this->lable1->setText(this->decoder->toUnicode("Список элементов: "));


	///********** lable2 Tab1 ********///
	this->lable2 = new QLabel(this->TabWidgetVector1.at(0));
	this->lable2->setGeometry(QRect(QPoint(240,10),QSize(100, 20)));
	this->lable2->setText(this->decoder->toUnicode("Имя архива: "));


	///***** GropBox1  Tab1 ******//
	groupBox1 = new QGroupBox(this->TabWidgetVector1.at(0));
	groupBox1->setTitle(this->decoder->toUnicode("Общая Информация:"));
	groupBox1->setGeometry(QRect(QPoint(10, 320),QSize(220, 100)));
	groupBox1->setStyleSheet(StyleGroupBox);


	QVBoxLayout *vbox = new QVBoxLayout;
	///****** label3 in GroupBox1 Tab1 ******///
	this->lable3 = new QLabel(groupBox1);
	this->lable3->setGeometry(QRect(QPoint(20,360),QSize(70, 15)));
	this->lable3->setStyleSheet(StyleLabel2);
	this->lable3->setText(this->decoder->toUnicode("Общий объем:   0 (байт)"));
	 vbox->addWidget(lable3);

	///****** label4 in GroupBox1 Tab1 ******///
	this->lable4 = new QLabel();
	this->lable4->setGeometry(QRect(QPoint(20,380),QSize(70, 15)));
	this->lable4->setStyleSheet(StyleLabel2);
	this->lable4->setText(this->decoder->toUnicode("Количество:   0")); 
	 vbox->addWidget(lable4);

	 groupBox1->setLayout(vbox);

	 
	 ///***** GropBox2  Tab1 ******//
	groupBox2 = new QGroupBox(this->TabWidgetVector1.at(0));
	groupBox2->setTitle(this->decoder->toUnicode("Настройки"));
	groupBox2->setGeometry(QRect(QPoint(370, 80),QSize(180, 220)));
	groupBox2->setStyleSheet(StyleGroupBox);

	comBox1 = new QComboBox(groupBox2);
	comBox1->setGeometry(QRect(QPoint(20, 50),QSize(150, 20)));
	SYSTEM_INFO sysinfo;
	GetSystemInfo(&sysinfo);
	for(int i = 0; i < sysinfo.dwNumberOfProcessors; i++)
	{
		std::string ss = std::to_string(i + 1);
		comBox1->addItem(decoder->toUnicode(ss.c_str()));
	}

	///****** label 8 GropupBox2 *******//////
	this->lable8 = new QLabel(groupBox2);
	this->lable8->setGeometry(QRect(QPoint(20, 30),QSize(150, 20)));
	this->lable8->setText(decoder->toUnicode("Количество ядер:"));



	comBox2 = new QComboBox(groupBox2);
	comBox2->setGeometry(QRect(QPoint(20, 110),QSize(150, 20)));
	
	for(int i = 1; i < 6; i++)
	{
		std::string ss = std::to_string(i * 4000);
		comBox2->addItem(decoder->toUnicode(ss.c_str()));
	}

	///****** label 9 GropupBox2 *******//////
	this->lable9 = new QLabel(groupBox2);
	this->lable9->setGeometry(QRect(QPoint(20, 90),QSize(150, 20)));
	this->lable9->setText(decoder->toUnicode("Размер блока: (байт)"));


	///****** label 7 Tab1 *******//////
	this->lable7 = new QLabel(this->TabWidgetVector1.at(0));
	this->lable7->setGeometry(QRect(QPoint(250, 300),QSize(70, 20)));
	this->lable7->setText(decoder->toUnicode("Обработанно:"));

	


	
	/////************************ Tab2 ************///////////

	/// ****  Кнопка 3  Tab2*****///
	pushButton3 = new QPushButton(decoder->toUnicode("Выбрать файл"), this->TabWidgetVector1.at(1));
	pushButton3->setGeometry(QRect(QPoint(380, 30),QSize(100, 25)));
	pushButton3->setStyleSheet(StylePushbuttom);
	connect(pushButton3, SIGNAL(clicked()), this, SLOT(on_pushButton3_clicked()));
	
	/// ****  Кнопка 4  Tab2 *****///
	pushButton4 = new QPushButton(decoder->toUnicode("Восстановить"), this->TabWidgetVector1.at(1));
	pushButton4->setGeometry(QRect(QPoint(270, 370),QSize(100, 35)));
	pushButton4->setStyleSheet(StylePushbuttom);
	connect(pushButton4, SIGNAL(clicked()), this, SLOT(on_pushButton4_clicked()));


	/// **** ProgressBar2 Tab2 ***** ///
	progressbar2 = new QProgressBar(this->TabWidgetVector1.at(1));
	progressbar2->setGeometry(QRect(QPoint(250, 320),QSize(320, 20)));
	QObject::connect(&this->timer2, SIGNAL(timeout()), SLOT(TimerTick2()));
	this->progressbar2->setMinimum(0);
	this->progressbar2->setMaximum(100);
    timer2.setInterval(100);


	///***** GropBox3  Tab2 ******//
	groupBox3 = new QGroupBox(this->TabWidgetVector1.at(1));
	groupBox3->setTitle(this->decoder->toUnicode("Общая Информация:"));
	groupBox3->setGeometry(QRect(QPoint(10, 320),QSize(220, 100)));
	groupBox3->setStyleSheet(StyleGroupBox);


	QVBoxLayout *vbox3 = new QVBoxLayout;
	///****** label5 in GroupBox3 Tab2 ******///
	this->lable5 = new QLabel(groupBox3);
	this->lable5->setGeometry(QRect(QPoint(20,360),QSize(70, 20)));
	this->lable5->setStyleSheet(StyleLabel2);
	this->lable5->setText(this->decoder->toUnicode("Общий объем:   0 (байт)"));
	 vbox3->addWidget(lable5);

	///****** label6 in GroupBox3 Tab2 ******///
	this->lable6 = new QLabel();
	this->lable6->setGeometry(QRect(QPoint(20,380),QSize(70, 20)));
	this->lable6->setStyleSheet(StyleLabel2);
	this->lable6->setText(this->decoder->toUnicode("Количество:   0")); 
	 vbox3->addWidget(lable6);

	 groupBox3->setLayout(vbox3);

	 ///********* Edit2 Tab2 *********///
	 this->edit3 = new QLineEdit(this->TabWidgetVector1.at(1));
	this->edit3->setGeometry(QRect(QPoint(20,30),QSize(350, 25)));
	this->edit3->setStyleSheet(StyleLabel1);
	this->edit3->setReadOnly(true);
	this->edit3->setProperty("mandatoryField", true);


	 ///********* Edit4 Tab2 *********///
	 this->edit4 = new QLineEdit(this->TabWidgetVector1.at(1));
	this->edit4->setGeometry(QRect(QPoint(20,80),QSize(350, 25)));
	this->edit4->setStyleSheet(StyleLabel1);
	this->edit4->setReadOnly(true);
	this->edit4->setProperty("mandatoryField", true);

	//////////////////////////////////////////


	 ///***** GropBox4  Tab2 ******//
	groupBox4 = new QGroupBox(this->TabWidgetVector1.at(1));
	groupBox4->setTitle(this->decoder->toUnicode("Настройки"));
	groupBox4->setGeometry(QRect(QPoint(370, 120),QSize(180, 180)));
	groupBox4->setStyleSheet(StyleGroupBox);

	comBox3 = new QComboBox(groupBox4);
	comBox3->setGeometry(QRect(QPoint(20, 50),QSize(150, 20)));
	SYSTEM_INFO sysinfo1;
	GetSystemInfo(&sysinfo1);
	for(int i = 0; i < sysinfo1.dwNumberOfProcessors; i++)
	{
		std::string ss = std::to_string(i + 1);
		comBox3->addItem(decoder->toUnicode(ss.c_str()));
	}

	///****** label 8 GropupBox2 *******//////
	this->lable8 = new QLabel(groupBox4);
	this->lable8->setGeometry(QRect(QPoint(20, 30),QSize(150, 20)));
	this->lable8->setText(decoder->toUnicode("Количество ядер:"));



	comBox4 = new QComboBox(groupBox4);
	comBox4->setGeometry(QRect(QPoint(20, 110),QSize(150, 20)));
	
	for(int i = 1; i < 6; i++)
	{
		std::string ss = std::to_string(i * 4000);
		comBox4->addItem(decoder->toUnicode(ss.c_str()));
	}

	///****** label 10 GropupBox4 *******//////
	this->lable10 = new QLabel(groupBox4);
	this->lable10->setGeometry(QRect(QPoint(20, 90),QSize(150, 20)));
	this->lable10->setText(decoder->toUnicode("Размер блока: (байт)"));


	///****** label 11 Tab2 *******//////
	this->lable11 = new QLabel(this->TabWidgetVector1.at(1));
	this->lable11->setGeometry(QRect(QPoint(250, 300),QSize(70, 20)));
	this->lable11->setText(decoder->toUnicode("Обработанно:"));

	/// ****  Кнопка 9  Tab2*****///
	pushButton9 = new QPushButton(decoder->toUnicode("Выбрать каталог"), this->TabWidgetVector1.at(1));
	pushButton9->setGeometry(QRect(QPoint(380, 80),QSize(100, 25)));
	pushButton9->setStyleSheet(StylePushbuttom);
	connect(pushButton9, SIGNAL(clicked()), this, SLOT(on_pushButton9_clicked()));

	/// ****  Кнопка 10  Tab2*****///
	pushButton10 = new QPushButton(decoder->toUnicode("Отмена"), this->TabWidgetVector1.at(1));
	pushButton10->setGeometry(QRect(QPoint(420, 370),QSize(100, 35)));
	pushButton10->setStyleSheet(StylePushbuttom);
	connect(pushButton10, SIGNAL(clicked()), this, SLOT(on_pushButton10_clicked()));

	///****** label 12 Tab2 *******//////
	this->lable12 = new QLabel(this->TabWidgetVector1.at(1));
	this->lable12->setGeometry(QRect(QPoint(20, 60),QSize(150, 20)));
	this->lable12->setText(decoder->toUnicode("Каталог сохранения:"));
	
		///****** label 13 Tab2 *******//////
	this->lable13 = new QLabel(this->TabWidgetVector1.at(1));
	this->lable13->setGeometry(QRect(QPoint(20, 10),QSize(100, 20)));
	this->lable13->setText(decoder->toUnicode("Путь к файлу:"));
}

MainWindow::~MainWindow()
{

}

void MainWindow::slotOpen()
{

	QString fileName = QFileDialog::getOpenFileName(0, (this->decoder->toUnicode("Открыть файл")), QDir::currentPath());
    if (!fileName.isEmpty())
    {
        QImage image(fileName);
        labelImage->setPixmap(QPixmap::fromImage(image));
        labelFile->setText(fileName);
    }
}

void MainWindow::slotAbout()
{
	
	QMessageBox::about( 0 , this->decoder->toUnicode("О программе..."), (this->decoder->toUnicode("Моисеев Андрей.")));
}

void MainWindow::slotImageSize(bool b)
{
	labelImage->setScaledContents(b);
}


void MainWindow::on_pushButton1_clicked()
{
	QString dirName = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                             "D:\\",
                                             QFileDialog::ShowDirsOnly
											 | QFileDialog::DontResolveSymlinks| QFileDialog::DontUseNativeDialog); 
	if(dirName != "")
	{
	 this->ParcAddressDirectory(dirName.toStdString());

	 this->UpdatelistWidget1();
	 this->UpdateGroupInfo();
	}
}

void MainWindow::on_pushButton2_clicked()
{
	int size = 0;
	for (auto it = this->mapSizeFiles.begin(); it != this->mapSizeFiles.end(); ++it)
	 {
		 size += it->second;
	 }

	try
	{
		if(flag1 == false)
		{
			if(this->filesVector.size() != 0 || this->directVector.size() != 0)
			{
				std::string ad = this->edit1->text().toStdString();
				if(this->CheckDirectory(ad))
				{
					if(this->CheckResultFile(ad))
					{
						this->progressbar1->setValue(0);
						this->flag1 = true;
						this->timer1.start();
						MM->Compression(ad, this->filesVector, this->directVector, size, this->countCoreCompression, this->sizeBlockCompression);
					}else
					{
						this->edit1->clear();
						this->edit1->setText(QString::fromStdString(this->followNameCom));
						ms->information(this, "Warning", this->decoder->toUnicode("Целевой файл имеет неверный формат или уже существует!"));
					}
				}else
				{
					this->edit1->clear();
					this->edit1->setText(QString::fromStdString(this->followNameCom));
					QMessageBox::information(this, "Warning", this->decoder->toUnicode("  Выбранной директории для сохранения архива не существует!  "));
					
				}
			}else
			{
				QMessageBox::information(this, "Warning", this->decoder->toUnicode("    Список пуст!    "));
			}	
		}else
		{
			QMessageBox::information(this, "Warning", this->decoder->toUnicode("  Операция сжатия еще не завершена! Поток занят! "));
		}
	}
	catch(...)
	{
		QMessageBox::information(this, "System Error", " Error inside the library  !");
	}
}


void MainWindow::on_pushButton5_clicked()
{
	 QString fileName = QFileDialog::getOpenFileName(this, tr("Open .bmp"), "/home", tr("*.bmp"));
	 if(fileName != "")
	 {
		 this->ParcAddressFile(fileName.toStdString());
		 this->UpdatelistWidget1();
		 this->UpdateGroupInfo();
	 }
}


void MainWindow::on_pushButton6_clicked()
{
	QString dirName = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                             "D:\\",
                                             QFileDialog::ShowDirsOnly
											 | QFileDialog::DontResolveSymlinks| QFileDialog::DontUseNativeDialog); 

	std::string NewAddrDir = dirName.toStdString();
	 std::replace_if(NewAddrDir.begin(), NewAddrDir.end(), std::bind2nd(std::equal_to<char>(), '/'), '\\');

	std::vector<std::string> VecAddr = this->SplitAddress(this->edit1->text().toStdString(), '\\');

	std::string NewAddrFile = "";

	if(NewAddrDir.size() == 0)
	{
		NewAddrFile = "D:\\" + VecAddr.at(VecAddr.size() - 1);
	}else
	{
		NewAddrFile = NewAddrDir + "\\" + VecAddr.at(VecAddr.size() - 1);
	}
	this->edit1->clear();
	this->edit1->setText(QString::fromStdString(NewAddrFile));

}


void MainWindow:: TimerTick1( void )
{
	if(!MM->ComEndWork())
	{
		double a = MM->GetComProgress();
		this->progressbar1->setValue(MM->GetComProgress());
	}else
	{
		this->timer1.stop();
		this->directVector.clear();
		this->filesVector.clear();
		fullSize = 0;
		this->edit1->clear();
		this->edit1->setText(QString::fromStdString(followNameCom));
		UpdateGroupInfo();
		UpdatelistWidget1();
		this->progressbar1->setValue(0);
		this->flag1 = false;
		QMessageBox::information(this, "Infomation", this->decoder->toUnicode("   Сжатие завершено!   "));

	}
}


void MainWindow::on_pushButton7_clicked()
{
	
	int index = listWidget1->row(listWidget1->currentItem());
	if(index != -1)
	{
		QString rett = listWidget1->currentItem()->text();
		listWidget1->takeItem(listWidget1->row(listWidget1->currentItem()));
		std::string num = rett.toStdString();

		std::vector<std::string> vvv;



		//std::map<std::string,int>::iterator it = this->mapSizeFiles.find(num);
		mapSizeFiles.erase(num);  


		if(index < filesVector.size())
		{
			filesVector.erase(filesVector.begin() + index);

		}else if((index - filesVector.size())  < directVector.size())
		{
			int df = index - filesVector.size();
			directVector.erase(directVector.begin() + df);
		}

		this->UpdateGroupInfo();
	}
}

void MainWindow::on_pushButton8_clicked()
{
	MM->TerminateThreadCompression();
}



int MainWindow::ParcAddressDirectory(std::string addressFile)
{
	int sz = 0;
	std::string finaladdr = "";
	char drive[56], path[80], name[56], ext[56];
	char * chrstr = new char[addressFile.size() + 1];
	strcpy(chrstr, addressFile.c_str());
	_splitpath(chrstr, drive, path, name, ext);	
	delete []chrstr;

	std::replace_if(addressFile.begin(), addressFile.end(), std::bind2nd(std::equal_to<char>(), '/'), '\\');

	

	TCHAR* file = 0;
	file = new TCHAR [addressFile.size() +1];
	copy(addressFile.begin(), addressFile.end(), file);
	file[addressFile.size()] = 0;


		std::vector<std::string> listFile;
		chrstr = new char[addressFile.size() + 1];
		strcpy(chrstr, addressFile.c_str());

		_splitpath(chrstr, drive, path, name, ext);	
		delete []chrstr;

		std::string strDir = addressFile + "\\*.bmp";
		TCHAR* file1 = 0;
		file1 = new TCHAR [strDir.size() +1];
		copy(strDir.begin(), strDir.end(), file1);
		file1[strDir.size()] = 0;
		WIN32_FIND_DATA FindFileData;
		HANDLE hf=FindFirstFile(file1, &FindFileData);
		if (hf!=INVALID_HANDLE_VALUE)
		{
		do
		{
			std::wstring ws(FindFileData.cFileName);
		
			std::string str(ws.begin(), ws.end());

			listFile.push_back(str);
		}
		while (FindNextFile(hf,&FindFileData)!=0);
		FindClose(hf);
		}

		delete[] file1;



		for(int j = 0; j < listFile.size(); j++)
		{	
			try
			{
				sz += this->CheckFile(addressFile + "\\" + listFile.at(j));
			}catch(std::string e)
			{
				QMessageBox::information(this, "Warning", this->decoder->toUnicode("Неверный формат (.bmp) !"));
			} 
	}
		this->mapSizeFiles.insert(std::pair<std::string, int>(addressFile, sz));
		this->directVector.push_back(addressFile);
		this->countElement ++;
		return sz;
}


void MainWindow::ParcAddressFile(std::string addressFile)
{
	int sz = 0;
	std::string finaladdr = "";
	char drive[56], path[80], name[56], ext[56];
	char * chrstr = new char[addressFile.size() + 1];
	strcpy(chrstr, addressFile.c_str());
	_splitpath(chrstr, drive, path, name, ext);	
	delete []chrstr;

	std::replace_if(addressFile.begin(), addressFile.end(), std::bind2nd(std::equal_to<char>(), '/'), '\\');

	TCHAR* file = 0;
	file = new TCHAR [addressFile.size() +1];
	copy(addressFile.begin(), addressFile.end(), file);
	file[addressFile.size()] = 0;

		try
		{
			sz += this->CheckFile(addressFile);
			this->filesVector.push_back(addressFile);
			this->countElement ++;
		}catch(std::string e)
		{
			QMessageBox::information(this, "Warning", this->decoder->toUnicode("Неверный формат (.bmp) !"));
		}
		this->mapSizeFiles.insert(std::pair<std::string, int>(addressFile, sz));
}


int MainWindow::CheckFile(std::string str)
{
	std::ifstream infile(str, std::ios::binary);

	bmpstruct bm;
	if(!infile.is_open()) throw "Error : file " + str + " is not open";
	infile.read((char *)&bm, sizeof(BITMAPFILEHEADERME));
	infile.close();

	return bm.bfSize;
}

void MainWindow::AddlistWidget1(std::string str)
{
	//QString qstr = QString::fromStdString(str);
	new QListWidgetItem(this->decoder->toUnicode(str.c_str()), listWidget1);
}

void MainWindow::UpdatelistWidget1()
{
	this->listWidget1->clear();
	for(int i = 0; i < this->filesVector.size(); i++)
	{
		this->AddlistWidget1(filesVector.at(i));
	}

	for(int i = 0; i < this->directVector.size(); i++)
	{
		this->AddlistWidget1(directVector.at(i));
	}
}

void MainWindow::UpdateGroupInfo()
{
	int size = 0;
	for (auto it = this->mapSizeFiles.begin(); it != this->mapSizeFiles.end(); ++it)
	 {
		 size += it->second;
	 }
	std::string st = "Общий объем (байт): ";
	std::string s = std::to_string(size);
	st += s + " ";
	this->lable3->setText(this->decoder->toUnicode(st.c_str()));

	int a = directVector.size();
	a += filesVector.size();
	 st = "Количество:   ";
	 s = std::to_string(a);
	st += s;
	this->lable4->setText(this->decoder->toUnicode(st.c_str()));
}



////************* Tab2 ***********///


void MainWindow::on_pushButton4_clicked()
{
	try
	{
		if(flag2 == false)
		{
			if(this->sourceDecomAddress != "")
			{
				flag2 = true;
				this->progressbar2->setValue(0);	
				MM->Decompression(this->sourceDecomAddress, this->followDecomAddress, this->countCoreDecompression, this->sizeblockDecompression);
				this->timer2.start();
			}else
			{
				QMessageBox::information(this, "Warning", this->decoder->toUnicode("  Файл не выбран!  "));
			}
		}else
		{
			QMessageBox::information(this, "Warning", this->decoder->toUnicode("  Операция восстановления еще не завершена! Поток занят!  "));
		}
	}
	catch(...)
	{
		QMessageBox::information(this, "System Error", " Error inside the library  !");
	}

}

void MainWindow::on_pushButton10_clicked()
{
	MM->TerminateThreadDecompression();
}

void MainWindow::on_pushButton3_clicked()
{
		 QString fileName = QFileDialog::getOpenFileName(this, tr("Open .dip"), "/home", tr("*.dip"));
	 if(fileName != "")
	 {
		 this->sourceDecomAddress = fileName.toStdString();
		 std::replace_if(this->sourceDecomAddress.begin(), this->sourceDecomAddress.end(), std::bind2nd(std::equal_to<char>(), '/'), '\\');
		 this->edit3->clear();
		 this->edit3->setText(QString::fromStdString(this->sourceDecomAddress));

		 this->lable5->clear();
		 std::string ddd = "Общий объем(байт): ";
		 ddd += std::to_string(this->GetDecompressionFile(this->sourceDecomAddress));
		 this->lable5->setText(decoder->toUnicode(ddd.c_str()));

		 this->lable6->clear();
		 std::string s = "Количество:   ";
		 s += std::to_string(1);
		 this->lable6->setText(decoder->toUnicode(s.c_str()));
	 }
}

void MainWindow::on_pushButton9_clicked()
{
	QString dirName = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                             "D:\\",
                                             QFileDialog::ShowDirsOnly
											 | QFileDialog::DontResolveSymlinks| QFileDialog::DontUseNativeDialog); 

	this->followDecomAddress = dirName.toStdString();
	std::replace_if(this->followDecomAddress.begin(), this->followDecomAddress.end(), std::bind2nd(std::equal_to<char>(), '/'), '\\');
	if(this->followDecomAddress != "")
	{
		this->edit4->clear();
		this->edit4->setText(QString::fromStdString(this->followDecomAddress));
	}
}

void MainWindow:: TimerTick2( void )
{
	if(!MM->DecomEndWork())
	{
		this->progressbar2->setValue(MM->GetDecomProgress());
	}else
	{
		this->timer2.stop();
		flag2 = false;
		QMessageBox::information(this, "Warning", this->decoder->toUnicode("  Восстановление завершено!  "));
		this->edit3->clear();
		this->edit4->clear();
		this->progressbar2->setValue(0);
		this->lable5->clear();
		//std::string uniStr = this->decoder->toUnicode("Общий объем: (байт)");
		this->lable5->setText(this->decoder->toUnicode("Общий объем: (байт)"));
		this->lable6->clear();
		this->lable6->setText(this->decoder->toUnicode("Количество : 0 "));
	}
	
}

std::vector<std::string> MainWindow:: SplitAddress(std::string str, char delim)
{
	std::vector<std::string> elems;
    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

bool  MainWindow:: CheckDirectory(std::string addr)
{
	QDir * dir = new QDir();

	std::vector<std::string> sst = this->SplitAddress(addr, '\\');
	std::string vtr = "";

	if(sst.size() != 0)
	{

		for(int i = 0; i < sst.size() - 1; i++)
		{
			vtr += sst.at(i);
		}
	}else
	{
		return false;
	}

	if(!dir->exists(QString::fromStdString(vtr)))
		return false;

	return true;
}

bool  MainWindow:: CheckResultFile(std::string st)
{
	QFile * file = new QFile();

	if(file ->exists(QString::fromStdString(st)))
		return false;

	std::vector<std::string> sst = this->SplitAddress(st, '\\');

	std::vector<std::string> res = this->SplitAddress(sst.at(sst.size() - 1), '.');
	
	if(res.size() == 2)
	{
		if(res.at(1) == "dip")
		{
			return true;
		}
		return false;
	}
	return false;
}

int MainWindow :: GetDecompressionFile(std::string addr)
{
	std::ifstream infile(addr, std::ios::binary );

	infile.seekg (0,infile.end);
	int sizeDecomprFile = infile.tellg();
	infile.seekg (0);
	return sizeDecomprFile;
}
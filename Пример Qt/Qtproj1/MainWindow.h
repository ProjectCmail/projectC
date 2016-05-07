#ifndef QTPROJ1_H
#define QTPROJ1_H


#include <QTextCodec>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QCheckBox>
#include <QFileDialog>
#include <QWidget>
#include <qgroupbox.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qlistwidget.h>
#include <qprogressbar.h>
#include <qfont.h>
#include <qtimer.h>
#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include <qmessagebox.h>
#include <vector>
#include "MainEntry.h"
#include <future>



class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
	QString str;
	MainEntry<double> * MM;
	QTextDecoder *decoder;
	std::vector<std::string> filesVector;
	std::vector<std::string> directVector;
	std::vector<QWidget *> TabWidgetVector1;

	//**** Decompression ****//
	std::string sourceDecomAddress;
	std::string followDecomAddress;


private:
	void ParcAddressFile(std::string addr);
	int ParcAddressDirectory(std::string addr);
	int CheckFile(std::string str);
	void AddlistWidget1(std::string str);
	void UpdatelistWidget1();
	void UpdateGroupInfo();

	bool CheckDirectory(std::string addr);
	std::vector<std::string> SplitAddress(std::string str, char delim);
	bool CheckResultFile(std::string addr);
	int GetDecompressionFile(std::string addr);

	bool flag1;
	bool flag2;

	std::map <std::string,int> mapSizeFiles;

	int countElement;
	unsigned long int fullSize;
	std::string followDirCom;
	std::string followNameCom;

	int countCoreCompression;
	int countCoreDecompression;

	int sizeBlockCompression;
	int sizeblockDecompression;

	Ui::Qtproj1Class ui;
	QAction *actionOpen;
    QAction *actionExit;
    QAction *actionAbout;
	QMenu *menuFile;
    QMenu *menuHelp;
    QLabel *labelMenu;
    QLabel *labelFile;
    QLabel *labelImage;
    QPushButton *butOpen;
    QCheckBox *cbSize;
    QVBoxLayout *vlayout;
    QHBoxLayout *hlayout;
    QWidget *mainWidget;
	QTabWidget *tabWidget;
	QPushButton *pushButton1;
	QPushButton *pushButton2;
	QProgressBar * progressbar1;
	QPushButton *pushButton3;
	QPushButton *pushButton4;
	QProgressBar * progressbar2;
	QPushButton *pushButton5;
	QPushButton *pushButton6;
	QPushButton *pushButton7;
	QPushButton *pushButton8;
	QListWidget *listWidget1;

	QLineEdit *edit1;
	QLineEdit *edit2;
	

	QLabel *lable1;
	QLabel *lable2;
	QGroupBox *groupBox1;
	QGroupBox *groupBox2;
	QGroupBox *groupBox3;
	QLabel *lable3;
	QLabel *lable4;
	QLabel *lable5;
	QLabel *lable6;
	QLabel *lable7;
	QLabel *lable8;
	QLabel *lable9;

	QComboBox *comBox1;
	QComboBox *comBox2;


	//// Tab2 //////
	QComboBox *comBox3;
	QComboBox *comBox4;

	QGroupBox *groupBox4;

	QLabel *lable10;
	QLabel *lable11;
	QLabel *lable12;
	QLabel *lable13;
	QLabel *lable14;

	QLineEdit *edit3;
	QLineEdit *edit4;

	QPushButton *pushButton9;
	QPushButton *pushButton10;


	QMessageBox *ms;
	QTimer timer1;
	QTimer timer2;
	
private slots:

	
	void TimerTick1( void );
	void TimerTick2( void );

	void on_pushButton1_clicked();
	void on_pushButton2_clicked();

	
	void on_pushButton4_clicked();

	void on_pushButton5_clicked();
	void on_pushButton6_clicked();
	void on_pushButton7_clicked();
	void on_pushButton8_clicked();

	///********* Tab2 ******** //

	void on_pushButton3_clicked();
	void on_pushButton9_clicked();
	void on_pushButton10_clicked();

	
	
	void slotOpen();
    void slotAbout();
	void slotImageSize(bool on);
};

#endif // QTPROJ1_H

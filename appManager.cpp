#include<QMainWindow>
#include<QWidget>
#include<QVBoxLayout>

class AppManager{

public :

    AppManager(){

        setupUI();
    }

    void show(){

        mainWindow->show();
    }

    QMainWindow *mainWindow;
    QWidget *centralWidget;
    QVBoxLayout *mainLayout;

    void setupUI(){

        mainWindow = new QMainWindow();
        mainWindow->setWindowTitle("Not Maker App");
        mainWindow->resize(400,300);

        centralWidget = new QWidget();
        mainLayout = new QVBoxLayout(centralWidget);

        centralWidget->setLayout(mainLayout);

        mainWindow->setCentralWidget(centralWidget);
    }
};
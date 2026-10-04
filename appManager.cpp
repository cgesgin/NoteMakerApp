#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QTextEdit>
#include <QPushButton>

class AppManager
{
public:

    AppManager()
    {
        setupUI();
    }

    void show()
    {
        mainWindow->show();
    }

private:

    QMainWindow *mainWindow;
    QWidget *centralWidget;
    QHBoxLayout *mainLayout;

    QListWidget *noteList;
    QTextEdit *noteEditor;

    QPushButton *saveButton;
    QPushButton *deleteButton;
    QPushButton *newButton;


    void setupUI()
    {
        mainWindow = new QMainWindow();

        mainWindow->setWindowTitle("Note Maker App");
        mainWindow->resize(600, 400);


        // Central Widget
        centralWidget = new QWidget();

        // LEFT + RIGHT yan yana olacak
        mainLayout = new QHBoxLayout(centralWidget);


        // --------------------
        // LEFT PANEL
        // --------------------

        QWidget *leftPanel = new QWidget();

        QVBoxLayout *leftLayout = new QVBoxLayout(leftPanel);

        noteList = new QListWidget();
        leftLayout->addWidget(noteList);


        newButton = new QPushButton("New Note");
        leftLayout->addWidget(newButton);


        deleteButton = new QPushButton("Delete");
        leftLayout->addWidget(deleteButton);


        // --------------------
        // RIGHT PANEL
        // --------------------

        QWidget *rightPanel = new QWidget();

        QVBoxLayout *rightLayout = new QVBoxLayout(rightPanel);


        noteEditor = new QTextEdit();

        noteEditor->setPlaceholderText(
            "Write your notes here..."
            );

        rightLayout->addWidget(noteEditor);


        saveButton = new QPushButton("Save");

        rightLayout->addWidget(saveButton);


        // --------------------
        // MAIN LAYOUT
        // --------------------

        mainLayout->addWidget(leftPanel, 1);
        mainLayout->addWidget(rightPanel, 2);


        mainWindow->setCentralWidget(centralWidget);
    }
};
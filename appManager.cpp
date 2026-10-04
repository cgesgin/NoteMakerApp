#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QMap>

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


    // Note storage
    QMap<QString, QString> notes;


    void setupUI()
    {
        mainWindow = new QMainWindow();

        mainWindow->setWindowTitle("Note Maker App");
        mainWindow->resize(600, 400);


        // Central Widget
        centralWidget = new QWidget();

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


        // --------------------
        // CONNECTIONS
        // --------------------

        QObject::connect(
            saveButton,
            &QPushButton::clicked,
            [this]()
            {
                saveCurrentNote();
            }
            );
    }


    void saveCurrentNote()
    {
        QString content = noteEditor->toPlainText().trimmed();

        if (content.isEmpty())
        {
            QMessageBox::warning(
                mainWindow,
                "Error",
                "No Text to Save"
                );

            return;
        }


        QString title = content.left(30).trimmed();

        notes[title] = content;

        updateNotes();
    }


    void updateNotes()
    {
        noteList->clear();

        for (const QString &title : notes.keys())
        {
            noteList->addItem(title);
        }
    }
};
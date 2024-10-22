#include "Scoreboard.h"
#include "Menu.h"

Scoreboard::Scoreboard(QWidget *parent)
{
    const int x_pos = 1366;
    const int y_pos = 768;
    texture_setter = new Texture_setter(); //texture constructor

    scene = new QGraphicsScene(0, 0, x_pos, y_pos); //create scene for instruction
    setScene(scene);

    QPixmap background = texture_setter->score_txt(1); //set texture background
    QGraphicsPixmapItem *backgroundItem = new QGraphicsPixmapItem(background);
    backgroundItem->setPos(0, 0);
    scene->addItem(backgroundItem);

    setFixedSize(x_pos, y_pos);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //create button back to menu
    backButton = new QPushButton("Menu", this);
    int button_x=300;
    int button_y=160;
    int gap=10;
    backButton->setGeometry(QRect(QPoint(x_pos/2 - button_x*2/3, y_pos*6/8), QSize(button_x, button_y)));
    backButton->setStyleSheet("background-color: orange; color: #1D4E89; font-size: 20px;");
    connect(backButton, &QPushButton::clicked, this, &Scoreboard::returnToMenu);

    scoreRecord = new Score_record();//create object
    displayScores();//show 10 best and 10 last scores from game
}

void Scoreboard::displayScores()
{
    //Get last 10 scores and top 10 scores
    std::vector<int> lastTenScores = scoreRecord->getLastTenScores();
    std::vector<int> topTenScores = scoreRecord->getTopTenScores();

    //Last 10 scores display on screen
    for (size_t i = 0; i < lastTenScores.size(); ++i) {
        QGraphicsTextItem *scoreItem = new QGraphicsTextItem(QString::number(i + 1) + ". " + QString::number(lastTenScores[i]));
        scoreItem->setDefaultTextColor(Qt::white);
        scoreItem->setFont(QFont("Arial", 30));
        scoreItem->setPos(80, 310 + i * 40);
        scene->addItem(scoreItem);
    }

    //Top 10 scores display on screen
    for (size_t i = 0; i < topTenScores.size(); ++i) {
        QGraphicsTextItem *scoreItem = new QGraphicsTextItem(QString::number(i + 1) + ". " + QString::number(topTenScores[i]));
        scoreItem->setDefaultTextColor(Qt::white);
        scoreItem->setFont(QFont("Arial", 30));
        scoreItem->setPos(970, 330 + i * 40);
        scene->addItem(scoreItem);
    }
}

void Scoreboard::returnToMenu()
{
    this->close(); //close instruction
    Menu *menuWindow = new Menu(); //open menu
    menuWindow->show(); //show
    qDebug("Menu");
}

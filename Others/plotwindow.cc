MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent)
{
lay=new QVBoxLayout();
scene = new QGraphicsScene();
scene->setSceneRect(0, 0, 250, 250);//rectuangular scene built
view=new QGraphicsView(scene);
view->drawForeground(); //What should be the calling parameter for this function ......i knw that its QPainter and QRectF but its not working perhaps i am writing wrong.....
view->show();
lay->addWidget(view);
setLayout(lay);
showMaximized();
}

MainWindow::~MainWindow()
{

}

void MainWindow::drawForeground(QPainter* painter, const QRectF& rect)
{
int gridInterval = 100; //interval to draw grid lines at
painter->setWorldMatrixEnabled(true);

qreal left = int(rect.left()) - (int(rect.left()) % gridInterval );
qreal top = int(rect.top()) - (int(rect.top()) % gridInterval );

QVarLengthArray<QLineF, 100> linesX;
for (qreal x = left; x < rect.right(); x += gridInterval )
linesX.append(QLineF(x, rect.top(), x, rect.bottom()));

QVarLengthArray<QLineF, 100> linesY;
for (qreal y = top; y < rect.bottom(); y += gridInterval )
linesY.append(QLineF(rect.left(), y, rect.right(), y));

painter->drawLines(linesX.data(), linesX.size());
painter->drawLines(linesY.data(), linesY.size());
}
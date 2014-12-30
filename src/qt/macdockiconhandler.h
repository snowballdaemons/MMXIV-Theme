#ifndef MACDOCKICONHANDLER_H
#define MACDOCKICONHANDLER_H

#include <QMainWindow>
#include <QtCore/QObject>

class QMenu;
class QIcon;
class QWidget;
class objc_object;

/** Macintosh-specific dock icon handler.
 */
class MacDockIconHandler : public QObject
{
    Q_OBJECT
public:
    ~MacDockIconHandler();

    QMenu *dockMenu();
    void setIcon(const QIcon &icon);
	void setMainWindow(QMainWindow *window);
    static MacDockIconHandler *instance();

    void handleDockIconClickEvent();

signals:
    void dockIconClicked();

public slots:

private:
    MacDockIconHandler();

    objc_object *m_dockIconClickEventHandler;
    QWidget *m_dummyWidget;
    QMenu *m_dockMenu;
	QMainWindow *mainWindow;
};

#endif // MACDOCKICONCLICKHANDLER_H

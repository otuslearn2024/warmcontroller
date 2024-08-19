#ifndef WARMITEMWIDGET_H
#define WARMITEMWIDGET_H

#include <QWidget>

namespace Ui {
class WarmItemWidget;
}

class WarmItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WarmItemWidget(QWidget *parent = nullptr);
    ~WarmItemWidget();

    void setLocationName(const QString& locationName);
    void setLocation(const QString& location);
    void setDescription(const QString& description);
    void setPower(const QString& power);

private:
    Ui::WarmItemWidget *ui;
};

#endif // WARMITEMWIDGET_H

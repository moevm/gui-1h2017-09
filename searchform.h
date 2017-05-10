#ifndef SEARCHFORM_H
#define SEARCHFORM_H

#include <QFrame>

namespace Ui {
class SearchForm;
}

class SearchForm : public QFrame
{
    Q_OBJECT

public:
    explicit SearchForm(QWidget *parent = 0);
    ~SearchForm();

private:
    Ui::SearchForm *ui;
};

#endif // SEARCHFORM_H

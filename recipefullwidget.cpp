#include "recipefullwidget.h"
#include "ui_recipefullwidget.h"

RecipeFullWidget::RecipeFullWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecipeFullWidget)
{
    ui->setupUi(this);
}

RecipeFullWidget::~RecipeFullWidget()
{
    delete ui;
}

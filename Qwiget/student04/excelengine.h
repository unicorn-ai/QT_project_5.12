#ifndef EXCELENGINE_H
#define EXCELENGINE_H
#include <QFile>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QTableWidget>
#include <QAxObject>

class QExcelEngine
{
public:
    QExcelEngine();
    QExcelEngine(QString xlsFile);
    ~QExcelEngine();

public:
    bool Open(int nSheet, bool visible);
    bool Open(QString xlsFile, int nSheet, bool visible);
    void Save();
    void Close();
    bool SaveDataFrTable(QTableWidget *tableWidget);
    bool ReadDataToTable(QTableWidget *tableWidget);
    QVariant GetCellData(int row, int column);
    bool SetCellData(int row, int column, QVariant data);
    void ClearAllData(QString strData);
    void Clear();
    bool IsOpen();
    bool IsValid();
    int GetRowCount() const;
    int GetColumnCount() const;

private:
    QAxObject *pExcel;
    QAxObject *pWorkbooks;
    QAxObject *pWorkbook;
    QAxObject *pWorksheet;

    QString sXlsFile;

    int nRowCount;
    int nColumnCount;
    int nStartRow;
    int nStartColumn;
    int nCurrSheet;

    bool bIsVisible;
    bool bIsOpen;
    bool bIsValid;
    bool bIsANewFile;
    bool bIsSaveAlready;
};

#endif // EXCELENGINE_H

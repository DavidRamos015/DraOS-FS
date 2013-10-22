/****************************************************************************
** Meta object code from reading C++ file 'fileexplorer.h'
**
** Created: Fri Dec 14 18:15:49 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../fileexplorer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fileexplorer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FileExplorer[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   14,   13,   13, 0x08,
      71,   14,   13,   13, 0x08,
     117,   13,   13,   13, 0x08,
     138,   13,   13,   13, 0x08,
     159,   13,   13,   13, 0x08,
     173,   13,   13,   13, 0x08,
     195,   13,   13,   13, 0x08,
     216,   13,   13,   13, 0x08,
     242,   13,   13,   13, 0x08,
     268,   13,   13,   13, 0x08,
     293,   13,   13,   13, 0x08,
     314,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FileExplorer[] = {
    "FileExplorer\0\0item\0"
    "on_tableWidget_itemDoubleClicked(QTableWidgetItem*)\0"
    "on_tableWidget_itemClicked(QTableWidgetItem*)\0"
    "on_btnNext_clicked()\0on_btnBack_clicked()\0"
    "On_LoadRoot()\0on_btnClose_clicked()\0"
    "on_btnHome_clicked()\0on_btnNewFolder_clicked()\0"
    "on_btnModificar_clicked()\0"
    "on_btnEliminar_clicked()\0on_btnOpen_clicked()\0"
    "on_btnSave_clicked()\0"
};

const QMetaObject FileExplorer::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FileExplorer,
      qt_meta_data_FileExplorer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FileExplorer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FileExplorer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FileExplorer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FileExplorer))
        return static_cast<void*>(const_cast< FileExplorer*>(this));
    return QDialog::qt_metacast(_clname);
}

int FileExplorer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_tableWidget_itemDoubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 1: on_tableWidget_itemClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 2: on_btnNext_clicked(); break;
        case 3: on_btnBack_clicked(); break;
        case 4: On_LoadRoot(); break;
        case 5: on_btnClose_clicked(); break;
        case 6: on_btnHome_clicked(); break;
        case 7: on_btnNewFolder_clicked(); break;
        case 8: on_btnModificar_clicked(); break;
        case 9: on_btnEliminar_clicked(); break;
        case 10: on_btnOpen_clicked(); break;
        case 11: on_btnSave_clicked(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

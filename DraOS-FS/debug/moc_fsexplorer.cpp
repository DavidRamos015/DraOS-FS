/****************************************************************************
** Meta object code from reading C++ file 'fsexplorer.h'
**
** Created: Fri Dec 14 18:15:46 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../fsexplorer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fsexplorer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FSExplorer[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      36,   11,   11,   11, 0x08,
      60,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FSExplorer[] = {
    "FSExplorer\0\0on_btnUsuario_clicked()\0"
    "on_btnFormato_clicked()\0"
    "on_btnFilesSystem_clicked()\0"
};

const QMetaObject FSExplorer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FSExplorer,
      qt_meta_data_FSExplorer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FSExplorer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FSExplorer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FSExplorer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FSExplorer))
        return static_cast<void*>(const_cast< FSExplorer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int FSExplorer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_btnUsuario_clicked(); break;
        case 1: on_btnFormato_clicked(); break;
        case 2: on_btnFilesSystem_clicked(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'formuser.h'
**
** Created: Fri Dec 14 18:15:48 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../formuser.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formuser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_formUser[] = {

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
      10,    9,    9,    9, 0x08,
      30,    9,    9,    9, 0x08,
      55,   50,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_formUser[] = {
    "formUser\0\0on_btnadd_clicked()\0"
    "on_btndel_clicked()\0item\0"
    "on_ListaUsuarios_itemClicked(QListWidgetItem*)\0"
};

const QMetaObject formUser::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_formUser,
      qt_meta_data_formUser, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &formUser::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *formUser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *formUser::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_formUser))
        return static_cast<void*>(const_cast< formUser*>(this));
    return QDialog::qt_metacast(_clname);
}

int formUser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_btnadd_clicked(); break;
        case 1: on_btndel_clicked(); break;
        case 2: on_ListaUsuarios_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

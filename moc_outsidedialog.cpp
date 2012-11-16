/****************************************************************************
** Meta object code from reading C++ file 'outsidedialog.h'
**
** Created: Fri Nov 16 23:13:11 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "outsidedialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'outsidedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OutsideDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      27,   14,   14,   14, 0x0a,
      41,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_OutsideDialog[] = {
    "OutsideDialog\0\0upClicked()\0downClicked()\0"
    "stepInsideClicked()\0"
};

void OutsideDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        OutsideDialog *_t = static_cast<OutsideDialog *>(_o);
        switch (_id) {
        case 0: _t->upClicked(); break;
        case 1: _t->downClicked(); break;
        case 2: _t->stepInsideClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData OutsideDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject OutsideDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_OutsideDialog,
      qt_meta_data_OutsideDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OutsideDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OutsideDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OutsideDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OutsideDialog))
        return static_cast<void*>(const_cast< OutsideDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int OutsideDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

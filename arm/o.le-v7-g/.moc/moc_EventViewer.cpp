/****************************************************************************
** Meta object code from reading C++ file 'EventViewer.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/EventViewer.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EventViewer.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EventViewer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       4,   39, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      30,   12,   12,   12, 0x05,
      48,   12,   12,   12, 0x05,
      67,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      84,   12,   12,   12, 0x08,

 // properties: name, type, flags
     139,  131, 0x0a495001,
     147,  131, 0x0a495001,
     156,  131, 0x0a495001,
     166,  131, 0x0a495001,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

static const char qt_meta_stringdata_EventViewer[] = {
    "EventViewer\0\0subjectChanged()\0"
    "locationChanged()\0startTimeChanged()\0"
    "endTimeChanged()\0"
    "eventsChanged(bb::pim::calendar::EventRefresh)\0"
    "QString\0subject\0location\0startTime\0"
    "endTime\0"
};

void EventViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EventViewer *_t = static_cast<EventViewer *>(_o);
        switch (_id) {
        case 0: _t->subjectChanged(); break;
        case 1: _t->locationChanged(); break;
        case 2: _t->startTimeChanged(); break;
        case 3: _t->endTimeChanged(); break;
        case 4: _t->eventsChanged((*reinterpret_cast< const bb::pim::calendar::EventRefresh(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData EventViewer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EventViewer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_EventViewer,
      qt_meta_data_EventViewer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EventViewer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EventViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EventViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EventViewer))
        return static_cast<void*>(const_cast< EventViewer*>(this));
    return QObject::qt_metacast(_clname);
}

int EventViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = subject(); break;
        case 1: *reinterpret_cast< QString*>(_v) = location(); break;
        case 2: *reinterpret_cast< QString*>(_v) = startTime(); break;
        case 3: *reinterpret_cast< QString*>(_v) = endTime(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void EventViewer::subjectChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void EventViewer::locationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void EventViewer::startTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void EventViewer::endTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE

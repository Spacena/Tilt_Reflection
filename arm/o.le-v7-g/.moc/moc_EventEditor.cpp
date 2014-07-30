/****************************************************************************
** Meta object code from reading C++ file 'EventEditor.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/EventEditor.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EventEditor.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EventEditor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       7,   69, // properties
       1,   97, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      30,   12,   12,   12, 0x05,
      48,   12,   12,   12, 0x05,
      67,   12,   12,   12, 0x05,
      84,   12,   12,   12, 0x05,
     102,   12,   12,   12, 0x05,
     121,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     144,  135,   12,   12, 0x0a,
     183,   12,   12,   12, 0x0a,
     195,   12,   12,   12, 0x0a,

 // methods: signature, parameters, type, tag, flags
     212,  203,   12,   12, 0x02,

 // properties: name, type, flags
     270,  262, 0x0a495103,
     278,  262, 0x0a495103,
     297,  287, 0x10495103,
     307,  287, 0x10495103,
     319,  315, 0x02495103,
     328,  315, 0x02495103,
     343,  338, 0x0049510b,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,

 // enums: name, flags, count, data
     338, 0x0,    2,  101,

 // enum data: key, value
     348, uint(EventEditor::CreateMode),
     359, uint(EventEditor::EditMode),

       0        // eod
};

static const char qt_meta_stringdata_EventEditor[] = {
    "EventEditor\0\0subjectChanged()\0"
    "locationChanged()\0startTimeChanged()\0"
    "endTimeChanged()\0folderIdChanged()\0"
    "accountIdChanged()\0modeChanged()\0"
    "eventKey\0loadEvent(bb::pim::calendar::EventKey)\0"
    "saveEvent()\0reset()\0downDown\0"
    "initializeFolderDropDown(bb::cascades::DropDown*)\0"
    "QString\0subject\0location\0QDateTime\0"
    "startTime\0endTime\0int\0folderId\0accountId\0"
    "Mode\0mode\0CreateMode\0EditMode\0"
};

void EventEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EventEditor *_t = static_cast<EventEditor *>(_o);
        switch (_id) {
        case 0: _t->subjectChanged(); break;
        case 1: _t->locationChanged(); break;
        case 2: _t->startTimeChanged(); break;
        case 3: _t->endTimeChanged(); break;
        case 4: _t->folderIdChanged(); break;
        case 5: _t->accountIdChanged(); break;
        case 6: _t->modeChanged(); break;
        case 7: _t->loadEvent((*reinterpret_cast< const bb::pim::calendar::EventKey(*)>(_a[1]))); break;
        case 8: _t->saveEvent(); break;
        case 9: _t->reset(); break;
        case 10: _t->initializeFolderDropDown((*reinterpret_cast< bb::cascades::DropDown*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData EventEditor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EventEditor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_EventEditor,
      qt_meta_data_EventEditor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EventEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EventEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EventEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EventEditor))
        return static_cast<void*>(const_cast< EventEditor*>(this));
    return QObject::qt_metacast(_clname);
}

int EventEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = subject(); break;
        case 1: *reinterpret_cast< QString*>(_v) = location(); break;
        case 2: *reinterpret_cast< QDateTime*>(_v) = startTime(); break;
        case 3: *reinterpret_cast< QDateTime*>(_v) = endTime(); break;
        case 4: *reinterpret_cast< int*>(_v) = folderId(); break;
        case 5: *reinterpret_cast< int*>(_v) = accountId(); break;
        case 6: *reinterpret_cast< Mode*>(_v) = mode(); break;
        }
        _id -= 7;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setSubject(*reinterpret_cast< QString*>(_v)); break;
        case 1: setLocation(*reinterpret_cast< QString*>(_v)); break;
        case 2: setStartTime(*reinterpret_cast< QDateTime*>(_v)); break;
        case 3: setEndTime(*reinterpret_cast< QDateTime*>(_v)); break;
        case 4: setFolderId(*reinterpret_cast< int*>(_v)); break;
        case 5: setAccountId(*reinterpret_cast< int*>(_v)); break;
        case 6: setMode(*reinterpret_cast< Mode*>(_v)); break;
        }
        _id -= 7;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void EventEditor::subjectChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void EventEditor::locationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void EventEditor::startTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void EventEditor::endTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void EventEditor::folderIdChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void EventEditor::accountIdChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void EventEditor::modeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}
QT_END_MOC_NAMESPACE

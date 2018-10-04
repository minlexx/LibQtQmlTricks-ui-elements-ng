#ifndef QMLVARPROPERTYHELPERS_H
#define QMLVARPROPERTYHELPERS_H

#include <QObject>

#define QML_PROPERTY_MEMBER_IMPL(PROP_NAME, VAR_TYPE, ARG_TYPE, RET_TYPE) \
    VAR_TYPE m_##PROP_NAME;

#define QML_PROPERTY_GETTER_IMPL(PROP_NAME, VAR_TYPE, ARG_TYPE, RET_TYPE) \
    RET_TYPE get_##PROP_NAME (void) const { \
        return m_##PROP_NAME; \
    }

#define QML_PROPERTY_SETTER_IMPL(PROP_NAME, VAR_TYPE, ARG_TYPE, RET_TYPE) \
    bool set_##PROP_NAME (ARG_TYPE PROP_NAME) { \
        bool ret = false; \
        if ((ret = (m_##PROP_NAME != PROP_NAME))) { \
            m_##PROP_NAME = PROP_NAME; \
            emit PROP_NAME##Changed (m_##PROP_NAME); \
        } \
        return ret; \
    }

#define QML_PROPERTY_NOTIFIER_IMPL(PROP_NAME, VAR_TYPE, ARG_TYPE, RET_TYPE) \
    void PROP_NAME##Changed (ARG_TYPE PROP_NAME);

#define QML_WRITABLE_PROPERTY_IMPL(PROP_NAME, VAR_TYPE, ARG_TYPE, RET_TYPE) \
    private: \
    Q_PROPERTY (VAR_TYPE PROP_NAME READ get_##PROP_NAME WRITE set_##PROP_NAME NOTIFY PROP_NAME##Changed) \
    private:        QML_PROPERTY_MEMBER_IMPL   (PROP_NAME, VAR_TYPE, ARG_TYPE, RET_TYPE) \
    public:         QML_PROPERTY_GETTER_IMPL   (PROP_NAME, VAR_TYPE, ARG_TYPE, RET_TYPE) \
    public Q_SLOTS: QML_PROPERTY_SETTER_IMPL   (PROP_NAME, VAR_TYPE, ARG_TYPE, RET_TYPE) \
    Q_SIGNALS:      QML_PROPERTY_NOTIFIER_IMPL (PROP_NAME, VAR_TYPE, ARG_TYPE, RET_TYPE) \
    private:

#define QML_READONLY_PROPERTY_IMPL(PROP_NAME, VAR_TYPE, ARG_TYPE, RET_TYPE) \
    private: \
    Q_PROPERTY (VAR_TYPE PROP_NAME READ get_##PROP_NAME NOTIFY PROP_NAME##Changed) \
    private:   QML_PROPERTY_MEMBER_IMPL   (PROP_NAME, VAR_TYPE, ARG_TYPE, RET_TYPE) \
    public:    QML_PROPERTY_GETTER_IMPL   (PROP_NAME, VAR_TYPE, ARG_TYPE, RET_TYPE) \
    public:    QML_PROPERTY_SETTER_IMPL   (PROP_NAME, VAR_TYPE, ARG_TYPE, RET_TYPE) \
    Q_SIGNALS: QML_PROPERTY_NOTIFIER_IMPL (PROP_NAME, VAR_TYPE, ARG_TYPE, RET_TYPE) \
    private:

#define QML_CONSTANT_PROPERTY_IMPL(PROP_NAME, VAR_TYPE, ARG_TYPE, RET_TYPE) \
    private: \
    Q_PROPERTY (VAR_TYPE PROP_NAME READ get_##PROP_NAME CONSTANT) \
    private: QML_PROPERTY_MEMBER_IMPL (PROP_NAME, VAR_TYPE, ARG_TYPE, RET_TYPE) \
    public:  QML_PROPERTY_GETTER_IMPL (PROP_NAME, VAR_TYPE, ARG_TYPE, RET_TYPE) \
    private:

#define QML_WRITABLE_VAR_PROPERTY(NAME, TYPE) \
    QML_WRITABLE_PROPERTY_IMPL(NAME, TYPE, const TYPE, TYPE)

#define QML_READONLY_VAR_PROPERTY(NAME, TYPE) \
    QML_READONLY_PROPERTY_IMPL(NAME, TYPE, const TYPE, TYPE)

#define QML_CONSTANT_VAR_PROPERTY(NAME, TYPE) \
    QML_CONSTANT_PROPERTY_IMPL(NAME, TYPE, const TYPE, TYPE)

#define QML_WRITABLE_CSTREF_PROPERTY(NAME, TYPE) \
    QML_WRITABLE_PROPERTY_IMPL(NAME, TYPE, const TYPE &, const TYPE &)

#define QML_READONLY_CSTREF_PROPERTY(NAME, TYPE) \
    QML_READONLY_PROPERTY_IMPL(NAME, TYPE, const TYPE &, const TYPE &)

#define QML_CONSTANT_CSTREF_PROPERTY(NAME, TYPE) \
    QML_CONSTANT_PROPERTY_IMPL(NAME, TYPE, const TYPE &, const TYPE &)

#define QML_WRITABLE_PTR_PROPERTY(NAME, TYPE) \
    QML_WRITABLE_PROPERTY_IMPL(NAME, TYPE *, TYPE *, TYPE *)

#define QML_READONLY_PTR_PROPERTY(NAME, TYPE) \
    QML_READONLY_PROPERTY_IMPL(NAME, TYPE *, TYPE *, TYPE *)

#define QML_CONSTANT_PTR_PROPERTY(NAME, TYPE) \
    QML_CONSTANT_PROPERTY_IMPL(NAME, TYPE *, TYPE *, TYPE *)


struct _QMLVARPROPERTYHELPERS_ { Q_GADGET }; // mock object

#endif // QMLVARPROPERTYHELPERS_H
// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#include <PyPrinterAttributes.h>
#include <ObserverToCallback.h>
#include <stdio.h>
#include <Py2and3Support.h>

// ****************************************************************************
// Module: PyPrinterAttributes
//
// Purpose:
//   This class contains the attributes used for controlling printers.
//
// Note:       Autogenerated by xml2python. Do not modify by hand!
//
// Programmer: xml2python
// Creation:   omitted
//
// ****************************************************************************

//
// This struct contains the Python type information and a PrinterAttributes.
//
struct PrinterAttributesObject
{
    PyObject_HEAD
    PrinterAttributes *data;
    bool        owns;
    PyObject   *parent;
};

//
// Internal prototypes
//
static PyObject *NewPrinterAttributes(int);
std::string
PyPrinterAttributes_ToString(const PrinterAttributes *atts, const char *prefix, const bool forLogging)
{
    std::string str;
    char tmpStr[1000];

    snprintf(tmpStr, 1000, "%sprinterName = \"%s\"\n", prefix, atts->GetPrinterName().c_str());
    str += tmpStr;
    snprintf(tmpStr, 1000, "%sprintProgram = \"%s\"\n", prefix, atts->GetPrintProgram().c_str());
    str += tmpStr;
    snprintf(tmpStr, 1000, "%sdocumentName = \"%s\"\n", prefix, atts->GetDocumentName().c_str());
    str += tmpStr;
    snprintf(tmpStr, 1000, "%screator = \"%s\"\n", prefix, atts->GetCreator().c_str());
    str += tmpStr;
    snprintf(tmpStr, 1000, "%snumCopies = %d\n", prefix, atts->GetNumCopies());
    str += tmpStr;
    if(atts->GetPortrait())
        snprintf(tmpStr, 1000, "%sportrait = 1\n", prefix);
    else
        snprintf(tmpStr, 1000, "%sportrait = 0\n", prefix);
    str += tmpStr;
    if(atts->GetPrintColor())
        snprintf(tmpStr, 1000, "%sprintColor = 1\n", prefix);
    else
        snprintf(tmpStr, 1000, "%sprintColor = 0\n", prefix);
    str += tmpStr;
    if(atts->GetOutputToFile())
        snprintf(tmpStr, 1000, "%soutputToFile = 1\n", prefix);
    else
        snprintf(tmpStr, 1000, "%soutputToFile = 0\n", prefix);
    str += tmpStr;
    snprintf(tmpStr, 1000, "%soutputToFileName = \"%s\"\n", prefix, atts->GetOutputToFileName().c_str());
    str += tmpStr;
    snprintf(tmpStr, 1000, "%spageSize = %d\n", prefix, atts->GetPageSize());
    str += tmpStr;
    return str;
}

static PyObject *
PrinterAttributes_Notify(PyObject *self, PyObject *args)
{
    PrinterAttributesObject *obj = (PrinterAttributesObject *)self;
    obj->data->Notify();
    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
PrinterAttributes_SetPrinterName(PyObject *self, PyObject *args)
{
    PrinterAttributesObject *obj = (PrinterAttributesObject *)self;

    PyObject *packaged_args = 0;

    // Handle args packaged as first member of a tuple of size one
    // if we think the unpackaged args matches our needs
    if (PySequence_Check(args) && PySequence_Size(args) == 1)
    {
        packaged_args = PySequence_GetItem(args, 0);
        if (PyUnicode_Check(packaged_args))
            args = packaged_args;
    }

    if (!PyUnicode_Check(args))
    {
        Py_XDECREF(packaged_args);
        return PyErr_Format(PyExc_TypeError, "arg is not a unicode string");
    }

    char const *val = PyUnicode_AsUTF8(args);
    std::string cval = std::string(val);

    if (val == 0 && PyErr_Occurred())
    {
        Py_XDECREF(packaged_args);
        PyErr_Clear();
        return PyErr_Format(PyExc_TypeError, "arg not interpretable as utf8 string");
    }

    Py_XDECREF(packaged_args);

    // Set the printerName in the object.
    obj->data->SetPrinterName(cval);

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
PrinterAttributes_GetPrinterName(PyObject *self, PyObject *args)
{
    PrinterAttributesObject *obj = (PrinterAttributesObject *)self;
    PyObject *retval = PyString_FromString(obj->data->GetPrinterName().c_str());
    return retval;
}

/*static*/ PyObject *
PrinterAttributes_SetPrintProgram(PyObject *self, PyObject *args)
{
    PrinterAttributesObject *obj = (PrinterAttributesObject *)self;

    PyObject *packaged_args = 0;

    // Handle args packaged as first member of a tuple of size one
    // if we think the unpackaged args matches our needs
    if (PySequence_Check(args) && PySequence_Size(args) == 1)
    {
        packaged_args = PySequence_GetItem(args, 0);
        if (PyUnicode_Check(packaged_args))
            args = packaged_args;
    }

    if (!PyUnicode_Check(args))
    {
        Py_XDECREF(packaged_args);
        return PyErr_Format(PyExc_TypeError, "arg is not a unicode string");
    }

    char const *val = PyUnicode_AsUTF8(args);
    std::string cval = std::string(val);

    if (val == 0 && PyErr_Occurred())
    {
        Py_XDECREF(packaged_args);
        PyErr_Clear();
        return PyErr_Format(PyExc_TypeError, "arg not interpretable as utf8 string");
    }

    Py_XDECREF(packaged_args);

    // Set the printProgram in the object.
    obj->data->SetPrintProgram(cval);

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
PrinterAttributes_GetPrintProgram(PyObject *self, PyObject *args)
{
    PrinterAttributesObject *obj = (PrinterAttributesObject *)self;
    PyObject *retval = PyString_FromString(obj->data->GetPrintProgram().c_str());
    return retval;
}

/*static*/ PyObject *
PrinterAttributes_SetDocumentName(PyObject *self, PyObject *args)
{
    PrinterAttributesObject *obj = (PrinterAttributesObject *)self;

    PyObject *packaged_args = 0;

    // Handle args packaged as first member of a tuple of size one
    // if we think the unpackaged args matches our needs
    if (PySequence_Check(args) && PySequence_Size(args) == 1)
    {
        packaged_args = PySequence_GetItem(args, 0);
        if (PyUnicode_Check(packaged_args))
            args = packaged_args;
    }

    if (!PyUnicode_Check(args))
    {
        Py_XDECREF(packaged_args);
        return PyErr_Format(PyExc_TypeError, "arg is not a unicode string");
    }

    char const *val = PyUnicode_AsUTF8(args);
    std::string cval = std::string(val);

    if (val == 0 && PyErr_Occurred())
    {
        Py_XDECREF(packaged_args);
        PyErr_Clear();
        return PyErr_Format(PyExc_TypeError, "arg not interpretable as utf8 string");
    }

    Py_XDECREF(packaged_args);

    // Set the documentName in the object.
    obj->data->SetDocumentName(cval);

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
PrinterAttributes_GetDocumentName(PyObject *self, PyObject *args)
{
    PrinterAttributesObject *obj = (PrinterAttributesObject *)self;
    PyObject *retval = PyString_FromString(obj->data->GetDocumentName().c_str());
    return retval;
}

/*static*/ PyObject *
PrinterAttributes_SetCreator(PyObject *self, PyObject *args)
{
    PrinterAttributesObject *obj = (PrinterAttributesObject *)self;

    PyObject *packaged_args = 0;

    // Handle args packaged as first member of a tuple of size one
    // if we think the unpackaged args matches our needs
    if (PySequence_Check(args) && PySequence_Size(args) == 1)
    {
        packaged_args = PySequence_GetItem(args, 0);
        if (PyUnicode_Check(packaged_args))
            args = packaged_args;
    }

    if (!PyUnicode_Check(args))
    {
        Py_XDECREF(packaged_args);
        return PyErr_Format(PyExc_TypeError, "arg is not a unicode string");
    }

    char const *val = PyUnicode_AsUTF8(args);
    std::string cval = std::string(val);

    if (val == 0 && PyErr_Occurred())
    {
        Py_XDECREF(packaged_args);
        PyErr_Clear();
        return PyErr_Format(PyExc_TypeError, "arg not interpretable as utf8 string");
    }

    Py_XDECREF(packaged_args);

    // Set the creator in the object.
    obj->data->SetCreator(cval);

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
PrinterAttributes_GetCreator(PyObject *self, PyObject *args)
{
    PrinterAttributesObject *obj = (PrinterAttributesObject *)self;
    PyObject *retval = PyString_FromString(obj->data->GetCreator().c_str());
    return retval;
}

/*static*/ PyObject *
PrinterAttributes_SetNumCopies(PyObject *self, PyObject *args)
{
    PrinterAttributesObject *obj = (PrinterAttributesObject *)self;

    PyObject *packaged_args = 0;

    // Handle args packaged into a tuple of size one
    // if we think the unpackaged args matches our needs
    if (PySequence_Check(args) && PySequence_Size(args) == 1)
    {
        packaged_args = PySequence_GetItem(args, 0);
        if (PyNumber_Check(packaged_args))
            args = packaged_args;
    }

    if (PySequence_Check(args))
    {
        Py_XDECREF(packaged_args);
        return PyErr_Format(PyExc_TypeError, "expecting a single number arg");
    }

    if (!PyNumber_Check(args))
    {
        Py_XDECREF(packaged_args);
        return PyErr_Format(PyExc_TypeError, "arg is not a number type");
    }

    long val = PyLong_AsLong(args);
    int cval = int(val);

    if (val == -1 && PyErr_Occurred())
    {
        Py_XDECREF(packaged_args);
        PyErr_Clear();
        return PyErr_Format(PyExc_TypeError, "arg not interpretable as C++ int");
    }
    if (fabs(double(val))>1.5E-7 && fabs((double(long(cval))-double(val))/double(val))>1.5E-7)
    {
        Py_XDECREF(packaged_args);
        return PyErr_Format(PyExc_ValueError, "arg not interpretable as C++ int");
    }

    Py_XDECREF(packaged_args);

    // Set the numCopies in the object.
    obj->data->SetNumCopies(cval);

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
PrinterAttributes_GetNumCopies(PyObject *self, PyObject *args)
{
    PrinterAttributesObject *obj = (PrinterAttributesObject *)self;
    PyObject *retval = PyInt_FromLong(long(obj->data->GetNumCopies()));
    return retval;
}

/*static*/ PyObject *
PrinterAttributes_SetPortrait(PyObject *self, PyObject *args)
{
    PrinterAttributesObject *obj = (PrinterAttributesObject *)self;

    PyObject *packaged_args = 0;

    // Handle args packaged into a tuple of size one
    // if we think the unpackaged args matches our needs
    if (PySequence_Check(args) && PySequence_Size(args) == 1)
    {
        packaged_args = PySequence_GetItem(args, 0);
        if (PyNumber_Check(packaged_args))
            args = packaged_args;
    }

    if (PySequence_Check(args))
    {
        Py_XDECREF(packaged_args);
        return PyErr_Format(PyExc_TypeError, "expecting a single number arg");
    }

    if (!PyNumber_Check(args))
    {
        Py_XDECREF(packaged_args);
        return PyErr_Format(PyExc_TypeError, "arg is not a number type");
    }

    long val = PyLong_AsLong(args);
    bool cval = bool(val);

    if (val == -1 && PyErr_Occurred())
    {
        Py_XDECREF(packaged_args);
        PyErr_Clear();
        return PyErr_Format(PyExc_TypeError, "arg not interpretable as C++ bool");
    }
    if (fabs(double(val))>1.5E-7 && fabs((double(long(cval))-double(val))/double(val))>1.5E-7)
    {
        Py_XDECREF(packaged_args);
        return PyErr_Format(PyExc_ValueError, "arg not interpretable as C++ bool");
    }

    Py_XDECREF(packaged_args);

    // Set the portrait in the object.
    obj->data->SetPortrait(cval);

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
PrinterAttributes_GetPortrait(PyObject *self, PyObject *args)
{
    PrinterAttributesObject *obj = (PrinterAttributesObject *)self;
    PyObject *retval = PyInt_FromLong(obj->data->GetPortrait()?1L:0L);
    return retval;
}

/*static*/ PyObject *
PrinterAttributes_SetPrintColor(PyObject *self, PyObject *args)
{
    PrinterAttributesObject *obj = (PrinterAttributesObject *)self;

    PyObject *packaged_args = 0;

    // Handle args packaged into a tuple of size one
    // if we think the unpackaged args matches our needs
    if (PySequence_Check(args) && PySequence_Size(args) == 1)
    {
        packaged_args = PySequence_GetItem(args, 0);
        if (PyNumber_Check(packaged_args))
            args = packaged_args;
    }

    if (PySequence_Check(args))
    {
        Py_XDECREF(packaged_args);
        return PyErr_Format(PyExc_TypeError, "expecting a single number arg");
    }

    if (!PyNumber_Check(args))
    {
        Py_XDECREF(packaged_args);
        return PyErr_Format(PyExc_TypeError, "arg is not a number type");
    }

    long val = PyLong_AsLong(args);
    bool cval = bool(val);

    if (val == -1 && PyErr_Occurred())
    {
        Py_XDECREF(packaged_args);
        PyErr_Clear();
        return PyErr_Format(PyExc_TypeError, "arg not interpretable as C++ bool");
    }
    if (fabs(double(val))>1.5E-7 && fabs((double(long(cval))-double(val))/double(val))>1.5E-7)
    {
        Py_XDECREF(packaged_args);
        return PyErr_Format(PyExc_ValueError, "arg not interpretable as C++ bool");
    }

    Py_XDECREF(packaged_args);

    // Set the printColor in the object.
    obj->data->SetPrintColor(cval);

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
PrinterAttributes_GetPrintColor(PyObject *self, PyObject *args)
{
    PrinterAttributesObject *obj = (PrinterAttributesObject *)self;
    PyObject *retval = PyInt_FromLong(obj->data->GetPrintColor()?1L:0L);
    return retval;
}

/*static*/ PyObject *
PrinterAttributes_SetOutputToFile(PyObject *self, PyObject *args)
{
    PrinterAttributesObject *obj = (PrinterAttributesObject *)self;

    PyObject *packaged_args = 0;

    // Handle args packaged into a tuple of size one
    // if we think the unpackaged args matches our needs
    if (PySequence_Check(args) && PySequence_Size(args) == 1)
    {
        packaged_args = PySequence_GetItem(args, 0);
        if (PyNumber_Check(packaged_args))
            args = packaged_args;
    }

    if (PySequence_Check(args))
    {
        Py_XDECREF(packaged_args);
        return PyErr_Format(PyExc_TypeError, "expecting a single number arg");
    }

    if (!PyNumber_Check(args))
    {
        Py_XDECREF(packaged_args);
        return PyErr_Format(PyExc_TypeError, "arg is not a number type");
    }

    long val = PyLong_AsLong(args);
    bool cval = bool(val);

    if (val == -1 && PyErr_Occurred())
    {
        Py_XDECREF(packaged_args);
        PyErr_Clear();
        return PyErr_Format(PyExc_TypeError, "arg not interpretable as C++ bool");
    }
    if (fabs(double(val))>1.5E-7 && fabs((double(long(cval))-double(val))/double(val))>1.5E-7)
    {
        Py_XDECREF(packaged_args);
        return PyErr_Format(PyExc_ValueError, "arg not interpretable as C++ bool");
    }

    Py_XDECREF(packaged_args);

    // Set the outputToFile in the object.
    obj->data->SetOutputToFile(cval);

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
PrinterAttributes_GetOutputToFile(PyObject *self, PyObject *args)
{
    PrinterAttributesObject *obj = (PrinterAttributesObject *)self;
    PyObject *retval = PyInt_FromLong(obj->data->GetOutputToFile()?1L:0L);
    return retval;
}

/*static*/ PyObject *
PrinterAttributes_SetOutputToFileName(PyObject *self, PyObject *args)
{
    PrinterAttributesObject *obj = (PrinterAttributesObject *)self;

    PyObject *packaged_args = 0;

    // Handle args packaged as first member of a tuple of size one
    // if we think the unpackaged args matches our needs
    if (PySequence_Check(args) && PySequence_Size(args) == 1)
    {
        packaged_args = PySequence_GetItem(args, 0);
        if (PyUnicode_Check(packaged_args))
            args = packaged_args;
    }

    if (!PyUnicode_Check(args))
    {
        Py_XDECREF(packaged_args);
        return PyErr_Format(PyExc_TypeError, "arg is not a unicode string");
    }

    char const *val = PyUnicode_AsUTF8(args);
    std::string cval = std::string(val);

    if (val == 0 && PyErr_Occurred())
    {
        Py_XDECREF(packaged_args);
        PyErr_Clear();
        return PyErr_Format(PyExc_TypeError, "arg not interpretable as utf8 string");
    }

    Py_XDECREF(packaged_args);

    // Set the outputToFileName in the object.
    obj->data->SetOutputToFileName(cval);

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
PrinterAttributes_GetOutputToFileName(PyObject *self, PyObject *args)
{
    PrinterAttributesObject *obj = (PrinterAttributesObject *)self;
    PyObject *retval = PyString_FromString(obj->data->GetOutputToFileName().c_str());
    return retval;
}

/*static*/ PyObject *
PrinterAttributes_SetPageSize(PyObject *self, PyObject *args)
{
    PrinterAttributesObject *obj = (PrinterAttributesObject *)self;

    PyObject *packaged_args = 0;

    // Handle args packaged into a tuple of size one
    // if we think the unpackaged args matches our needs
    if (PySequence_Check(args) && PySequence_Size(args) == 1)
    {
        packaged_args = PySequence_GetItem(args, 0);
        if (PyNumber_Check(packaged_args))
            args = packaged_args;
    }

    if (PySequence_Check(args))
    {
        Py_XDECREF(packaged_args);
        return PyErr_Format(PyExc_TypeError, "expecting a single number arg");
    }

    if (!PyNumber_Check(args))
    {
        Py_XDECREF(packaged_args);
        return PyErr_Format(PyExc_TypeError, "arg is not a number type");
    }

    long val = PyLong_AsLong(args);
    int cval = int(val);

    if (val == -1 && PyErr_Occurred())
    {
        Py_XDECREF(packaged_args);
        PyErr_Clear();
        return PyErr_Format(PyExc_TypeError, "arg not interpretable as C++ int");
    }
    if (fabs(double(val))>1.5E-7 && fabs((double(long(cval))-double(val))/double(val))>1.5E-7)
    {
        Py_XDECREF(packaged_args);
        return PyErr_Format(PyExc_ValueError, "arg not interpretable as C++ int");
    }

    Py_XDECREF(packaged_args);

    // Set the pageSize in the object.
    obj->data->SetPageSize(cval);

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
PrinterAttributes_GetPageSize(PyObject *self, PyObject *args)
{
    PrinterAttributesObject *obj = (PrinterAttributesObject *)self;
    PyObject *retval = PyInt_FromLong(long(obj->data->GetPageSize()));
    return retval;
}



PyMethodDef PyPrinterAttributes_methods[PRINTERATTRIBUTES_NMETH] = {
    {"Notify", PrinterAttributes_Notify, METH_VARARGS},
    {"SetPrinterName", PrinterAttributes_SetPrinterName, METH_VARARGS},
    {"GetPrinterName", PrinterAttributes_GetPrinterName, METH_VARARGS},
    {"SetPrintProgram", PrinterAttributes_SetPrintProgram, METH_VARARGS},
    {"GetPrintProgram", PrinterAttributes_GetPrintProgram, METH_VARARGS},
    {"SetDocumentName", PrinterAttributes_SetDocumentName, METH_VARARGS},
    {"GetDocumentName", PrinterAttributes_GetDocumentName, METH_VARARGS},
    {"SetCreator", PrinterAttributes_SetCreator, METH_VARARGS},
    {"GetCreator", PrinterAttributes_GetCreator, METH_VARARGS},
    {"SetNumCopies", PrinterAttributes_SetNumCopies, METH_VARARGS},
    {"GetNumCopies", PrinterAttributes_GetNumCopies, METH_VARARGS},
    {"SetPortrait", PrinterAttributes_SetPortrait, METH_VARARGS},
    {"GetPortrait", PrinterAttributes_GetPortrait, METH_VARARGS},
    {"SetPrintColor", PrinterAttributes_SetPrintColor, METH_VARARGS},
    {"GetPrintColor", PrinterAttributes_GetPrintColor, METH_VARARGS},
    {"SetOutputToFile", PrinterAttributes_SetOutputToFile, METH_VARARGS},
    {"GetOutputToFile", PrinterAttributes_GetOutputToFile, METH_VARARGS},
    {"SetOutputToFileName", PrinterAttributes_SetOutputToFileName, METH_VARARGS},
    {"GetOutputToFileName", PrinterAttributes_GetOutputToFileName, METH_VARARGS},
    {"SetPageSize", PrinterAttributes_SetPageSize, METH_VARARGS},
    {"GetPageSize", PrinterAttributes_GetPageSize, METH_VARARGS},
    {NULL, NULL}
};

//
// Type functions
//

static void
PrinterAttributes_dealloc(PyObject *v)
{
   PrinterAttributesObject *obj = (PrinterAttributesObject *)v;
   if(obj->parent != 0)
       Py_DECREF(obj->parent);
   if(obj->owns)
       delete obj->data;
}

static PyObject *PrinterAttributes_richcompare(PyObject *self, PyObject *other, int op);
PyObject *
PyPrinterAttributes_getattr(PyObject *self, char *name)
{
    if(strcmp(name, "printerName") == 0)
        return PrinterAttributes_GetPrinterName(self, NULL);
    if(strcmp(name, "printProgram") == 0)
        return PrinterAttributes_GetPrintProgram(self, NULL);
    if(strcmp(name, "documentName") == 0)
        return PrinterAttributes_GetDocumentName(self, NULL);
    if(strcmp(name, "creator") == 0)
        return PrinterAttributes_GetCreator(self, NULL);
    if(strcmp(name, "numCopies") == 0)
        return PrinterAttributes_GetNumCopies(self, NULL);
    if(strcmp(name, "portrait") == 0)
        return PrinterAttributes_GetPortrait(self, NULL);
    if(strcmp(name, "printColor") == 0)
        return PrinterAttributes_GetPrintColor(self, NULL);
    if(strcmp(name, "outputToFile") == 0)
        return PrinterAttributes_GetOutputToFile(self, NULL);
    if(strcmp(name, "outputToFileName") == 0)
        return PrinterAttributes_GetOutputToFileName(self, NULL);
    if(strcmp(name, "pageSize") == 0)
        return PrinterAttributes_GetPageSize(self, NULL);


    // Add a __dict__ answer so that dir() works
    if (!strcmp(name, "__dict__"))
    {
        PyObject *result = PyDict_New();
        for (int i = 0; PyPrinterAttributes_methods[i].ml_meth; i++)
            PyDict_SetItem(result,
                PyString_FromString(PyPrinterAttributes_methods[i].ml_name),
                PyString_FromString(PyPrinterAttributes_methods[i].ml_name));
        return result;
    }

    return Py_FindMethod(PyPrinterAttributes_methods, self, name);
}

int
PyPrinterAttributes_setattr(PyObject *self, char *name, PyObject *args)
{
    PyObject NULL_PY_OBJ;
    PyObject *obj = &NULL_PY_OBJ;

    if(strcmp(name, "printerName") == 0)
        obj = PrinterAttributes_SetPrinterName(self, args);
    else if(strcmp(name, "printProgram") == 0)
        obj = PrinterAttributes_SetPrintProgram(self, args);
    else if(strcmp(name, "documentName") == 0)
        obj = PrinterAttributes_SetDocumentName(self, args);
    else if(strcmp(name, "creator") == 0)
        obj = PrinterAttributes_SetCreator(self, args);
    else if(strcmp(name, "numCopies") == 0)
        obj = PrinterAttributes_SetNumCopies(self, args);
    else if(strcmp(name, "portrait") == 0)
        obj = PrinterAttributes_SetPortrait(self, args);
    else if(strcmp(name, "printColor") == 0)
        obj = PrinterAttributes_SetPrintColor(self, args);
    else if(strcmp(name, "outputToFile") == 0)
        obj = PrinterAttributes_SetOutputToFile(self, args);
    else if(strcmp(name, "outputToFileName") == 0)
        obj = PrinterAttributes_SetOutputToFileName(self, args);
    else if(strcmp(name, "pageSize") == 0)
        obj = PrinterAttributes_SetPageSize(self, args);

    if (obj != NULL && obj != &NULL_PY_OBJ)
        Py_DECREF(obj);

    if (obj == &NULL_PY_OBJ)
    {
        obj = NULL;
        PyErr_Format(PyExc_NameError, "name '%s' is not defined", name);
    }
    else if (obj == NULL && !PyErr_Occurred())
        PyErr_Format(PyExc_RuntimeError, "unknown problem with '%s'", name);

    return (obj != NULL) ? 0 : -1;
}

static int
PrinterAttributes_print(PyObject *v, FILE *fp, int flags)
{
    PrinterAttributesObject *obj = (PrinterAttributesObject *)v;
    fprintf(fp, "%s", PyPrinterAttributes_ToString(obj->data, "",false).c_str());
    return 0;
}

PyObject *
PrinterAttributes_str(PyObject *v)
{
    PrinterAttributesObject *obj = (PrinterAttributesObject *)v;
    return PyString_FromString(PyPrinterAttributes_ToString(obj->data,"", false).c_str());
}

//
// The doc string for the class.
//
#if PY_MAJOR_VERSION > 2 || (PY_MAJOR_VERSION == 2 && PY_MINOR_VERSION >= 5)
static const char *PrinterAttributes_Purpose = "This class contains the attributes used for controlling printers.";
#else
static char *PrinterAttributes_Purpose = "This class contains the attributes used for controlling printers.";
#endif

//
// Python Type Struct Def Macro from Py2and3Support.h
//
//         VISIT_PY_TYPE_OBJ( VPY_TYPE,
//                            VPY_NAME,
//                            VPY_OBJECT,
//                            VPY_DEALLOC,
//                            VPY_PRINT,
//                            VPY_GETATTR,
//                            VPY_SETATTR,
//                            VPY_STR,
//                            VPY_PURPOSE,
//                            VPY_RICHCOMP,
//                            VPY_AS_NUMBER)

//
// The type description structure
//

VISIT_PY_TYPE_OBJ(PrinterAttributesType,         \
                  "PrinterAttributes",           \
                  PrinterAttributesObject,       \
                  PrinterAttributes_dealloc,     \
                  PrinterAttributes_print,       \
                  PyPrinterAttributes_getattr,   \
                  PyPrinterAttributes_setattr,   \
                  PrinterAttributes_str,         \
                  PrinterAttributes_Purpose,     \
                  PrinterAttributes_richcompare, \
                  0); /* as_number*/

//
// Helper function for comparing.
//
static PyObject *
PrinterAttributes_richcompare(PyObject *self, PyObject *other, int op)
{
    // only compare against the same type 
    if ( Py_TYPE(self) != &PrinterAttributesType
         || Py_TYPE(other) != &PrinterAttributesType)
    {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }

    PyObject *res = NULL;
    PrinterAttributes *a = ((PrinterAttributesObject *)self)->data;
    PrinterAttributes *b = ((PrinterAttributesObject *)other)->data;

    switch (op)
    {
       case Py_EQ:
           res = (*a == *b) ? Py_True : Py_False;
           break;
       case Py_NE:
           res = (*a != *b) ? Py_True : Py_False;
           break;
       default:
           res = Py_NotImplemented;
           break;
    }

    Py_INCREF(res);
    return res;
}

//
// Helper functions for object allocation.
//

static PrinterAttributes *defaultAtts = 0;
static PrinterAttributes *currentAtts = 0;

static PyObject *
NewPrinterAttributes(int useCurrent)
{
    PrinterAttributesObject *newObject;
    newObject = PyObject_NEW(PrinterAttributesObject, &PrinterAttributesType);
    if(newObject == NULL)
        return NULL;
    if(useCurrent && currentAtts != 0)
        newObject->data = new PrinterAttributes(*currentAtts);
    else if(defaultAtts != 0)
        newObject->data = new PrinterAttributes(*defaultAtts);
    else
        newObject->data = new PrinterAttributes;
    newObject->owns = true;
    newObject->parent = 0;
    return (PyObject *)newObject;
}

static PyObject *
WrapPrinterAttributes(const PrinterAttributes *attr)
{
    PrinterAttributesObject *newObject;
    newObject = PyObject_NEW(PrinterAttributesObject, &PrinterAttributesType);
    if(newObject == NULL)
        return NULL;
    newObject->data = (PrinterAttributes *)attr;
    newObject->owns = false;
    newObject->parent = 0;
    return (PyObject *)newObject;
}

///////////////////////////////////////////////////////////////////////////////
//
// Interface that is exposed to the VisIt module.
//
///////////////////////////////////////////////////////////////////////////////

PyObject *
PrinterAttributes_new(PyObject *self, PyObject *args)
{
    int useCurrent = 0;
    if (!PyArg_ParseTuple(args, "i", &useCurrent))
    {
        if (!PyArg_ParseTuple(args, ""))
            return NULL;
        else
            PyErr_Clear();
    }

    return (PyObject *)NewPrinterAttributes(useCurrent);
}

//
// Plugin method table. These methods are added to the visitmodule's methods.
//
static PyMethodDef PrinterAttributesMethods[] = {
    {"PrinterAttributes", PrinterAttributes_new, METH_VARARGS},
    {NULL,      NULL}        /* Sentinel */
};

static Observer *PrinterAttributesObserver = 0;

std::string
PyPrinterAttributes_GetLogString()
{
    std::string s("PrinterAtts = PrinterAttributes()\n");
    if(currentAtts != 0)
        s += PyPrinterAttributes_ToString(currentAtts, "PrinterAtts.", true);
    return s;
}

static void
PyPrinterAttributes_CallLogRoutine(Subject *subj, void *data)
{
    typedef void (*logCallback)(const std::string &);
    logCallback cb = (logCallback)data;

    if(cb != 0)
    {
        std::string s("PrinterAtts = PrinterAttributes()\n");
        s += PyPrinterAttributes_ToString(currentAtts, "PrinterAtts.", true);
        cb(s);
    }
}

void
PyPrinterAttributes_StartUp(PrinterAttributes *subj, void *data)
{
    if(subj == 0)
        return;

    currentAtts = subj;
    PyPrinterAttributes_SetDefaults(subj);

    //
    // Create the observer that will be notified when the attributes change.
    //
    if(PrinterAttributesObserver == 0)
    {
        PrinterAttributesObserver = new ObserverToCallback(subj,
            PyPrinterAttributes_CallLogRoutine, (void *)data);
    }

}

void
PyPrinterAttributes_CloseDown()
{
    delete defaultAtts;
    defaultAtts = 0;
    delete PrinterAttributesObserver;
    PrinterAttributesObserver = 0;
}

PyMethodDef *
PyPrinterAttributes_GetMethodTable(int *nMethods)
{
    *nMethods = 1;
    return PrinterAttributesMethods;
}

bool
PyPrinterAttributes_Check(PyObject *obj)
{
    return (obj->ob_type == &PrinterAttributesType);
}

PrinterAttributes *
PyPrinterAttributes_FromPyObject(PyObject *obj)
{
    PrinterAttributesObject *obj2 = (PrinterAttributesObject *)obj;
    return obj2->data;
}

PyObject *
PyPrinterAttributes_New()
{
    return NewPrinterAttributes(0);
}

PyObject *
PyPrinterAttributes_Wrap(const PrinterAttributes *attr)
{
    return WrapPrinterAttributes(attr);
}

void
PyPrinterAttributes_SetParent(PyObject *obj, PyObject *parent)
{
    PrinterAttributesObject *obj2 = (PrinterAttributesObject *)obj;
    obj2->parent = parent;
}

void
PyPrinterAttributes_SetDefaults(const PrinterAttributes *atts)
{
    if(defaultAtts)
        delete defaultAtts;

    defaultAtts = new PrinterAttributes(*atts);
}


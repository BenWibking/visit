// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ****************************************************************************
//  avtHTGFileFormat.C
// ****************************************************************************

#include <avtHTGFileFormat.h>

#include <string>

#include <vtkFloatArray.h>
#include <vtkRectilinearGrid.h>

#include <avtDatabaseMetaData.h>

#include <DBOptionsAttributes.h>
#include <Expression.h>

#include <VisItException.h>
#include <InvalidVariableException.h>


using     std::string;


// ****************************************************************************
//  Method: avtHTGFileFormat constructor
//
//  Programmer: brugger -- generated by xml2avt
//  Creation:   Mon May 1 15:28:30 PST 2023
//
// ****************************************************************************

avtHTGFileFormat::avtHTGFileFormat(const char *filename, const DBOptionsAttributes *readOpts)
    : avtSTMDFileFormat(&filename, 1)
{
}


// ****************************************************************************
//  Method: avtHTGFileFormat::FreeUpResources
//
//  Purpose:
//      When VisIt is done focusing on a particular timestep, it asks that
//      timestep to free up any resources (memory, file descriptors) that
//      it has associated with it.  This method is the mechanism for doing
//      that.
//
//  Programmer: brugger -- generated by xml2avt
//  Creation:   Mon May 1 15:28:30 PST 2023
//
// ****************************************************************************

void
avtHTGFileFormat::FreeUpResources(void)
{
}


// ****************************************************************************
//  Method: avtHTGFileFormat::PopulateDatabaseMetaData
//
//  Purpose:
//      This database meta-data object is like a table of contents for the
//      file.  By populating it, you are telling the rest of VisIt what
//      information it can request from you.
//
//  Programmer: brugger -- generated by xml2avt
//  Creation:   Mon May 1 15:28:30 PST 2023
//
// ****************************************************************************

void
avtHTGFileFormat::PopulateDatabaseMetaData(avtDatabaseMetaData *md)
{
    EXCEPTION1(VisItException, "The HTG database plugin can only export files.")
}


// ****************************************************************************
//  Method: avtHTGFileFormat::GetMesh
//
//  Purpose:
//      Gets the mesh associated with this file.  The mesh is returned as a
//      derived type of vtkDataSet (ie vtkRectilinearGrid, vtkStructuredGrid,
//      vtkUnstructuredGrid, etc).
//
//  Arguments:
//      domain      The index of the domain.  If there are NDomains, this
//                  value is guaranteed to be between 0 and NDomains-1,
//                  regardless of block origin.
//      meshname    The name of the mesh of interest.  This can be ignored if
//                  there is only one mesh.
//
//  Programmer: brugger -- generated by xml2avt
//  Creation:   Mon May 1 15:28:30 PST 2023
//
// ****************************************************************************

vtkDataSet *
avtHTGFileFormat::GetMesh(int domain, const char *meshname)
{
    return NULL;
}


// ****************************************************************************
//  Method: avtHTGFileFormat::GetVar
//
//  Purpose:
//      Gets a scalar variable associated with this file.  Although VTK has
//      support for many different types, the best bet is vtkFloatArray, since
//      that is supported everywhere through VisIt.
//
//  Arguments:
//      domain     The index of the domain.  If there are NDomains, this
//                 value is guaranteed to be between 0 and NDomains-1,
//                 regardless of block origin.
//      varname    The name of the variable requested.
//
//  Programmer: brugger -- generated by xml2avt
//  Creation:   Mon May 1 15:28:30 PST 2023
//
// ****************************************************************************

vtkDataArray *
avtHTGFileFormat::GetVar(int domain, const char *varname)
{
    return NULL;
}


// ****************************************************************************
//  Method: avtHTGFileFormat::GetVectorVar
//
//  Purpose:
//      Gets a vector variable associated with this file.  Although VTK has
//      support for many different types, the best bet is vtkFloatArray, since
//      that is supported everywhere through VisIt.
//
//  Arguments:
//      domain     The index of the domain.  If there are NDomains, this
//                 value is guaranteed to be between 0 and NDomains-1,
//                 regardless of block origin.
//      varname    The name of the variable requested.
//
//  Programmer: brugger -- generated by xml2avt
//  Creation:   Mon May 1 15:28:30 PST 2023
//
// ****************************************************************************

vtkDataArray *
avtHTGFileFormat::GetVectorVar(int domain, const char *varname)
{
    return NULL;
}

// ****************************************************************************
//                               TSurfPluginInfo.h
// ****************************************************************************

#ifndef TSURF_PLUGIN_INFO_H
#define TSURF_PLUGIN_INFO_H
#include <DatabasePluginInfo.h>
#include <database_plugin_exports.h>

class avtDatabase;
class avtDatabaseWriter;

// ****************************************************************************
//  Class: TSurfDatabasePluginInfo
//
//  Purpose:
//    Classes that provide all the information about the TSurf plugin.
//    Portions are separated into pieces relevant to the appropriate
//    components of VisIt.
//
//  Programmer: whitlocb -- generated by xml2info
//  Creation:   Tue Apr 11 10:26:45 PDT 2006
//
//  Modifications:
//
// ****************************************************************************

class TSurfGeneralPluginInfo : public virtual GeneralDatabasePluginInfo
{
  public:
    virtual char *GetName() const;
    virtual char *GetVersion() const;
    virtual char *GetID() const;
    virtual bool  EnabledByDefault() const;
    virtual bool  HasWriter() const;
};

class TSurfCommonPluginInfo : public virtual CommonDatabasePluginInfo, public virtual TSurfGeneralPluginInfo
{
  public:
    virtual DatabaseType              GetDatabaseType();
    virtual std::vector<std::string>  GetDefaultExtensions();
    virtual avtDatabase              *SetupDatabase(const char * const *list,
                                                    int nList, int nBlock);
};

class TSurfMDServerPluginInfo : public virtual MDServerDatabasePluginInfo, public virtual TSurfCommonPluginInfo
{
  public:
    // this makes compilers happy... remove if we ever have functions here
    virtual void dummy();
};

class TSurfEnginePluginInfo : public virtual EngineDatabasePluginInfo, public virtual TSurfCommonPluginInfo
{
  public:
    virtual avtDatabaseWriter        *GetWriter(void);
};

#endif

/*****************************************************************************
*
* Copyright (c) 2000 - 2007, The Regents of the University of California
* Produced at the Lawrence Livermore National Laboratory
* All rights reserved.
*
* This file is part of VisIt. For details, see http://www.llnl.gov/visit/. The
* full copyright notice is contained in the file COPYRIGHT located at the root
* of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
*
* Redistribution  and  use  in  source  and  binary  forms,  with  or  without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of  source code must  retain the above  copyright notice,
*    this list of conditions and the disclaimer below.
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
*    documentation and/or materials provided with the distribution.
*  - Neither the name of the UC/LLNL nor  the names of its contributors may be
*    used to  endorse or  promote products derived from  this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED.  IN  NO  EVENT  SHALL  THE  REGENTS  OF  THE  UNIVERSITY OF
* CALIFORNIA, THE U.S.  DEPARTMENT  OF  ENERGY OR CONTRIBUTORS BE  LIABLE  FOR
* ANY  DIRECT,  INDIRECT,  INCIDENTAL,  SPECIAL,  EXEMPLARY,  OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

#ifndef LIGHTATTRIBUTES_H
#define LIGHTATTRIBUTES_H
#include <state_exports.h>
#include <string>
#include <AttributeSubject.h>
#include <ColorAttribute.h>

// ****************************************************************************
// Class: LightAttributes
//
// Purpose:
//    This class is a light in a light list.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   Wed May 17 09:05:48 PDT 2006
//
// Modifications:
//   
// ****************************************************************************

class STATE_API LightAttributes : public AttributeSubject
{
public:
    enum LightType
    {
        Ambient,
        Object,
        Camera
    };

    LightAttributes();
    LightAttributes(const LightAttributes &obj);
    virtual ~LightAttributes();

    virtual LightAttributes& operator = (const LightAttributes &obj);
    virtual bool operator == (const LightAttributes &obj) const;
    virtual bool operator != (const LightAttributes &obj) const;

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectDirection();
    void SelectColor();

    // Property setting methods
    void SetEnabledFlagCanBeToggled(bool enabledFlagCanBeToggled_);
    void SetEnabledFlag(bool enabledFlag_);
    void SetType(LightType type_);
    void SetDirection(const double *direction_);
    void SetColor(const ColorAttribute &color_);
    void SetBrightness(double brightness_);

    // Property getting methods
    bool                 GetEnabledFlagCanBeToggled() const;
    bool                 GetEnabledFlag() const;
    LightType            GetType() const;
    const double         *GetDirection() const;
          double         *GetDirection();
    const ColorAttribute &GetColor() const;
          ColorAttribute &GetColor();
    double               GetBrightness() const;

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);

    // Enum conversion functions
    static std::string LightType_ToString(LightType);
    static bool LightType_FromString(const std::string &, LightType &);
protected:
    static std::string LightType_ToString(int);
public:

    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

private:
    bool           enabledFlagCanBeToggled;
    bool           enabledFlag;
    int            type;
    double         direction[3];
    ColorAttribute color;
    double         brightness;
};

#endif

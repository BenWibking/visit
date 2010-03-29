// ***************************************************************************
//
// Copyright (c) 2000 - 2010, Lawrence Livermore National Security, LLC
// Produced at the Lawrence Livermore National Laboratory
// LLNL-CODE-400124
// All rights reserved.
//
// This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
// full copyright notice is contained in the file COPYRIGHT located at the root
// of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
//
// Redistribution  and  use  in  source  and  binary  forms,  with  or  without
// modification, are permitted provided that the following conditions are met:
//
//  - Redistributions of  source code must  retain the above  copyright notice,
//    this list of conditions and the disclaimer below.
//  - Redistributions in binary form must reproduce the above copyright notice,
//    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
//    documentation and/or other materials provided with the distribution.
//  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
//    be used to endorse or promote products derived from this software without
//    specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
// ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
// LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
// DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
// SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
// CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
// LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
// OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
// DAMAGE.
//
// ***************************************************************************

package llnl.visit;


// ****************************************************************************
// Class: FontAttributes
//
// Purpose:
//    Describes font properties that we can set through VTK
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class FontAttributes extends AttributeSubject
{
    private static int numAdditionalAttributes = 6;

    // Enum values
    public final static int FONTNAME_ARIAL = 0;
    public final static int FONTNAME_COURIER = 1;
    public final static int FONTNAME_TIMES = 2;


    public FontAttributes()
    {
        super(numAdditionalAttributes);

        font = FONTNAME_ARIAL;
        scale = 1;
        useForegroundColor = true;
        color = new ColorAttribute(0, 0, 0);
        bold = false;
        italic = false;
    }

    public FontAttributes(int nMoreFields)
    {
        super(numAdditionalAttributes + nMoreFields);

        font = FONTNAME_ARIAL;
        scale = 1;
        useForegroundColor = true;
        color = new ColorAttribute(0, 0, 0);
        bold = false;
        italic = false;
    }

    public FontAttributes(FontAttributes obj)
    {
        super(numAdditionalAttributes);

        font = obj.font;
        scale = obj.scale;
        useForegroundColor = obj.useForegroundColor;
        color = new ColorAttribute(obj.color);
        bold = obj.bold;
        italic = obj.italic;

        SelectAll();
    }

    public int Offset()
    {
        return super.Offset() + super.GetNumAdditionalAttributes();
    }

    public int GetNumAdditionalAttributes()
    {
        return numAdditionalAttributes;
    }

    public boolean equals(FontAttributes obj)
    {
        // Create the return value
        return ((font == obj.font) &&
                (scale == obj.scale) &&
                (useForegroundColor == obj.useForegroundColor) &&
                (color == obj.color) &&
                (bold == obj.bold) &&
                (italic == obj.italic));
    }

    // Property setting methods
    public void SetFont(int font_)
    {
        font = font_;
        Select(0);
    }

    public void SetScale(double scale_)
    {
        scale = scale_;
        Select(1);
    }

    public void SetUseForegroundColor(boolean useForegroundColor_)
    {
        useForegroundColor = useForegroundColor_;
        Select(2);
    }

    public void SetColor(ColorAttribute color_)
    {
        color = color_;
        Select(3);
    }

    public void SetBold(boolean bold_)
    {
        bold = bold_;
        Select(4);
    }

    public void SetItalic(boolean italic_)
    {
        italic = italic_;
        Select(5);
    }

    // Property getting methods
    public int            GetFont() { return font; }
    public double         GetScale() { return scale; }
    public boolean        GetUseForegroundColor() { return useForegroundColor; }
    public ColorAttribute GetColor() { return color; }
    public boolean        GetBold() { return bold; }
    public boolean        GetItalic() { return italic; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteInt(font);
        if(WriteSelect(1, buf))
            buf.WriteDouble(scale);
        if(WriteSelect(2, buf))
            buf.WriteBool(useForegroundColor);
        if(WriteSelect(3, buf))
            color.Write(buf);
        if(WriteSelect(4, buf))
            buf.WriteBool(bold);
        if(WriteSelect(5, buf))
            buf.WriteBool(italic);
    }

    public void ReadAtts(int index, CommunicationBuffer buf)
    {
        switch(index)
        {
        case 0:
            SetFont(buf.ReadInt());
            break;
        case 1:
            SetScale(buf.ReadDouble());
            break;
        case 2:
            SetUseForegroundColor(buf.ReadBool());
            break;
        case 3:
            color.Read(buf);
            Select(3);
            break;
        case 4:
            SetBold(buf.ReadBool());
            break;
        case 5:
            SetItalic(buf.ReadBool());
            break;
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + indent + "font = ";
        if(font == FONTNAME_ARIAL)
            str = str + "FONTNAME_ARIAL";
        if(font == FONTNAME_COURIER)
            str = str + "FONTNAME_COURIER";
        if(font == FONTNAME_TIMES)
            str = str + "FONTNAME_TIMES";
        str = str + "\n";
        str = str + doubleToString("scale", scale, indent) + "\n";
        str = str + boolToString("useForegroundColor", useForegroundColor, indent) + "\n";
        str = str + indent + "color = {" + color.Red() + ", " + color.Green() + ", " + color.Blue() + ", " + color.Alpha() + "}\n";
        str = str + boolToString("bold", bold, indent) + "\n";
        str = str + boolToString("italic", italic, indent) + "\n";
        return str;
    }


    // Attributes
    private int            font;
    private double         scale;
    private boolean        useForegroundColor;
    private ColorAttribute color;
    private boolean        bold;
    private boolean        italic;
}


// ****************************************************************************
//
// Copyright (c) 2000 - 2007, The Regents of the University of California
// Produced at the Lawrence Livermore National Laboratory
// All rights reserved.
//
// This file is part of VisIt. For details, see http://www.llnl.gov/visit/. The
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
//    documentation and/or materials provided with the distribution.
//  - Neither the name of the UC/LLNL nor  the names of its contributors may be
//    used to  endorse or  promote products derived from  this software without
//    specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
// ARE  DISCLAIMED.  IN  NO  EVENT  SHALL  THE  REGENTS  OF  THE  UNIVERSITY OF
// CALIFORNIA, THE U.S.  DEPARTMENT  OF  ENERGY OR CONTRIBUTORS BE  LIABLE  FOR
// ANY  DIRECT,  INDIRECT,  INCIDENTAL,  SPECIAL,  EXEMPLARY,  OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
// SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
// CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
// LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
// OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
// DAMAGE.
//
// ****************************************************************************

package llnl.visit;


// ****************************************************************************
// Class: ColorControlPoint
//
// Purpose:
//    This class contains an RGBA color with a position value.
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   Mon Aug 12 12:17:09 PDT 2002
//
// Modifications:
//   
// ****************************************************************************

public class ColorControlPoint extends AttributeSubject
{
    public ColorControlPoint()
    {
        super(2);

        colors = new int[4];
        colors[0] = 0;
        colors[1] = 0;
        colors[2] = 0;
        colors[3] = 255;
        position = 0;
    }

    public ColorControlPoint(ColorControlPoint obj)
    {
        super(2);

        int i;

        colors = new int[4];
        for(i = 0; i < 4; ++i)
            colors[i] = obj.colors[i];

        position = obj.position;

        SelectAll();
    }

    public ColorControlPoint(float pos, int r, int g, int b, int a)
    {
        super(2);

        colors = new int[4];
        colors[0] = r;
        colors[1] = g;
        colors[2] = b;
        colors[3] = a;
        position = pos;
    }

    public boolean equals(ColorControlPoint obj)
    {
        int i;

        // Compare the colors arrays.
        boolean colors_equal = true;
        for(i = 0; i < 4 && colors_equal; ++i)
            colors_equal = (colors[i] == obj.colors[i]);

        // Create the return value
        return (colors_equal &&
                (position == obj.position));
    }

    // Property setting methods
    public void SetColors(int[] colors_)
    {
        colors[0] = colors_[0];
        colors[1] = colors_[1];
        colors[2] = colors_[2];
        colors[3] = colors_[3];
        Select(0);
    }

    public void SetPosition(float position_)
    {
        position = position_;
        Select(1);
    }

    // Property getting methods
    public int[] GetColors() { return colors; }
    public float  GetPosition() { return position; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
        {
            byte tmp[] = new byte[4];
            for(int i = 0; i < 4; ++i)
                tmp[i] = (byte)colors[i];
            buf.WriteByteArray(tmp, true);
        }
        if(WriteSelect(1, buf))
            buf.WriteFloat(position);
    }

    public void ReadAtts(int n, CommunicationBuffer buf)
    {
        for(int i = 0; i < n; ++i)
        {
            int index = (int)buf.ReadByte();
            switch(index)
            {
            case 0:
                byte[] tmp = buf.ReadByteArray();
                colors[0] = (int)tmp[0];
                colors[1] = (int)tmp[1];
                colors[2] = (int)tmp[2];
                colors[3] = (int)tmp[3];
                Select(0);
                break;
            case 1:
                SetPosition(buf.ReadFloat());
                break;
            }
        }
    }


    // Attributes
    private int[] colors;
    private float position;
}


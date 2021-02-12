///////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2000 Intel Corporation
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
// * Neither name of the Intel Corporation nor the names of its contributors
// may be used to endorse or promote products derived from this software
// without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL INTEL OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
// OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
///////////////////////////////////////////////////////////////////////////

// $Revision: 1.1.1.1 $
// $Date: 2001/06/14 23:52:28 $

#ifndef NETREADER_H
#define NETREADER_H

#include <genlib/meta/stream/charreader.h>

class NetReader : public CharReader
{
public:
    NetReader( int socketfd );
    virtual ~NetReader();

    // get next char from network
    // throws NetException  
    char getChar();
    
    // return previously read char to buffer
    // throws OutOfBoundsException
    void pushBack();

    // reads raw data into buffer
    // input:
    //   bufferSize: size of buffer in bytes
    // output:
    //   buffer: contains data read from network
    // returns:
    //   num bytes read
    // throws:
    //   NetworkReadException
    int read( void* buffer, int bufferSize );
    
    bool endOfStream() { return buf_eof; }
    
private:
    void refillBuffer();
    bool bufferHasData() const;
    
private:
    // BUFSIZE > MAX_PUSHBACK
    enum { BUFSIZE = 5, MAX_PUSHBACK = 3 };
    
    int sockfd;
    char data[ BUFSIZE + MAX_PUSHBACK ];
    int datalen;
    int offset;
    bool buf_eof;
};

#endif /* NETREADER_H */

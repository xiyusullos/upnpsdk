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
// * Neither name of Intel Corporation nor the names of its contributors
// may be used to endorse or promote products derived from this software
// without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
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

//	$Revision: 1.1.1.5 $
//	$Date: 2001/06/15 00:22:14 $

#ifndef PARSER_H
#define PARSER_H

#include "NodeAct.h"
#include "all.h"
#include <genlib/util/membuffer.h>

// Parser definitions


#define QUOT		"&quot;"
#define LT			"&lt;"
#define GT			"&gt;"
#define APOS		"&apos;"
#define AMP			"&amp;"
#define ESC_HEX		"&#x"
#define ESC_DEC		"&#"
#define SEMICOLON	";"
#define MAX_HANDLE  1024
#define START_TREE  1024
#define END_TREE  1024



class Parser  
{
public:
	//getNextNode returns NodeName, NodeValue and NodeType of the next node parsed
	int getNextNode(NODE_TYPE &NodeType, char **NodeName, char **NodeValue, bool &IsEnd, bool IgnoreWhiteSpace);
	Parser(char *parseStr);
	~Parser();

private:
	char *ParseBuff; //Holds the buffer to parse
	char *CurrPtr; //Holds the ptr to the token parsed most recently.
	//char LastElement[5000]; //Holds the string of the last element scanned
	//char TokenBuff[5000]; //Holds the token
	bool TagVal;
	bool TagName;
	char *SavePtr; //Saves for not ignoring the leading and trailing white space from">" to "<"
    membuffer lastElem, tokBuf;    

	long skipString (char **pstrFragment, const char *strSkipChars);
	long skipUntilString (char **pstrSource, const char *strSkipKey);
    int  getNextToken(); //this will return the string to the next token in the TokrenBuff
	void IgnoreWhiteSpaces();
	char * findNextMatch (char *strSearch, const char *strMatch);
	bool inAttrib;//Indicates Inside Attribute
	bool attrFound;//Indicates that an attribute was found after parsing the attribute node
	bool atLeastOneAttrFound;//Indicates that atleast one atribute was found.
	void rewindCurrentPtr(int n);
    bool copy_token(char *src, int len);

    char *getLastElem();
    int getLastElemLength();
    // returns 0: success; or -1 if out of memory
    int setLastElem(const char*s);

    char *getTokBuf();
    int  getTokBufLength();

    // returns 0: success; or -1 if out of memory
    int clearTokBuf();

    // returns 0: success; or -1 if out of memory
    int appendTokBuf(const char *s);
    int appendTokBuf(char c);

};

#endif

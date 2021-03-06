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

//	$Revision: 1.1.1.4 $
//	$Date: 2001/06/15 00:22:14 $

#ifndef _NODEACT_H_
#define _NODEACT_H_
#include <string.h>
#include "Node.h"
#include "all.h"
#include "DOMException.h"

class Node;

class NodeAct
{
public:
	int RefCount;

	NodeAct(NODE_TYPE nt,char *NodeName, char *NodeValue, Node * myCreator);
	NodeAct(const NodeAct &other, bool deep);
	~NodeAct();
	NodeAct* cloneNode(bool deep);
	void appendChild(NodeAct *newChild);
	void insertBefore(NodeAct *newChild, NodeAct *refChild);
	void replaceChild(NodeAct *newChild, NodeAct *oldChild);
	void removeChild(NodeAct *oldChild);
	bool findNode(NodeAct *find);

	void deleteNodeAct();
	void setName(char *n);
	void setValue(char *v);
	char *NA_NodeName;
	char *NA_NodeValue;
	NODE_TYPE NA_NodeType;
	Node *Creator;
	NodeAct *ParentNode;
	NodeAct *FirstChild;
	NodeAct *LastChild;
	NodeAct *OwnerNode;
	NodeAct *NextSibling;
	NodeAct *PrevSibling;
	NodeAct *FirstAttr;
	NodeAct *LastAttr;

private:
	void deleteNodeTree(NodeAct *na);
	bool findNodeFromRef(NodeAct *from, NodeAct *find);
	void changeOwnerNode(NodeAct *n, NodeAct *newOwner);

};

#endif






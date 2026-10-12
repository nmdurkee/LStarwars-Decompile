/* Ghidra analysis pseudocode, not original source.
 * ev_b88322fe7ca6c602bc72773b9244a05ea8c75e29ff1db88ba7165308671a45a1
 * Entry: 0x703774; label: DName::operator+=
 */

/* Library Function - Single Match
    public: class DName & __thiscall DName::operator+=(enum DNameStatus)
   
   Library: Visual Studio 2005 Release */

DName * __thiscall DName::operator+=(DName *this,DNameStatus param_1)

{
  int iVar1;
  DNameStatusNode *this_00;
  DNameNode *pDVar2;
  DNameNode *this_01;
  DName *this_02;
  
  iVar1 = isEmpty(this);
  if (((iVar1 != 0) || (param_1 == 1)) || (param_1 == 3)) {
    operator=(this_02,param_1);
    return this;
  }
  this_00 = HeapManager::getMemory((HeapManager *)&DAT_0297cb58,0x10,0);
  if (this_00 == (DNameStatusNode *)0x0) {
    pDVar2 = (DNameNode *)0x0;
  }
  else {
    pDVar2 = (DNameNode *)DNameStatusNode::DNameStatusNode(this_00,param_1);
  }
  if (pDVar2 == (DNameNode *)0x0) {
    *(undefined4 *)this = 0;
  }
  else {
    this_01 = DNameNode::clone(*(DNameNode **)this);
    *(DNameNode **)this = this_01;
    if (this_01 == (DNameNode *)0x0) goto LAB_007037d2;
    DNameNode::operator+=(this_01,pDVar2);
  }
  if (*(int *)this != 0) {
    return this;
  }
LAB_007037d2:
  *(uint *)(this + 4) = *(uint *)(this + 4) & 0xfffffff3 | 3;
  return this;
}


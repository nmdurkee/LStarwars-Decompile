/* Ghidra analysis pseudocode, not original source.
 * ev_b88322fe7ca6c602bc72773b9244a05ea8c75e29ff1db88ba7165308671a45a1
 * Entry: 0x703e48; label: DName::operator+=
 */

/* Library Function - Single Match
    public: class DName & __thiscall DName::operator+=(char const *)
   
   Library: Visual Studio 2005 Release */

DName * __thiscall DName::operator+=(DName *this,char *param_1)

{
  int iVar1;
  DNameNode *pDVar2;
  pcharNode *this_00;
  DName *this_01;
  
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    iVar1 = isEmpty(this);
    if (iVar1 == 0) {
      pDVar2 = DNameNode::clone(*(DNameNode **)this);
      *(DNameNode **)this = pDVar2;
      if (pDVar2 == (DNameNode *)0x0) {
        *(uint *)(this + 4) = *(uint *)(this + 4) & 0xfffffff3 | 3;
      }
      else {
        this_00 = HeapManager::getMemory((HeapManager *)&DAT_0297cb58,0x10,0);
        if (this_00 == (pcharNode *)0x0) {
          pDVar2 = (DNameNode *)0x0;
        }
        else {
          pDVar2 = (DNameNode *)pcharNode::pcharNode(this_00,param_1,0);
        }
        DNameNode::operator+=(*(DNameNode **)this,pDVar2);
      }
    }
    else {
      operator=(this_01,param_1);
    }
  }
  return this;
}


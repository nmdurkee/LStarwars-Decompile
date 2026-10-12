/* Ghidra analysis pseudocode, not original source.
 * ev_b88322fe7ca6c602bc72773b9244a05ea8c75e29ff1db88ba7165308671a45a1
 * Entry: 0x703566; label: DNameNode::clone
 */

/* Library Function - Single Match
    public: class DNameNode * __thiscall DNameNode::clone(void)
   
   Library: Visual Studio 2005 Release */

DNameNode * __thiscall DNameNode::clone(DNameNode *this)

{
  pDNameNode *this_00;
  DName *pDVar1;
  DNameNode *pDVar2;
  
  this_00 = HeapManager::getMemory((HeapManager *)&DAT_0297cb58,0xc,0);
  if (this_00 == (pDNameNode *)0x0) {
    pDVar2 = (DNameNode *)0x0;
  }
  else {
    pDVar1 = HeapManager::getMemory((HeapManager *)&DAT_0297cb58,8,0);
    if (pDVar1 == (DName *)0x0) {
      pDVar1 = (DName *)0x0;
    }
    else {
      *(uint *)(pDVar1 + 4) = *(uint *)(pDVar1 + 4) & 0xfffff000;
      *(DNameNode **)pDVar1 = this;
    }
    pDVar2 = (DNameNode *)pDNameNode::pDNameNode(this_00,pDVar1);
  }
  return pDVar2;
}


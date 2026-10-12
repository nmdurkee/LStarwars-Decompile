/* Ghidra analysis pseudocode, not original source.
 * ev_b88322fe7ca6c602bc72773b9244a05ea8c75e29ff1db88ba7165308671a45a1
 * Entry: 0x7037ed; label: DName::operator=
 */

/* Library Function - Single Match
    public: class DName & __thiscall DName::operator=(class DName *)
   
   Library: Visual Studio 2005 Release */

DName * __thiscall DName::operator=(DName *this,DName *param_1)

{
  pDNameNode *this_00;
  int iVar1;
  
  iVar1 = (int)(*(uint *)(this + 4) << 0x1c) >> 0x1c;
  if ((iVar1 == 0) || (iVar1 == 2)) {
    if (param_1 == (DName *)0x0) {
      operator=(this,3);
    }
    else {
      *(uint *)(this + 4) = *(uint *)(this + 4) & 0xfffff70f;
      this_00 = HeapManager::getMemory((HeapManager *)&DAT_0297cb58,0xc,0);
      if (this_00 == (pDNameNode *)0x0) {
        iVar1 = 0;
      }
      else {
        iVar1 = pDNameNode::pDNameNode(this_00,param_1);
      }
      *(int *)this = iVar1;
      if (iVar1 == 0) {
        *(uint *)(this + 4) = *(uint *)(this + 4) & 0xfffffff3 | 3;
      }
    }
  }
  return this;
}


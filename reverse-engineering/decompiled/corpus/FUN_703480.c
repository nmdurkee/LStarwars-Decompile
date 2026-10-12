/* Ghidra analysis pseudocode, not original source.
 * ev_b88322fe7ca6c602bc72773b9244a05ea8c75e29ff1db88ba7165308671a45a1
 * Entry: 0x703480; label: DName::operator=
 */

/* Library Function - Single Match
    public: class DName & __thiscall DName::operator=(enum DNameStatus)
   
   Library: Visual Studio 2005 Release */

DName * __thiscall DName::operator=(DName *this,DNameStatus param_1)

{
  DNameStatus DVar1;
  DNameStatusNode *this_00;
  int iVar2;
  
  if ((param_1 == 1) || (param_1 == 3)) {
    DVar1 = *(DNameStatus *)(this + 4);
    *(undefined4 *)this = 0;
    if (((byte)DVar1 & 0xf) != 3) {
      *(DNameStatus *)(this + 4) = (DVar1 ^ param_1) & 0xf ^ DVar1;
    }
  }
  else {
    iVar2 = (int)(*(uint *)(this + 4) << 0x1c) >> 0x1c;
    if ((iVar2 == 0) || (iVar2 == 2)) {
      *(uint *)(this + 4) = *(uint *)(this + 4) & 0xfffff70f;
      this_00 = HeapManager::getMemory((HeapManager *)&DAT_0297cb58,0x10,0);
      if (this_00 == (DNameStatusNode *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = DNameStatusNode::DNameStatusNode(this_00,param_1);
      }
      *(int *)this = iVar2;
      if (iVar2 == 0) {
        *(uint *)(this + 4) = *(uint *)(this + 4) & 0xfffffff3 | 3;
      }
    }
  }
  return this;
}


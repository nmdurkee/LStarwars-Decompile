/* Ghidra analysis pseudocode, not original source.
 * ev_8dba402bb7d22455a765fa1be408776d0f2383442396bc16910bcc92f9a08d40
 * Entry: 0x70329a; label: DName::DName
 */

/* Library Function - Single Match
    public: __thiscall DName::DName(enum DNameStatus)
   
   Library: Visual Studio 2005 Release */

DName * __thiscall DName::DName(DName *this,DNameStatus param_1)

{
  DNameStatus DVar1;
  DNameStatusNode *this_00;
  int iVar2;
  
  DVar1 = param_1;
  if ((param_1 != 1) && (param_1 != 3)) {
    DVar1 = 0;
  }
  *(DNameStatus *)(this + 4) =
       *(DNameStatus *)(this + 4) ^ (*(DNameStatus *)(this + 4) ^ DVar1) & 0xf;
  this_00 = HeapManager::getMemory((HeapManager *)&DAT_0297cb58,0x10,0);
  if (this_00 == (DNameStatusNode *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = DNameStatusNode::DNameStatusNode(this_00,param_1);
  }
  *(uint *)(this + 4) = *(uint *)(this + 4) & 0xfffff00f;
  *(int *)this = iVar2;
  if (iVar2 == 0) {
    *(uint *)(this + 4) = *(uint *)(this + 4) & 0xfffffff3 | 3;
  }
  return this;
}


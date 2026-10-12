/* Ghidra analysis pseudocode, not original source.
 * ev_8dba402bb7d22455a765fa1be408776d0f2383442396bc16910bcc92f9a08d40
 * Entry: 0x703244; label: DName::DName
 */

/* Library Function - Single Match
    public: __thiscall DName::DName(class DName *)
   
   Library: Visual Studio 2005 Release */

DName * __thiscall DName::DName(DName *this,DName *param_1)

{
  pDNameNode *this_00;
  int iVar1;
  
  if (param_1 == (DName *)0x0) {
    *(uint *)(this + 4) = *(uint *)(this + 4) & 0xfffffff0;
    *(undefined4 *)this = 0;
  }
  else {
    this_00 = HeapManager::getMemory((HeapManager *)&DAT_0297cb58,0xc,0);
    if (this_00 == (pDNameNode *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = pDNameNode::pDNameNode(this_00,param_1);
    }
    *(int *)this = iVar1;
    *(uint *)(this + 4) =
         *(uint *)(this + 4) ^ ((-(uint)(iVar1 != 0) & 0xfffffffd) + 3 ^ *(uint *)(this + 4)) & 0xf;
  }
  *(uint *)(this + 4) = *(uint *)(this + 4) & 0xfffff00f;
  return this;
}


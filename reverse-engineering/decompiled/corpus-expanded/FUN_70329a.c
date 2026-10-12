/* Ghidra pseudocode, not original source.
 * ev_dafa2233724afb43ee4ce5fb75a2fdf73c0a8c82e75434708f3b2ad0dea6bad5
 * Entry: 0x70329a; label: DName::DName
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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


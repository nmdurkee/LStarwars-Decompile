/* Ghidra analysis pseudocode, not original source.
 * ev_b88322fe7ca6c602bc72773b9244a05ea8c75e29ff1db88ba7165308671a45a1
 * Entry: 0x70351f; label: Replicator::operator+=
 */

/* Library Function - Single Match
    public: class Replicator & __thiscall Replicator::operator+=(class DName const &)
   
   Library: Visual Studio 2005 Release */

Replicator * __thiscall Replicator::operator+=(Replicator *this,DName *param_1)

{
  int iVar1;
  DName *this_00;
  
  if (*(int *)this != 9) {
    iVar1 = DName::isEmpty(param_1);
    if (iVar1 == 0) {
      this_00 = HeapManager::getMemory((HeapManager *)&DAT_0297cb58,8,0);
      if (this_00 == (DName *)0x0) {
        iVar1 = 0;
      }
      else {
        iVar1 = DName::DName(this_00,param_1);
      }
      if (iVar1 != 0) {
        *(int *)this = *(int *)this + 1;
        *(int *)(this + *(int *)this * 4 + 4) = iVar1;
      }
    }
  }
  return this;
}


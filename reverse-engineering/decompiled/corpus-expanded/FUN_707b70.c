/* Ghidra pseudocode, not original source.
 * ev_bdf1d7790352cc42fa475d7feda1d016092a6193a7278bd37bc81c47b8a4034d
 * Entry: 0x707b70; label: UnDecorator::getExternalDataType
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getExternalDataType(class DName const &)
   
   Library: Visual Studio 2005 Release */

DName * __cdecl UnDecorator::getExternalDataType(DName *param_1)

{
  DName *pDVar1;
  DName *this;
  DName *this_00;
  undefined1 local_1c [8];
  DName local_14 [8];
  DName local_c [8];
  
  pDVar1 = HeapManager::getMemory((HeapManager *)&DAT_0297cb58,8,0);
  this_00 = (DName *)0x0;
  if (pDVar1 != (DName *)0x0) {
    *(uint *)(pDVar1 + 4) = *(uint *)(pDVar1 + 4) & 0xfffff000;
    *(undefined4 *)pDVar1 = 0;
    this_00 = pDVar1;
  }
  getDataType(param_1);
  getDataIndirectType();
  pDVar1 = local_14;
  this = (DName *)DName::operator+(local_c,(char)local_1c);
  pDVar1 = (DName *)DName::operator+(this,pDVar1);
  DName::operator=(this_00,pDVar1);
  return param_1;
}


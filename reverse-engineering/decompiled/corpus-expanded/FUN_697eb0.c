/* Ghidra pseudocode, not original source.
 * ev_ab45728ea6dd43502824c472d7f84a4237b6985bbd98dd18e4509cbe0b313452
 * Entry: 0x697eb0; label: FUN_00697eb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00697eb0(void)

{
  int iVar1;
  
  iVar1 = DAT_02972c04;
  if (DAT_02962bac != 0) {
    if (DAT_02972c04 != 0) {
      FUN_006998f0();
      FUN_006e85b0(iVar1);
    }
    iVar1 = DAT_02972c00;
    if (DAT_02972c00 != 0) {
      FUN_006998f0();
      FUN_006e85b0(iVar1);
    }
    DAT_02972c04 = 0;
    DAT_02972c00 = 0;
    if ((DAT_02972c24 != (HANDLE)0x0) && (DAT_02972c28 != 0)) {
      DAT_02972c2c = 1;
      SetEvent(DAT_02972c24);
      while (DAT_02972c28 != 0) {
        Sleep(10);
      }
      DeleteObject(DAT_02972c24);
      DAT_02972c24 = (HANDLE)0x0;
      DAT_02972c28 = 0;
    }
    if (DAT_02972bf4 != 0) {
      FUN_004ef280(DAT_02972bf4,".\\pc\\nusound.cpp",0x72f);
    }
    DAT_02972bf4 = 0;
    DAT_02962bac = 0;
  }
  return;
}


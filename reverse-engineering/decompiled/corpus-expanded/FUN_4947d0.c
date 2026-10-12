/* Ghidra pseudocode, not original source.
 * ev_f838318f8db109b6dcd3b75a6a424a1459b1413cbbc9987106adb019bff4cb04
 * Entry: 0x4947d0; label: FUN_004947d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004947d0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 100) == 0) {
    if (*(int *)(param_1 + 0x68) != 0) {
      FUN_00509ab0();
      DAT_00800940 = FUN_00547990(0x31);
      return;
    }
  }
  else {
    iVar2 = (*(int *)(param_1 + 0x34) + 0x2c) % 0x2d;
    if (((&DAT_0086e4c8)[(int)(iVar2 + (iVar2 >> 0x1f & 0x1fU)) >> 5] & 1 << ((byte)iVar2 & 0x1f))
        != 0) {
      if (DAT_00951154 == 0) {
LAB_0049483e:
        iVar1 = FUN_0056e160(iVar2,1);
        FUN_0056e130(iVar2,iVar1 == 0);
        FUN_00547930(0x30,0,0,0);
        return;
      }
      iVar1 = FUN_0056e100(iVar2,0x200000);
      if (iVar1 == 0) goto LAB_0049483e;
    }
    FUN_00547930(0x32,0,0,0);
  }
  return;
}


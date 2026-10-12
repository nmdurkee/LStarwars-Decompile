/* Ghidra pseudocode, not original source.
 * ev_e184d5b1c01771fdc7fcde98b9e576adf0de0b497982e0e92263394112c13494
 * Entry: 0x685eb0; label: FUN_00685eb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00685eb0(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_029620a8;
  while (iVar2 = iVar1, iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0x1c8);
    if (*(short *)(iVar2 + 0x18e) != *(short *)(iVar2 + 0x186)) {
      FUN_00683560(iVar2);
    }
  }
  return;
}


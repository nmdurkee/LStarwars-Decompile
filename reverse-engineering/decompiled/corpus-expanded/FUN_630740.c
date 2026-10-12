/* Ghidra pseudocode, not original source.
 * ev_4e08cb6b9a05324ae7a2b7ff12e5cd4300e2bf96324e358c1c445da0c9e3f38b
 * Entry: 0x630740; label: FUN_00630740
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00630740(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if (DAT_029130e4 == 0) {
    return -1;
  }
  if ((DAT_0291311c != 0) && (iVar2 = 0, 0 < *(int *)(DAT_029130e4 + 8))) {
    do {
      iVar1 = FUN_004f8b10(*(undefined4 *)(DAT_0291311c + iVar2 * 8),param_1);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(DAT_029130e4 + 8));
  }
  if (DAT_02913120 != (int *)0x0) {
    iVar2 = *DAT_02913120;
    piVar3 = DAT_02913120;
    while (iVar2 != 0) {
      iVar2 = FUN_004f8b10(*piVar3,param_1);
      if (iVar2 == 0) {
        return piVar3[1];
      }
      piVar3 = piVar3 + 2;
      iVar2 = *piVar3;
    }
  }
  return -1;
}


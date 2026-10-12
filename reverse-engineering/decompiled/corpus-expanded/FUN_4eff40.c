/* Ghidra pseudocode, not original source.
 * ev_32329224682956fa8cc17060d0cd356f2ceec3520653550ffb34c5179fbcb220
 * Entry: 0x4eff40; label: FUN_004eff40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_004eff40(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == -3) {
    return (undefined4 *)PTR_DAT_00800478;
  }
  if ((param_1 == 1) || (param_1 == 3)) {
    param_1 = 2;
  }
  iVar1 = 0;
  if (0 < DAT_0297e064) {
    piVar2 = &DAT_029803e4;
    do {
      if ((piVar2[-1] == param_1) && ((param_2 < 0 || (param_2 == *piVar2)))) {
        return &DAT_029803e0 + iVar1 * 0x8d;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0x8d;
    } while (iVar1 < DAT_0297e064);
  }
  return (undefined4 *)0x0;
}


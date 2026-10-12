/* Ghidra pseudocode, not original source.
 * ev_61672b8aee088191725705707427e6d28989067365c008b5a0fbb4fab739a1ee
 * Entry: 0x5ae450; label: FUN_005ae450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ae450(int *param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 != (int *)0x0) && (iVar1 = *param_1, iVar1 != 0)) {
    if (param_2 != 0) {
      FUN_005a1230(*(undefined4 *)(iVar1 + 0x20));
      FUN_005a1030(*(undefined4 *)(iVar1 + 0x20),0x3f800000,1);
      *(byte *)(iVar1 + 0x24) = *(byte *)(iVar1 + 0x24) | 2;
      return;
    }
    FUN_005a1170(*(undefined4 *)(iVar1 + 0x20));
    *(byte *)(iVar1 + 0x24) = *(byte *)(iVar1 + 0x24) & 0xfd;
  }
  return;
}


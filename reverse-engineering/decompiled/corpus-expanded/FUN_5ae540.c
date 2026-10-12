/* Ghidra pseudocode, not original source.
 * ev_61672b8aee088191725705707427e6d28989067365c008b5a0fbb4fab739a1ee
 * Entry: 0x5ae540; label: FUN_005ae540
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005ae540(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  if ((*param_1 != 0) && (iVar1 = *(int *)(*param_1 + 0x20), *(char *)(iVar1 + 8) != '\0')) {
    iVar1 = FUN_005cfac0(*(int *)(iVar1 + 0x18) + 4);
    if (iVar1 != 0) {
      uVar2 = FUN_005cf9c0();
      return uVar2;
    }
  }
  return 0;
}


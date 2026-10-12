/* Ghidra pseudocode, not original source.
 * ev_61672b8aee088191725705707427e6d28989067365c008b5a0fbb4fab739a1ee
 * Entry: 0x5ae3a0; label: FUN_005ae3a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_005ae3a0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (((param_1 != (int *)0x0) && (iVar1 = *param_1, iVar1 != 0)) &&
     (*(char *)(*(int *)(iVar1 + 0x20) + 8) != '\0')) {
    iVar2 = FUN_005cfac0(*(int *)(*(int *)(iVar1 + 0x20) + 0x18) + 4);
    if ((iVar2 != 0) && (((*(byte *)(iVar1 + 0x24) & 2) != 0 || (param_3 != 0)))) {
      if ((*(byte *)(*(int *)(iVar1 + 0x20) + 10) & 4) == 0) {
        FUN_005a0670(*(int *)(iVar1 + 0x20));
      }
      if (param_2 == 0) {
        return *(int *)(*(int *)(iVar1 + 0x20) + 0xc) == 2;
      }
      if (param_2 == 1) {
        return *(int *)(*(int *)(iVar1 + 0x20) + 0xc) != 0;
      }
    }
  }
  return false;
}


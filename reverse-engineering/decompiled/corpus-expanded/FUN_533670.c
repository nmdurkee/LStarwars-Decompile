/* Ghidra pseudocode, not original source.
 * ev_f14574f1686883c8a991ff5dcc30f6c2e407e48e229a0065a53ff25a44d38981
 * Entry: 0x533670; label: FUN_00533670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00533670(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((((param_2 != 0) && (*(int *)(param_2 + 0xc) != 0)) &&
      (iVar1 = *(int *)(DAT_009238e4 + 0x4868), *(int *)(iVar1 + 0x20) != 0)) &&
     (*(int *)(iVar1 + 0x20) == *(int *)(iVar1 + 0x24))) {
    iVar2 = *(int *)(iVar1 + 0x20);
    FUN_00532220(iVar2,iVar1);
    FUN_0052a4b0(iVar2);
    FUN_00530e50(iVar2);
    if (DAT_009238f4 != (code *)0x0) {
      (*DAT_009238f4)(iVar2);
    }
    if (*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) == iVar2) {
      *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) = 0;
    }
  }
  if (*(int *)(DAT_009238e4 + 4) != 0) {
    FUN_00624220(*(undefined4 *)(DAT_009238e4 + 4));
    *(undefined4 *)(DAT_009238e4 + 4) = 0;
  }
  return;
}


/* Ghidra pseudocode, not original source.
 * ev_1b4e61f1467db5c8e431c69a2548c20deac6709d01307c3b7894b5c0724271ef
 * Entry: 0x522c30; label: FUN_00522c30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00522c30(void)

{
  int iVar1;
  undefined4 local_4;
  
  iVar1 = FUN_00522b60(&local_4,0,0);
  if (iVar1 != 0) {
    *(undefined4 *)(DAT_009238e4 + 0x4868) = local_4;
    *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) = iVar1;
    FUN_00620f10(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) + 0x18);
  }
  return;
}


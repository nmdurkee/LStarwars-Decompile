/* Ghidra pseudocode, not original source.
 * ev_7d1c367504044a8aaca3f86d1c78a9fb18090d1bc2abefa9dee9498b100eab75
 * Entry: 0x593920; label: FUN_00593920
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00593920(int param_1,ushort *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x24) + (uint)*param_2 * 0x28;
  if ((((*(byte *)(*(int *)(param_1 + 0x24) + 0x12 + (uint)*param_2 * 0x28) & 0x20) != 0) ||
      ((*(byte *)(*(int *)(param_1 + 0x28) + 0x12 + (uint)param_2[1] * 0x28) & 1) != 0)) ||
     ((iVar2 = (int)*(short *)(iVar1 + 6), iVar2 == -1 &&
      (iVar2 = (int)*(short *)(iVar1 + 4), iVar2 == -1)))) {
    iVar2 = (int)*(short *)(*(int *)(param_1 + 0x28) + 6 + (uint)param_2[1] * 0x28);
    if ((iVar2 == -1) &&
       (iVar2 = (int)*(short *)(*(int *)(param_1 + 0x28) + (uint)param_2[1] * 0x28 + 4), iVar2 == -1
       )) {
      return DAT_00803b98;
    }
  }
  return (int)*(short *)(iVar2 * 0x4c + 0x42 + DAT_0093b274);
}


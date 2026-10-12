/* Ghidra pseudocode, not original source.
 * ev_e8754f098cec4467dd9989e7d0bc7b4ce6834c9196706effdc433d5dfb6256ff
 * Entry: 0x406af0; label: FUN_00406af0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00406af0(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_2;
  iVar3 = (uint)*(byte *)((*(char *)(param_1 + 0x160) == '\0') + 0x10 + *(int *)(param_1 + 0x15c)) *
          0x5c + *(int *)(*(int *)(param_1 + 0x158) + 0x7c);
  iVar2 = FUN_0043c9a0(iVar1,iVar3,1);
  if (iVar2 == 0) {
    if ((*(char *)(iVar1 + 0x7b5) == 'D') || (0.0 < *(float *)(iVar1 + 0x1090))) {
      return 0;
    }
    FUN_0043cbb0(iVar1,iVar3,0,4);
    *(ushort *)((int)param_2 + 0x292) = *(ushort *)((int)param_2 + 0x292) | 0x2000;
  }
  return 1;
}


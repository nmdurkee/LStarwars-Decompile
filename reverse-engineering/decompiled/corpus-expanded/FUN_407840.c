/* Ghidra pseudocode, not original source.
 * ev_e8754f098cec4467dd9989e7d0bc7b4ce6834c9196706effdc433d5dfb6256ff
 * Entry: 0x407840; label: FUN_00407840
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00407840(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  if ((*(byte *)(*(int *)(*(int *)(*param_2 + 0x54) + 0x24) + 0x90) & 0x40) != 0) {
    iVar1 = *(int *)(*param_2 + 0xcd0);
    if (iVar1 != 0) {
      iVar2 = (uint)*(byte *)((*(char *)(param_1 + 0x160) == '\0') + 0x10 +
                             *(int *)(param_1 + 0x15c)) * 0x5c +
              *(int *)(*(int *)(param_1 + 0x158) + 0x7c);
      FUN_004882d0(iVar1,1);
      FUN_00561e20(iVar1,iVar2 + 4,0,0x3f000000,0x3f800000,0);
      FUN_0043cbb0(iVar1,iVar2,0,3);
    }
    return 1;
  }
  return 0;
}


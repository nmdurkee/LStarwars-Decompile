/* Ghidra pseudocode, not original source.
 * ev_b0367b6b7ea93641fa3f234a6a49c94b930ee723d26ca433ffbeb1a06357d05a
 * Entry: 0x555550; label: FUN_00555550
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00555550(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    if (param_2 != 0) {
      *(byte *)(iVar1 + 0xac) = *(byte *)(iVar1 + 0xac) & 0xdd;
      *(uint *)(iVar1 + 0x84) = *(uint *)(iVar1 + 0x84) & 0xffffffdf;
      return;
    }
    *(byte *)(iVar1 + 0xac) = *(byte *)(iVar1 + 0xac) | 2;
  }
  return;
}


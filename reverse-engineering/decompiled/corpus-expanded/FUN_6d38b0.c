/* Ghidra pseudocode, not original source.
 * ev_5667e5448bcdd65d51b4846c6b703f5dc39afd73914fbe1d2cb4bfca537c9b4f
 * Entry: 0x6d38b0; label: FUN_006d38b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006d38b0(int param_1)

{
  int iVar1;
  int in_ECX;
  short *psVar2;
  
  iVar1 = 0;
  psVar2 = (short *)(in_ECX + 0x5e);
  while ((*(int *)(param_1 + 0x40) != *(int *)(psVar2 + -0xf) ||
         (*(short *)(param_1 + 0x5e) != *psVar2))) {
    iVar1 = iVar1 + 1;
    psVar2 = psVar2 + 0x4e;
    if (0x3f < iVar1) {
      return -1;
    }
  }
  return iVar1;
}


/* Ghidra pseudocode, not original source.
 * ev_5667e5448bcdd65d51b4846c6b703f5dc39afd73914fbe1d2cb4bfca537c9b4f
 * Entry: 0x6d3710; label: FUN_006d3710
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d3710(int param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = param_1 * 0x17c + in_ECX;
  *param_2 = (int)*(short *)(iVar1 + 0x4e4c);
  *param_3 = (int)*(char *)(iVar1 + 0x4e4e);
  *param_4 = (int)*(char *)(iVar1 + 0x4e4f);
  return;
}


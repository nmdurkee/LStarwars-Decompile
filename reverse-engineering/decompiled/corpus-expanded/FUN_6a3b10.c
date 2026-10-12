/* Ghidra pseudocode, not original source.
 * ev_7628bb02d4360686842aba648e3e8351ab050d06c55da9366e8a0a89d745bc47
 * Entry: 0x6a3b10; label: FUN_006a3b10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006a3b10(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_2 + param_1[1];
  iVar1 = (int)(uVar2 + ((int)uVar2 >> 0x1f & 7U)) >> 3;
  param_1[3] = param_1[3] + iVar1;
  *param_1 = *param_1 + iVar1;
  param_1[1] = uVar2 & 7;
  return;
}


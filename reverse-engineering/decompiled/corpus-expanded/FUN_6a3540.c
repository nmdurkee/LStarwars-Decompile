/* Ghidra pseudocode, not original source.
 * ev_7628bb02d4360686842aba648e3e8351ab050d06c55da9366e8a0a89d745bc47
 * Entry: 0x6a3540; label: FUN_006a3540
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006a3540(int *param_1,int param_2)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = param_2 >> 3;
  param_2 = param_2 + iVar1 * -8;
  pbVar2 = (byte *)(param_1[2] + iVar1);
  param_1[1] = param_2;
  param_1[3] = (int)pbVar2;
  *param_1 = iVar1;
  *pbVar2 = *pbVar2 & (&DAT_0076f56c)[param_2 * 4];
  return;
}


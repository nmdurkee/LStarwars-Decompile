/* Ghidra analysis pseudocode, not original source.
 * ev_84e5cb8303fa38d748e4458d34c9d4265893eb5844f058a0a1436ec0ce38dbe0
 * Entry: 0x6a3510; label: FUN_006a3510
 */

void FUN_006a3510(int *param_1,int param_2)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = param_2 >> 3;
  param_2 = param_2 + iVar1 * -8;
  pbVar2 = (byte *)(param_1[2] + iVar1);
  param_1[1] = param_2;
  param_1[3] = (int)pbVar2;
  *param_1 = iVar1;
  *pbVar2 = *pbVar2 & (&DAT_0076f4e8)[param_2 * 4];
  return;
}


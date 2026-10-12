/* Ghidra analysis pseudocode, not original source.
 * ev_84e5cb8303fa38d748e4458d34c9d4265893eb5844f058a0a1436ec0ce38dbe0
 * Entry: 0x6a3b10; label: FUN_006a3b10
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


/* Ghidra pseudocode, not original source.
 * ev_901c6aaecd0b47868ef1d3f758584dfae83b8347f4e0d529523c41e91b06b177
 * Entry: 0x6d92c0; label: FUN_006d92c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d92c0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  uint uVar1;
  int in_ECX;
  char *pcVar2;
  int iVar3;
  
  uVar1 = 0;
  pcVar2 = (char *)(DAT_02975144 + 0x67f1);
  iVar3 = in_ECX;
  while( true ) {
    if (uVar1 < 0x20) {
      in_ECX = (int)pcVar2[-1];
      iVar3 = (int)*pcVar2;
    }
    if ((iVar3 == param_1) && (in_ECX == param_2)) break;
    uVar1 = uVar1 + 1;
    pcVar2 = pcVar2 + 6;
    if (0x1f < (int)uVar1) {
      return;
    }
  }
  FUN_006d8d60(uVar1,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  return;
}


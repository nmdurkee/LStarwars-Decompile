/* Ghidra pseudocode, not original source.
 * ev_901c6aaecd0b47868ef1d3f758584dfae83b8347f4e0d529523c41e91b06b177
 * Entry: 0x6d9250; label: FUN_006d9250
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d9250(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  uint uVar1;
  int in_ECX;
  char *pcVar2;
  
  uVar1 = 0;
  pcVar2 = (char *)(DAT_02975144 + 0x67f2);
  while( true ) {
    if (uVar1 < 0x20) {
      in_ECX = (int)*pcVar2;
    }
    if (in_ECX == param_1) break;
    uVar1 = uVar1 + 1;
    pcVar2 = pcVar2 + 6;
    if (0x1f < (int)uVar1) {
      return;
    }
  }
  FUN_006d8d60(uVar1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}


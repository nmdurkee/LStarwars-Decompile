/* Ghidra pseudocode, not original source.
 * ev_e165dd79ce50f74ce872f7d9e4945159ab28a1cd27d81db1142f7150b3bed141
 * Entry: 0x629dd0; label: FUN_00629dd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00629dd0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  int iVar1;
  
  iVar1 = FUN_00629d00(param_1,param_2,param_3,param_9);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x58) = param_4;
    *(undefined4 *)(iVar1 + 0x5c) = param_5;
    *(undefined4 *)(iVar1 + 0x60) = param_6;
    *(undefined4 *)(iVar1 + 8) = 9;
    *(undefined4 *)(iVar1 + 100) = param_7;
    *(undefined4 *)(iVar1 + 0x68) = param_8;
  }
  return;
}


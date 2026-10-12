/* Ghidra pseudocode, not original source.
 * ev_e165dd79ce50f74ce872f7d9e4945159ab28a1cd27d81db1142f7150b3bed141
 * Entry: 0x629da0; label: FUN_00629da0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00629da0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_00629d00(param_1,param_2,param_3,param_4);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 8) = 8;
  }
  return;
}


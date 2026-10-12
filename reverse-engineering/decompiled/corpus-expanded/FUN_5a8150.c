/* Ghidra pseudocode, not original source.
 * ev_ab3200993c06f50ca9adf40c5a4b161cdaf830edaeb783e0e0f7b7da1276ea12
 * Entry: 0x5a8150; label: FUN_005a8150
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a8150(undefined4 param_1)

{
  int iVar1;
  
  DAT_00805b3c = 0xffffffff;
  iVar1 = thunk_FUN_004fa610(param_1);
  if (iVar1 != 0) {
    DAT_00805b3c = FUN_0068df20(param_1,1,0);
  }
  return;
}


/* Ghidra pseudocode, not original source.
 * ev_fb4a243913288e8884e4b26b9d3f1b2cc90d3774ba2cd7b272b490162dad9d99
 * Entry: 0x46aa90; label: FUN_0046aa90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0046aa90(int param_1)

{
  int iVar1;
  
  FUN_00547930(0x26,0,0,0);
  iVar1 = FUN_005618e0(7,0,(int)*(char *)(param_1 + 0xfd),param_1);
  if (iVar1 != 0) {
    FUN_0046a9f0();
    return;
  }
  return;
}


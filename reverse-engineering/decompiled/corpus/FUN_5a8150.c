/* Ghidra analysis pseudocode, not original source.
 * ev_bdbc2bae44bf5487d6b3a1a9f152189c4c55001891ec534863a9f12b45a65f9f
 * Entry: 0x5a8150; label: FUN_005a8150
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


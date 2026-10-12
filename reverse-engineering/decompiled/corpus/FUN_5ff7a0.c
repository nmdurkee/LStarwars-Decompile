/* Ghidra analysis pseudocode, not original source.
 * ev_6b9b03a08e90b2df5bf3c313ce6606e542f48a6b83443b8cc9ea7bf85be4ed2c
 * Entry: 0x5ff7a0; label: FUN_005ff7a0
 */

undefined4 FUN_005ff7a0(int *param_1,undefined4 param_2,float param_3)

{
  undefined4 uVar1;
  
  if ((*param_1 != 0) && (param_3 < 0.0 == (param_3 == 0.0))) {
    if (1.0 <= param_3) {
      uVar1 = FUN_005f0f00(param_1,param_2,0,0,0);
      return uVar1;
    }
    FUN_005cfb50(1,param_3);
    uVar1 = FUN_005f0f00(param_1,param_2,0,0,0);
    FUN_005cfb50(0,0);
    return uVar1;
  }
  return 0;
}


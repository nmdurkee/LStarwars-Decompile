/* Ghidra analysis pseudocode, not original source.
 * ev_949d4af3ed5d02dbfb80406f797a2538e9383f6308f9fa8dd86ff8ae723dc597
 * Entry: 0x514a50; label: FUN_00514a50
 */

float10 FUN_00514a50(undefined4 param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  float10 fVar1;
  undefined1 local_c [12];
  
  if (((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) &&
     ((param_5 != 0 || (param_5 = *(int *)(param_2 + 0xa4), param_5 != 0)))) {
    fVar1 = (float10)FUN_005bed80(param_3 + 0x14c,param_5 + 0x10,local_c);
    return fVar1;
  }
  return (float10)3.4028235e+38;
}


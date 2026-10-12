/* Ghidra analysis pseudocode, not original source.
 * ev_177857cb78ddb8ad13dc6718881af1dfaef05e8a3811f551bff9ab7ba98e27a8
 * Entry: 0x5456c0; label: FUN_005456c0
 */

float * FUN_005456c0(float *param_1,undefined4 param_2)

{
  int iVar1;
  float10 fVar2;
  
  fVar2 = (float10)FUN_00673820(param_2,0,0x40a00000,0);
  param_1[1] = (float)fVar2;
  iVar1 = FUN_005be2d0(DAT_0292fdc0,DAT_0292fdbc);
  *param_1 = (float)iVar1;
  fVar2 = (float10)FUN_005c0240(DAT_0292fdbc * DAT_0292fdbc + DAT_0292fdc0 * DAT_0292fdc0);
  iVar1 = FUN_005be2d0(DAT_0292fdb8,(float)fVar2);
  param_1[2] = (float)-iVar1;
  return param_1;
}


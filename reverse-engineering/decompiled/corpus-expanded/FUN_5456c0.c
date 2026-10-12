/* Ghidra pseudocode, not original source.
 * ev_67e04bb194beb06fa3ce238b04e3098eb4f9bf275f7ff551e45745ee5a93428c
 * Entry: 0x5456c0; label: FUN_005456c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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


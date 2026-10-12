/* Ghidra analysis pseudocode, not original source.
 * ev_d8945a36929edeac9ee45c1fd9ef4d2b22c6103a52c54fc2dc40f3cab4594402
 * Entry: 0x5dbed0; label: FUN_005dbed0
 */

undefined4 FUN_005dbed0(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  FUN_00607ec0(0xe,7,param_2,param_3);
  FUN_005c1f70();
  uVar1 = param_1[8];
  puVar3 = (undefined4 *)*DAT_02854d10;
  puVar3[4] = param_1[7];
  puVar3[5] = uVar1;
  uVar1 = param_1[1];
  uVar2 = param_1[2];
  *puVar3 = *param_1;
  puVar3[1] = uVar1;
  *(undefined4 *)(*DAT_02854d10 + 8) = uVar2;
  *DAT_02854d10 = *DAT_02854d10 + 0x18;
  DAT_02854d14 = DAT_02854d14 + 1;
  FUN_005c1f70();
  uVar1 = param_1[0x11];
  puVar3 = (undefined4 *)*DAT_02854d10;
  puVar3[4] = param_1[0x10];
  puVar3[5] = uVar1;
  uVar1 = param_1[10];
  uVar2 = param_1[0xb];
  *puVar3 = param_1[9];
  puVar3[1] = uVar1;
  *(undefined4 *)(*DAT_02854d10 + 8) = uVar2;
  *DAT_02854d10 = *DAT_02854d10 + 0x18;
  DAT_02854d14 = DAT_02854d14 + 1;
  FUN_006009c0();
  return 1;
}


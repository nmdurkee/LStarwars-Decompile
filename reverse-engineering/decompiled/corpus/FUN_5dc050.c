/* Ghidra analysis pseudocode, not original source.
 * ev_d8945a36929edeac9ee45c1fd9ef4d2b22c6103a52c54fc2dc40f3cab4594402
 * Entry: 0x5dc050; label: FUN_005dc050
 */

void FUN_005dc050(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined4 *puVar1;
  
  FUN_00607ec0(0xe,5,0,&DAT_00806680);
  FUN_005c1f70();
  puVar1 = (undefined4 *)*DAT_02854d10;
  *puVar1 = param_1;
  puVar1[1] = param_2;
  *(undefined4 *)(*DAT_02854d10 + 8) = param_3;
  *DAT_02854d10 = *DAT_02854d10 + 0x18;
  DAT_02854d14 = DAT_02854d14 + 1;
  FUN_005c1f70();
  puVar1 = (undefined4 *)*DAT_02854d10;
  *puVar1 = param_4;
  puVar1[1] = param_5;
  *(undefined4 *)(*DAT_02854d10 + 8) = param_6;
  *DAT_02854d10 = *DAT_02854d10 + 0x18;
  DAT_02854d14 = DAT_02854d14 + 1;
  FUN_006009c0();
  return;
}


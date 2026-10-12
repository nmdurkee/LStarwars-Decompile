/* Ghidra pseudocode, not original source.
 * ev_87b0cc36f0a526e4b097042d81b23e73008cbbd7a9cf76d2852b3ccb3adbc9c9
 * Entry: 0x5dbfb0; label: FUN_005dbfb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005dbfb0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined4 *puVar1;
  
  FUN_00607ec0(0xe,5,0,&DAT_00806680);
  FUN_005c1f70();
  puVar1 = (undefined4 *)*DAT_02854d10;
  puVar1[4] = 0;
  puVar1[5] = 0;
  *puVar1 = param_1;
  puVar1[1] = param_2;
  *(undefined4 *)(*DAT_02854d10 + 8) = param_3;
  *DAT_02854d10 = *DAT_02854d10 + 0x18;
  DAT_02854d14 = DAT_02854d14 + 1;
  FUN_005c1f70();
  puVar1 = (undefined4 *)*DAT_02854d10;
  puVar1[4] = 0x3f800000;
  puVar1[5] = 0x3f800000;
  *puVar1 = param_4;
  puVar1[1] = param_5;
  *(undefined4 *)(*DAT_02854d10 + 8) = param_6;
  *DAT_02854d10 = *DAT_02854d10 + 0x18;
  DAT_02854d14 = DAT_02854d14 + 1;
  FUN_006009c0();
  return;
}


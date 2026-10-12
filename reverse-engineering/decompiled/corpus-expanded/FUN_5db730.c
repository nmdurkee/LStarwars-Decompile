/* Ghidra pseudocode, not original source.
 * ev_87b0cc36f0a526e4b097042d81b23e73008cbbd7a9cf76d2852b3ccb3adbc9c9
 * Entry: 0x5db730; label: FUN_005db730
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005db730(float param_1,float param_2,undefined4 param_3,float param_4,float param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
                 undefined4 param_10,undefined4 param_11)

{
  int iVar1;
  
  FUN_00607d70(0x10,7,param_11);
  iVar1 = *DAT_02854d10;
  *(undefined4 *)(iVar1 + 0x10) = param_6;
  *(undefined4 *)(iVar1 + 0x14) = param_7;
  FUN_005c1f70();
  FUN_006009e0(param_1,param_2,param_3);
  iVar1 = *DAT_02854d10;
  *(undefined4 *)(iVar1 + 0x10) = param_8;
  *(undefined4 *)(iVar1 + 0x14) = param_9;
  FUN_005c1f70();
  FUN_006009e0(param_1 + param_4,param_2 + param_5,param_3);
  FUN_006009a0();
  return;
}


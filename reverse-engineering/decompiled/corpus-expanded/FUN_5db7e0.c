/* Ghidra pseudocode, not original source.
 * ev_87b0cc36f0a526e4b097042d81b23e73008cbbd7a9cf76d2852b3ccb3adbc9c9
 * Entry: 0x5db7e0; label: FUN_005db7e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005db7e0(float param_1,float param_2,undefined4 param_3,float param_4,float param_5,
                 undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  
  FUN_00607d70(0x10,7,param_7);
  FUN_005c1f70();
  iVar1 = *DAT_02854d10;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  FUN_006009e0(param_1,param_2,param_3);
  FUN_005c1f70();
  iVar1 = *DAT_02854d10;
  *(undefined4 *)(iVar1 + 0x10) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x14) = 0x3f800000;
  FUN_006009e0(param_1 + param_4,param_2 + param_5,param_3);
  FUN_006009a0();
  return;
}


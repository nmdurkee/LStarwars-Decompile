/* Ghidra pseudocode, not original source.
 * ev_1c43a4838a2574475d6c9682bec7b0db8a67988369837137b0115a570ceb3a0a
 * Entry: 0x4f9940; label: FUN_004f9940
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004f9940(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  FUN_004ff4a0(param_1,param_2,param_3);
  _memset(&DAT_02983740,0,400);
  _memset(&DAT_0297dc60,0,0x3c0);
  DAT_0088ab48 = FUN_004ffa60();
  iVar1 = FUN_006db910();
  FUN_004f78b0(iVar1 == 0);
  DAT_0091ce60 = 0;
  DAT_00917844 = 0;
  _DAT_0088ab40 = 0xffffffff;
  _DAT_0088ab44 = 0xffffffff;
  return param_1;
}


/* Ghidra pseudocode, not original source.
 * ev_9af94503fce638d48c98755f8a4ba03de7c5cdf51e6dce151974c12e75b3fd49
 * Entry: 0x5505a0; label: FUN_005505a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005505a0(undefined4 param_1,float param_2,float param_3)

{
  int iVar1;
  int extraout_ECX;
  
  if (param_3 != 2e+06) {
    if (DAT_0093b0e0 != (code *)0x0) {
      iVar1 = (*DAT_0093b0e0)();
      if (iVar1 == 0) goto LAB_005505c8;
    }
    param_2 = param_3;
  }
LAB_005505c8:
  FUN_0054fa00();
  *(float *)(extraout_ECX + 4) = -*(float *)(extraout_ECX + 4);
  *(float *)(extraout_ECX + 0x14) = -*(float *)(extraout_ECX + 0x14);
  *(float *)(extraout_ECX + 0x24) = -*(float *)(extraout_ECX + 0x24);
  *(float *)(extraout_ECX + 0x34) = param_2 - (*(float *)(extraout_ECX + 0x34) - param_2);
  return 1;
}


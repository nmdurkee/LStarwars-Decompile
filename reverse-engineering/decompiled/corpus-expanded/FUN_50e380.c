/* Ghidra pseudocode, not original source.
 * ev_b0e64e2dfe3722016930d355629873abe6bb90a38d3b309aad52c0d35b9c8629
 * Entry: 0x50e380; label: FUN_0050e380
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0050e380(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
                 undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16)

{
  int iVar1;
  
  iVar1 = DAT_00921ea0;
  if (DAT_00921e90 != 0) {
    DAT_00921ea0 = DAT_00921e90;
  }
  FUN_0050d910(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
               param_11,param_12,param_13,param_14,param_15,param_16);
  DAT_00921ea0 = iVar1;
  return;
}


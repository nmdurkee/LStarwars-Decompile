/* Ghidra pseudocode, not original source.
 * ev_b0e64e2dfe3722016930d355629873abe6bb90a38d3b309aad52c0d35b9c8629
 * Entry: 0x50e550; label: FUN_0050e550
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0050e550(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                int param_5)

{
  DAT_00921e8c = FUN_005eb090(param_1,param_2,4,param_5,param_3,param_4);
  if (DAT_00921e8c != 0) {
    if (DAT_00921ea8 != 0) {
      DAT_00921e90 = FUN_005eaf70(DAT_00921e8c,4,param_5 + -1,param_3,param_4);
    }
    if (DAT_00921eac != 0) {
      DAT_00921e94 = FUN_005eaf70(DAT_00921e8c,4,0x40000,param_3,param_4);
    }
    if (DAT_00921eb0 != 0) {
      DAT_00921e98 = FUN_005eaf70(DAT_00921e8c,0x18,param_5,param_3,param_4);
    }
    if (DAT_00921eb4 != 0) {
      DAT_00921e9c = FUN_005eaf70(DAT_00921e8c,0x4c,param_5,param_3,param_4);
    }
  }
  return DAT_00921e8c;
}


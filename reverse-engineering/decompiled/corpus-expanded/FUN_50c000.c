/* Ghidra pseudocode, not original source.
 * ev_b0e64e2dfe3722016930d355629873abe6bb90a38d3b309aad52c0d35b9c8629
 * Entry: 0x50c000; label: FUN_0050c000
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0050c000(void)

{
  if (((DAT_00921e6c != 0) && (DAT_00921e58 != 0)) && (DAT_00802014 != -1)) {
    DAT_00921de8 = 1;
    _DAT_00921d30 = 0;
    return 1;
  }
  return 0;
}


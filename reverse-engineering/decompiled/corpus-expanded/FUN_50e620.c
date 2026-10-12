/* Ghidra pseudocode, not original source.
 * ev_b0e64e2dfe3722016930d355629873abe6bb90a38d3b309aad52c0d35b9c8629
 * Entry: 0x50e620; label: FUN_0050e620
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0050e620(void)

{
  if (DAT_00921e90 != 0) {
    FUN_005ea7d0(DAT_00921e90);
    DAT_00921e90 = 0;
  }
  if (DAT_00921e94 != 0) {
    FUN_005ea7d0(DAT_00921e94);
    DAT_00921e94 = 0;
  }
  if (DAT_00921e98 != 0) {
    FUN_005ea7d0(DAT_00921e98);
    DAT_00921e98 = 0;
  }
  if (DAT_00921e9c != 0) {
    FUN_005ea7d0(DAT_00921e9c);
    DAT_00921e9c = 0;
  }
  FUN_005ea7d0();
  return;
}


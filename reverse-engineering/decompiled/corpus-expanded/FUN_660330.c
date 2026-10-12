/* Ghidra pseudocode, not original source.
 * ev_3c91a6b80548833a29ecc2d389e89e55b74ab0261b3e94a742c4850371a9aab1
 * Entry: 0x660330; label: FUN_00660330
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00660330(int param_1,int param_2)

{
  DAT_00810a70 = param_1;
  DAT_00810a74 = param_2;
  if (param_1 < 1) {
    DAT_00810a70 = 1;
  }
  if (param_2 < 1) {
    DAT_00810a74 = 1;
  }
  return;
}


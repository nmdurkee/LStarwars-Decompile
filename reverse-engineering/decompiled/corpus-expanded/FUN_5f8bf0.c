/* Ghidra pseudocode, not original source.
 * ev_eb6388f9e6f0da39ba23c58a55c6a14172e207ae27b9d6b4ddcb98efebe4d9b1
 * Entry: 0x5f8bf0; label: FUN_005f8bf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f8bf0(int param_1)

{
  if ((DAT_02854bc4 != param_1) || ((param_1 != 0 && (*(int *)(param_1 + 0xa0) != 0)))) {
    if (param_1 == DAT_02854bc8) {
      FUN_006e33a0();
    }
    else if (param_1 == DAT_02854bcc) {
      FUN_006e3650();
    }
    else if (param_1 != 0) {
      FUN_006e3720(param_1,0);
      FUN_006e3720(param_1 + 0x1c,1);
      FUN_006e3720(param_1 + 0x38,2);
      FUN_006e3720(param_1 + 0x54,3);
      FUN_006e2260(param_1 + 0x70);
    }
    DAT_02854bc4 = param_1;
    if (param_1 != 0) {
      *(undefined4 *)(param_1 + 0xa0) = 1;
    }
  }
  return;
}


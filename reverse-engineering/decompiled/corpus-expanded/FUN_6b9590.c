/* Ghidra pseudocode, not original source.
 * ev_53ad6b1d8bb34752a747640de0a0339f355d943428ba011e4ade8e8202156388
 * Entry: 0x6b9590; label: FUN_006b9590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b9590(undefined4 *param_1)

{
  for (param_1 = (undefined4 *)*param_1; param_1 != (undefined4 *)0x0;
      param_1 = (undefined4 *)*param_1) {
    if (param_1[3] - 3 < 0x3d) {
      *(byte *)((int)param_1 + 0x11) =
           *(byte *)((int)param_1 + 0x11) ^
           ((DAT_0081fadc & 1 << ((char)param_1[3] - 3U & 0x1f)) != 0 ^
           *(byte *)((int)param_1 + 0x11)) & 1;
    }
  }
  return;
}


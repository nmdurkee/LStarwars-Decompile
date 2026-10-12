/* Ghidra pseudocode, not original source.
 * ev_e27af7f74871e1dc60c6c80a9c8e67e6864abe93d2064640e98ee3190c864676
 * Entry: 0x4f3130; label: FUN_004f3130
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004f3130(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((0xffffff < param_1) && (param_1 != 0xffffffff)) {
    uVar1 = param_1 >> 0x18;
    param_1 = param_1 & 0xffffff;
    if (2 < uVar1) {
      return 0;
    }
  }
  if ((-1 < (int)param_1) && ((int)param_1 < (int)(&DAT_0091eed4)[uVar1 * 3])) {
    return *(undefined4 *)((&DAT_0091eed0)[uVar1 * 3] + 4 + param_1 * 8);
  }
  return 0;
}


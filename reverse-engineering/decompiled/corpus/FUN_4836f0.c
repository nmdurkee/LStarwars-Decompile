/* Ghidra analysis pseudocode, not original source.
 * ev_7aab14e0333828c3f97507d2210eedd59fd790849ff0958821514dbec2d3feea
 * Entry: 0x4836f0; label: FUN_004836f0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004836f0(int param_1,float param_2,float param_3,int param_4)

{
  if ((DAT_0087a6cc != '\0') && ((param_1 == -1 || (param_1 == 0)))) {
    if ((0.0 < param_2) &&
       ((DAT_0087a650 < 0.0 != (DAT_0087a650 == 0.0) ||
        ((DAT_0087a650 / DAT_0087a654) * DAT_0087a64c < param_2)))) {
      DAT_0087a64c = param_2;
      DAT_0087a654 = param_2;
      DAT_0087a650 = param_2;
    }
    if (DAT_0087a658 < param_3) {
      DAT_0087a658 = param_3;
    }
    if ((0 < param_4) && (param_4 = param_4 + 1, (int)(uint)DAT_0087a65c < param_4)) {
      DAT_0087a65c = (byte)param_4;
    }
  }
  if ((DAT_0087a6cd != '\0') && ((param_1 == -1 || (param_1 == 1)))) {
    if ((0.0 < param_2) &&
       ((_DAT_0087a664 < 0.0 != (_DAT_0087a664 == 0.0) ||
        ((_DAT_0087a664 / _DAT_0087a668) * _DAT_0087a660 < param_2)))) {
      _DAT_0087a660 = param_2;
      _DAT_0087a668 = param_2;
      _DAT_0087a664 = param_2;
    }
    if (DAT_0087a66c < param_3) {
      DAT_0087a66c = param_3;
    }
    if ((0 < param_4) && ((int)(uint)DAT_0087a670 < param_4 + 1)) {
      DAT_0087a670 = (char)(param_4 + 1);
      return;
    }
  }
  return;
}


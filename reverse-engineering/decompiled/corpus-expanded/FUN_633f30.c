/* Ghidra pseudocode, not original source.
 * ev_c4ffb1da974488f0d31d138643195e5dda1d4714e1fef5a95fdc86fcf60e8c52
 * Entry: 0x633f30; label: FUN_00633f30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00633f30(void)

{
  undefined4 *in_EAX;
  undefined4 *in_ECX;
  
  if (in_ECX != (undefined4 *)0x0) {
    _DAT_0097173c = *in_ECX;
    _DAT_00971740 = in_ECX[1];
    _DAT_00971744 = in_ECX[2];
  }
  _DAT_00971748 = (uint)(in_ECX == (undefined4 *)0x0);
  if (in_EAX == (undefined4 *)0x0) {
    _DAT_0097175c = 0;
    FUN_005ff840();
    return;
  }
  _DAT_0097174c = *in_EAX;
  _DAT_00971750 = in_EAX[1];
  _DAT_00971754 = in_EAX[2];
  _DAT_00971758 = in_EAX[3];
  _DAT_0097175c = 1;
  FUN_005ff840();
  return;
}


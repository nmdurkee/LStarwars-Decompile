/* Ghidra pseudocode, not original source.
 * ev_ba19024e936acaebc8caa887b02629c3d2df1b51d473842281df89ce325ba5c8
 * Entry: 0x5494f0; label: FUN_005494f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005494f0(void)

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


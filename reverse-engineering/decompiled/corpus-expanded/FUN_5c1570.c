/* Ghidra pseudocode, not original source.
 * ev_f814ac66c7176acc11aba85969a47ad0d72f6a74214126b9ee26f1e14042bc0b
 * Entry: 0x5c1570; label: FUN_005c1570
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005c1570(void)

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


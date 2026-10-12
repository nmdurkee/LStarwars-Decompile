/* Ghidra analysis pseudocode, not original source.
 * ev_6696c20a63c48b02c48d5a5db7e1958972e2427aa057f5485eee4f348cd6e250
 * Entry: 0x5c3200; label: FUN_005c3200
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005c3200(void)

{
  if (DAT_009737e4 != (int *)0x0) {
    (**(code **)(*DAT_009737e4 + 0x1c))();
  }
  if (DAT_009737e0 != (int *)0x0) {
    (**(code **)(*DAT_009737e0 + 0x1c))();
  }
  if (DAT_009737e8 != (int *)0x0) {
    (**(code **)(*DAT_009737e8 + 0x1c))();
  }
  if (DAT_009737ec != (int *)0x0) {
    (**(code **)(*DAT_009737ec + 0x1c))();
  }
  _DAT_0080bb38 = 0;
  _DAT_0080bb3c = 0;
  DAT_0080bb41 = 0;
  _DAT_0080bb44 = 0;
  DAT_0080bb4d = 0;
  _DAT_0080bb50 = 0;
  DAT_0080bb59 = 0;
  _DAT_0080bb68 = 0;
  DAT_0080bb71 = 0;
  DAT_0080bb40 = 1;
  _DAT_0080bb48 = 1;
  DAT_0080bb4c = 1;
  _DAT_0080bb54 = 2;
  DAT_0080bb58 = 1;
  _DAT_0080bb6c = 4;
  DAT_0080bb70 = 1;
  return;
}


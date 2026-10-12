/* Ghidra pseudocode, not original source.
 * ev_a85b3e4898e579c25a43afce2c9968e46b76c95f9b8b71b7b173505cf03a6bab
 * Entry: 0x4a4900; label: FUN_004a4900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a4900(int param_1,int param_2,float param_3,undefined4 param_4)

{
  DAT_0087b8c8 = param_1;
  if (param_1 != 0) {
    param_2 = param_1 + 0x80;
  }
  _DAT_0087b890 = param_3;
  DAT_0087b8cc = param_2;
  DAT_0087b8d0 = param_4;
  _DAT_0087b894 = param_3 * param_3;
  return;
}


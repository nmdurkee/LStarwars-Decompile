/* Ghidra pseudocode, not original source.
 * ev_0482cf9cbac4014c2cc66ca9c1732d06d5723bc39accc7934085547e48d62c38
 * Entry: 0x5c3880; label: FUN_005c3880
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005c3880(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_0080bf24 == param_1) {
    return DAT_0097acc4;
  }
  DAT_0080bf24 = param_1;
  if (DAT_0080bb68 != 0) {
    if (DAT_0080bb71 == '\0') {
      FUN_005f8ba0(DAT_0080bb6c,DAT_0080bb70);
      DAT_0080bb71 = '\x01';
    }
    DAT_0097acc4 = DAT_0080bb68;
    return DAT_0080bb68;
  }
  FUN_005f8ba0(4,0);
  uVar1 = FUN_005f8a50();
  DAT_0097acc4 = FUN_005f8a80(uVar1,4,0,0);
  return DAT_0097acc4;
}


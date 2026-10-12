/* Ghidra pseudocode, not original source.
 * ev_6fa6af6f6c20542b4b3f476ed9727be59ab920ff8cd58abbde73c8c49552840b
 * Entry: 0x5ca3d0; label: FUN_005ca3d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_005ca3d0(undefined1 param_1)

{
  undefined1 uVar1;
  
  uVar1 = DAT_009737de;
  if (DAT_00973888 < 4) {
    (&DAT_0096e4e8)[DAT_00973888] = DAT_009737de;
    DAT_00973888 = DAT_00973888 + 1;
    DAT_009737de = param_1;
    return uVar1;
  }
  return 0;
}


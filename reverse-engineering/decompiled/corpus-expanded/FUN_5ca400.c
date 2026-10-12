/* Ghidra pseudocode, not original source.
 * ev_6fa6af6f6c20542b4b3f476ed9727be59ab920ff8cd58abbde73c8c49552840b
 * Entry: 0x5ca400; label: FUN_005ca400
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005ca400(void)

{
  int iVar1;
  
  iVar1 = DAT_00973888;
  if (DAT_00973888 != 0) {
    DAT_00973888 = DAT_00973888 + -1;
    DAT_009737de = (&DAT_0096e4e7)[iVar1];
    return CONCAT31((int3)((uint)DAT_00973888 >> 8),(&DAT_0096e4e7)[iVar1]);
  }
  return 0;
}


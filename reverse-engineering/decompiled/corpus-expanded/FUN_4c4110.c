/* Ghidra pseudocode, not original source.
 * ev_70591197c926ebc674651557d03c19c52d1cbc8417e398ad949c9ada842aa1a9
 * Entry: 0x4c4110; label: FUN_004c4110
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004c4110(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_008800a0 != (code *)0x0) {
    iVar1 = (*DAT_008800a0)(param_1);
    if (iVar1 == 5) {
      return 1;
    }
    if (iVar1 == 6) {
      DAT_008800a0 = (code *)(&DAT_008801c0)[DAT_008800f8];
      (&DAT_008801c0)[DAT_008800f8] = 0;
      DAT_008800f8 = DAT_008800f8 + -1;
      if (DAT_008800f8 < 0) {
        DAT_008800f8 = 0;
      }
      DAT_008800e0 = (&DAT_0087c4e0)[DAT_00880154];
      (&DAT_0087c4e0)[DAT_00880154] = 0;
      DAT_00880154 = DAT_00880154 + -1;
      DAT_0087bf8c = 0;
      if (DAT_00880154 < 0) {
        DAT_00880154 = 0;
      }
    }
  }
  return 0;
}


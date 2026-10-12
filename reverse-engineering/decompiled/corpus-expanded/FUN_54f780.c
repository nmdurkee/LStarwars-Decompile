/* Ghidra pseudocode, not original source.
 * ev_5bb5b933382fccff1624478c543279b7c4a11e7bde078056255cfa1f5dfacd26
 * Entry: 0x54f780; label: FUN_0054f780
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0054f780(int param_1)

{
  float fVar1;
  
  if (((DAT_00802874 != -1) && (*(char *)(param_1 + 0x7b5) == DAT_00802874)) &&
     ((*(char *)(param_1 + 0x7b3) == '\x01' ||
      ((*(char *)(param_1 + 0x7b3) == '\0' &&
       (fVar1 = *(float *)(param_1 + 0x784), !NAN(fVar1) && 0.5 < fVar1 != (fVar1 == 0.5))))))) {
    return 1;
  }
  return 0;
}


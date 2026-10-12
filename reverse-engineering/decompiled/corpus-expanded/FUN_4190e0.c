/* Ghidra pseudocode, not original source.
 * ev_a5c3a3c7ef2e1a12e467fd0202ed50a9ce8374cc5ec0bfb4f993dbf776f2abbe
 * Entry: 0x4190e0; label: FUN_004190e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004190e0(int param_1)

{
  int iVar1;
  
  if ((((DAT_0093b2a4 == 0) && (*(short *)(param_1 + 0x1064) == DAT_007f19cc)) &&
      (iVar1 = *(int *)(PTR_DAT_00802c54 + 300), iVar1 != 0)) &&
     ((iVar1 == DAT_0087af74 || (iVar1 == DAT_0087af7c)))) {
    return 1;
  }
  return 0;
}


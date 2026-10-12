/* Ghidra pseudocode, not original source.
 * ev_dd26b1472d11f86911997a5210ef83804c7265178bcab9b4c8b40141cd7b855f
 * Entry: 0x4d23e0; label: FUN_004d23e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004d23e0(int param_1)

{
  short sVar1;
  
  if ((param_1 != 0) &&
     ((((sVar1 = *(short *)(param_1 + 0x1064), sVar1 == DAT_007f1960 || (sVar1 == DAT_007f1ad4)) ||
       (sVar1 == DAT_007f1964)) || ((sVar1 == DAT_007f1adc || (sVar1 == DAT_007f1ae0)))))) {
    return 5;
  }
  return 3;
}


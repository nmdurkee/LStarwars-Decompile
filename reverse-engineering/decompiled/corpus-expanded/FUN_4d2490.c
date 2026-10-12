/* Ghidra pseudocode, not original source.
 * ev_dd26b1472d11f86911997a5210ef83804c7265178bcab9b4c8b40141cd7b855f
 * Entry: 0x4d2490; label: FUN_004d2490
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004d2490(char param_1)

{
  int in_ECX;
  
  if (in_ECX != 0) {
    if (param_1 == '\0') {
      FUN_00567800();
    }
    else {
      if (param_1 == '\x01') {
        FUN_005ad540(PTR_DAT_00802c54);
        return;
      }
      if (param_1 == '\x02') {
        FUN_00558a70(PTR_DAT_00802c54);
        return;
      }
    }
  }
  return;
}


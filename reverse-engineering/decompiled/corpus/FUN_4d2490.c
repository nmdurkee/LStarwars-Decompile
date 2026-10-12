/* Ghidra analysis pseudocode, not original source.
 * ev_9ea77467f72f0a730098339cc8760ef11d2ea4126d873e77c8bb761228bbcc9d
 * Entry: 0x4d2490; label: FUN_004d2490
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


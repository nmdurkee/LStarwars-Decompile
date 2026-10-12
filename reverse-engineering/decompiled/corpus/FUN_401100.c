/* Ghidra analysis pseudocode, not original source.
 * ev_4eb19e57a9d3b9beba017312b3b21652588e9c732adfcebbbddaeb757a53089f
 * Entry: 0x401100; label: FUN_00401100
 */

void FUN_00401100(void)

{
  int in_EAX;
  int in_ECX;
  
  for (; 0 < in_ECX; in_ECX = in_ECX + -1) {
    FUN_006d3430(in_ECX,in_EAX);
    in_EAX = in_EAX + 4;
  }
  DAT_00876580 = 0;
  DAT_007f39e4 = 1;
  return;
}


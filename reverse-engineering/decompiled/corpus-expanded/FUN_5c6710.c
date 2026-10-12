/* Ghidra pseudocode, not original source.
 * ev_27b4776215878f137ff0909fe422d2d71d1f91aa156c4f9d6b43512fc3378c0f
 * Entry: 0x5c6710; label: FUN_005c6710
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c6710(void)

{
  undefined1 in_AL;
  int in_ECX;
  
  switch(in_AL) {
  case 0:
    *(undefined1 *)(in_ECX + 1) = 0;
    return;
  case 1:
    *(undefined1 *)(in_ECX + 1) = 1;
    return;
  case 3:
    *(undefined1 *)(in_ECX + 1) = 3;
    return;
  case 4:
    *(undefined1 *)(in_ECX + 1) = 4;
  }
  return;
}


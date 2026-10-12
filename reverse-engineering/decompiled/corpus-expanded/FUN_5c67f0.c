/* Ghidra pseudocode, not original source.
 * ev_27b4776215878f137ff0909fe422d2d71d1f91aa156c4f9d6b43512fc3378c0f
 * Entry: 0x5c67f0; label: FUN_005c67f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c67f0(void)

{
  undefined1 *in_EAX;
  undefined4 in_ECX;
  
  *in_EAX = 0x80;
  *(undefined4 *)(in_EAX + 4) = in_ECX;
  in_EAX[1] = 3;
  return;
}


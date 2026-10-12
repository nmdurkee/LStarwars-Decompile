/* Ghidra analysis pseudocode, not original source.
 * ev_64710b70227263f531e000337bf3c7b84d0ba3dbee751b1080463e073dfde27a
 * Entry: 0x6e2390; label: FUN_006e2390
 */

void FUN_006e2390(char param_1)

{
  int in_ECX;
  
  FUN_006e56c0(*(undefined4 *)(in_ECX + 0x684));
  FUN_006e5590(0,*(undefined4 *)(in_ECX + 0x688),0,0x10);
  if (param_1 != '\0') {
    FUN_006e5290(0);
  }
  FUN_006e4980(4,0,1);
  return;
}


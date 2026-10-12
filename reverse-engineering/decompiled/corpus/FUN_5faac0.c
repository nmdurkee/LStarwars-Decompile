/* Ghidra analysis pseudocode, not original source.
 * ev_7bd2508c4b1dcfad55b57fc1ea402f6c06ab2cec8e89f22b5b974cf1cad07afb
 * Entry: 0x5faac0; label: FUN_005faac0
 */

int FUN_005faac0(undefined2 param_1,undefined2 param_2)

{
  int in_EAX;
  int in_ECX;
  int extraout_ECX;
  
  if ((0x328 < in_EAX) || (in_EAX < 0)) {
    in_EAX = FUN_005f7490();
    in_ECX = extraout_ECX;
  }
  *(undefined2 *)(in_ECX + in_EAX * 4) = param_1;
  *(undefined2 *)(in_ECX + 2 + in_EAX * 4) = param_2;
  return in_EAX + 1;
}


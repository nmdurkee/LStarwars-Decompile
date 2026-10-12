/* Ghidra pseudocode, not original source.
 * ev_63eb9bd68174043ae1497f20c7ab174ab5c86e6d078dec24e1a9d3709ec9fcaa
 * Entry: 0x5faac0; label: FUN_005faac0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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


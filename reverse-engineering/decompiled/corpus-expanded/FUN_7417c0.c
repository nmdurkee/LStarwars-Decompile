/* Ghidra pseudocode, not original source.
 * ev_d6810b63b1adbb1cff68d70c4de6dcedf5c7ec9f8161f7a4b49c43fe0c68c9ee
 * Entry: 0x7417c0; label: FUN_007417c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_007417c0(undefined2 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                 undefined1 param_5)

{
  undefined2 *in_EAX;
  undefined2 in_CX;
  
  *in_EAX = in_CX;
  in_EAX[1] = param_1;
  *(undefined1 *)(in_EAX + 2) = param_2;
  *(undefined1 *)((int)in_EAX + 5) = param_3;
  *(undefined1 *)(in_EAX + 3) = param_4;
  *(undefined1 *)((int)in_EAX + 7) = param_5;
  return;
}


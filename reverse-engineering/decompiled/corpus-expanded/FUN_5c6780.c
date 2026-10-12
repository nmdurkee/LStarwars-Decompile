/* Ghidra pseudocode, not original source.
 * ev_27b4776215878f137ff0909fe422d2d71d1f91aa156c4f9d6b43512fc3378c0f
 * Entry: 0x5c6780; label: FUN_005c6780
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c6780(undefined1 param_1,undefined4 param_2)

{
  undefined1 *in_EAX;
  undefined1 in_CL;
  
  *in_EAX = in_CL;
  *(undefined4 *)(in_EAX + 4) = param_2;
  switch(param_1) {
  case 0:
    in_EAX[1] = 0;
    return;
  case 1:
    in_EAX[1] = 1;
    return;
  case 3:
    in_EAX[1] = 3;
    return;
  case 4:
    in_EAX[1] = 4;
  }
  return;
}


/* Ghidra pseudocode, not original source.
 * ev_f88dcc3d8d52db9817d56bdb32315046821db5231446aa7c2a0f18fee0dcf233
 * Entry: 0x5fc9f0; label: FUN_005fc9f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005fc9f0(undefined1 param_1,undefined4 param_2)

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


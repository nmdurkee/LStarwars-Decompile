/* Ghidra pseudocode, not original source.
 * ev_cc6b5d9c9dc19119c5b50c1e1d885dc592b880ad73e24652555bc61e14428cde
 * Entry: 0x6c8c20; label: FUN_006c8c20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c8c20(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x68) = param_1;
  switch(param_1) {
  case 0:
  case 1:
  case 2:
    *(undefined ***)(in_ECX + 0x20) = &PTR_PTR_0081faf0;
    FUN_006c58a0();
    return;
  case 3:
    *(undefined ***)(in_ECX + 0x20) = &PTR_PTR_0081fb70;
    FUN_006c58a0();
    return;
  case 4:
    *(undefined ***)(in_ECX + 0x20) = &PTR_PTR_0081fbf0;
    FUN_006c58a0();
    return;
  case 5:
    *(undefined ***)(in_ECX + 0x20) = &PTR_PTR_0081fc70;
  }
  FUN_006c58a0();
  return;
}


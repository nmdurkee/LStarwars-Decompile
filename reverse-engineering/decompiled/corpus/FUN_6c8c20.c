/* Ghidra analysis pseudocode, not original source.
 * ev_e0849b30759777b1ea42e04473fa04c4a6f69ff919b3575aa742b133a483e34a
 * Entry: 0x6c8c20; label: FUN_006c8c20
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


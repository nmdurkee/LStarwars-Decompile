/* Ghidra pseudocode, not original source.
 * ev_cc6b5d9c9dc19119c5b50c1e1d885dc592b880ad73e24652555bc61e14428cde
 * Entry: 0x6c8ad0; label: FUN_006c8ad0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006c8ad0(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  FUN_006be450(param_1,param_2,0x20,0x20,10,1);
  FUN_006c6110();
  DAT_0081fae4 = 0;
  _DAT_0081fae8 = *(undefined4 *)(in_ECX + 0x14);
  if (*(int *)(in_ECX + 0x14) != 0) {
    *(undefined ***)(*(int *)(in_ECX + 0x14) + 4) = &PTR_PTR_0081fae0;
  }
  *(undefined ***)(in_ECX + 0x14) = &PTR_PTR_0081fae0;
  if (*(int *)(in_ECX + 0x10) == 0) {
    *(undefined ***)(in_ECX + 0x10) = &PTR_PTR_0081fae0;
  }
  *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
  _DAT_0081fe24 = 0;
  _DAT_0081fe28 = *(undefined4 *)(in_ECX + 0x14);
  if (*(int *)(in_ECX + 0x14) != 0) {
    *(undefined ***)(*(int *)(in_ECX + 0x14) + 4) = &PTR_PTR_0081fe20;
  }
  *(undefined ***)(in_ECX + 0x14) = &PTR_PTR_0081fe20;
  if (*(int *)(in_ECX + 0x10) == 0) {
    *(undefined ***)(in_ECX + 0x10) = &PTR_PTR_0081fe20;
  }
  *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
  *(undefined ***)(in_ECX + 0x1c) = &PTR_PTR_0081fae0;
  return;
}


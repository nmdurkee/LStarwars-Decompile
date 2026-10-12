/* Ghidra analysis pseudocode, not original source.
 * ev_a0c592da085b7a74f005db934e1c866d8df8930552270784c21655c1c3dfc310
 * Entry: 0x6af210; label: FUN_006af210
 */

void FUN_006af210(int *param_1,int param_2)

{
  void *pvVar1;
  
  *param_1 = param_2;
  pvVar1 = _calloc(param_2 * 3,4);
  param_1[1] = (int)pvVar1;
  pvVar1 = _calloc(0x20,4);
  param_1[2] = (int)pvVar1;
  if (param_2 != 1) {
    FUN_006a9e30(param_2,param_1[1] + param_2 * 4,pvVar1);
  }
  return;
}


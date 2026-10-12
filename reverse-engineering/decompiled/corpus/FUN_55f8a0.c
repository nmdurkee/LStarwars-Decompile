/* Ghidra analysis pseudocode, not original source.
 * ev_b8818be8b1d42ca956a2be2988b1e4995be83f28184475e50ebee2db8720dc05
 * Entry: 0x55f8a0; label: FUN_0055f8a0
 */

undefined4 FUN_0055f8a0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *in_ECX;
  int in_EDX;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((DAT_00803b70 == -1) ||
     (iVar3 = *(int *)(*(int *)(in_EDX + 0x2ac4) + DAT_00803b70 * 4), iVar3 == 0)) {
    return 0;
  }
  if (in_ECX == (undefined4 *)0x0) {
    iVar2 = FUN_0055e340(&local_c,0);
    if (iVar2 == 0) {
      return 0;
    }
  }
  else {
    local_c = *in_ECX;
    local_8 = in_ECX[1];
    local_4 = in_ECX[2];
  }
  puVar1 = *(undefined4 **)(iVar3 + 8);
  iVar3 = FUN_00550cf0(local_c,local_4,*puVar1,puVar1[2],puVar1[3],puVar1[5]);
  if (iVar3 == 0) {
    DAT_00802c5c = param_2;
    return 1;
  }
  DAT_00802c5c = param_1;
  return 1;
}


/* Ghidra analysis pseudocode, not original source.
 * ev_49f26c3128d8416ab7d2a78e52c78c067d57c30a907ee8cca08757c1961064c2
 * Entry: 0x60e1b0; label: FUN_0060e1b0
 */

void FUN_0060e1b0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  int *piVar3;
  
  iVar1 = FUN_00633440(0x250,1);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_0060e120(param_1,param_2,param_3);
  }
  piVar3 = *(int **)(in_ECX + 4);
  if (piVar3 != (int *)0x0) {
    do {
      if ((piVar3[2] == puVar2[2]) && ((char)piVar3[3] == *(char *)(puVar2 + 3))) {
        FUN_006334d0(puVar2,0x250);
        return;
      }
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)0x0);
  }
  *puVar2 = 0;
  puVar2[1] = *(undefined4 *)(in_ECX + 8);
  if (*(undefined4 **)(in_ECX + 8) != (undefined4 *)0x0) {
    **(undefined4 **)(in_ECX + 8) = puVar2;
  }
  *(undefined4 **)(in_ECX + 8) = puVar2;
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 **)(in_ECX + 4) = puVar2;
  }
  *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + 1;
  return;
}


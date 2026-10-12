/* Ghidra analysis pseudocode, not original source.
 * ev_25f1bb0fd3b13d30151a1bfb26bccad5e839f981975d2103181562bea11eb120
 * Entry: 0x501540; label: FUN_00501540
 */

void FUN_00501540(int *param_1)

{
  int iVar1;
  int *in_ECX;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  if ((char)in_ECX[2] != '\0') {
    iVar3 = 0;
    do {
      iVar1 = *param_1;
      *(undefined4 *)(iVar1 + uVar2 * 8) = 0;
      if ((*(byte *)(in_ECX[1] + 4 + (uint)*(byte *)(iVar3 + 0x59 + *in_ECX) * 0xc) & 0x10) != 0) {
        *(undefined4 *)(iVar1 + uVar2 * 8 + 4) = 0xffffffff;
      }
      uVar2 = uVar2 + 1;
      iVar3 = iVar3 + 100;
    } while (uVar2 < *(byte *)(in_ECX + 2));
  }
  return;
}


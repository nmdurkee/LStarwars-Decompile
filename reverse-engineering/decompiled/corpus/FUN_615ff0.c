/* Ghidra analysis pseudocode, not original source.
 * ev_f69f911d5171d962ef70197e58b92155315effa295abdaf930a75dc3063ba02e
 * Entry: 0x615ff0; label: FUN_00615ff0
 */

void FUN_00615ff0(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_006153c0(*(int *)(in_ECX + 4),in_ECX,1);
    iVar1 = *(int *)(in_ECX + 4);
    if (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 4);
      if (iVar2 != 0) {
        if (*(uint *)(iVar2 + 0x4b0) < 2) {
          *(undefined4 *)(iVar2 + 0x4b0) = 0;
        }
        else {
          *(uint *)(iVar2 + 0x4b0) = *(uint *)(iVar2 + 0x4b0) - 1;
        }
      }
      FUN_006334d0(iVar1,0x10);
    }
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  if (*(int *)(in_ECX + 8) != 0) {
    FUN_006153c0(*(int *)(in_ECX + 8),in_ECX,0);
    iVar1 = *(int *)(in_ECX + 8);
    if (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 4);
      if (iVar2 != 0) {
        if (1 < *(uint *)(iVar2 + 0x4b0)) {
          *(uint *)(iVar2 + 0x4b0) = *(uint *)(iVar2 + 0x4b0) - 1;
          FUN_006334d0(iVar1,0x10);
          *(undefined4 *)(in_ECX + 8) = 0;
          return;
        }
        *(undefined4 *)(iVar2 + 0x4b0) = 0;
      }
      FUN_006334d0(iVar1,0x10);
    }
    *(undefined4 *)(in_ECX + 8) = 0;
  }
  return;
}


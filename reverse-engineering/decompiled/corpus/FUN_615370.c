/* Ghidra analysis pseudocode, not original source.
 * ev_f69f911d5171d962ef70197e58b92155315effa295abdaf930a75dc3063ba02e
 * Entry: 0x615370; label: FUN_00615370
 */

void FUN_00615370(byte param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if (*(uint *)(iVar1 + 0x4b0) < 2) {
      *(undefined4 *)(iVar1 + 0x4b0) = 0;
    }
    else {
      *(uint *)(iVar1 + 0x4b0) = *(uint *)(iVar1 + 0x4b0) - 1;
    }
  }
  if ((param_1 & 1) != 0) {
    FUN_006334d0(in_ECX,0x10);
  }
  return;
}


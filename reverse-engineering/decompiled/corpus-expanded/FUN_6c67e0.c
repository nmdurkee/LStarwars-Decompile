/* Ghidra pseudocode, not original source.
 * ev_647b85ee0a7e8e41d889ce710347a98583a3d140d8a364c007ecae69f59044b8
 * Entry: 0x6c67e0; label: FUN_006c67e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c67e0(int param_1)

{
  int iVar1;
  int in_ECX;
  
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(in_ECX + 0xc);
  if (*(int *)(in_ECX + 0xc) != 0) {
    *(int *)(*(int *)(in_ECX + 0xc) + 4) = param_1;
  }
  *(int *)(in_ECX + 0xc) = param_1;
  if (*(int *)(in_ECX + 8) == 0) {
    *(int *)(in_ECX + 8) = param_1;
  }
  *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + 1;
  *(uint *)(in_ECX + 4) = *(uint *)(in_ECX + 4) | *(uint *)(param_1 + 0x1c) & 0x17a;
  if ((*(uint *)(param_1 + 0x1c) & 0x80000000) != 0) {
    iVar1 = *(int *)(param_1 + 0xc);
    if ((-1 < iVar1) && (iVar1 < DAT_02973bac)) {
      *(uint *)(in_ECX + 4) =
           *(uint *)(DAT_02973b90 + iVar1 * 0x18 + 4) & 0x17a | *(uint *)(in_ECX + 4);
      return;
    }
    *(uint *)(in_ECX + 4) = uRam00000004 & 0x17a | *(uint *)(in_ECX + 4);
  }
  return;
}


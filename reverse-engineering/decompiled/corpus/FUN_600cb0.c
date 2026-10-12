/* Ghidra analysis pseudocode, not original source.
 * ev_17b66c49ee27a79138b1f69ed50983bbb8f85fa72fbf9f24d2924e74b686a814
 * Entry: 0x600cb0; label: FUN_00600cb0
 */

void FUN_00600cb0(int param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x110) == 0) {
    iVar2 = 0;
    if (0 < *(int *)(param_1 + 0x1c)) {
      iVar3 = 0;
      do {
        puVar1 = (uint *)(*(int *)(param_1 + 0x20) + 0x44 + iVar3);
        *puVar1 = *puVar1 & 0xfffffffb;
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x50;
      } while (iVar2 < *(int *)(param_1 + 0x1c));
    }
    return;
  }
  _memset(&DAT_0280a2f0,0,0x271);
  return;
}


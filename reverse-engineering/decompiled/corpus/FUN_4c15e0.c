/* Ghidra analysis pseudocode, not original source.
 * ev_d6cfc7f984a94bc477afc350e10de4c03e30e64e3e924293972bd20ad72e1aa6
 * Entry: 0x4c15e0; label: FUN_004c15e0
 */

void FUN_004c15e0(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  if (DAT_00855efe != 0) {
    iVar3 = 0;
    iVar2 = 0;
    do {
      uVar1 = *(undefined4 *)(iVar2 + 4 + DAT_00855ef8);
      *(undefined2 *)(iVar3 + 0x60 + DAT_00880478) = *(undefined2 *)(iVar2 + DAT_00855ef8);
      *(undefined4 *)(iVar3 + 100 + DAT_00880478) = uVar1;
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + 0x1c;
      iVar3 = iVar3 + 0x74;
    } while (iVar4 < (int)(uint)DAT_00855efe);
  }
  return;
}


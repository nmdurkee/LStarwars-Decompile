/* Ghidra analysis pseudocode, not original source.
 * ev_51d776bbf7e198208a4486308eec4a97f7acd5ccc3951e1c43c2ae0a52a9ca8f
 * Entry: 0x6c5a20; label: FUN_006c5a20
 */

void FUN_006c5a20(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  int in_ECX;
  
  iVar1 = *(int *)(param_1 + 8);
  bVar4 = true;
  *(undefined4 *)(iVar1 + 0x14) = 0x14;
  *(undefined4 *)(iVar1 + 0x18) = 5;
  do {
    bVar5 = true;
    for (puVar2 = *(undefined4 **)(in_ECX + 0xc); puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)*puVar2) {
      iVar3 = puVar2[2];
      if (iVar3 != iVar1) {
        bVar4 = false;
        if ((*(int *)(iVar3 + 0x14) <= *(int *)(iVar1 + 0x1c) + *(int *)(iVar1 + 0x14)) &&
           (*(int *)(iVar1 + 0x14) <= *(int *)(iVar3 + 0x1c) + *(int *)(iVar3 + 0x14))) {
          bVar5 = false;
          *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 10;
          goto LAB_006c5aa8;
        }
      }
    }
    if (bVar4) {
      *(undefined4 *)(iVar1 + 0x14) = DAT_0081f9e8;
      *(undefined4 *)(iVar1 + 0x18) = DAT_0081f9ec;
      *(undefined4 *)(iVar1 + 0x1c) = DAT_0081f9f0;
      *(undefined4 *)(iVar1 + 0x20) = DAT_0081f9f4;
    }
LAB_006c5aa8:
    if (640.0 < (double)(*(int *)(iVar1 + 0x1c) + *(int *)(iVar1 + 0x14))) {
      *(undefined4 *)(iVar1 + 0x14) = 0x14;
      *(undefined4 *)(iVar1 + 0x18) = 5;
      return;
    }
    if (bVar5) {
      return;
    }
  } while( true );
}


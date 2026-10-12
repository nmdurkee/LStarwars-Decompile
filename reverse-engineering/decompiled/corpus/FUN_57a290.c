/* Ghidra analysis pseudocode, not original source.
 * ev_0fe45ae231fd2dfd40158a7785e6912069fa204ac07eb0ac56676de85047f6bb
 * Entry: 0x57a290; label: FUN_0057a290
 */

void FUN_0057a290(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  if ((DAT_00951bb8 != 0) && (iVar4 = 0, 0 < DAT_00951bbc)) {
    iVar5 = 0;
    do {
      *(undefined2 *)(*(int *)(param_1 + 0x2ac0) + 0xc + iVar5) = 0xffff;
      if (((*(int *)(param_1 + 0x295c) != 0) &&
          (iVar2 = FUN_005cfac0(*(int *)(param_1 + 0x2ac0) + iVar5), iVar2 != 0)) &&
         (*(char *)(DAT_00951bb8 + iVar4 * 8) == '\x01')) {
        uVar3 = FUN_005cffb0(*(int *)(param_1 + 0x2ac0) + iVar5);
        uVar1 = FUN_0067c760(uVar3);
        *(undefined2 *)(*(int *)(param_1 + 0x2ac0) + 0xc + iVar5) = uVar1;
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x10;
    } while (iVar4 < DAT_00951bbc);
  }
  return;
}


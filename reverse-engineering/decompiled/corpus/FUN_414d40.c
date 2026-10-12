/* Ghidra analysis pseudocode, not original source.
 * ev_c05bc3de3023c0a6cb52f4e362146021e78fd9035a9b4ae5f12ca5d880999daa
 * Entry: 0x414d40; label: FUN_00414d40
 */

int FUN_00414d40(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  
  iVar5 = 0;
  iVar6 = 0;
  if (0 < param_1) {
    puVar2 = &DAT_0093d517;
    do {
      iVar1 = (&DAT_0093d7f0)[iVar6];
      if (iVar1 != 0) {
        if (DAT_00855f7c == 1) {
          uVar4 = *(undefined2 *)(&DAT_0087a840 + iVar6);
LAB_00414d89:
          (&DAT_0093d590)[iVar5] = uVar4;
        }
        else if (DAT_00855f7c != 2) {
          uVar4 = *(undefined2 *)(iVar1 + 0x1064);
          goto LAB_00414d89;
        }
        puVar2[-1] = (byte)(*(uint *)(iVar1 + 0x1fc) >> 7) & 1;
        if (((*(char *)(iVar1 + 0x7b5) == '\x06') || (*(char *)(iVar1 + 0xe33) == '\x02')) ||
           (((*(byte *)(iVar1 + 0xe22) & 1) == 0 && (*(char *)(iVar1 + 0xe33) == '\0')))) {
          *puVar2 = 0;
        }
        else {
          *puVar2 = 1;
        }
        if (*(undefined4 **)(iVar1 + 0x7fc) == (undefined4 *)0x0) {
          *(undefined4 *)(puVar2 + -7) = 0;
        }
        else {
          *(undefined4 *)(puVar2 + -7) = **(undefined4 **)(iVar1 + 0x7fc);
        }
        puVar2[4] = *(char *)(iVar1 + 0xe32) == '\x01';
        if (*(char *)(iVar1 + 0x28b) == '\0') {
          puVar2[1] = *(undefined1 *)(iVar1 + 0x107f);
          puVar2[2] = *(undefined1 *)(iVar1 + 0xe39);
        }
        else {
          puVar2[1] = *(undefined1 *)(iVar1 + 0x107e);
          puVar2[2] = 4;
        }
        puVar2[3] = *(undefined1 *)(iVar1 + 0x1082);
        *(undefined2 *)(puVar2 + -3) = *(undefined2 *)(iVar1 + 0x1062);
        *(undefined4 *)(puVar2 + 5) = *(undefined4 *)(iVar1 + 0xdec);
        (&DAT_00855e84)[iVar5] = *(undefined4 *)(iVar1 + 0xcbc);
        if (*(undefined1 **)(iVar1 + 0xcc4) == (undefined1 *)0x0) {
          (&DAT_00881258)[iVar5] = 0;
        }
        else {
          (&DAT_00881258)[iVar5] = **(undefined1 **)(iVar1 + 0xcc4);
        }
        iVar5 = iVar5 + 1;
        puVar2 = puVar2 + 0x10;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_1);
  }
  DAT_00855f7c = 0;
  if (iVar5 < 8) {
    puVar7 = (undefined4 *)(&DAT_0093d590 + iVar5);
    for (uVar3 = 8U - iVar5 >> 1; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar7 = 0xffffffff;
      puVar7 = puVar7 + 1;
    }
    for (uVar3 = (uint)((8U - iVar5 & 1) != 0); uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined2 *)puVar7 = 0xffff;
      puVar7 = (undefined4 *)((int)puVar7 + 2);
    }
  }
  return iVar5;
}


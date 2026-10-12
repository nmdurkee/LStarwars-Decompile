/* Ghidra analysis pseudocode, not original source.
 * ev_1b769233bdb8589f5b6c19d1b053d2efd2e6005a2a8cafb96b11ff416f994ddb
 * Entry: 0x4e7090; label: FUN_004e7090
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e7090(int param_1)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  
  FUN_004e6b70();
  iVar5 = 0;
  bVar4 = DAT_0087aa20;
  do {
    iVar1 = (&DAT_0088a4d0)[iVar5];
    if (iVar1 != 0) {
      bVar3 = (byte)iVar5;
      if (((*(byte *)(iVar1 + 0x94) & 1) == 0) || ((bVar4 & (byte)(1 << (bVar3 & 0x1f))) != 0)) {
        if ((iVar1 != 0) &&
           (((*(byte *)(iVar1 + 0x94) & 1) == 0 && ((bVar4 & (byte)(1 << (bVar3 & 0x1f))) != 0)))) {
          bVar4 = bVar4 & ~('\x01' << (bVar3 & 0x1f));
          DAT_0087aa20 = bVar4;
        }
      }
      else {
        DAT_0087aa20 = bVar4 | '\x01' << (bVar3 & 0x1f);
        FUN_0046d780(iVar1 + 0x30,0xffffffff,0xffffffff,1);
        bVar4 = DAT_0087aa20;
      }
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 4);
  iVar5 = 0;
  do {
    iVar1 = *(int *)((int)&DAT_0093d7f0 + iVar5);
    if (iVar1 == 0) {
LAB_004e720d:
      *(undefined4 *)((int)&DAT_0087a9cc + iVar5) = 0;
    }
    else {
      if (((*(short *)(iVar1 + 0x1064) != DAT_007f19a4) || (DAT_0087a95c == 0)) ||
         (uVar2 = 1 << ((byte)(DAT_0087a95c - *(int *)(*(int *)(param_1 + 0x2ae8) + 0x38) >> 6) &
                       0x1f),
         (uVar2 & *(uint *)(iVar1 + 0x2b0)) == 0 &&
         ((int)uVar2 >> 0x1f & *(uint *)(iVar1 + 0x2b4)) == 0)) {
        if ((iVar1 != 0) && (*(short *)(iVar1 + 0x1064) == DAT_007f19a4)) {
          if (0.0 < *(float *)((int)&DAT_0087a9cc + iVar5)) {
            *(float *)((int)&DAT_0087a9cc + iVar5) =
                 *(float *)((int)&DAT_0087a9cc + iVar5) - _DAT_00925018;
            goto LAB_004e7215;
          }
          *(uint *)(iVar1 + 0x1048) = *(uint *)(iVar1 + 0x1048) & 0xfffffff7;
          DAT_0088a531 = 0;
        }
        goto LAB_004e720d;
      }
      if (2.0 < *(float *)((int)&DAT_0087a9cc + iVar5) ==
          (*(float *)((int)&DAT_0087a9cc + iVar5) == 2.0)) {
        *(float *)((int)&DAT_0087a9cc + iVar5) =
             _DAT_00925018 + *(float *)((int)&DAT_0087a9cc + iVar5);
      }
      else {
        *(undefined4 *)((int)&DAT_0087a9cc + iVar5) = 0x40000000;
        *(uint *)(iVar1 + 0x1048) = *(uint *)(iVar1 + 0x1048) | 8;
        FUN_004e6d40(*(undefined4 *)((int)&DAT_0093d7f0 + iVar5));
        DAT_0088a531 = 1;
      }
    }
LAB_004e7215:
    iVar5 = iVar5 + 4;
    if (7 < iVar5) {
      return;
    }
  } while( true );
}


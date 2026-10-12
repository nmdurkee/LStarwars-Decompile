/* Ghidra analysis pseudocode, not original source.
 * ev_22daf69c4a948facb72037c7642983d59ec5bfdbe162bc8de16c186a70e458b1
 * Entry: 0x43d0c0; label: FUN_0043d0c0
 */

void FUN_0043d0c0(int param_1)

{
  uint *puVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  
  if (param_1 != 0) {
    for (iVar3 = FUN_004f1440(param_1 + 0x10); iVar3 != 0;
        iVar3 = FUN_004f1460(param_1 + 0x10,iVar3)) {
      *(ushort *)(iVar3 + 0xa6) = *(ushort *)(iVar3 + 0xa6) & 0xffdf;
      switch(*(undefined1 *)(iVar3 + 0xa4)) {
      case 0:
        if (((*(ushort *)(iVar3 + 0xa6) & 4) == 0) ||
           (iVar4 = FUN_005cfd60(iVar3 + 0xc), iVar4 != 0)) {
          iVar4 = FUN_005d0420((int *)(iVar3 + 0xc));
          if ((iVar4 != 0) &&
             (iVar5 = *(int *)(*(int *)(iVar3 + 0xc) + 0x54),
             *(int *)(iVar5 + (uint)*(ushort *)(iVar4 + 0x5c) * 4) != 0)) {
            FUN_005ca4b0(*(undefined4 *)(iVar5 + (uint)*(ushort *)(iVar4 + 0x5c) * 4));
            iVar4 = FUN_006e6b90();
            if (0x400 < iVar4) {
              iVar4 = 0x400;
            }
            iVar5 = FUN_006e6b90();
            if (0 < iVar5) goto LAB_0043d180;
          }
LAB_0043d188:
          iVar5 = 1;
          goto LAB_0043d18d;
        }
        goto LAB_0043d26f;
      case 1:
        iVar4 = FUN_006e6b90();
        if (0x400 < iVar4) {
          iVar4 = 0x400;
        }
        iVar5 = FUN_006e6b90();
        if (iVar5 < 1) goto LAB_0043d188;
LAB_0043d180:
        if (iVar4 < iVar5) {
          iVar5 = iVar4;
        }
        goto LAB_0043d18d;
      case 2:
        bVar7 = *(char *)(*(int *)(iVar3 + 0xc) + 0x6d) == '\x02';
        goto LAB_0043d269;
      case 3:
        uVar6 = FUN_0055a1b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),*(undefined4 *)(iVar3 + 0xc)
                             ,*(undefined4 *)(iVar3 + 0x18),1);
        goto joined_r0x0043d3a7;
      case 4:
        if ((*(byte *)(*(int *)(iVar3 + 0xc) + 0x94) & 1) != 0) goto LAB_0043d26f;
        break;
      case 5:
        iVar4 = FUN_006e6b90();
        if (0x400 < iVar4) {
          iVar4 = 0x400;
        }
        iVar5 = FUN_006e6b90();
        if (iVar5 < 1) goto LAB_0043d188;
        if (iVar4 < iVar5) {
          iVar5 = iVar4;
        }
LAB_0043d18d:
        iVar5 = iVar5 + -1;
        uVar6 = 1 << ((byte)iVar5 & 0x1f) &
                *(uint *)(iVar3 + 0x24 + ((int)(iVar5 + (iVar5 >> 0x1f & 0x1fU)) >> 5) * 4);
        goto joined_r0x0043d3a7;
      case 6:
        if ((*(byte *)(*(int *)(iVar3 + 0xc) + 10) & 2) == 0) goto LAB_0043d26f;
        break;
      case 7:
        uVar6 = FUN_00467890(*(undefined4 *)(iVar3 + 0xc));
joined_r0x0043d3a7:
        if (uVar6 != 0) break;
LAB_0043d26f:
        *(byte *)(*(int *)(iVar3 + 8) + 0x16) = *(byte *)(iVar3 + 0xa6) >> 4 & 1;
        puVar1 = (uint *)(*(int *)(iVar3 + 8) + (*(byte *)(iVar3 + 0xa6) & 1) * 4);
        *puVar1 = *puVar1 & ~*(uint *)(iVar3 + 0x1c);
        puVar1 = (uint *)(*(int *)(iVar3 + 8) + (*(byte *)(iVar3 + 0xa6) & 1) * 4);
        *puVar1 = *puVar1 | *(uint *)(iVar3 + 0x20);
        if ((*(ushort *)(iVar3 + 0xa6) & 2) != 0) {
          puVar1 = (uint *)(*(int *)(iVar3 + 8) + ((byte)~(byte)*(ushort *)(iVar3 + 0xa6) & 1) * 4);
          *puVar1 = *puVar1 & ~*(uint *)(iVar3 + 0x1c);
          uVar6 = *(uint *)(iVar3 + 0x20);
          goto LAB_0043d2d0;
        }
        goto LAB_0043d2e5;
      case 8:
        bVar7 = *(int *)(*(int *)(*(int *)(iVar3 + 0xc) + 0x34) + 0xc) == 2;
LAB_0043d269:
        if (bVar7) break;
        goto LAB_0043d26f;
      case 9:
        uVar2 = *(ushort *)(*(int *)(iVar3 + 0xc) + 0x68);
        if (((uVar2 & 0x40) == 0) || (-1 < (char)uVar2)) goto LAB_0043d26f;
      }
      *(ushort *)(iVar3 + 0xa6) = *(ushort *)(iVar3 + 0xa6) | 0x20;
      *(byte *)(*(int *)(iVar3 + 8) + 0x16) = (byte)*(undefined2 *)(iVar3 + 0xa6) >> 3 & 1;
      puVar1 = (uint *)(*(int *)(iVar3 + 8) + (*(byte *)(iVar3 + 0xa6) & 1) * 4);
      *puVar1 = *puVar1 & ~*(uint *)(iVar3 + 0x20);
      puVar1 = (uint *)(*(int *)(iVar3 + 8) + (*(byte *)(iVar3 + 0xa6) & 1) * 4);
      *puVar1 = *puVar1 | *(uint *)(iVar3 + 0x1c);
      if ((*(ushort *)(iVar3 + 0xa6) & 2) != 0) {
        puVar1 = (uint *)(*(int *)(iVar3 + 8) + ((byte)~(byte)*(ushort *)(iVar3 + 0xa6) & 1) * 4);
        *puVar1 = *puVar1 & ~*(uint *)(iVar3 + 0x20);
        uVar6 = *(uint *)(iVar3 + 0x1c);
LAB_0043d2d0:
        puVar1 = (uint *)(*(int *)(iVar3 + 8) + ((byte)~*(byte *)(iVar3 + 0xa6) & 1) * 4);
        *puVar1 = *puVar1 | uVar6;
      }
LAB_0043d2e5:
    }
  }
  return;
}


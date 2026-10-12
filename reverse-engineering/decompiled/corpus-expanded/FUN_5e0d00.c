/* Ghidra pseudocode, not original source.
 * ev_a87fd181e19a595ed696a9e48a76c3177ea695d31392ba84c3867c15109a72c3
 * Entry: 0x5e0d00; label: FUN_005e0d00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e0d00(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  byte bVar7;
  byte *pbVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  int local_3c;
  int local_38;
  undefined1 local_34 [52];
  
  local_3c = 0;
  FUN_005fca40(local_34);
  for (iVar11 = DAT_00973ecc; iVar11 != 0; iVar11 = *(int *)(iVar11 + 8)) {
    iVar1 = *(int *)(iVar11 + 0x1c);
    if (iVar1 == 0) {
      FUN_005fca80(local_34,*(undefined4 *)(iVar11 + 4));
    }
    else if (((*(byte *)(iVar1 + 0x74) & 6) != 0) && (local_38 = 0, *(short *)(iVar11 + 0x20) != 0))
    {
      do {
        iVar3 = ((uint)*(ushort *)(iVar11 + 0x22) + local_38) * 4;
        iVar2 = *(int *)(iVar3 + *(int *)(iVar1 + 0x54));
        if (*(char *)(*(int *)(iVar2 + 0xc) + 1) == '\0') {
          iVar3 = *(int *)(iVar3 + *(int *)(iVar1 + 0x50));
          iVar4 = *(int *)(iVar1 + 0x80);
          if ((iVar4 == 0) || ((*(byte *)(iVar1 + 0x74) & 4) == 0)) {
            local_3c = 0;
          }
          else if (*(int *)(iVar2 + 0x14) == *(int *)(iVar2 + 0x10)) {
            if (local_3c != iVar4) {
              FUN_00607590(iVar2,iVar4);
              local_3c = *(int *)(iVar1 + 0x80);
            }
          }
          else {
            FUN_00607590(iVar2,iVar4);
            local_3c = *(int *)(iVar1 + 0x80);
          }
          puVar5 = *(undefined4 **)(iVar2 + 0x10);
          if (*(undefined4 **)(iVar2 + 0x14) == puVar5) {
            iVar4 = *(int *)(iVar2 + 0x28 + *(int *)(iVar2 + 0x34) * 4);
            if (iVar4 == *(int *)(iVar2 + 0x30)) {
              *(int *)(*(int *)(iVar2 + 0x18) + 4) = *(int *)(iVar2 + 0x18) + 0x10;
            }
            else {
              *(int *)(*(int *)(iVar2 + 0x18) + 4) = iVar4;
              **(undefined1 **)(iVar2 + 0x30) = 0x8d;
              *(undefined1 *)(*(int *)(iVar2 + 0x30) + 1) = 1;
              *(int *)(*(int *)(iVar2 + 0x30) + 4) = *(int *)(iVar2 + 0x18) + 0x10;
            }
          }
          else {
            puVar6 = *(undefined4 **)(iVar2 + 0x18);
            *puVar6 = *puVar5;
            puVar6[1] = puVar5[1];
            puVar6[2] = puVar5[2];
            puVar6[3] = puVar5[3];
            if ((*(byte *)(iVar1 + 0x74) & 4) == 0) {
              *(undefined4 *)(*(int *)(iVar2 + 0x14) + 4) =
                   *(undefined4 *)(*(int *)(iVar2 + 0xc) + 4);
              *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar2 + 0x10);
            }
            else {
              iVar4 = *(int *)(iVar2 + 0x28 + *(int *)(iVar2 + 0x34) * 4);
              if (iVar4 != *(int *)(iVar2 + 0x30)) {
                *(int *)(*(int *)(iVar2 + 0x14) + 4) = iVar4;
                **(undefined1 **)(iVar2 + 0x30) = 0x8d;
                *(undefined1 *)(*(int *)(iVar2 + 0x30) + 1) = 1;
                *(int *)(*(int *)(iVar2 + 0x30) + 4) = *(int *)(iVar2 + 0x18) + 0x10;
              }
              *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar2 + 0x10);
            }
          }
          FUN_005fca70(local_34,iVar3,*(undefined4 *)(iVar2 + 0xc));
          bVar7 = (byte)(*(uint *)(iVar1 + 0x74) >> 5);
          if ((bVar7 != 0) && ((bVar7 & (byte)(*(uint *)(iVar3 + 0x44) >> 0xe)) != 0)) {
            *(undefined1 *)(*(int *)(iVar2 + 0xc) + 1) = 1;
            uVar9 = *(uint *)(iVar2 + 4);
            pbVar8 = (byte *)(((int)(uVar9 + ((int)uVar9 >> 0x1f & 7U)) >> 3) +
                             *(int *)(iVar1 + 0x58 + (*(uint *)(iVar1 + 0x74) >> 0xf & 1) * 4));
            uVar9 = uVar9 & 0x80000007;
            if ((int)uVar9 < 0) {
              uVar9 = (uVar9 - 1 | 0xfffffff8) + 1;
            }
            *pbVar8 = *pbVar8 & ~('\x01' << ((byte)uVar9 & 0x1f));
          }
        }
        local_38 = local_38 + 1;
      } while (local_38 < (int)(uint)*(ushort *)(iVar11 + 0x20));
    }
  }
  iVar11 = 0;
  if (0 < DAT_009739b8) {
    piVar10 = &DAT_009739bc;
    do {
      if (*(int *)(*piVar10 + 0x80) != 0) {
        FUN_005fd100(*(int *)(*piVar10 + 0x80));
      }
      iVar11 = iVar11 + 1;
      piVar10 = piVar10 + 1;
    } while (iVar11 < DAT_009739b8);
  }
  return;
}


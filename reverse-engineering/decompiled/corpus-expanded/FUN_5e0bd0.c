/* Ghidra pseudocode, not original source.
 * ev_a87fd181e19a595ed696a9e48a76c3177ea695d31392ba84c3867c15109a72c3
 * Entry: 0x5e0bd0; label: FUN_005e0bd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e0bd0(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int unaff_ESI;
  int iVar11;
  bool bVar12;
  int local_18;
  
  iVar11 = 0;
  if (((unaff_ESI != 0) && (*(int **)(unaff_ESI + 0x50) != (int *)0x0)) &&
     (**(int **)(unaff_ESI + 0x50) != 0)) {
    uVar6 = *(uint *)(unaff_ESI + 0x74) >> 0xf;
    iVar2 = *(int *)(unaff_ESI + 0x54);
    uVar8 = *(int *)(unaff_ESI + 0x4c) + 7U >> 3;
    pbVar7 = *(byte **)(unaff_ESI + 0x58 + (~uVar6 & 1) * 4);
    local_18 = 0;
    if (uVar8 != 0) {
      iVar9 = *(int *)(unaff_ESI + 0x58 + (uVar6 & 1) * 4) - (int)pbVar7;
      do {
        bVar1 = pbVar7[iVar9];
        if (bVar1 == *pbVar7) {
          iVar11 = iVar11 + 8;
        }
        else {
          iVar10 = 0;
          do {
            bVar5 = bVar1 >> ((byte)iVar10 & 0x1f);
            iVar3 = *(int *)(iVar2 + iVar11 * 4);
            iVar4 = *(int *)(*(int *)(unaff_ESI + 0x50) + *(int *)(iVar3 + 4) * 4);
            bVar12 = (bool)(bVar5 & 1);
            if (iVar4 == 0) {
LAB_005e0c89:
              if (bVar12 != false) goto LAB_005e0c8d;
LAB_005e0cb7:
              *(undefined1 *)(*(int *)(iVar3 + 0xc) + 1) = 1;
            }
            else {
              if ((bVar5 & 1) == 0) goto LAB_005e0cb7;
              if (DAT_02974d1c != 1) {
                bVar12 = *(char *)(iVar4 + 0xf8) != -1;
                goto LAB_005e0c89;
              }
              if ((*(byte *)(iVar4 + 0xf8) != 0xff) &&
                 ((uint)*(byte *)(iVar4 + 0xfa) + (uint)*(byte *)(iVar4 + 0xf9) +
                  (uint)*(byte *)(iVar4 + 0xf8) != 0)) goto LAB_005e0cb7;
LAB_005e0c8d:
              *(undefined1 *)(*(int *)(iVar3 + 0xc) + 1) = 0;
            }
            iVar11 = iVar11 + 1;
            if (*(int *)(unaff_ESI + 0x4c) <= iVar11) {
              return;
            }
            iVar10 = iVar10 + 1;
          } while (iVar10 < 8);
        }
        local_18 = local_18 + 1;
        pbVar7 = pbVar7 + 1;
      } while (local_18 < (int)uVar8);
    }
  }
  return;
}


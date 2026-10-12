/* Ghidra pseudocode, not original source.
 * ev_0e37ff2b068f2f451a629821c3494056628992f54992bdfe8536c4096373c130
 * Entry: 0x4e90e0; label: FUN_004e90e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e90e0(void)

{
  undefined4 uVar1;
  float fVar2;
  short sVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  short *psVar10;
  int iVar11;
  int *piVar12;
  
  bVar5 = false;
  bVar4 = false;
  iVar6 = FUN_0051ac70(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),"spawn");
  if (DAT_0087b504 != 0) {
    return;
  }
  uVar7 = (uint)DAT_0088a3c4;
  if (uVar7 != 0) {
    psVar10 = &DAT_0088a30c;
    do {
      sVar3 = *psVar10;
      if (sVar3 == DAT_007f18b4) {
        bVar4 = true;
      }
      else if ((sVar3 != DAT_007f19a8) && (sVar3 == DAT_007f18f8)) {
        bVar5 = true;
      }
      psVar10 = psVar10 + 0x14;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  uVar1 = *(undefined4 *)(DAT_007f18b4 * 0x4c + 0x30 + *(int *)(DAT_029130e4 + 0x20));
  DAT_0087b504 = 0;
  do {
    if ((4 < DAT_00876848) || (bVar4)) {
LAB_004e9288:
      iVar9 = -1;
      iVar8 = 5;
      piVar12 = &DAT_0088a3bc;
      do {
        iVar11 = piVar12[1];
        if (iVar11 != 0) {
          if ((((*(uint *)(iVar11 + 0x1fc) & 0x1000) == 0) || (*(char *)(iVar11 + 0x28b) != '\0'))
             || (*(char *)(iVar11 + 0x378) != '\x03')) {
            if (iVar9 == -1) {
              piVar12[1] = 0;
            }
            else {
              piVar12[1] = (&DAT_0088a3ac)[iVar9];
              (&DAT_0088a3ac)[iVar9] = 0;
              iVar9 = iVar9 + -1;
            }
          }
          else if (iVar9 == -1) {
            iVar9 = iVar8;
          }
        }
        iVar11 = *piVar12;
        if (iVar11 != 0) {
          if ((((*(uint *)(iVar11 + 0x1fc) & 0x1000) == 0) || (*(char *)(iVar11 + 0x28b) != '\0'))
             || (*(char *)(iVar11 + 0x378) != '\x03')) {
            if (iVar9 == -1) {
              *piVar12 = 0;
            }
            else {
              *piVar12 = (&DAT_0088a3ac)[iVar9];
              (&DAT_0088a3ac)[iVar9] = 0;
              iVar9 = iVar9 + -1;
            }
          }
          else if (iVar9 == -1) {
            iVar9 = iVar8 + -1;
          }
        }
        iVar11 = piVar12[-1];
        if (iVar11 != 0) {
          if ((((*(uint *)(iVar11 + 0x1fc) & 0x1000) == 0) || (*(char *)(iVar11 + 0x28b) != '\0'))
             || (*(char *)(iVar11 + 0x378) != '\x03')) {
            if (iVar9 == -1) {
              piVar12[-1] = 0;
            }
            else {
              piVar12[-1] = (&DAT_0088a3ac)[iVar9];
              (&DAT_0088a3ac)[iVar9] = 0;
              iVar9 = iVar9 + -1;
            }
          }
          else if (iVar9 == -1) {
            iVar9 = iVar8 + -2;
          }
        }
        piVar12 = piVar12 + -3;
        iVar8 = iVar8 + -3;
      } while (0x88a3a7 < (int)piVar12);
      fVar2 = *(float *)(DAT_007f18f8 * 0x4c + 0x30 + *(int *)(DAT_029130e4 + 0x20));
      if (DAT_0087684a < 6) {
        piVar12 = &DAT_0088a3b0 + iVar9;
        do {
          if (bVar5) {
            return;
          }
          iVar8 = FUN_004e9000(fVar2 + fVar2,"spawn");
          if (iVar8 == 0) {
            return;
          }
          iVar9 = FUN_0043d890((int)DAT_007f18f8,iVar8 + 0x10,*(undefined4 *)(iVar8 + 0x1c),"rider",
                               iVar8 + 0x20,0,1,0,0,0,3);
          *piVar12 = iVar9;
          if (iVar9 == 0) {
            return;
          }
          *(uint *)(iVar9 + 0xeec) = *(uint *)(iVar9 + 0xeec) | 0x10000000;
          iVar9 = 0;
          if (0 < *(char *)(iVar6 + 0x10)) {
            do {
              if (*piVar12 == 0) break;
              if (*(int *)(*(int *)(PTR_DAT_00802c54 + 0x2ae8) + 0x28) +
                  (uint)*(byte *)(*(int *)(iVar6 + 0x14) + iVar9) * 0x3c == iVar8) {
                *(uint *)(*piVar12 + 0x36c) =
                     *(int *)(*(int *)(PTR_DAT_00802c54 + 0x2ae8) + 0x28) +
                     (uint)*(byte *)(*(int *)(iVar6 + 0x14) + iVar9) * 0x3c;
                *(undefined1 *)(iVar9 + *(int *)(iVar6 + 0x18)) = *(undefined1 *)(*piVar12 + 0x28d);
                break;
              }
              iVar9 = iVar9 + 1;
            } while (iVar9 < *(char *)(iVar6 + 0x10));
          }
          piVar12 = piVar12 + 1;
        } while (DAT_0087684a < 6);
      }
      return;
    }
    iVar8 = FUN_004e9000(uVar1,"spawn");
    if (iVar8 == 0) {
      return;
    }
    iVar9 = FUN_0043d890((int)DAT_007f18b4,iVar8 + 0x10,*(undefined4 *)(iVar8 + 0x1c),"Probe",
                         iVar8 + 0x20,0,1,0,0,0,1);
    if (iVar9 == 0) goto LAB_004e9288;
    *(uint *)(iVar9 + 0xeec) = *(uint *)(iVar9 + 0xeec) | 0x10000000;
    iVar11 = 0;
    if (0 < *(char *)(iVar6 + 0x10)) {
      do {
        if (*(int *)(*(int *)(PTR_DAT_00802c54 + 0x2ae8) + 0x28) +
            (uint)*(byte *)(iVar11 + *(int *)(iVar6 + 0x14)) * 0x3c == iVar8) {
          *(uint *)(iVar9 + 0x36c) =
               *(int *)(*(int *)(PTR_DAT_00802c54 + 0x2ae8) + 0x28) +
               (uint)*(byte *)(iVar11 + *(int *)(iVar6 + 0x14)) * 0x3c;
          *(undefined1 *)(iVar11 + *(int *)(iVar6 + 0x18)) = *(undefined1 *)(iVar9 + 0x28d);
          break;
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 < *(char *)(iVar6 + 0x10));
    }
  } while( true );
}


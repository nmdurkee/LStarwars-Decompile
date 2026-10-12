/* Ghidra analysis pseudocode, not original source.
 * ev_198b3c40c86fc47a34e355c4a7b923cf37494fadf6a0e41ec42e09959f8ec2d3
 * Entry: 0x5080f0; label: FUN_005080f0
 */

uint FUN_005080f0(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  byte *pbVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  uint uStack_8;
  int *local_4;
  
  piVar6 = DAT_00921308 + DAT_009213d4 * 4;
  local_4 = (int *)0x0;
  piVar2 = DAT_00921308;
  if (DAT_00921308 < piVar6) {
    piVar3 = DAT_00921308 + 1;
    piVar8 = DAT_00921308;
    do {
      pbVar5 = (byte *)(piVar3 + 2);
      if ((*(byte *)(piVar3 + 2) & 1) == 0) {
        piVar2 = piVar3;
        if (piVar8 < piVar6) {
LAB_00508126:
          if (((*(byte *)(piVar2 + 2) & 1) == 0) || (*piVar3 != *piVar2)) goto LAB_00508136;
          iVar7 = ((uint)((int)piVar6 + (-1 - (int)piVar8)) >> 4) + 1;
          do {
            if (((*pbVar5 & 1) != 0) && (*piVar3 == *(int *)(pbVar5 + -8))) {
              *pbVar5 = *pbVar5 | 1;
            }
            pbVar5 = pbVar5 + 0x10;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
          goto LAB_00508168;
        }
LAB_00508140:
        piVar2 = (int *)*piVar3;
        if (*piVar2 != 0x44454144) {
          if ((piVar2[6] != 0) && (DAT_0092139c != (code *)0x0)) {
            (*DAT_0092139c)(piVar2);
          }
          *(undefined4 *)*piVar3 = 0x44454144;
        }
      }
LAB_00508168:
      piVar8 = piVar8 + 4;
      piVar3 = piVar3 + 4;
      piVar2 = DAT_00921308;
    } while (piVar8 < piVar6);
  }
  for (; uStack_8 = DAT_00921330, piVar2 < piVar6; piVar2 = piVar2 + 4) {
    piVar3 = (int *)(*DAT_00921338)(*piVar2);
    piVar3[0x16] = piVar3[0x17];
    if ((*(byte *)(piVar3 + 0x22) & 2) != 0) {
      FUN_005060e0(piVar3);
    }
    if (piVar3[0x29] != 0) {
      FUN_00502b40();
    }
    if (*piVar3 != 0) {
      *(int *)(*piVar3 + 4) = piVar3[1];
    }
    if ((int *)piVar3[1] == (int *)0x0) {
      DAT_0092133c = *piVar3;
    }
    else {
      *(int *)piVar3[1] = *piVar3;
    }
  }
  while (uVar9 = 0xffffffff, piVar2 = DAT_00921308, DAT_00921308 < piVar6) {
    do {
      if (((*(byte *)(piVar2 + 3) & 1) != 0) && ((uint)piVar2[1] < uVar9)) {
        uVar9 = piVar2[1];
        local_4 = piVar2;
      }
      piVar2 = piVar2 + 4;
    } while (piVar2 < piVar6);
    if (uVar9 == 0xffffffff) break;
    uVar4 = uStack_8 + 3 & 0xfffffffc;
    iVar7 = uVar4 - uVar9;
    uStack_8 = uVar4;
    if (iVar7 != 0) {
      *(int *)(uVar9 + 4) = iVar7;
      *(int *)(uVar9 + 0x28) = iVar7;
      FUN_004ef660(uVar4,uVar9,*(undefined4 *)(uVar9 + 0x58));
      FUN_00505780(1);
    }
    uStack_8 = uStack_8 + *(int *)(uVar4 + 0x58);
    if (local_4 < piVar6) {
      pbVar5 = (byte *)(local_4 + 3);
      iVar7 = ((uint)((int)piVar6 + (-1 - (int)local_4)) >> 4) + 1;
      do {
        if (((*pbVar5 & 1) != 0) && (*(uint *)(pbVar5 + -8) == uVar9)) {
          *(uint *)(pbVar5 + -8) = uVar4;
          *pbVar5 = *pbVar5 ^ 1;
        }
        pbVar5 = pbVar5 + 0x10;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
  }
  iVar7 = DAT_009212d8;
  piVar2 = DAT_00921308;
  if (DAT_00921334 != 0) {
    uStack_8 = DAT_00921334;
  }
  for (; DAT_009212d8 = iVar7, piVar2 < piVar6; piVar2 = piVar2 + 4) {
    if ((char)piVar2[3] == '\0') {
      (*DAT_00921344)(*piVar2);
    }
    else {
      iVar7 = (*DAT_00921300)(*piVar2,piVar2[1],&uStack_8);
      *(int *)(iVar7 + 0xe0) = piVar2[2];
    }
    iVar7 = DAT_009212d8;
  }
  if (iVar7 != 0) {
    DAT_009212d8 = 0;
    DAT_0092133c = iVar7;
  }
  return uStack_8;
LAB_00508136:
  piVar1 = piVar2 + 3;
  piVar2 = piVar2 + 4;
  if (piVar6 <= piVar1) goto LAB_00508140;
  goto LAB_00508126;
}


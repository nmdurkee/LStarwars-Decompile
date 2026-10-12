/* Ghidra pseudocode, not original source.
 * ev_e29f926c447264a3e79b54e28a3bd4babd6a11bd163f218199d416ac4d0e9917
 * Entry: 0x424500; label: FUN_00424500
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00424500(short *param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined2 *puVar7;
  int iVar8;
  int local_4;
  
  iVar3 = (int)param_1;
  puVar7 = &DAT_0086e4ec;
  if (param_1 != (short *)0x0) {
    param_1 = (short *)((int)param_1 + 0x6c);
    local_4 = 2;
    do {
      iVar8 = *param_1 * 0x4c + DAT_0093b274;
      iVar2 = *(int *)(iVar8 + 0x24);
      *(undefined4 *)(iVar2 + 0x90) = 0;
      uVar5 = FUN_004243e0(puVar7,0xffffffff,iVar2);
      *(undefined4 *)(iVar2 + 0x9c) = uVar5;
      *(undefined4 *)(iVar2 + 0xa0) = uVar5;
      *(undefined4 *)(iVar2 + 0xa4) = uVar5;
      *(undefined4 *)(iVar2 + 0xa8) = uVar5;
      *(undefined4 *)(iVar2 + 0xac) = uVar5;
      *(uint *)(iVar8 + 4) = *(uint *)(iVar8 + 4) & 3;
      iVar6 = 0;
      do {
        if (0 < *(int *)(iVar3 + 0x48 + iVar6 * 4)) {
          if ((iVar6 != 0) ||
             ((*(byte *)(*(int *)(iVar3 + 0x28) + 0x12 + (uint)(ushort)puVar7[1] * 0x28) & 1) == 0))
          {
            *(uint *)(iVar8 + 4) =
                 *(uint *)(iVar8 + 4) |
                 *(uint *)(*(int *)(iVar3 + 0x24 + iVar6 * 4) + 0x14 +
                          (uint)(ushort)puVar7[iVar6] * 0x28);
          }
          if ((char)*(uint *)(iVar8 + 4) < '\0') {
            *(uint *)(iVar8 + 4) = *(uint *)(iVar8 + 4) | 0x10000000;
          }
          *(uint *)(iVar2 + 0x90) =
               *(uint *)(iVar2 + 0x90) |
               *(uint *)(*(int *)(iVar3 + 0x24 + iVar6 * 4) + 0x18 +
                        (uint)(ushort)puVar7[iVar6] * 0x28);
        }
        if (0 < *(int *)(iVar3 + 0x4c + iVar6 * 4)) {
          if ((iVar6 != -1) ||
             ((*(byte *)(*(int *)(iVar3 + 0x28) + 0x12 + (uint)(ushort)puVar7[1] * 0x28) & 1) == 0))
          {
            *(uint *)(iVar8 + 4) =
                 *(uint *)(iVar8 + 4) |
                 *(uint *)(*(int *)(iVar3 + 0x28 + iVar6 * 4) + 0x14 +
                          (uint)(ushort)puVar7[iVar6 + 1] * 0x28);
          }
          if ((char)*(uint *)(iVar8 + 4) < '\0') {
            *(uint *)(iVar8 + 4) = *(uint *)(iVar8 + 4) | 0x10000000;
          }
          *(uint *)(iVar2 + 0x90) =
               *(uint *)(iVar2 + 0x90) |
               *(uint *)(*(int *)(iVar3 + 0x28 + iVar6 * 4) + 0x18 +
                        (uint)(ushort)puVar7[iVar6 + 1] * 0x28);
        }
        if (0 < *(int *)(iVar3 + 0x50 + iVar6 * 4)) {
          if ((iVar6 != -2) ||
             ((*(byte *)(*(int *)(iVar3 + 0x28) + 0x12 + (uint)(ushort)puVar7[1] * 0x28) & 1) == 0))
          {
            *(uint *)(iVar8 + 4) =
                 *(uint *)(iVar8 + 4) |
                 *(uint *)(*(int *)(iVar3 + 0x2c + iVar6 * 4) + 0x14 +
                          (uint)(ushort)puVar7[iVar6 + 2] * 0x28);
          }
          if ((char)*(uint *)(iVar8 + 4) < '\0') {
            *(uint *)(iVar8 + 4) = *(uint *)(iVar8 + 4) | 0x10000000;
          }
          *(uint *)(iVar2 + 0x90) =
               *(uint *)(iVar2 + 0x90) |
               *(uint *)(*(int *)(iVar3 + 0x2c + iVar6 * 4) + 0x18 +
                        (uint)(ushort)puVar7[iVar6 + 2] * 0x28);
        }
        iVar6 = iVar6 + 3;
      } while (iVar6 < 9);
      if ((*(byte *)(*(int *)(iVar3 + 0x28) + 0x12 + (uint)(ushort)puVar7[1] * 0x28) & 1) != 0) {
        *(uint *)(iVar2 + 0x90) = *(uint *)(iVar2 + 0x90) | 0x10;
      }
      sVar1 = *(short *)(*(int *)(iVar3 + 0x2c) + 8 + (uint)(ushort)puVar7[2] * 0x28);
      *(short *)(iVar2 + 0xec) = sVar1;
      uVar4 = FUN_0049f800((int)sVar1,0);
      param_1 = param_1 + 1;
      puVar7 = puVar7 + 0x1c;
      local_4 = local_4 + -1;
      *(undefined1 *)(iVar2 + 0x117) = uVar4;
    } while (local_4 != 0);
    FUN_00423c30(iVar3,0xffffffff);
  }
  return;
}


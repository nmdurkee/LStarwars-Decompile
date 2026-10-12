/* Ghidra analysis pseudocode, not original source.
 * ev_5c5e85395afb46ea48eeeced9462a622408ed7e413dd4eac1252ab90af09b35e
 * Entry: 0x4a82a0; label: FUN_004a82a0
 */

void FUN_004a82a0(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  short sVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  int local_114;
  undefined1 local_110 [12];
  uint local_104 [24];
  undefined1 local_a4 [12];
  undefined1 *local_98 [8];
  undefined1 local_78 [12];
  undefined1 local_6c [12];
  undefined1 local_60 [96];
  
  local_104[0] = 0;
  local_104[1] = 0;
  local_104[2] = 0;
  local_104[3] = 0;
  local_104[4] = 0;
  local_98[0] = (undefined1 *)0x0;
  local_104[5] = 0;
  local_98[1] = (undefined1 *)0x0;
  local_104[6] = 0;
  local_98[2] = (undefined1 *)0x0;
  local_104[7] = 0;
  local_98[3] = (undefined1 *)0x0;
  local_98[4] = (undefined1 *)0x0;
  local_98[5] = (undefined1 *)0x0;
  local_98[6] = (undefined1 *)0x0;
  local_98[7] = (undefined1 *)0x0;
  local_104[0x10] = 0;
  local_104[0x11] = 0;
  local_104[0x12] = 0;
  local_104[0x13] = 0;
  local_104[0x14] = 0;
  local_104[0x15] = 0;
  local_104[0x16] = 0;
  local_104[0x17] = 0;
  local_104[8] = 0;
  local_104[9] = 0;
  local_104[10] = 0;
  local_104[0xb] = 0;
  local_104[0xc] = 0;
  local_104[0xd] = 0;
  local_104[0xe] = 0;
  local_104[0xf] = 0;
  if ((*(char *)(param_1 + 0x28c) != '\0') && (*(char *)(param_1 + 0x288) != '\0')) {
    iVar7 = 0;
    local_114 = 0;
    if ((*(int *)(PTR_DAT_00802c54 + 300) == 0) ||
       (((*(byte *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x7a) & 1) == 0 ||
        (*(short *)(param_1 + 0x1064) != DAT_007f1914)))) {
      if (param_2 == 0) {
        sVar4 = *(short *)(param_1 + 0x1064);
        if (sVar4 == DAT_007f1948) {
          if ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b234) && (DAT_009253a4 != 0)) {
            local_114 = 1;
            local_104[0] = 0x3ea66666;
            local_104[0x10] = 2;
            local_104[8] = 0;
          }
        }
        else if (PTR_DAT_007fc098 != (undefined *)0x0) {
          puVar5 = &DAT_007fc0a0;
          do {
            local_114 = iVar7;
            if (7 < iVar7) break;
            if (sVar4 == *(short *)puVar5[-2]) {
              uVar3 = *puVar5;
              local_104[iVar7 + 0x10] = (int)(short)puVar5[-1];
              local_104[iVar7] = uVar3;
              local_104[iVar7 + 8] = (uint)*(ushort *)((int)puVar5 + -2);
              iVar7 = iVar7 + 1;
            }
            puVar1 = puVar5 + 1;
            puVar5 = puVar5 + 3;
            local_114 = iVar7;
          } while (*puVar1 != 0);
        }
      }
      else {
        FUN_00597f90(param_1,local_6c,local_60);
        local_104[0] = 0x3dcccccd;
        local_98[0] = local_60;
        local_104[8] = 1;
        local_114 = 1;
      }
      iVar7 = 0;
      if (0 < local_114) {
        do {
          puVar8 = local_98[iVar7];
          if ((((puVar8 != (undefined1 *)0x0) ||
               ((*(int *)(*(int *)(param_1 + 0x50) + 0x14 + local_104[iVar7 + 0x10] * 4) != 0 &&
                (puVar8 = (undefined1 *)(local_104[iVar7 + 0x10] * 0x40 + 0x834 + param_1),
                puVar8 != (undefined1 *)0x0)))) &&
              (FUN_0055e660(puVar8,local_104[iVar7],0,0,0,param_1,0x40000000,5),
              local_104[iVar7 + 8] != 0)) &&
             (((*(byte *)(param_1 + 0x1fc) & 0x80) != 0 ||
              ((*(byte *)(param_1 + 0xef4) & 0x80) != 0)))) {
            iVar2 = param_1 + 0x80;
            FUN_005b3800(local_110,puVar8,iVar2);
            FUN_005b3b30(local_a4,local_110);
            FUN_005b3830(local_a4,local_a4,local_104[iVar7]);
            FUN_005b37d0(local_110,local_110,local_a4);
            iVar6 = FUN_0067b430(iVar2,local_110,0,0x3f800000,0,DAT_008034c4 | 0x1f);
            if (iVar6 != 0) {
              FUN_005b37d0(local_78,iVar2,local_110);
              FUN_0055e660(local_78,0x41200000,0,0,param_1,0,0x40400000,1);
            }
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < local_114);
      }
    }
  }
  return;
}


/* Ghidra analysis pseudocode, not original source.
 * ev_5f3da693bf096313253939ed49ba5271cfe8862e4a440ae5c9d57980f69a0d69
 * Entry: 0x45c580; label: FUN_0045c580
 */

void FUN_0045c580(int param_1,int param_2,float param_3)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  uint *puVar6;
  int local_c;
  
  bVar3 = false;
  bVar4 = false;
  bVar5 = false;
  if (*(int *)(param_1 + 0x14) == 0) {
    param_3 = param_3 + *(float *)(param_1 + 0x18);
    *(float *)(param_1 + 0x18) = param_3;
    if (0.5 <= param_3) {
      local_c = 0;
      puVar6 = &DAT_009253b8;
      do {
        if (bVar4) goto LAB_0045c6ed;
        if (bVar5) {
          return;
        }
        if (bVar3) {
          return;
        }
        if (*(char *)(local_c + 0xa4 + param_2) != '\0') {
          uVar1 = *puVar6;
          if ((DAT_008022c4 & uVar1) == 0) {
            uVar2 = *(uint *)(param_2 + 0xb0);
            if (((((uVar2 & 0x40) == 0) && ((uVar2 & 8) != 0)) &&
                ((*(short *)(param_2 + 0x118) == -1 ||
                 (((*(byte *)(*(int *)(param_2 + 0x14) + 0x7a) & 2) != 0 ||
                  ((&DAT_0086e0f4)[*(short *)(param_2 + 0x118) * 0xc] != '\0')))))) ||
               (((uVar2 & 0x100) != 0 ||
                ((*(char *)(param_2 + 0xa6) != '\0' || (*(char *)(param_2 + 0xa7) != '\0')))))) {
              if ((DAT_0087a604 < 1) ||
                 (((puVar6[2] & DAT_00802290) == 0 && ((DAT_00802290 & uVar1) == 0)))) {
                if ((DAT_0087a604 < 1) &&
                   (((puVar6[2] & DAT_00802294) != 0 || ((DAT_00802294 & uVar1) != 0)))) {
                  FUN_00547930(0x2f,0,0,0);
                  bVar3 = true;
                  DAT_0087a604 = DAT_0087a604 + 1;
                }
              }
              else {
                FUN_00547930(0x2f,0,0,0);
                DAT_0087a604 = DAT_0087a604 + -1;
                bVar5 = true;
              }
            }
          }
          else {
            bVar4 = true;
          }
        }
        local_c = local_c + 1;
        puVar6 = puVar6 + 0x18;
      } while ((int)puVar6 < 0x925478);
      if (bVar4) {
LAB_0045c6ed:
        if (((((*(byte *)(param_2 + 0xb0) & 8) == 0) || (*(short *)(param_2 + 0x118) == -1)) ||
            ((*(byte *)(*(int *)(param_2 + 0x14) + 0x7a) & 2) != 0)) ||
           ((&DAT_0086e0f4)[*(short *)(param_2 + 0x118) * 0xc] != '\0')) {
          *(undefined1 *)(param_2 + 0xba) = (undefined1)DAT_0087a604;
        }
        else {
          *(undefined1 *)(param_2 + 0xba) = 1;
        }
        FUN_00547930(0x30,0,0,0);
        *(undefined4 *)(param_1 + 0x18) = 0;
        *(undefined4 *)(param_1 + 0x14) = 1;
        *(undefined4 *)(param_1 + 0x1c) = 0x3f000000;
      }
    }
  }
  else if ((*(int *)(param_1 + 0x14) == 1) &&
          (param_3 = param_3 + *(float *)(param_1 + 0x18), *(float *)(param_1 + 0x18) = param_3,
          *(float *)(param_1 + 0x1c) < param_3)) {
    FUN_004838f0(param_2);
    return;
  }
  return;
}


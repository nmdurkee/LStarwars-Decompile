/* Ghidra analysis pseudocode, not original source.
 * ev_49dad5f20e053bf764d7eecccea7d519a0835f455b7dcdd298ee46307ff6e048
 * Entry: 0x60c410; label: FUN_0060c410
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060c410(char *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
                 undefined4 param_10)

{
  uint uVar1;
  char *pcVar2;
  bool bVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  char *pcVar8;
  int local_80;
  undefined1 local_78 [32];
  float local_58;
  float local_54;
  float local_50;
  float local_48;
  float local_44;
  float local_40;
  
  if (param_2 != 0) {
    if ((param_3 != 0) && ((*(char *)(param_3 + 0x99) != -0x69 || (1 < DAT_02974d1c)))) {
      if (param_2 != DAT_02854d08) {
        uVar1 = *(uint *)(param_3 + 0x40);
        if (((uVar1 & 0x30000) != 0x20000) || ((uVar1 & 0x40000) == 0)) {
          *(uint *)(param_3 + 0x40) = uVar1 & 0xfffeffff | 0x60000;
          FUN_005e4b00(param_3);
        }
        if (DAT_02854ce8 == (undefined4 *)0x0) {
          FUN_005edd70(&DAT_0097f978);
        }
        else {
          puVar6 = DAT_02854ce8;
          puVar7 = &DAT_0097f978;
          for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar7 = puVar7 + 1;
          }
        }
        FUN_005d60c0(local_78);
        _DAT_00987500 = local_58;
        _DAT_00987504 = local_54;
        _DAT_00987508 = local_50;
        _DAT_0098750c = -(local_50 * local_40 + local_44 * local_54 + local_48 * local_58);
        *(undefined4 *)(param_2 + 0x14) = param_4;
        *DAT_009736e0 = *DAT_009736e0 + 0xf & 0xfffffff0;
        DAT_02854d04 = (undefined1 *)*DAT_009736e0;
        *DAT_009736e0 = (uint)(DAT_02854d04 + 0x14);
        iVar5 = DAT_02854cf0;
        *(undefined4 *)(DAT_02854d04 + 4) = DAT_02854cec;
        uVar4 = DAT_02854cf4;
        *DAT_02854d04 = (char)iVar5;
        *(undefined4 *)(DAT_02854d04 + 8) = uVar4;
        *(int *)(DAT_02854d04 + 0x10) = param_3;
        *(undefined4 *)(DAT_02854d04 + 0xc) = 0;
        if (DAT_02854d00 == 0) {
          FUN_006e5b90(0,DAT_02854cf8,&DAT_02854d00,0x2000,(&DAT_0280d3cc)[iVar5]);
        }
        FUN_00607cb0(DAT_02854d04);
        DAT_02854d08 = param_2;
      }
      bVar3 = false;
      local_80 = 0;
      pcVar8 = param_1;
      do {
        pcVar2 = *(char **)(param_1 + 4);
        if (*param_1 == 'N') {
          if (pcVar2 != (char *)0x0) {
            FUN_0060b5d0(param_2,pcVar8,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                         param_10);
            param_1 = pcVar2;
            pcVar8 = pcVar2;
          }
        }
        else if (*param_1 == 'R') {
          FUN_0060b5d0(param_2,pcVar8,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                       param_10);
          bVar3 = true;
        }
        local_80 = local_80 + 1;
      } while ((local_80 < 0x101) && (!bVar3));
    }
    return;
  }
  DAT_02854d08 = 0;
  return;
}


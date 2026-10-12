/* Ghidra pseudocode, not original source.
 * ev_ec63a0996326cf703ee2b3a6fc0e0cae7d47cd208787877e90138bc554ba8dc2
 * Entry: 0x4bbd10; label: FUN_004bbd10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004bbd10(int param_1)

{
  char cVar1;
  int iVar2;
  float *pfVar3;
  int *piVar4;
  undefined1 uVar5;
  int iVar6;
  undefined4 *puVar7;
  float **ppfVar8;
  float10 extraout_ST0;
  undefined1 local_74;
  undefined1 local_70;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float *local_50 [3];
  float local_44;
  undefined1 local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined1 local_39;
  undefined4 local_38;
  short local_2a;
  int local_28;
  float local_1c;
  undefined1 local_2;
  
  if ((DAT_00951288 != 0) || (_DAT_00950780 != 0.0)) {
    return;
  }
  if (((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) && (0.0 < *(float *)(param_1 + 0xee8))) {
    cVar1 = *(char *)(param_1 + 0x280);
    puVar7 = &DAT_00802cd8;
    ppfVar8 = local_50;
    for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
      *ppfVar8 = (float *)*puVar7;
      puVar7 = puVar7 + 1;
      ppfVar8 = ppfVar8 + 1;
    }
    if (cVar1 == '\0') {
      uVar5 = 0;
      local_74 = 0x7f;
      local_70 = 0xff;
    }
    else {
      uVar5 = 0x3f;
      local_74 = 0xff;
      local_70 = 0;
    }
    local_39 = FUN_006e6b90();
    local_5c = *(float *)(param_1 + 400);
    local_58 = *(float *)(param_1 + 0xff4) * *(float *)(param_1 + 0xa8) + *(float *)(param_1 + 0x60)
               + 0.05;
    local_54 = *(float *)(param_1 + 0x198);
    if ((*(byte *)(param_1 + 0xe24) & 8) != 0) {
      local_60 = (float)extraout_ST0;
      iVar6 = 0;
      local_68 = (float)extraout_ST0;
      piVar4 = (int *)(*(int *)(param_1 + 0x50) + 0x18);
      local_64 = *(float *)(param_1 + 0x84);
      pfVar3 = (float *)(param_1 + 0x838);
      iVar2 = 4;
      do {
        if (piVar4[-1] != 0) {
          iVar6 = iVar6 + 1;
          local_68 = pfVar3[-1] + local_68;
          local_60 = pfVar3[1] + local_60;
          if (local_64 < *pfVar3) {
            local_64 = *pfVar3;
          }
        }
        if (*piVar4 != 0) {
          iVar6 = iVar6 + 1;
          local_68 = pfVar3[0xf] + local_68;
          local_60 = pfVar3[0x11] + local_60;
          if (local_64 < pfVar3[0x10]) {
            local_64 = pfVar3[0x10];
          }
        }
        if (piVar4[1] != 0) {
          iVar6 = iVar6 + 1;
          local_68 = pfVar3[0x1f] + local_68;
          local_60 = pfVar3[0x21] + local_60;
          if (local_64 < pfVar3[0x20]) {
            local_64 = pfVar3[0x20];
          }
        }
        if (piVar4[2] != 0) {
          iVar6 = iVar6 + 1;
          local_68 = pfVar3[0x2f] + local_68;
          local_60 = pfVar3[0x31] + local_60;
          if (local_64 < pfVar3[0x30]) {
            local_64 = pfVar3[0x30];
          }
        }
        piVar4 = piVar4 + 4;
        pfVar3 = pfVar3 + 0x40;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      if (0 < iVar6) {
        local_5c = ((1.0 / (float)iVar6) * local_68 + local_5c) * 0.5;
        local_54 = (local_54 + local_60 * (1.0 / (float)iVar6)) * 0.5;
        local_58 = (local_58 + local_64 + 0.05) * 0.5;
      }
    }
    cVar1 = *(char *)(param_1 + 0x280);
    puVar7 = &DAT_00802cd8;
    ppfVar8 = local_50;
    for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
      *ppfVar8 = (float *)*puVar7;
      puVar7 = puVar7 + 1;
      ppfVar8 = ppfVar8 + 1;
    }
    local_1c = (float)extraout_ST0;
    local_50[1] = &local_5c;
    local_2 = 2;
    local_3b = local_74;
    local_3a = local_70;
    if (cVar1 == '\x01') {
      local_1c = 0.002;
    }
    local_44 = 2.0;
    local_50[0] = (float *)PTR_DAT_007f3a1c;
    local_38 = 0x1087;
    local_3c = uVar5;
    FUN_00560b60(local_50);
    local_58 = local_58 + 0.1175;
    local_44 = _DAT_007fc318 + _DAT_007fc318;
    local_50[0] = (float *)0x0;
    local_38 = 0x11087;
    local_2a = *(short *)(*(short *)(param_1 + 0x1064) * 0x4c + 0x42 + *(int *)(DAT_029130e4 + 0x20)
                         );
    local_28 = local_2a * 0x10 + *(int *)(PTR_DAT_00802c54 + 0x2ac0);
    FUN_00560b60(local_50);
    local_2a = 0xa6 - (ushort)(*(char *)(param_1 + 0x280) != '\0');
    local_28 = local_2a * 0x10 + *(int *)(PTR_DAT_00802c54 + 0x2ac0);
    FUN_00560b60(local_50);
    return;
  }
  return;
}


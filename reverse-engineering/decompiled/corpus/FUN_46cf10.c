/* Ghidra analysis pseudocode, not original source.
 * ev_656543c8328aa29e7546f4f9ed4e60ad4c1e465caa45a29e90694e112f58dfef
 * Entry: 0x46cf10; label: FUN_0046cf10
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046cf10(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 int param_6)

{
  char *pcVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char cVar6;
  byte *pbVar7;
  int iVar8;
  undefined4 *puVar9;
  float **ppfVar10;
  undefined1 auStack_94 [4];
  int local_90;
  uint local_8c;
  uint local_88;
  int local_84;
  undefined4 local_80;
  undefined4 local_7c;
  int local_78;
  float local_74;
  float local_70;
  undefined4 local_6c;
  float *local_68 [6];
  undefined4 local_50;
  float local_4c;
  undefined4 local_48;
  short local_42;
  int local_40;
  uint local_3c;
  undefined1 *local_28;
  undefined1 *local_20;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined4 local_18;
  undefined4 local_14;
  undefined2 local_10;
  uint local_c;
  
  local_c = DAT_00829570 ^ (uint)auStack_94;
  local_7c = param_2;
  local_84 = FUN_0055f450();
  if (param_1 == 0) goto LAB_0046d251;
  if ((DAT_00856c08 != 0) || (iVar3 = FUN_0058a900(0), iVar3 != 0)) {
    param_1 = 0;
  }
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  if (0 < param_1 % 10) {
    param_1 = param_1 - param_1 % 10;
  }
  if (param_1 < 0x7d001) {
    if (0 < param_1) goto LAB_0046cfae;
  }
  else {
    param_1 = 0x7d000;
LAB_0046cfae:
    FUN_00681f40("CoinsLand",param_2);
  }
  if (param_6 == 0) {
    if (0 < param_1) {
      pbVar7 = &DAT_007f902b;
      do {
        iVar3 = param_1 - (uint)*(ushort *)(&DAT_007f8e0a + (uint)*pbVar7 * 0x38);
        if (-1 < iVar3) {
          pcVar1 = (char *)((int)&local_18 + (uint)*pbVar7);
          cVar6 = *pcVar1;
          do {
            param_1 = iVar3;
            cVar6 = cVar6 + '\x01';
            iVar3 = param_1 - (uint)*(ushort *)(&DAT_007f8e0a + (uint)*pbVar7 * 0x38);
          } while (-1 < iVar3);
          *pcVar1 = cVar6;
        }
        pbVar7 = pbVar7 + -1;
      } while (0 < param_1);
    }
  }
  else {
    for (; 0 < param_1; param_1 = param_1 - (uint)uVar2) {
      do {
        iVar3 = FUN_0054fa60();
        uVar2 = *(ushort *)
                 (&DAT_007f8e0a +
                 (uint)(byte)(&DAT_007f9028)[(int)(iVar3 + (iVar3 >> 0x1f & 0x3fffU)) >> 0xe] * 0x38
                 );
      } while ((int)(param_1 - (uint)uVar2) < 0);
      pcVar1 = (char *)((int)&local_18 +
                       (uint)(byte)(&DAT_007f9028)[(int)(iVar3 + (iVar3 >> 0x1f & 0x3fffU)) >> 0xe])
      ;
      *pcVar1 = *pcVar1 + '\x01';
    }
  }
  if (param_3 == 0) {
LAB_0046d068:
    local_74 = -_DAT_007fc2e0;
  }
  else {
    local_74 = _DAT_007fc2e0;
    if (param_3 != 1) {
      param_3 = -1;
      goto LAB_0046d068;
    }
  }
  iVar3 = FUN_00570bb0();
  if (iVar3 == 0) {
    local_70 = _DAT_007fc2e4 + _DAT_007fc310;
    local_80 = _DAT_007fc2f4;
  }
  else {
    local_70 = _DAT_007fc310;
    local_80 = _DAT_007fc368;
  }
  local_8c = (uint)(iVar3 != 0);
  local_90 = 0;
  local_6c = 0x3f800000;
  _DAT_0087b94c = _DAT_008033a8 + 1.0;
  do {
    uVar4 = (uint)(byte)(&DAT_007f9028)[local_90];
    iVar8 = (int)*(short *)(&DAT_007f8e08 + uVar4 * 0x38);
    iVar3 = uVar4 * 0x38;
    local_78 = iVar8;
    if (*(char *)((int)&local_18 + uVar4) != '\0') {
      local_88 = (uint)*(byte *)((int)&local_18 + uVar4);
      do {
        iVar5 = iVar8;
        if ((&DAT_007f8e05)[iVar3] != '\0') {
          iVar5 = FUN_0054fa60();
          iVar5 = iVar5 / ((int)(0xffff / (ulonglong)
                                          (longlong)(int)(uint)(byte)(&DAT_007f8e05)[iVar3]) + 1) +
                  iVar8;
        }
        if ((*(char *)(iVar5 * 0x10 + 0xe + *(int *)(local_84 + 0x2ac0)) != '\0') && (param_3 != -1)
           ) {
          puVar9 = &DAT_00802cd8;
          ppfVar10 = local_68;
          for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
            *ppfVar10 = (float *)*puVar9;
            puVar9 = puVar9 + 1;
            ppfVar10 = ppfVar10 + 1;
          }
          local_68[3] = (float *)0x3f800000;
          local_68[4] = (float *)local_80;
          local_48 = *(undefined4 *)(&DAT_00950f64 + param_3 * 4);
          local_42 = (short)iVar5;
          local_68[1] = (float *)local_7c;
          local_68[2] = &local_74;
          local_40 = local_42 * 0x10 + *(int *)(local_84 + 0x2ac0);
          local_3c = (uint)*(ushort *)(&DAT_007f8e0a + iVar3);
          local_4c = _DAT_008033a8;
          local_1c = (undefined1)param_3;
          local_20 = &LAB_0046af20;
          local_1b = 1;
          local_50 = 0x12d;
          if (local_8c != 0) {
            local_1a = 1;
            local_28 = &LAB_0046af00;
          }
          FUN_00560b60(local_68);
          *(float *)(&DAT_00950f64 + param_3 * 4) = *(float *)(&DAT_00950f64 + param_3 * 4) + 0.1;
          iVar8 = local_78;
        }
        local_88 = local_88 - 1;
      } while (local_88 != 0);
      local_88 = 0;
    }
    local_90 = local_90 + 1;
  } while (local_90 < 4);
LAB_0046d251:
  __security_check_cookie(local_c ^ (uint)auStack_94);
  return;
}


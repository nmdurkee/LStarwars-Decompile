/* Ghidra analysis pseudocode, not original source.
 * ev_cadbdcea344f284c720862a9d60fea326d89961e952df44594a2f8e4339e7270
 * Entry: 0x52b9c0; label: FUN_0052b9c0
 */

void FUN_0052b9c0(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined *puVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  undefined1 *local_c0c;
  int local_c08;
  undefined1 local_c04 [3072];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_c0c;
  local_c08 = param_1;
  iVar1 = FUN_004fc5b0(param_1);
  while (iVar1 != 0) {
    FUN_004f7fb0(param_1);
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_0075ff74);
    if (iVar1 == 0) break;
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"DoMacro");
    if (iVar1 == 0) {
      FUN_004f7fb0(param_1);
      for (iVar1 = FUN_004f1440(DAT_0092221c + 0x50); iVar1 != 0;
          iVar1 = FUN_004f1460(DAT_0092221c + 0x50,iVar1)) {
        iVar2 = FUN_004f8b10(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(param_1 + 0x510));
        if (iVar2 == 0) {
          FUN_00513b30(iVar1 + 0xc,DAT_00922234,DAT_00922214,DAT_00922218);
          goto LAB_0052bc33;
        }
      }
LAB_0052bc72:
      if (DAT_00922248 == 1) {
        if (DAT_00922220 == 0) {
          puVar5 = &DAT_00755ba8;
        }
        else {
          puVar5 = *(undefined **)(DAT_00922220 + 0x18);
        }
        FUN_00512860(*(undefined4 *)(param_1 + 0x510),*(undefined4 *)(DAT_0092221c + 8),puVar5);
      }
      else {
        if (DAT_00922220 == 0) {
          puVar5 = &DAT_00755ba8;
        }
        else {
          puVar5 = *(undefined **)(DAT_00922220 + 0x18);
        }
        FUN_00512850(*(undefined4 *)(param_1 + 0x510),*(undefined4 *)(DAT_0092221c + 8),puVar5);
      }
    }
    else {
      iVar1 = FUN_00512f00();
      if (iVar1 == 0) {
        iVar1 = FUN_004f1f90(*(undefined4 *)(param_1 + 0x510),0x7b);
        if (iVar1 == 0) goto LAB_0052bc72;
      }
      else if (((DAT_00922214 == (int *)0x0) || (DAT_00922218 == (uint *)0x0)) ||
              (*DAT_00922218 <= *DAT_00922214 + 0x14U)) {
        FUN_00512850();
      }
      else {
        uVar3 = *DAT_00922214 + 0xf;
        puVar6 = (undefined4 *)(uVar3 & 0xfffffff0);
        *DAT_00922214 = (uVar3 & 0xfffffff0) + 0x14;
        *puVar6 = 0;
        puVar6[1] = 0;
        puVar6[2] = 0;
        puVar6[3] = 0;
        puVar6[4] = 0;
        if (puVar6 != (undefined4 *)0x0) {
          *puVar6 = 0;
          puVar6[1] = 0;
          puVar6[2] = 0;
          puVar6[3] = 0;
          puVar6[4] = 0;
          FUN_004f1310(DAT_00922234,puVar6);
          puVar6[4] = iVar1;
          iVar2 = 0;
          iVar1 = FUN_004f7fb0(param_1);
          if (iVar1 != 0) {
            puVar7 = local_c04;
            do {
              iVar1 = FUN_004f20f0(*(undefined4 *)(param_1 + 0x510),&DAT_0075a204);
              if (iVar1 == 0) {
                FUN_004fc5b0(param_1);
              }
              else {
                FUN_004f1f10(puVar7,*(undefined4 *)(param_1 + 0x510));
                iVar2 = iVar2 + 1;
                puVar7 = puVar7 + 0x80;
              }
              iVar1 = FUN_004f7fb0(param_1);
            } while (iVar1 != 0);
            if (iVar2 != 0) {
              iVar1 = FUN_00512e60();
              puVar6[2] = iVar1;
              if (iVar1 != 0) {
                iVar1 = 0;
                puVar6[3] = iVar2;
                param_1 = local_c08;
                if (0 < iVar2) {
                  local_c0c = local_c04;
                  do {
                    uVar4 = FUN_00513100(local_c0c,DAT_00922218);
                    local_c0c = local_c0c + 0x80;
                    *(undefined4 *)(puVar6[2] + iVar1 * 4) = uVar4;
                    iVar1 = iVar1 + 1;
                    param_1 = local_c08;
                  } while (iVar1 < iVar2);
                }
              }
            }
          }
        }
      }
    }
LAB_0052bc33:
    iVar1 = FUN_004fc5b0(param_1);
  }
  __security_check_cookie(local_4 ^ (uint)&local_c0c);
  return;
}


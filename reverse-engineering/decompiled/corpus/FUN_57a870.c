/* Ghidra analysis pseudocode, not original source.
 * ev_3de2cf7b8df928d729538760151df11dfb76bb55f80af3b4d4d063063f9aa6a2
 * Entry: 0x57a870; label: FUN_0057a870
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_0057a870(undefined4 param_1,uint *param_2)

{
  bool bVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined1 *local_2ff0;
  uint *local_2fec;
  short local_2fe8 [2];
  undefined4 local_2fe4 [2];
  short local_2fdc [5996];
  char local_104 [128];
  char local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_2ff0;
  local_2fec = param_2;
  DAT_00951ca4 = 0;
  DAT_00951ca8 = 0;
  iVar2 = FUN_004fc860(param_1);
  if (iVar2 != 0) {
    puVar3 = (undefined1 *)(*param_2 + 3 & 0xfffffffc);
    *param_2 = (uint)puVar3;
    local_2ff0 = puVar3;
    if (DAT_00951ca8 < 1000) {
LAB_0057a8e0:
      iVar4 = FUN_004fc5b0(iVar2);
      if (iVar4 != 0) {
        iVar4 = FUN_004f7fb0(iVar2);
        if ((iVar4 != 0) &&
           (iVar4 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"cutscene_start"), iVar4 == 0)) {
          local_84[0] = '\0';
          local_104[0] = '\0';
          local_2fdc[DAT_00951ca8 * 6] = -1;
          while( true ) {
            iVar4 = FUN_004fc5b0(iVar2);
            if ((iVar4 == 0) || (iVar4 = FUN_004f7fb0(iVar2), iVar4 == 0)) goto LAB_0057abc7;
            iVar4 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"cutscene_end");
            if (iVar4 == 0) break;
            iVar4 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),&PTR_DAT_00761cc4);
            if ((iVar4 == 0) ||
               (iVar4 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),&DAT_00757e68), iVar4 == 0)) {
              iVar4 = FUN_004f7fb0(iVar2);
              if ((iVar4 != 0) &&
                 (iVar4 = FUN_004f1ff0(*(undefined4 *)(iVar2 + 0x510)), iVar4 < 0x80)) {
                FUN_004f1f10(local_84,*(undefined4 *)(iVar2 + 0x510));
              }
            }
            else {
              iVar4 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),&DAT_00761cbc);
              if ((iVar4 == 0) ||
                 (iVar4 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"filename"), iVar4 == 0)) {
                iVar4 = FUN_004f7fb0(iVar2);
                if ((iVar4 != 0) &&
                   (iVar4 = FUN_004f1ff0(*(undefined4 *)(iVar2 + 0x510)), iVar4 < 0x40)) {
                  FUN_004f1f10(local_104,*(undefined4 *)(iVar2 + 0x510));
                }
              }
              else {
                iVar4 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"level");
                if (((iVar4 == 0) ||
                    (iVar4 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"in_level"), iVar4 == 0))
                   && (iVar4 = FUN_004f7fb0(iVar2), iVar4 != 0)) {
                  FUN_00578da0(*(undefined4 *)(iVar2 + 0x510),local_2fe8);
                  local_2fdc[DAT_00951ca8 * 6] = local_2fe8[0];
                }
              }
            }
          }
          if (((local_84[0] != '\0') && (local_104[0] != '\0')) &&
             (local_2fdc[DAT_00951ca8 * 6] != -1)) {
            bVar1 = false;
            iVar4 = 0;
            if (DAT_00951ca8 < 1) goto LAB_0057ac2c;
            puVar6 = local_2fe4 + 1;
            goto LAB_0057ab25;
          }
        }
        goto LAB_0057abc7;
      }
    }
LAB_0057abd3:
    FUN_004fa300(iVar2);
    if (0 < DAT_00951ca8) {
      DAT_00951ca4 = (uint)(puVar3 + 3) & 0xfffffffc;
      *param_2 = DAT_00951ca4;
      iVar2 = DAT_00951ca8 * 0xc;
      FUN_004ef660(DAT_00951ca4,local_2fe4,iVar2);
      *param_2 = *param_2 + iVar2;
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_2ff0);
  return;
  while( true ) {
    iVar5 = FUN_004f8b10(local_84,puVar6[-1]);
    if (((iVar5 == 0) && (iVar5 = FUN_004f8b10(local_104,*puVar6), iVar5 == 0)) &&
       (local_2fdc[DAT_00951ca8 * 6] == *(short *)(puVar6 + 1))) {
      bVar1 = true;
    }
    else {
      iVar4 = iVar4 + 1;
      puVar6 = puVar6 + 3;
    }
    if (DAT_00951ca8 <= iVar4) break;
LAB_0057ab25:
    if (bVar1) goto LAB_0057ab89;
  }
  puVar3 = local_2ff0;
  if (bVar1) {
LAB_0057ab89:
    FUN_0057a820(local_84,local_104,local_2fdc[DAT_00951ca8 * 6] * 0x130 + 0x40 + DAT_00951b78);
    param_2 = local_2fec;
    puVar3 = local_2ff0;
  }
  else {
LAB_0057ac2c:
    local_2fe4[DAT_00951ca8 * 3] = puVar3;
    FUN_004f1f10(puVar3,local_84);
    iVar4 = FUN_004f1ff0(local_84);
    puVar3[iVar4] = 0;
    puVar3 = puVar3 + iVar4 + 1;
    local_2fe4[DAT_00951ca8 * 3 + 1] = puVar3;
    FUN_004f1f10(puVar3,local_104);
    iVar4 = FUN_004f1ff0(local_104);
    puVar3[iVar4] = 0;
    local_2ff0 = puVar3 + iVar4 + 1;
    DAT_00951ca8 = DAT_00951ca8 + 1;
    param_2 = local_2fec;
    puVar3 = local_2ff0;
  }
LAB_0057abc7:
  if (999 < DAT_00951ca8) goto LAB_0057abd3;
  goto LAB_0057a8e0;
}


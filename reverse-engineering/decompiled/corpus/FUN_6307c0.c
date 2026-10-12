/* Ghidra analysis pseudocode, not original source.
 * ev_e26d15e716f54b37dc9752c5bbece96131eaa1b0064d3ed9476ea38cc0029dc6
 * Entry: 0x6307c0; label: FUN_006307c0
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_006307c0(undefined4 param_1,uint *param_2,undefined4 param_3,int param_4,int *param_5,
                 int param_6,uint *param_7)

{
  short *psVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  uint uVar6;
  uint *puVar7;
  int *piVar8;
  undefined4 *puVar9;
  int iVar10;
  int local_2f00;
  int local_2efc;
  int local_2ef8;
  undefined4 *local_2ef4;
  uint *local_2ef0;
  int *local_2eec;
  undefined4 local_2ee8;
  short asStack_2ee4 [499];
  short asStack_2afe [501];
  undefined1 local_2714 [10000];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_2f00;
  local_2ee8 = param_1;
  local_2eec = param_5;
  local_2ef0 = param_7;
  iVar3 = FUN_004fc860(param_1);
  if (iVar3 == 0) {
    FUN_0062a5e0(param_1);
  }
  if (500 < param_4) {
    param_4 = 500;
  }
  iVar10 = 0;
  puVar9 = (undefined4 *)(*param_2 + 3 & 0xfffffffc);
  *param_2 = (uint)puVar9;
  local_2ef4 = puVar9;
  _memset(local_2714,0,10000);
  local_2714[0] = 0;
  local_2f00 = 0;
  local_2ef8 = 0;
  iVar4 = FUN_004fc5b0(iVar3);
  do {
    if (iVar4 == 0) {
      FUN_004fa300(iVar3);
      iVar3 = local_2f00;
      if (iVar10 < 1) {
        FUN_0062a5e0(local_2ee8);
      }
      else {
        *param_2 = (uint)puVar9;
        FUN_004ef660(puVar9,local_2714,local_2f00);
        iVar4 = 0;
        if (0 < iVar10) {
          piVar8 = local_2ef4 + 3;
          do {
            psVar1 = asStack_2ee4 + iVar4;
            iVar4 = iVar4 + 1;
            piVar8[-1] = (int)*psVar1 + *param_2;
            *piVar8 = (int)asStack_2afe[iVar4] + *param_2;
            piVar8 = piVar8 + 0x13;
          } while (iVar4 < iVar10);
        }
        uVar6 = *param_2 + 3 + iVar3 & 0xfffffffc;
        *param_2 = uVar6;
        if (0 < param_6) {
          if (local_2ef0 != (uint *)0x0) {
            *local_2ef0 = uVar6;
          }
          if (0 < iVar10) {
            puVar7 = local_2ef4 + 9;
            iVar3 = iVar10;
            do {
              *puVar7 = *param_2;
              *param_2 = *param_2 + param_6;
              puVar7 = puVar7 + 0x13;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
        }
        *param_2 = *param_2 + 3 & 0xfffffffc;
        if (local_2eec != (int *)0x0) {
          *local_2eec = iVar10;
        }
      }
      __security_check_cookie(local_4 ^ (uint)&local_2f00);
      return;
    }
    FUN_004f7fb0(iVar3);
    pcVar2 = *(char **)(iVar3 + 0x510);
    if (*pcVar2 != '\0') {
      if (local_2ef8 == 0) {
        iVar4 = FUN_004f8b10(pcVar2,"char_start");
        if ((iVar4 == 0) && (iVar10 < param_4)) {
          sVar5 = -1;
          *(byte *)(puVar9 + 0x10) = *(byte *)(puVar9 + 0x10) & 0xfe;
          puVar9[0xb] = 0x3f800000;
          local_2ef8 = 1;
          puVar9[0xc] = 0x3f000000;
          asStack_2afe[iVar10 + 1] = -1;
          *puVar9 = 0xffffffff;
          puVar9[0xd] = 0xbf000000;
          puVar9[1] = 0;
          puVar9[2] = 0;
          puVar9[3] = 0;
          puVar9[0xe] = 0x3f000000;
          puVar9[4] = 0;
          *(undefined2 *)(puVar9 + 5) = 0;
          puVar9[0xf] = 0x3f800000;
          puVar9[6] = 0;
          puVar9[7] = 0;
          puVar9[8] = 0;
          puVar9[9] = 0;
          puVar9[10] = 0;
          *(undefined2 *)((int)puVar9 + 0x42) = 0xffff;
          puVar9[0x11] = 0;
          puVar9[0x12] = 0;
LAB_00630a4c:
          asStack_2ee4[iVar10] = sVar5;
        }
      }
      else {
        iVar4 = FUN_004f8b10(pcVar2,"char_end");
        if (iVar4 == 0) {
          local_2ef8 = 0;
          if ((asStack_2ee4[iVar10] != -1) && (asStack_2afe[iVar10 + 1] != -1)) {
            iVar10 = iVar10 + 1;
            puVar9 = puVar9 + 0x13;
          }
        }
        else {
          iVar4 = FUN_004f8b10(*(undefined4 *)(iVar3 + 0x510),&PTR_DAT_00761cc4);
          if (iVar4 == 0) {
            iVar4 = FUN_004f7fb0(iVar3);
            if (iVar4 != 0) {
              iVar4 = FUN_004f1ff0(*(undefined4 *)(iVar3 + 0x510));
              local_2efc = iVar4 + 1 + local_2f00;
              if (local_2efc < 10000) {
                FUN_004f1f10(local_2714 + local_2f00,*(undefined4 *)(iVar3 + 0x510));
                sVar5 = (short)local_2f00;
                local_2f00 = local_2efc;
                goto LAB_00630a4c;
              }
            }
          }
          else {
            iVar4 = FUN_004f8b10(*(undefined4 *)(iVar3 + 0x510),&DAT_00761cbc);
            if ((iVar4 == 0) && (iVar4 = FUN_004f7fb0(iVar3), iVar4 != 0)) {
              iVar4 = FUN_004f1ff0(*(undefined4 *)(iVar3 + 0x510));
              local_2efc = iVar4 + 1 + local_2f00;
              if (local_2efc < 10000) {
                FUN_004f1f10(local_2714 + local_2f00,*(undefined4 *)(iVar3 + 0x510));
                asStack_2afe[iVar10 + 1] = (short)local_2f00;
                local_2f00 = local_2efc;
              }
            }
          }
        }
      }
    }
    iVar4 = FUN_004fc5b0(iVar3);
  } while( true );
}


/* Ghidra pseudocode, not original source.
 * ev_49baf35693289c9b209f5eaac5bb5c67719489504b9157070dca4e7dc617b8b0
 * Entry: 0x4d44a0; label: FUN_004d44a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d44a0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  bool bVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  float10 fVar9;
  int local_44;
  undefined1 local_40 [48];
  undefined1 local_10 [4];
  float local_c;
  
  iVar4 = param_1;
  bVar3 = false;
  *(undefined4 *)(param_1 + 0x5168) = 0;
  if ((*(int *)(param_1 + 0x13c) != 0) &&
     (iVar6 = FUN_004fc900("Traffic",param_2,0xffff), iVar6 != 0)) {
    uVar1 = *(undefined4 *)(param_1 + 0x104);
    uVar2 = *(undefined4 *)(param_1 + 0x108);
    iVar7 = FUN_00552670((undefined4 *)(param_1 + 0x104),param_1 + 0x108,0x77e4);
    *(int *)(param_1 + 0x5168) = iVar7;
    if (iVar7 != 0) {
      DAT_00881c30 = param_1;
      DAT_00881ae8 = iVar7;
      _memset(&DAT_00881af0,0,0x140);
      FUN_004f10e0(iVar6,&PTR_s_animobj_007ffb08);
      iVar7 = FUN_004fc5b0(iVar6);
      while (iVar7 != 0) {
        iVar7 = FUN_004f7fb0(iVar6);
        if (iVar7 != 0) {
          if (bVar3) {
            iVar7 = FUN_004f8b10(*(undefined4 *)(iVar6 + 0x510),"traffic_end");
            if (iVar7 == 0) {
              bVar3 = false;
            }
            else {
              FUN_004fa020(iVar6);
            }
          }
          else {
            iVar7 = FUN_004f8b10(*(undefined4 *)(iVar6 + 0x510),"traffic_start");
            if (iVar7 == 0) {
              bVar3 = true;
              _memset(&DAT_00881af0,0,0x140);
              _DAT_00881b08 = 0x41700000;
              _DAT_00881b0c = 0x40a00000;
              _DAT_00881b04 = 0x3f800000;
            }
          }
        }
        iVar7 = FUN_004fc5b0(iVar6);
      }
      FUN_004f11e0(iVar6);
      FUN_004fa300(iVar6);
      if (*(char *)(DAT_00881ae8 + 0x77e0) == '\0') {
        *(undefined4 *)(param_1 + 0x104) = uVar1;
        *(undefined4 *)(param_1 + 0x108) = uVar2;
        *(undefined4 *)(param_1 + 0x5168) = 0;
      }
      else {
        local_44 = 0;
        if ('\0' < *(char *)(DAT_00881ae8 + 0x77e0)) {
          piVar8 = (int *)(DAT_00881ae8 + 0xc);
          iVar6 = DAT_00881ae8;
          do {
            if (*piVar8 != 0) {
              fVar9 = (float10)FUN_005ca4b0(*piVar8);
              piVar8[1] = (int)(float)fVar9;
              param_1 = 0;
              piVar8[5] = (int)(((float)fVar9 - 1.0) * 0.00390625);
              do {
                FUN_005526c0(piVar8 + -3,(float)param_1 * (float)piVar8[5] + 1.0,local_40,1);
                local_c = (float)piVar8[6] + local_c;
                *(undefined1 *)((int)piVar8 + param_1 + 0x2c) = 0xff;
                sVar5 = FUN_005d92b0(*(undefined4 *)(iVar4 + 0x13c),local_10);
                if ((sVar5 < 0x40) && (-1 < sVar5)) {
                  *(char *)((int)piVar8 + param_1 + 0x2c) = (char)sVar5;
                }
                param_1 = param_1 + 1;
                iVar6 = DAT_00881ae8;
              } while (param_1 < 0x100);
            }
            local_44 = local_44 + 1;
            piVar8 = piVar8 + 0x50;
          } while (local_44 < *(char *)(iVar6 + 0x77e0));
          DAT_00881ae8 = 0;
          DAT_00881c30 = 0;
          return;
        }
      }
      DAT_00881ae8 = 0;
      DAT_00881c30 = 0;
    }
  }
  return;
}


/* Ghidra analysis pseudocode, not original source.
 * ev_b2ae0094aac4233f18363a226dc902c019a1728ce7ff5cc7e95ded3ed7c5c2a8
 * Entry: 0x68df20; label: FUN_0068df20
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068df20(undefined4 param_1,char param_2,undefined4 param_3)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  undefined4 uVar10;
  undefined1 auStack_440 [3];
  char local_43d;
  int local_43c;
  int local_438;
  int local_434;
  int local_430;
  undefined1 local_42c [1064];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)auStack_440;
  local_434 = 0;
  local_43d = param_2;
  iVar7 = 1;
  if (param_2 == '\x06') {
    param_2 = '\x01';
LAB_0068df5e:
    iVar3 = 2;
    do {
      if ((&DAT_02924b10)[iVar3] == 0) {
        local_43c = iVar3;
        if (iVar3 != -1) goto LAB_0068df99;
        break;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 8);
  }
  else {
    if (param_2 == '\0') {
      local_43c = 0;
    }
    else {
      if (param_2 != '\x05') goto LAB_0068df5e;
      local_43c = 1;
    }
LAB_0068df99:
    if (DAT_02962a28 == 0) {
      uVar10 = 1;
    }
    else {
      uVar10 = 2;
    }
    FUN_006211c0(uVar10);
    iVar3 = FUN_00621270(param_1,0);
    if (iVar3 != 0) {
      FUN_006211b0(1);
      local_438 = FUN_006217e0();
      if ((4 < local_438) && (local_438 < 0x2a)) {
        (&DAT_02924b10)[local_43c] = 1;
        *(undefined4 *)(&DAT_02947bdc + local_43c * 4) = param_3;
        iVar3 = FUN_006217e0();
        if (DAT_02962098 < DAT_02962a24 + iVar3) {
          local_434 = (DAT_02962a24 - DAT_02962098) + iVar3;
          iVar3 = DAT_02962098 - DAT_02962a24;
          _DAT_0296293c = 300;
        }
        if (0 < iVar3) {
          iVar8 = 4;
          local_430 = iVar3;
          do {
            iVar3 = *(int *)(iVar8 + DAT_0296209c);
            while (iVar3 != 0) {
              iVar7 = iVar7 + 1;
              iVar3 = *(int *)(DAT_0296209c + iVar7 * 4);
            }
            iVar3 = iVar7 * 0x428;
            FUN_0066a190(iVar3 + DAT_029620a0,local_438,param_2);
            *(undefined1 *)(iVar3 + 0x11 + DAT_029620a0) = (undefined1)local_43c;
            *(undefined4 *)(iVar3 + 0x2a8 + DAT_029620a0) = 0;
            iVar8 = iVar7 * 4;
            *(undefined4 *)(iVar3 + 0x2ac + DAT_029620a0) = 0;
            *(int *)(iVar8 + DAT_0296209c) = iVar3 + DAT_029620a0;
            FUN_0068cfd0();
            DAT_02962a24 = DAT_02962a24 + 1;
            local_430 = local_430 + -1;
          } while (local_430 != 0);
        }
        iVar7 = local_438;
        iVar3 = local_434;
        if (0 < local_434) {
          do {
            FUN_0066a190(local_42c,iVar7,param_2);
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
        cVar6 = local_43d;
        if ((local_43d == '\x01') || (local_43d == '\x02')) {
          iVar3 = FUN_006217e0();
          if (0x200 < DAT_02962a2c + iVar3) {
            iVar3 = 0x200 - DAT_02962a2c;
          }
          DAT_02962a3c = 0;
          local_434 = 0;
          if (0 < iVar3) {
            do {
              local_430 = iVar3;
              iVar5 = local_43c;
              piVar4 = &DAT_02924b60 + local_434 * 0x16;
              iVar3 = (&DAT_02924b60)[local_434 * 0x16];
              iVar8 = local_434;
              while (iVar3 != -1) {
                piVar4 = piVar4 + 0x16;
                iVar8 = iVar8 + 1;
                iVar3 = *piVar4;
              }
              iVar3 = iVar8 * 0x58;
              (&DAT_02924ba1)[iVar3] = (char)local_43c;
              local_434 = iVar8;
              fVar9 = (float10)FUN_006217a0();
              (&DAT_02924b50)[iVar8 * 0x16] = (float)fVar9;
              fVar9 = (float10)FUN_006217a0();
              (&DAT_02924b54)[iVar8 * 0x16] = (float)fVar9;
              fVar9 = (float10)FUN_006217a0();
              (&DAT_02924b58)[iVar8 * 0x16] = (float)fVar9;
              if (iVar7 < 7) {
                (&DAT_02924b64)[iVar8 * 0x2c] = 0;
                (&DAT_02924b66)[iVar8 * 0x2c] = 0;
                uVar2 = FUN_006217e0();
                (&DAT_02924b68)[iVar8 * 0x2c] = uVar2;
                uVar2 = FUN_006217e0();
              }
              else {
                uVar2 = FUN_00621860();
                (&DAT_02924b64)[iVar8 * 0x2c] = uVar2;
                uVar2 = FUN_00621860();
                (&DAT_02924b66)[iVar8 * 0x2c] = uVar2;
                uVar2 = FUN_00621860();
                (&DAT_02924b68)[iVar8 * 0x2c] = uVar2;
                uVar2 = FUN_00621860();
              }
              (&DAT_02924b6a)[iVar8 * 0x2c] = uVar2;
              if (iVar7 < 0x16) {
                (&DAT_02924b6c)[iVar8 * 0x2c] = 0;
              }
              else {
                uVar2 = FUN_00621860();
                (&DAT_02924b6c)[iVar8 * 0x2c] = uVar2;
              }
              if (iVar7 < 0x22) {
                if (iVar7 < 8) {
                  fVar9 = (float10)0;
                }
                else {
                  local_438 = FUN_006217e0();
                  fVar9 = (float10)local_438 / (float10)60.0;
                }
              }
              else {
                fVar9 = (float10)FUN_006217a0();
              }
              (&DAT_02924b70)[iVar8 * 0x16] = (float)fVar9;
              FUN_006216f0(&DAT_02924b74 + iVar3,0x10);
              (&DAT_02924b60)[iVar8 * 0x16] = 99999;
              iVar5 = FUN_00658490(&DAT_02924b74 + iVar3,iVar5);
              (&DAT_02924b5c)[iVar8 * 0x16] = iVar5;
              if (iVar5 == -1) {
                DAT_02962a3c = DAT_02962a3c + 1;
              }
              if (iVar7 < 9) {
                fVar9 = (float10)0;
                (&DAT_02924b84)[iVar8 * 0x16] = 0;
                (&DAT_02924b88)[iVar8 * 0x16] = 0xffffffff;
              }
              else {
                uVar10 = FUN_006217e0();
                (&DAT_02924b84)[iVar8 * 0x16] = uVar10;
                uVar10 = FUN_006217e0();
                (&DAT_02924b88)[iVar8 * 0x16] = uVar10;
                fVar9 = (float10)FUN_006217a0();
              }
              (&DAT_02924b8c)[iVar8 * 0x16] = (float)fVar9;
              if (iVar7 < 0xc) {
                fVar9 = (float10)0;
                (&DAT_02924b90)[iVar8 * 0x2c] = 0;
                (&DAT_02924b92)[iVar8 * 0x2c] = 0;
              }
              else {
                uVar2 = FUN_00621860();
                (&DAT_02924b90)[iVar8 * 0x2c] = uVar2;
                uVar2 = FUN_00621860();
                (&DAT_02924b92)[iVar8 * 0x2c] = uVar2;
                fVar9 = (float10)FUN_006217a0();
              }
              (&DAT_02924b94)[iVar8 * 0x16] = (float)fVar9;
              if (iVar7 < 0xd) {
                fVar9 = (float10)0.9;
              }
              else {
                fVar9 = (float10)FUN_006217a0();
              }
              (&DAT_02924b98)[iVar8 * 0x16] = (float)fVar9;
              if (iVar7 < 0xf) {
                (&DAT_02924b9c)[iVar8 * 0x2c] = 0;
              }
              else {
                uVar2 = FUN_00621860();
                (&DAT_02924b9c)[iVar8 * 0x2c] = uVar2;
              }
              if (iVar7 < 0x1b) {
                iVar5 = (&DAT_02924b5c)[iVar8 * 0x16];
                (&DAT_02924b9e)[iVar8 * 0x2c] = 20000;
                if (iVar5 != -1) {
                  cVar6 = *(char *)(*(int *)(DAT_0296209c + iVar5 * 4) + 0x2e);
                  if (cVar6 == '\x02') {
                    (&DAT_02924b9e)[iVar8 * 0x2c] = 40000;
                  }
                  else if (cVar6 == '\x03') {
                    (&DAT_02924b9e)[iVar8 * 0x2c] = 30000;
                  }
                  else if (cVar6 == '\0') {
                    (&DAT_02924b9e)[iVar8 * 0x2c] = 20000;
                  }
                  else if (cVar6 == '\a') {
                    (&DAT_02924b9e)[iVar8 * 0x2c] = 10000;
                  }
                }
                (&DAT_02924ba0)[iVar3] = 0;
              }
              else {
                uVar2 = FUN_00621890();
                (&DAT_02924b9e)[iVar8 * 0x2c] = uVar2;
                uVar1 = FUN_006218c0();
                (&DAT_02924ba0)[iVar3] = uVar1;
              }
              if (iVar7 < 0x24) {
                (&DAT_02924ba2)[iVar3] = 7;
              }
              else {
                uVar1 = FUN_006218c0();
                (&DAT_02924ba2)[iVar3] = uVar1;
              }
              if (iVar7 < 0x26) {
                (&DAT_02924ba3)[iVar3] = 0;
                (&DAT_02924ba4)[iVar8 * 0x2c] = 0;
                (&DAT_02924ba6)[iVar8 * 0x2c] = 0;
              }
              else {
                uVar1 = FUN_006218c0();
                (&DAT_02924ba3)[iVar3] = uVar1;
                uVar2 = FUN_00621860();
                (&DAT_02924ba4)[iVar8 * 0x2c] = uVar2;
                uVar2 = FUN_00621860();
                (&DAT_02924ba6)[iVar8 * 0x2c] = uVar2;
              }
              DAT_02962a2c = DAT_02962a2c + 1;
              iVar3 = local_430 + -1;
            } while (local_430 + -1 != 0);
            local_430 = 0;
            cVar6 = local_43d;
          }
        }
        FUN_006211b0(0);
        FUN_006213e0();
        FUN_00661f60(0x3f800000);
        if (cVar6 == '\0') {
          DAT_02962920 = local_43c;
          __security_check_cookie(local_4 ^ (uint)auStack_440);
          return;
        }
        if (cVar6 == '\x05') {
          DAT_008109c8 = local_43c;
          __security_check_cookie(local_4 ^ (uint)auStack_440);
          return;
        }
        if (cVar6 == '\x01') {
          DAT_008109cc = local_43c;
        }
        __security_check_cookie(local_4 ^ (uint)auStack_440);
        return;
      }
      FUN_006211b0(0);
      FUN_006213e0();
    }
  }
  __security_check_cookie(local_4 ^ (uint)auStack_440);
  return;
}


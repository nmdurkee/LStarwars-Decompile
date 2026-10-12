/* Ghidra analysis pseudocode, not original source.
 * ev_45ac563217612fbe2426642b00b9c96cf69ca1c78f087433beffcbe1e9bd0306
 * Entry: 0x523c40; label: FUN_00523c40
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00523c40(int param_1)

{
  ushort *puVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int in_ECX;
  undefined4 uVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  float fVar11;
  float fVar12;
  float local_2044;
  int local_2040;
  undefined4 local_203c;
  int local_2038;
  uint local_2034;
  uint local_2030;
  undefined4 local_202c;
  float local_2028;
  undefined4 local_2024;
  undefined4 local_2014;
  undefined4 local_2008;
  float local_2004;
  undefined4 local_2000;
  undefined4 local_1ff0;
  byte local_1fe4;
  undefined4 local_1fe3;
  undefined4 local_1fdf;
  undefined4 local_1fdb;
  undefined4 local_1fd7;
  undefined4 local_1fd3;
  undefined4 local_1fcf;
  undefined4 local_1fcb;
  undefined2 local_1fc7;
  undefined1 local_1fc5;
  undefined1 local_1fc4 [8128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_2044;
  local_1fe3 = 0;
  local_1fdf = 0;
  local_1fdb = 0;
  local_1fd7 = 0;
  local_1fd3 = 0;
  local_1fcf = 0;
  local_1fcb = 0;
  local_1fc7 = 0;
  local_1fc5 = 0;
  local_2038 = param_1;
  local_1fe4 = 0;
  _memset(local_1fc4,0,0x1fc0);
  iVar5 = DAT_009238e4;
  local_2034 = 0;
  if ((((byte)DAT_00921f50 & 0x80) == 0) ||
     (((iVar4 = (int)DAT_009220ee, iVar4 != DAT_00801c98 && (iVar4 != DAT_00801ca0)) &&
      (iVar4 != DAT_00801ca8)))) {
    local_2040 = 0;
  }
  else {
    local_2040 = 1;
  }
  if (DAT_009220ee == DAT_00801c9c) {
    local_2034 = __allshl();
  }
  if (param_1 == *(int *)(iVar5 + 0x4868)) {
    local_203c = 0xffffffff;
  }
  else {
    local_203c = *(undefined4 *)(&DAT_0075ff9c + (in_ECX % 5) * 4);
  }
  if (param_1 != 0) {
    for (iVar5 = FUN_004f1440(param_1 + 0x18); iVar5 != 0;
        iVar5 = FUN_004f1460(param_1 + 0x18,iVar5)) {
      if (_DAT_00924298 != 0.0) {
        *(float *)(iVar5 + 0x2c) = _DAT_00924298;
      }
      if (_DAT_0092429c != 0.0) {
        *(float *)(iVar5 + 0x28) = _DAT_0092429c;
      }
      local_2030 = (uint)*(short *)(iVar5 + 0x90);
      if (param_1 == *(int *)(DAT_009238e4 + 0x4868)) {
        if (*(int *)(param_1 + 0x20) == iVar5) {
          uVar6 = 0x20;
          uVar7 = 0xff0000ff;
        }
        else {
          if ((param_1 != *(int *)(DAT_009238e4 + 0x4868)) || (*(int *)(param_1 + 0x24) != iVar5))
          goto LAB_00523dfa;
          uVar6 = 0x20;
          uVar7 = 0xff00ffff;
        }
      }
      else {
LAB_00523dfa:
        uVar6 = 8;
        uVar7 = local_203c;
      }
      local_2044 = *(float *)(iVar5 + 0x28) + *(float *)(iVar5 + 0x1c);
      FUN_00523640(iVar5 + 0x18,*(undefined4 *)(iVar5 + 0x24),local_2044,
                   *(float *)(iVar5 + 0x2c) + *(float *)(iVar5 + 0x1c),uVar7,0,uVar6,local_2040);
      if ((*(int *)(iVar5 + 0xb0) != 0) && ((*(byte *)(*(int *)(iVar5 + 0xb0) + 10) & 1) == 0)) {
        FUN_005235a0(*(undefined4 *)(iVar5 + 0x24));
        puVar1 = (ushort *)(*(int *)(iVar5 + 0xb0) + 10);
        *puVar1 = *puVar1 | 1;
      }
      if ((local_2034 & *(ushort *)(iVar5 + 0x96)) != 0) {
        if (param_1 == *(int *)(DAT_009238e4 + 0x4868)) {
          if (*(int *)(param_1 + 0x20) == iVar5) {
            fVar12 = *(float *)(iVar5 + 0x2c) + *(float *)(iVar5 + 0x1c);
            uVar6 = 0x20;
            fVar11 = *(float *)(iVar5 + 0x28) + *(float *)(iVar5 + 0x1c);
            local_2044 = *(float *)(iVar5 + 0x24) * 0.9;
            uVar7 = 0xff0000ff;
          }
          else {
            if ((param_1 != *(int *)(DAT_009238e4 + 0x4868)) || (*(int *)(param_1 + 0x24) != iVar5))
            goto LAB_00523f39;
            fVar12 = *(float *)(iVar5 + 0x2c) + *(float *)(iVar5 + 0x1c);
            uVar6 = 0x20;
            fVar11 = *(float *)(iVar5 + 0x28) + *(float *)(iVar5 + 0x1c);
            local_2044 = *(float *)(iVar5 + 0x24) * 0.9;
            uVar7 = 0xff00ffff;
          }
        }
        else {
LAB_00523f39:
          fVar12 = *(float *)(iVar5 + 0x2c) + *(float *)(iVar5 + 0x1c);
          uVar6 = 8;
          fVar11 = *(float *)(iVar5 + 0x28) + *(float *)(iVar5 + 0x1c);
          local_2044 = *(float *)(iVar5 + 0x24) * 0.9;
          uVar7 = local_203c;
        }
        FUN_00523640(iVar5 + 0x18,local_2044,fVar11,fVar12,uVar7,0,uVar6,local_2040);
      }
      piVar9 = (int *)(iVar5 + 0x30);
      local_2044 = 1.12104e-44;
      do {
        iVar4 = *piVar9;
        if (iVar4 != 0) {
          uVar10 = (uint)*(short *)(iVar4 + 0x90);
          uVar7 = local_203c;
          if ((iVar5 == *(int *)(param_1 + 0x20)) && (iVar4 == *(int *)(param_1 + 0x24))) {
            uVar7 = 0xff00ffff;
          }
          FUN_005236d0(iVar5 + 0x18,*(undefined4 *)(iVar5 + 0x24),iVar4 + 0x18,piVar9[1],uVar7);
          iVar4 = local_2038;
          bVar2 = (&local_1fe4)
                  [((int)(uVar10 + ((int)uVar10 >> 0x1f & 7U)) >> 3) + local_2030 * 0x20];
          uVar8 = uVar10 & 0x80000007;
          if ((int)uVar8 < 0) {
            uVar8 = (uVar8 - 1 | 0xfffffff8) + 1;
          }
          param_1 = iVar4;
          if ((bVar2 & (byte)(1 << ((byte)uVar8 & 0x1f))) == 0) {
            (&local_1fe4)[((int)(uVar10 + ((int)uVar10 >> 0x1f & 7U)) >> 3) + local_2030 * 0x20] =
                 '\x01' << ((byte)uVar8 & 0x1f) | bVar2;
            uVar8 = local_2030 & 0x80000007;
            if ((int)uVar8 < 0) {
              uVar8 = (uVar8 - 1 | 0xfffffff8) + 1;
            }
            (&local_1fe4)[uVar10 * 0x20 + ((int)(local_2030 + ((int)local_2030 >> 0x1f & 7U)) >> 3)]
                 = (&local_1fe4)
                   [uVar10 * 0x20 + ((int)(local_2030 + ((int)local_2030 >> 0x1f & 7U)) >> 3)] |
                   '\x01' << ((byte)uVar8 & 0x1f);
            uVar7 = local_203c;
            if (local_2038 == *(int *)(DAT_009238e4 + 0x4868)) {
              iVar3 = *(int *)(local_2038 + 0x20);
              if (((iVar5 == iVar3) && (*piVar9 == *(int *)(local_2038 + 0x24))) ||
                 ((iVar5 == *(int *)(local_2038 + 0x24) && (*piVar9 == iVar3)))) {
                uVar7 = 0xff00ffff;
              }
              else if ((iVar5 == iVar3) || (*piVar9 == iVar3)) {
                uVar7 = 0xff0000ff;
              }
            }
            if (local_2040 == 0) {
              FUN_00523220(iVar5,*piVar9,uVar7);
            }
            else {
              FUN_00522e30();
            }
            uVar7 = 0xffff0000;
            if (((iVar5 == *(int *)(iVar4 + 0x20)) && (*piVar9 == *(int *)(iVar4 + 0x24))) ||
               ((iVar5 == *(int *)(iVar4 + 0x24) && (*piVar9 == *(int *)(iVar4 + 0x20))))) {
              uVar7 = 0xff00ffff;
            }
            param_1 = local_2038;
            if ((local_2034 & *(ushort *)(piVar9 + 2)) != 0) {
              local_202c = *(undefined4 *)(iVar5 + 0x18);
              local_2024 = *(undefined4 *)(iVar5 + 0x20);
              local_2028 = *(float *)(iVar5 + 0x1c) + _DAT_00801cc8 + 0.02;
              iVar3 = *piVar9;
              local_2008 = *(undefined4 *)(iVar3 + 0x18);
              local_2000 = *(undefined4 *)(iVar3 + 0x20);
              local_2004 = _DAT_00801cc8 + 0.02 + *(float *)(iVar3 + 0x1c);
              local_2014 = uVar7;
              local_1ff0 = uVar7;
              FUN_00512b00(&local_202c,0,0);
              param_1 = iVar4;
            }
          }
        }
        piVar9 = piVar9 + 3;
        local_2044 = (float)((int)local_2044 + -1);
      } while (local_2044 != 0.0);
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_2044);
  return;
}


/* Ghidra pseudocode, not original source.
 * ev_ab3200993c06f50ca9adf40c5a4b161cdaf830edaeb783e0e0f7b7da1276ea12
 * Entry: 0x5a73e0; label: FUN_005a73e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a73e0(int param_1)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  int local_118;
  int local_114;
  uint local_110;
  int local_10c;
  int local_108;
  undefined1 local_104 [16];
  undefined1 local_f4;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_118;
  if (*(int *)(param_1 + 0x46c0) != 0) {
    __security_check_cookie(local_4 ^ (uint)&local_118);
    return;
  }
  DAT_00805b20 = FUN_006217e0();
  iVar3 = FUN_006217e0();
  *(int *)(param_1 + 0x46c0) = iVar3;
  local_10c = 0;
  local_114 = 0;
  if (0 < iVar3) {
    local_118 = 0;
    do {
      iVar7 = *(int *)(param_1 + 0x46bc) + local_118;
      local_108 = 0;
      _memset(local_104,0,0x100);
      cVar1 = FUN_006218c0();
      FUN_006216f0(local_104,(int)cVar1);
      iVar3 = iVar7 + 0x44;
      iVar4 = FUN_0055acd0(*(undefined4 *)(param_1 + 0x13c),iVar7 + 0x24,local_104,1,
                           *(undefined4 *)(param_1 + 0x2ac8),"PushBlock",iVar3);
      if (iVar4 == 0) {
        local_108 = 1;
      }
      else {
        uVar5 = FUN_005cfa50(iVar7 + 0x24);
        FUN_004f1f10(iVar3,uVar5);
      }
      fVar8 = (float10)FUN_006217a0();
      *(float *)(iVar7 + 0x40) = (float)fVar8;
      *(uint *)(iVar7 + 200) = *(uint *)(iVar7 + 200) & 0xfbffffff;
      cVar1 = FUN_006218c0();
      if (cVar1 != '\0') {
        *(uint *)(iVar7 + 200) = *(uint *)(iVar7 + 200) | 0x4000000;
      }
      *(uint *)(iVar7 + 200) = *(uint *)(iVar7 + 200) & 0xf7ffffff;
      cVar1 = FUN_006218c0();
      if (cVar1 != '\0') {
        *(uint *)(iVar7 + 200) = *(uint *)(iVar7 + 200) | 0x8000000;
      }
      *(uint *)(iVar7 + 200) = *(uint *)(iVar7 + 200) & 0xffefffff;
      cVar1 = FUN_006218c0();
      if (cVar1 != '\0') {
        *(uint *)(iVar7 + 200) = *(uint *)(iVar7 + 200) | 0x100000;
      }
      *(uint *)(iVar7 + 200) = *(uint *)(iVar7 + 200) & 0xffdfffff;
      cVar1 = FUN_006218c0();
      if (cVar1 != '\0') {
        *(uint *)(iVar7 + 200) = *(uint *)(iVar7 + 200) | 0x200000;
      }
      if (3 < DAT_00805b20) {
        *(uint *)(iVar7 + 200) = *(uint *)(iVar7 + 200) & 0xdfffffff;
        cVar1 = FUN_006218c0();
        if (cVar1 != '\0') {
          *(uint *)(iVar7 + 200) = *(uint *)(iVar7 + 200) | 0x20000000;
        }
        *(uint *)(iVar7 + 200) = *(uint *)(iVar7 + 200) & 0xbfffffff;
        cVar1 = FUN_006218c0();
        if (cVar1 != '\0') {
          *(uint *)(iVar7 + 200) = *(uint *)(iVar7 + 200) | 0x40000000;
        }
      }
      if (4 < DAT_00805b20) {
        *(uint *)(iVar7 + 200) = *(uint *)(iVar7 + 200) & 0xffbfffff;
        cVar1 = FUN_006218c0();
        if (cVar1 != '\0') {
          *(uint *)(iVar7 + 200) = *(uint *)(iVar7 + 200) | 0x400000;
        }
        *(uint *)(iVar7 + 200) = *(uint *)(iVar7 + 200) & 0xff7fffff;
        cVar1 = FUN_006218c0();
        if (cVar1 != '\0') {
          *(uint *)(iVar7 + 200) = *(uint *)(iVar7 + 200) | 0x800000;
        }
      }
      iVar4 = DAT_00805b20;
      *(undefined1 *)(iVar7 + 0xd1) = 0;
      if (2 < iVar4) {
        bVar2 = FUN_006218c0();
        *(byte *)(iVar7 + 0xd1) = bVar2;
        if (bVar2 != 0) {
          iVar4 = iVar7 + 0x5c;
          local_110 = (uint)bVar2;
          do {
            _memset(local_104,0,0x100);
            cVar1 = FUN_006218c0();
            FUN_006216f0(local_104,(int)cVar1);
            local_f4 = 0;
            iVar6 = FUN_0055acd0(*(undefined4 *)(param_1 + 0x13c),iVar4,local_104,1,
                                 *(undefined4 *)(param_1 + 0x2ac8),"PushBlockLinkObject",iVar3);
            if (iVar6 == 0) {
              *(char *)(iVar7 + 0xd1) = *(char *)(iVar7 + 0xd1) + -1;
            }
            iVar4 = iVar4 + 0xc;
            local_110 = local_110 - 1;
          } while (local_110 != 0);
        }
      }
      if (local_108 == 0) {
        local_114 = local_114 + 1;
        local_118 = local_118 + 0xd4;
      }
      local_10c = local_10c + 1;
    } while (local_10c < *(int *)(param_1 + 0x46c0));
  }
  *(int *)(param_1 + 0x46c0) = local_114;
  __security_check_cookie(local_4 ^ (uint)&local_118);
  return;
}


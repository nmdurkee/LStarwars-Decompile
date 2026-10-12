/* Ghidra pseudocode, not original source.
 * ev_7e454dac1a79555432f813726d68bcfcf5762a505a2d8dbf5e6e5fb42bc98c3e
 * Entry: 0x54cd80; label: FUN_0054cd80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0054cd80(int param_1)

{
  byte *pbVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  char cVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  float10 fVar10;
  int local_108;
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_108;
  iVar9 = 0;
  if (*(int *)(param_1 + 0x5084) != 0) {
    __security_check_cookie(local_4 ^ (uint)&local_108);
    return;
  }
  iVar6 = FUN_006217e0();
  iVar7 = FUN_006217e0();
  *(int *)(param_1 + 0x5084) = iVar7;
  local_108 = 0;
  if (0 < iVar7) {
    do {
      FUN_006216f0(*(int *)(param_1 + 0x5080) + iVar9,0x10);
      FUN_00621900(*(int *)(param_1 + 0x5080) + 0x10 + iVar9);
      if (iVar6 < 2) {
        FUN_00621890();
        uVar5 = FUN_00621890();
        *(undefined2 *)(*(int *)(param_1 + 0x5080) + 0x20 + iVar9) = uVar5;
      }
      else {
        uVar5 = FUN_00621890();
        *(undefined2 *)(*(int *)(param_1 + 0x5080) + 0x20 + iVar9) = uVar5;
      }
      if (iVar6 < 3) {
        *(undefined4 *)(*(int *)(param_1 + 0x5080) + 0x4c + iVar9) = 0x3f800000;
      }
      else {
        fVar10 = (float10)FUN_006217a0();
        *(float *)(*(int *)(param_1 + 0x5080) + 0x4c + iVar9) = (float)fVar10;
      }
      if (iVar6 < 4) {
        pbVar1 = (byte *)(*(int *)(param_1 + 0x5080) + 0x1e + iVar9);
        *pbVar1 = *pbVar1 & 0xfb;
        *(undefined4 *)(*(int *)(param_1 + 0x5080) + 0x50 + iVar9) = 0x40000000;
      }
      else {
        cVar4 = FUN_006218c0();
        pbVar1 = (byte *)(*(int *)(param_1 + 0x5080) + 0x1e + iVar9);
        *pbVar1 = *pbVar1 ^ ((cVar4 != '\0') * '\x04' ^ *pbVar1) & 4;
        fVar10 = (float10)FUN_006217a0();
        *(float *)(*(int *)(param_1 + 0x5080) + 0x50 + iVar9) = (float)fVar10;
      }
      if (iVar6 < 5) {
        *(undefined2 *)(*(int *)(param_1 + 0x5080) + 0x22 + iVar9) = 0;
      }
      else {
        uVar5 = FUN_00621890();
        *(undefined2 *)(*(int *)(param_1 + 0x5080) + 0x22 + iVar9) = uVar5;
      }
      if (iVar6 < 6) {
        pbVar1 = (byte *)(*(int *)(param_1 + 0x5080) + 0x1e + iVar9);
        *pbVar1 = *pbVar1 & 0xf7;
      }
      else {
        cVar4 = FUN_006218c0();
        pbVar1 = (byte *)(*(int *)(param_1 + 0x5080) + 0x1e + iVar9);
        *pbVar1 = *pbVar1 ^ ((cVar4 != '\0') << 3 ^
                            *(byte *)(*(int *)(param_1 + 0x5080) + 0x1e + iVar9)) & 8;
      }
      puVar2 = (undefined4 *)(*(int *)(param_1 + 0x5080) + 0xec + iVar9);
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      if (6 < iVar6) {
        uVar8 = FUN_006218e0();
        uVar8 = uVar8 & 0xff;
        if (uVar8 != 0) {
          FUN_006216f0(local_104,uVar8);
          iVar7 = *(int *)(param_1 + 0x5080);
          uVar3 = *(undefined4 *)(param_1 + 0x13c);
          local_104[uVar8] = 0;
          FUN_005cf5b0(uVar3,iVar7 + 0xec + iVar9,local_104,1);
        }
      }
      local_108 = local_108 + 1;
      iVar9 = iVar9 + 0xf8;
    } while (local_108 < *(int *)(param_1 + 0x5084));
  }
  __security_check_cookie(local_4 ^ (uint)&local_108);
  return;
}


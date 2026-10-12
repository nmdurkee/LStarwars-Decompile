/* Ghidra pseudocode, not original source.
 * ev_51f4537ed7c57c9a0fa7f304a7a0f3427cc608dfecd65a4b8280241ed2e1f797
 * Entry: 0x5ab3d0; label: FUN_005ab3d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ab3d0(int param_1,int *param_2)

{
  undefined4 *puVar1;
  byte *pbVar2;
  byte bVar3;
  char cVar4;
  undefined1 uVar5;
  short sVar6;
  undefined2 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  float10 fVar12;
  int local_118;
  int local_114;
  int local_110;
  int *local_10c;
  undefined4 local_108;
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_118;
  local_118 = param_1;
  local_10c = param_2;
  bVar3 = FUN_006218c0();
  local_108 = CONCAT31(local_108._1_3_,bVar3);
  sVar6 = FUN_00621860();
  *(short *)(param_2 + 2) = sVar6;
  if (sVar6 != 0) {
    local_114 = *param_2;
    local_110 = 0;
    iVar11 = local_114 + 8;
    do {
      FUN_005ab2d0();
      FUN_006216f0(iVar11,0x10);
      FUN_005aef10(*(undefined4 *)(iVar11 + 0x10),local_118,FUN_005ab390,local_108,"GizTurret",
                   iVar11);
      FUN_00621900(iVar11 + 0x1c);
      FUN_00621900(iVar11 + 0x28);
      FUN_00621900(iVar11 + 0x34);
      FUN_00621900(iVar11 + 0x40);
      uVar8 = FUN_006217e0();
      *(undefined4 *)(iVar11 + 0x50) = uVar8;
      uVar8 = FUN_006217e0();
      *(undefined4 *)(iVar11 + 0x54) = uVar8;
      uVar8 = FUN_006217e0();
      *(undefined4 *)(iVar11 + 0x5c) = uVar8;
      uVar8 = FUN_006217e0();
      *(undefined4 *)(iVar11 + 0x60) = uVar8;
      uVar8 = FUN_006217e0();
      *(undefined4 *)(iVar11 + 100) = uVar8;
      uVar8 = FUN_006217e0();
      *(undefined4 *)(iVar11 + 0x68) = uVar8;
      if (1 < bVar3) {
        uVar8 = FUN_006217e0();
        *(undefined4 *)(iVar11 + 0x100) = uVar8;
      }
      cVar4 = FUN_006218c0();
      iVar9 = 0;
      *(char *)(iVar11 + 0x128) = cVar4;
      if (cVar4 != '\0') {
        iVar10 = iVar11 + 0x6c;
        do {
          FUN_00621900(iVar10);
          iVar9 = iVar9 + 1;
          iVar10 = iVar10 + 0xc;
        } while (iVar9 < (int)(uint)*(byte *)(iVar11 + 0x128));
      }
      fVar12 = (float10)FUN_006217a0();
      *(float *)(iVar11 + 0xe4) = (float)fVar12;
      fVar12 = (float10)FUN_006217a0();
      *(float *)(iVar11 + 0xe8) = (float)fVar12;
      fVar12 = (float10)FUN_006217a0();
      *(float *)(iVar11 + 0xec) = (float)fVar12;
      fVar12 = (float10)FUN_006217a0();
      *(float *)(iVar11 + 0xf4) = (float)fVar12;
      fVar12 = (float10)FUN_006217a0();
      *(float *)(iVar11 + 0xf8) = (float)fVar12;
      fVar12 = (float10)FUN_006217a0();
      *(float *)(iVar11 + 0xfc) = (float)fVar12;
      uVar7 = FUN_00621860();
      *(undefined2 *)(iVar11 + 0x104) = uVar7;
      uVar7 = FUN_00621860();
      *(undefined2 *)(iVar11 + 0x108) = uVar7;
      uVar7 = FUN_00621860();
      *(undefined2 *)(iVar11 + 0x10a) = uVar7;
      FUN_00621900(iVar11 + 0x10c);
      if (bVar3 < 6) {
        if ((*(int *)(local_118 + 300) == 0) ||
           ((*(byte *)(*(int *)(local_118 + 300) + 0x7a) & 1) == 0)) {
          fVar12 = (float10)1.75;
        }
        else {
          fVar12 = (float10)12.0;
        }
      }
      else {
        fVar12 = (float10)FUN_006217a0();
      }
      *(float *)(iVar11 + 0x118) = (float)fVar12;
      uVar5 = FUN_006218c0();
      *(undefined1 *)(iVar11 + 0x127) = uVar5;
      if (3 < bVar3) {
        uVar5 = FUN_006218c0();
        *(undefined1 *)(iVar11 + 0x129) = uVar5;
        uVar7 = FUN_00621860();
        *(undefined2 *)(iVar11 + 0x120) = uVar7;
      }
      iVar9 = FUN_005595b0(local_104);
      if (iVar9 != 0) {
        uVar5 = FUN_005806f0(local_104,local_118);
        *(undefined1 *)(iVar11 + 0x125) = uVar5;
      }
      iVar9 = FUN_005595b0(local_104);
      if (iVar9 != 0) {
        uVar7 = FUN_00650dc0(local_104);
        *(undefined2 *)(iVar11 + 0x122) = uVar7;
      }
      iVar9 = FUN_005595b0(local_104);
      if (iVar9 != 0) {
        uVar7 = FUN_00650dc0(local_104);
        *(undefined2 *)(iVar11 + 0x11e) = uVar7;
      }
      if ((6 < bVar3) && (iVar9 = FUN_005595b0(local_104), iVar9 != 0)) {
        uVar7 = FUN_00650dc0(local_104);
        *(undefined2 *)(iVar11 + 0x130) = uVar7;
      }
      iVar9 = FUN_005595b0(local_104);
      if (iVar9 != 0) {
        sVar6 = FUN_0056a9d0(local_104);
        *(short *)(iVar11 + 0x11c) = sVar6;
        if (sVar6 != -1) {
          *(ushort *)(iVar11 + 0x132) = *(ushort *)(iVar11 + 0x132) | 0x100;
        }
      }
      uVar7 = FUN_00621860();
      *(undefined2 *)(iVar11 + 300) = uVar7;
      if (bVar3 < 5) {
        iVar9 = 0;
        for (puVar1 = *(undefined4 **)(*(int *)(iVar11 + 0x10) + 0x18); puVar1 != (undefined4 *)0x0;
            puVar1 = (undefined4 *)*puVar1) {
          pbVar2 = (byte *)puVar1[9];
          if (iVar9 == 0) {
            pbVar2[1] = 1;
          }
          else if (iVar9 == 1) {
            pbVar2[1] = 2;
          }
          else if ((*pbVar2 & 1) != 0) {
            pbVar2[1] = 3;
          }
          iVar9 = iVar9 + 1;
        }
      }
      local_114 = local_114 + 0x13c;
      local_110 = local_110 + 1;
      iVar11 = iVar11 + 0x13c;
    } while (local_110 < (int)(uint)*(ushort *)(local_10c + 2));
  }
  __security_check_cookie(local_4 ^ (uint)&local_118);
  return;
}


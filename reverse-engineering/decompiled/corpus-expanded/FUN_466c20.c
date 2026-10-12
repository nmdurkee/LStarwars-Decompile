/* Ghidra pseudocode, not original source.
 * ev_8b33ce688355ba097f8d2f702831fda396d81ac3370e92e38da24fe76235d9ff
 * Entry: 0x466c20; label: FUN_00466c20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00466c20(int param_1,int *param_2)

{
  byte bVar1;
  undefined1 uVar2;
  char cVar3;
  short sVar4;
  undefined2 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  int local_7c;
  int *local_78;
  undefined4 local_74;
  undefined1 local_70 [12];
  undefined1 local_64 [64];
  undefined1 local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_7c;
  local_78 = param_2;
  bVar1 = FUN_006218c0();
  DAT_007f8cc8 = (uint)bVar1;
  local_74 = CONCAT31(local_74._1_3_,bVar1);
  sVar4 = FUN_00621860();
  *(short *)((int)param_2 + 0xe) = sVar4;
  if (sVar4 != 0) {
    iVar8 = *param_2;
    local_7c = 0;
    do {
      FUN_006216f0(iVar8,0x10);
      FUN_00621900(iVar8 + 0x10);
      if (bVar1 == 1) {
        FUN_00621900(local_70);
      }
      fVar9 = (float10)FUN_006217a0();
      *(float *)(iVar8 + 0x44) = (float)fVar9;
      if (7 < bVar1) {
        fVar9 = (float10)FUN_006217a0();
        *(float *)(iVar8 + 0x4c) = (float)fVar9;
      }
      fVar9 = (float10)FUN_006217a0();
      *(float *)(iVar8 + 0x54) = (float)fVar9;
      if (bVar1 == 1) {
        FUN_00621900(local_70);
        FUN_00621860();
      }
      uVar6 = FUN_006217e0();
      *(uint *)(iVar8 + 0x74) = uVar6;
      if (bVar1 < 0xd) {
        *(uint *)(iVar8 + 0x74) = uVar6 | 0x800;
      }
      uVar2 = FUN_006218c0();
      *(undefined1 *)(iVar8 + 0x7c) = uVar2;
      if (10 < bVar1) {
        cVar3 = FUN_006218c0();
        *(char *)(iVar8 + 0x7d) = cVar3;
        if ((bVar1 == 0xb) && (cVar3 != '\0')) {
          *(char *)(iVar8 + 0x7d) = '\x01' << (cVar3 - 1U & 0x1f);
        }
      }
      uVar2 = FUN_006218c0();
      *(undefined1 *)(iVar8 + 0x7e) = uVar2;
      if (bVar1 == 1) {
        FUN_006218c0();
      }
      FUN_005aef10(*(undefined4 *)(iVar8 + 0x28),param_1,FUN_00466bf0,local_74,"GizForce",iVar8);
      fVar9 = (float10)FUN_006217a0();
      *(float *)(iVar8 + 0x5c) = (float)fVar9;
      fVar9 = (float10)FUN_006217a0();
      *(float *)(iVar8 + 0x60) = (float)fVar9;
      if (5 < bVar1) {
        fVar9 = (float10)FUN_006217a0();
        *(float *)(iVar8 + 100) = (float)fVar9;
      }
      if (bVar1 < 7) {
        fVar9 = (float10)1;
      }
      else {
        fVar9 = (float10)FUN_006217a0();
      }
      *(float *)(iVar8 + 0x70) = (float)fVar9;
      if (2 < bVar1) {
        fVar9 = (float10)FUN_006217a0();
        *(float *)(iVar8 + 0x6c) = (float)fVar9;
      }
      *(undefined2 *)(iVar8 + 0x88) = 0xffff;
      if (3 < bVar1) {
        if (bVar1 < 5) {
          uVar5 = FUN_00621860();
          *(undefined2 *)(iVar8 + 0x88) = uVar5;
        }
        else {
          cVar3 = FUN_006218c0();
          if (cVar3 != 0) {
            FUN_006216f0(local_24,(int)cVar3);
            sVar4 = FUN_0056a9d0(local_24);
            *(short *)(iVar8 + 0x88) = sVar4;
            if (sVar4 != -1) {
              *(uint *)(iVar8 + 0xa0) = *(uint *)(iVar8 + 0xa0) | 0x400;
            }
          }
        }
        uVar5 = FUN_00621860();
        *(undefined2 *)(iVar8 + 0x8a) = uVar5;
        uVar5 = FUN_00621860();
        *(undefined2 *)(iVar8 + 0x8c) = uVar5;
        uVar5 = FUN_00621860();
        *(undefined2 *)(iVar8 + 0x8e) = uVar5;
        FUN_00621900(iVar8 + 0x90);
      }
      if (bVar1 < 10) {
        if ((*(int *)(param_1 + 300) == 0) || ((*(byte *)(*(int *)(param_1 + 300) + 0x7a) & 1) == 0)
           ) {
          fVar9 = (float10)1.75;
        }
        else {
          fVar9 = (float10)12.0;
        }
      }
      else {
        fVar9 = (float10)FUN_006217a0();
      }
      *(float *)(iVar8 + 0x9c) = (float)fVar9;
      *(undefined2 *)(iVar8 + 0x82) = 0xffff;
      *(undefined2 *)(iVar8 + 0x84) = 0xffff;
      *(undefined2 *)(iVar8 + 0x86) = 0xffff;
      if (bVar1 < 0xe) {
LAB_00466ed2:
        *(undefined2 *)(iVar8 + 0x82) = 0xffff;
        *(undefined2 *)(iVar8 + 0x84) = 0xffff;
        *(undefined2 *)(iVar8 + 0x86) = 0xffff;
      }
      else {
        iVar7 = FUN_005595b0(local_64);
        if (iVar7 != 0) {
          uVar5 = FUN_00650dc0(local_64);
          *(undefined2 *)(iVar8 + 0x82) = uVar5;
        }
        iVar7 = FUN_005595b0(local_64);
        if (iVar7 != 0) {
          uVar5 = FUN_00650dc0(local_64);
          *(undefined2 *)(iVar8 + 0x84) = uVar5;
        }
        iVar7 = FUN_005595b0(local_64);
        if (iVar7 != 0) {
          uVar5 = FUN_00650dc0(local_64);
          *(undefined2 *)(iVar8 + 0x86) = uVar5;
        }
        if (bVar1 < 0xf) goto LAB_00466ed2;
      }
      if ((*(byte *)(iVar8 + 0x74) & 0x40) != 0) {
        FUN_00466b30();
      }
      local_7c = local_7c + 1;
      iVar8 = iVar8 + 0xa4;
    } while (local_7c < (int)(uint)*(ushort *)((int)local_78 + 0xe));
  }
  __security_check_cookie(local_4 ^ (uint)&local_7c);
  return;
}


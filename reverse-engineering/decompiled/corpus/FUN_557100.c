/* Ghidra analysis pseudocode, not original source.
 * ev_6abf8ab4ca62df3d34ad8936d98d3e0ff06655f6d2b2d7dbe0f57931c7009014
 * Entry: 0x557100; label: FUN_00557100
 */

/* WARNING: Removing unreachable block (ram,0x005573af) */

void FUN_00557100(int param_1,int *param_2)

{
  byte bVar1;
  undefined1 uVar2;
  char cVar3;
  short sVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  float10 fVar10;
  int local_74;
  int local_70;
  undefined4 local_6c;
  int *local_68;
  undefined1 local_64 [32];
  undefined1 local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_74;
  local_74 = param_1;
  local_68 = param_2;
  bVar1 = FUN_006218c0();
  local_6c = CONCAT31(local_6c._1_3_,bVar1);
  sVar4 = FUN_00621860();
  *(short *)(param_2 + 2) = sVar4;
  if (sVar4 != 0) {
    iVar8 = *param_2;
    local_70 = 0;
    puVar9 = (undefined4 *)(iVar8 + 0x1c);
    do {
      FUN_006216f0(iVar8,0x10);
      FUN_00621900(puVar9 + -3);
      if (bVar1 < 2) {
        *puVar9 = puVar9[-3];
        puVar9[1] = puVar9[-2];
        puVar9[2] = puVar9[-1];
      }
      else {
        FUN_00621900(puVar9);
      }
      fVar10 = (float10)FUN_006217a0();
      puVar9[8] = (float)fVar10;
      fVar10 = (float10)FUN_006217a0();
      puVar9[10] = (float)fVar10;
      if (bVar1 < 3) {
        puVar9[0x10] = 0x3e800000;
        puVar9[0x11] = 0x3e800000;
        puVar9[0x12] = 0x3e800000;
      }
      else {
        FUN_00621900(puVar9 + 0x10);
        uVar5 = FUN_00621860();
        *(undefined2 *)(puVar9 + 0x1a) = uVar5;
      }
      uVar6 = FUN_006217e0();
      puVar9[0x13] = uVar6;
      if (0xb < bVar1) {
        uVar6 = FUN_006217e0();
        puVar9[0x14] = uVar6;
      }
      if (bVar1 == 6) {
        FUN_00621860();
        FUN_006218c0();
      }
      uVar2 = FUN_006218c0();
      *(undefined1 *)(puVar9 + 0x1d) = uVar2;
      uVar2 = FUN_006218c0();
      *(undefined1 *)((int)puVar9 + 0x75) = uVar2;
      if (bVar1 < 7) {
        *(undefined1 *)((int)puVar9 + 0x76) = 0xff;
      }
      else {
        uVar2 = FUN_006218c0();
        *(undefined1 *)((int)puVar9 + 0x76) = uVar2;
      }
      FUN_005aef10(puVar9[6],local_74,&LAB_005570c0,local_6c,"GizObstacle",iVar8);
      if (bVar1 < 4) {
        fVar10 = (float10)1;
      }
      else {
        fVar10 = (float10)FUN_006217a0();
      }
      puVar9[0xc] = (float)fVar10;
      if (bVar1 < 5) {
        fVar10 = (float10)(float)puVar9[0xc];
      }
      else {
        fVar10 = (float10)FUN_006217a0();
      }
      puVar9[0xd] = (float)fVar10;
      if (7 < bVar1) {
        fVar10 = (float10)FUN_006217a0();
        puVar9[0xe] = (float)fVar10;
      }
      *(undefined2 *)(puVar9 + 0x1b) = 0xffff;
      if (8 < bVar1) {
        if (bVar1 < 10) {
          uVar5 = FUN_00621860();
          *(undefined2 *)(puVar9 + 0x1b) = uVar5;
        }
        else {
          cVar3 = FUN_006218c0();
          if (cVar3 != 0) {
            FUN_006216f0(local_64,(int)cVar3);
            sVar4 = FUN_0056a9d0(local_64);
            *(short *)(puVar9 + 0x1b) = sVar4;
            if (sVar4 != -1) {
              puVar9[0x20] = puVar9[0x20] | 2;
            }
          }
        }
        uVar5 = FUN_00621860();
        *(undefined2 *)((int)puVar9 + 0x6e) = uVar5;
        uVar5 = FUN_00621860();
        *(undefined2 *)(puVar9 + 0x19) = uVar5;
        uVar5 = FUN_00621860();
        *(undefined2 *)((int)puVar9 + 0x66) = uVar5;
        FUN_00621900(puVar9 + 0x15);
      }
      if (bVar1 < 0xb) {
        if ((*(int *)(local_74 + 300) == 0) ||
           ((*(byte *)(*(int *)(local_74 + 300) + 0x7a) & 1) == 0)) {
          fVar10 = (float10)1.75;
        }
        else {
          fVar10 = (float10)12.0;
        }
      }
      else {
        fVar10 = (float10)FUN_006217a0();
      }
      puVar9[0x18] = (float)fVar10;
      *(undefined2 *)(puVar9 + 0x1c) = 0xffff;
      *(undefined2 *)((int)puVar9 + 0x72) = 0xffff;
      if (bVar1 < 0xd) {
        if (DAT_0093b1e8 != (code *)0x0) {
          (*DAT_0093b1e8)(local_74,iVar8);
        }
      }
      else {
        iVar7 = FUN_005595b0(local_44);
        if (iVar7 != 0) {
          uVar5 = FUN_00650dc0(local_44);
          *(undefined2 *)(puVar9 + 0x1c) = uVar5;
        }
      }
      if ((0xd < bVar1) && (iVar7 = FUN_005595b0(local_44), iVar7 != 0)) {
        uVar5 = FUN_00650dc0(local_44);
        *(undefined2 *)((int)puVar9 + 0x72) = uVar5;
      }
      local_70 = local_70 + 1;
      iVar8 = iVar8 + 0xa0;
      puVar9 = puVar9 + 0x28;
    } while (local_70 < (int)(uint)*(ushort *)(local_68 + 2));
    __security_check_cookie(local_4 ^ (uint)&local_74);
    return;
  }
  __security_check_cookie(local_4 ^ (uint)&local_74);
  return;
}


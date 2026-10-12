/* Ghidra pseudocode, not original source.
 * ev_e9e973cc1e732372fb6e3c1361e2c8e184c78a797f94e34f658706f6700bd0dd
 * Entry: 0x5fe0d0; label: FUN_005fe0d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005fe0d0(int *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  float fVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  float fVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  float fVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar1 = param_1[1];
  if (((param_1[6] != 0) && (param_1[5] != 0)) && (iVar2 = *param_1, iVar2 != 0)) {
    iVar3 = *(int *)(*(int *)(iVar2 + 0xc) + -0x60 + *(int *)(iVar2 + 4) * 0x78);
    iVar2 = *(int *)(iVar2 + 0xc) + -0x78 + *(int *)(iVar2 + 4) * 0x78;
    local_10 = (float)iVar3;
    if (*(char *)(iVar2 + 0x14) == '\0') {
      local_c = 0;
    }
    else {
      local_c = 0x3f800000;
    }
    local_8 = *(undefined4 *)(iVar2 + 0x20);
    local_4 = *(undefined4 *)(iVar2 + 0x24);
    FUN_006e5750(200,&local_10,1);
    local_10 = *(float *)(iVar2 + 0x28);
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    FUN_006e5750(0xc9,&local_10,1);
    local_10 = *(float *)(iVar2 + 0x3c);
    local_c = *(undefined4 *)(iVar2 + 0x40);
    local_8 = *(undefined4 *)(iVar2 + 0x44);
    fVar4 = *(float *)(iVar2 + 0x48);
    uVar5 = *(undefined4 *)(iVar2 + 0x4c);
    uVar6 = *(undefined4 *)(iVar2 + 0x50);
    fVar7 = *(float *)(iVar2 + 0x54);
    uVar8 = *(undefined4 *)(iVar2 + 0x58);
    uVar9 = *(undefined4 *)(iVar2 + 0x5c);
    fVar10 = *(float *)(iVar2 + 0x60);
    uVar11 = *(undefined4 *)(iVar2 + 100);
    uVar12 = *(undefined4 *)(iVar2 + 0x68);
    fVar13 = *(float *)(iVar2 + 0x6c);
    uVar14 = *(undefined4 *)(iVar2 + 0x70);
    uVar15 = *(undefined4 *)(iVar2 + 0x74);
    local_4 = 0x3f800000;
    FUN_006e52e0(0xca,&local_10,1);
    local_4 = 0x3f800000;
    local_10 = fVar4;
    local_c = uVar5;
    local_8 = uVar6;
    FUN_006e52e0(0xcb,&local_10,1);
    local_4 = 0x3f800000;
    local_10 = fVar7;
    local_c = uVar8;
    local_8 = uVar9;
    FUN_006e52e0(0xcc,&local_10,1);
    local_4 = 0x3f800000;
    local_10 = fVar10;
    local_c = uVar11;
    local_8 = uVar12;
    FUN_006e52e0(0xcd,&local_10,1);
    local_4 = 0x3f800000;
    local_10 = fVar13;
    local_c = uVar14;
    local_8 = uVar15;
    FUN_006e52e0(0xce,&local_10,1);
    local_10 = *(float *)(iVar2 + 0x1c);
    local_c = *(undefined4 *)(iVar2 + 0x2c);
    local_8 = *(undefined4 *)(iVar2 + 0x30);
    local_4 = *(undefined4 *)(iVar2 + 0x34);
    FUN_006e52e0(0xd3,&local_10,1);
    local_10 = *(float *)(iVar2 + 0x38);
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    FUN_006e52e0(0xd4,&local_10,1);
    FUN_006e5590(0,param_1[6],0,0x10);
    FUN_006e5610(0,uVar1 | 0x40000000);
    FUN_006e5590(1,param_1[5],0,0x50);
    FUN_006e5610(1,0x80000001);
    FUN_006e51d0(param_1[7]);
    iVar3 = iVar3 * 2;
    FUN_006e48e0(5,0,0,iVar3 + 2,0,iVar3);
    FUN_006e5590(0,0,0,0);
    FUN_006e5610(0,1);
    FUN_006e5610(1,1);
  }
  return;
}


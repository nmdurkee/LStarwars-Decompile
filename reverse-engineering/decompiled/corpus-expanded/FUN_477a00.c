/* Ghidra pseudocode, not original source.
 * ev_d7259de4d528e446adcf31e3fd20dda0be8e8c3eebc020039674bf2429a30a4e
 * Entry: 0x477a00; label: FUN_00477a00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00477a00(int param_1)

{
  int *piVar1;
  undefined2 uVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  float10 fVar7;
  
  iVar5 = *(int *)(param_1 + 0x2ae0);
  if ((iVar5 != 0) && (uVar6 = 0, 0 < DAT_00951360)) {
    do {
      *(undefined4 *)(iVar5 + 4) = 0x49f42400;
      *(undefined4 *)(iVar5 + 0xc) = 0;
      *(undefined4 *)(iVar5 + 0x10) = 0;
      uVar2 = FUN_0054fa60();
      *(undefined2 *)(iVar5 + 0x34) = uVar2;
      if (PTR_s_negotiations_007f9368 != (undefined *)0x0) {
        piVar3 = &DAT_007f9388;
        do {
          if ((*piVar3 != 0) && (*(byte *)(*piVar3 + 0x7c) == uVar6)) break;
          piVar1 = piVar3 + 7;
          piVar3 = piVar3 + 0xf;
        } while (*piVar1 != 0);
      }
      fVar7 = (float10)FUN_005506f0(0,iVar5,0x40a00000,0xffffffff);
      if ((float)fVar7 != 2e+06) {
        *(float *)(iVar5 + 4) = (float)fVar7;
      }
      uVar4 = FUN_0054fa60();
      *(undefined4 *)(iVar5 + 0x14) = uVar4;
      uVar4 = FUN_0054fa60();
      *(undefined4 *)(iVar5 + 0x1c) = uVar4;
      uVar4 = FUN_0054fa60();
      *(undefined4 *)(iVar5 + 0x24) = uVar4;
      uVar4 = FUN_0054fa60();
      *(undefined4 *)(iVar5 + 0x2c) = uVar4;
      FUN_0054fa60();
      uVar4 = FUN_006e6b90();
      *(undefined4 *)(iVar5 + 0x18) = uVar4;
      FUN_0054fa60();
      uVar4 = FUN_006e6b90();
      *(undefined4 *)(iVar5 + 0x20) = uVar4;
      FUN_0054fa60();
      uVar4 = FUN_006e6b90();
      *(undefined4 *)(iVar5 + 0x28) = uVar4;
      FUN_0054fa60();
      uVar4 = FUN_006e6b90();
      *(undefined4 *)(iVar5 + 0x74) = 0;
      *(undefined4 *)(iVar5 + 0x6c) = 0;
      *(undefined4 *)(iVar5 + 0x30) = uVar4;
      *(undefined4 *)(iVar5 + 0x78) = 0;
      *(undefined2 *)(iVar5 + 0x3a) = *(undefined2 *)(iVar5 + 0x34);
      *(undefined4 *)(iVar5 + 0x70) = 0;
      *(undefined2 *)(iVar5 + 0x36) = 0;
      *(undefined2 *)(iVar5 + 0x38) = 0;
      *(undefined1 *)(iVar5 + 0x3d) = 0;
      *(undefined1 *)(iVar5 + 0x3c) = 0;
      uVar6 = uVar6 + 1;
      iVar5 = iVar5 + 0x7c;
    } while ((int)uVar6 < DAT_00951360);
  }
  return;
}


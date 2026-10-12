/* Ghidra pseudocode, not original source.
 * ev_8be83d5a314ed06484cc1a00e0611cd4a1346ac66c548b102291ab30b68096a0
 * Entry: 0x4cce10; label: FUN_004cce10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004cce10(int param_1)

{
  int iVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  float10 fVar8;
  
  if (*(int *)(param_1 + 0x507c) != 0) {
    return 0;
  }
  iVar4 = FUN_006217e0();
  iVar5 = FUN_006217e0();
  iVar7 = 0;
  *(int *)(param_1 + 0x507c) = iVar5;
  if (0 < iVar5) {
    iVar5 = 0;
    do {
      FUN_006216f0(*(int *)(param_1 + 0x5078) + iVar5,0x10);
      FUN_00621900(iVar5 + 0x10 + *(int *)(param_1 + 0x5078));
      uVar3 = FUN_00621860();
      *(undefined2 *)(iVar5 + 0x30 + *(int *)(param_1 + 0x5078)) = uVar3;
      if (1 < iVar4) {
        uVar2 = FUN_006218c0();
        *(undefined1 *)(iVar5 + 0x37 + *(int *)(param_1 + 0x5078)) = uVar2;
        uVar6 = FUN_006217e0();
        FUN_006216f0(iVar5 + 0x4d + *(int *)(param_1 + 0x5078),uVar6);
        iVar1 = iVar5 + *(int *)(param_1 + 0x5078);
        FUN_004f1f10(iVar1 + 0x3d,iVar1 + 0x4d);
        if (iVar4 < 3) {
          *(undefined1 *)(iVar5 + 0x36 + *(int *)(param_1 + 0x5078)) = 1;
        }
        else {
          uVar2 = FUN_006218c0();
          *(undefined1 *)(iVar5 + 0x36 + *(int *)(param_1 + 0x5078)) = uVar2;
        }
      }
      if (iVar4 < 4) {
        *(undefined4 *)(iVar5 + 0x2c + *(int *)(param_1 + 0x5078)) = 0x3f800000;
      }
      else {
        fVar8 = (float10)FUN_006217a0();
        *(float *)(iVar5 + 0x2c + *(int *)(param_1 + 0x5078)) = (float)fVar8;
      }
      if (iVar4 < 5) {
        *(undefined4 *)(iVar5 + 0x38 + *(int *)(param_1 + 0x5078)) = 0;
      }
      else {
        uVar6 = FUN_006217e0();
        *(undefined4 *)(iVar5 + 0x38 + *(int *)(param_1 + 0x5078)) = uVar6;
      }
      iVar7 = iVar7 + 1;
      iVar5 = iVar5 + 0x70;
    } while (iVar7 < *(int *)(param_1 + 0x507c));
  }
  return 1;
}


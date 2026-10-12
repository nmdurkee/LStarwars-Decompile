/* Ghidra pseudocode, not original source.
 * ev_d9512b1cdbab5300ab403012014fa5708c5416e00a513842278be36b13b8a77c
 * Entry: 0x46f8c0; label: FUN_0046f8c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0046f8c0(int param_1)

{
  byte *pbVar1;
  int *piVar2;
  char cVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  float10 fVar9;
  
  if (((param_1 != 0) && (piVar2 = *(int **)(param_1 + 0x5100), piVar2 != (int *)0x0)) &&
     (piVar2[1] == 0)) {
    iVar5 = FUN_006217e0();
    iVar6 = FUN_006217e0();
    piVar2[1] = iVar6;
    if (iVar5 < 3) {
      fVar9 = (float10)1;
    }
    else {
      fVar9 = (float10)FUN_006217a0();
    }
    iVar6 = 0;
    piVar2[2] = (int)(float)fVar9;
    if (0 < piVar2[1]) {
      iVar8 = 0;
      do {
        uVar7 = FUN_006217e0();
        FUN_006216f0(*piVar2 + iVar8,uVar7);
        FUN_00621900(*piVar2 + 0x10 + iVar8);
        uVar4 = FUN_00621860();
        *(undefined2 *)(*piVar2 + 0x20 + iVar8) = uVar4;
        if (iVar5 < 2) {
          pbVar1 = (byte *)(*piVar2 + 0x2b + iVar8);
          *pbVar1 = *pbVar1 & 0xfb;
        }
        else {
          cVar3 = FUN_006218e0();
          pbVar1 = (byte *)(*piVar2 + 0x2b + iVar8);
          *pbVar1 = *pbVar1 ^ ((cVar3 != '\0') * '\x04' ^ *(byte *)(*piVar2 + 0x2b + iVar8)) & 4;
        }
        iVar6 = iVar6 + 1;
        iVar8 = iVar8 + 0x2c;
      } while (iVar6 < piVar2[1]);
    }
    return 1;
  }
  return 0;
}


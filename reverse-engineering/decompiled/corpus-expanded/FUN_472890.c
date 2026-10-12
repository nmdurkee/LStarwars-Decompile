/* Ghidra pseudocode, not original source.
 * ev_f56492005d3db2572965d416e35be25a43fb24333701b400d47d471ee6ec09ab
 * Entry: 0x472890; label: FUN_00472890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00472890(int param_1)

{
  byte *pbVar1;
  int *piVar2;
  undefined1 uVar3;
  char cVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  float10 fVar10;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x5074) != 0)) {
    piVar2 = *(int **)(param_1 + 0x5074);
    if (*piVar2 != 0) {
      return 0;
    }
    iVar6 = FUN_006217e0();
    iVar7 = FUN_006217e0();
    iVar9 = 0;
    *piVar2 = iVar7;
    if (0 < iVar7) {
      iVar7 = 0;
      do {
        uVar8 = FUN_006217e0();
        FUN_006216f0(piVar2[3] + 0x40 + iVar7,uVar8);
        FUN_00621900(piVar2[3] + 0x50 + iVar7);
        uVar5 = FUN_00621860();
        *(undefined2 *)(piVar2[3] + 0x5c + iVar7) = uVar5;
        uVar3 = FUN_006218c0();
        *(undefined1 *)(piVar2[3] + 0x5e + iVar7) = uVar3;
        if (iVar6 < 3) {
          *(undefined1 *)(piVar2[3] + 0x61 + iVar7) = 0x72;
        }
        else {
          uVar3 = FUN_006218c0();
          *(undefined1 *)(piVar2[3] + 0x61 + iVar7) = uVar3;
        }
        if (iVar6 < 4) {
          *(undefined4 *)(piVar2[3] + 0x74 + iVar7) = 0;
          *(undefined4 *)(piVar2[3] + 0x70 + iVar7) = 0;
          *(undefined4 *)(piVar2[3] + 0x78 + iVar7) = 0xbe138ef3;
          *(undefined4 *)(piVar2[3] + 0x90 + iVar7) = 0x3f800000;
        }
        else {
          FUN_00621900(piVar2[3] + 0x70 + iVar7);
          fVar10 = (float10)FUN_006217a0();
          *(float *)(piVar2[3] + 0x90 + iVar7) = (float)fVar10;
        }
        if (4 < iVar6) {
          cVar4 = FUN_006218c0();
          pbVar1 = (byte *)(piVar2[3] + 99 + iVar7);
          *pbVar1 = *pbVar1 ^ (cVar4 << 5 ^ *(byte *)(piVar2[3] + 99 + iVar7)) & 0x20;
        }
        *(undefined2 *)(piVar2[3] + 0x80 + iVar7) = 0xffff;
        iVar9 = iVar9 + 1;
        iVar7 = iVar7 + 0xa0;
      } while (iVar9 < *piVar2);
    }
    return 1;
  }
  return 0;
}


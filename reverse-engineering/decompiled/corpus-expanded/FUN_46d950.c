/* Ghidra pseudocode, not original source.
 * ev_da30da9df459bd28e82b339ffdc0f4cd1266c83ded903d656831cff2a8a86063
 * Entry: 0x46d950; label: FUN_0046d950
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0046d950(int param_1)

{
  byte *pbVar1;
  int *piVar2;
  undefined1 uVar3;
  char cVar4;
  byte bVar5;
  undefined2 uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  float10 fVar11;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x5070) != 0)) {
    piVar2 = *(int **)(param_1 + 0x5070);
    if (*piVar2 != 0) {
      return 0;
    }
    iVar7 = FUN_006217e0();
    iVar8 = FUN_006217e0();
    iVar10 = 0;
    *piVar2 = iVar8;
    if (0 < iVar8) {
      iVar8 = 0;
      do {
        uVar9 = FUN_006217e0();
        FUN_006216f0(piVar2[1] + 0x40 + iVar8,uVar9);
        FUN_00621900(piVar2[1] + 0x50 + iVar8);
        uVar6 = FUN_00621890();
        *(undefined2 *)(piVar2[1] + 0x5c + iVar8) = uVar6;
        uVar3 = FUN_006218c0();
        *(undefined1 *)(piVar2[1] + 0x61 + iVar8) = uVar3;
        if (2 < iVar7) {
          cVar4 = FUN_006218c0();
          pbVar1 = (byte *)(piVar2[1] + 0x62 + iVar8);
          *pbVar1 = *pbVar1 ^ (cVar4 << 5 ^ *(byte *)(piVar2[1] + 0x62 + iVar8)) & 0x20;
        }
        if (iVar7 < 4) {
          *(undefined4 *)(piVar2[1] + 0x74 + iVar8) = 0;
          *(undefined4 *)(piVar2[1] + 0x70 + iVar8) = 0;
          *(undefined4 *)(piVar2[1] + 0x78 + iVar8) = 0xbecccccd;
          *(undefined4 *)(piVar2[1] + 0x8c + iVar8) = 0x3f800000;
        }
        else {
          FUN_00621900(piVar2[1] + 0x70 + iVar8);
          fVar11 = (float10)FUN_006217a0();
          *(float *)(piVar2[1] + 0x8c + iVar8) = (float)fVar11;
        }
        if (4 < iVar7) {
          cVar4 = FUN_006218c0();
          pbVar1 = (byte *)(piVar2[1] + 0x62 + iVar8);
          *pbVar1 = *pbVar1 ^ (cVar4 << 6 ^ *(byte *)(piVar2[1] + 0x62 + iVar8)) & 0x40;
        }
        if (5 < iVar7) {
          cVar4 = FUN_006218c0();
          pbVar1 = (byte *)(piVar2[1] + 0x62 + iVar8);
          *pbVar1 = *pbVar1 & 0x7f | cVar4 << 7;
          bVar5 = FUN_006218c0();
          pbVar1 = (byte *)(piVar2[1] + 99 + iVar8);
          *pbVar1 = *pbVar1 ^ (*(byte *)(piVar2[1] + 99 + iVar8) ^ bVar5) & 1;
        }
        if (6 < iVar7) {
          cVar4 = FUN_006218c0();
          pbVar1 = (byte *)(piVar2[1] + 99 + iVar8);
          *pbVar1 = *pbVar1 ^ (cVar4 * '\x02' ^ *(byte *)(piVar2[1] + 99 + iVar8)) & 2;
        }
        if (iVar7 < 8) {
          pbVar1 = (byte *)(piVar2[1] + 99 + iVar8);
          *pbVar1 = *pbVar1 & 0xfb;
        }
        else {
          cVar4 = FUN_006218c0();
          pbVar1 = (byte *)(piVar2[1] + 99 + iVar8);
          *pbVar1 = *pbVar1 ^ ((cVar4 != '\0') * '\x04' ^ *(byte *)(piVar2[1] + 99 + iVar8)) & 4;
        }
        iVar10 = iVar10 + 1;
        iVar8 = iVar8 + 0x90;
      } while (iVar10 < *piVar2);
    }
    return 1;
  }
  return 0;
}


/* Ghidra pseudocode, not original source.
 * ev_608779b64e90f57b93ecbf13df65bed39f2d483d8cb24d2405739ebf49354e95
 * Entry: 0x57ccb0; label: FUN_0057ccb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0057ccb0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  short sVar4;
  int *piVar6;
  int unaff_EDI;
  uint uVar5;
  
  puVar1 = *(undefined4 **)(unaff_EDI + 0x2ab0);
  uVar5 = 0xffffffff;
  sVar4 = -1;
  if (puVar1 != (undefined4 *)0x0) {
    uVar3 = 0;
    if (0 < (int)puVar1[1]) {
      piVar6 = (int *)*puVar1;
      do {
        if (*piVar6 == param_1) {
          uVar5 = uVar3 & 0xffff;
        }
        sVar4 = (short)uVar5;
        uVar3 = uVar3 + 1;
        piVar6 = piVar6 + 1;
      } while ((int)uVar3 < (int)puVar1[1]);
    }
    iVar2 = *(int *)(unaff_EDI + 0x130);
    if (iVar2 != 0) {
      uVar5 = 1 << ((byte)sVar4 & 0x1f);
      if (((sVar4 != -1) && ((*(byte *)(param_1 + 0x18a) & 1) != 0)) &&
         ((*(uint *)(iVar2 + 0x2820) & uVar5) != 0)) {
        return 1;
      }
      *(uint *)(iVar2 + 0x2820) = *(uint *)(iVar2 + 0x2820) | uVar5;
    }
  }
  return 0;
}


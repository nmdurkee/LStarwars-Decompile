/* Ghidra pseudocode, not original source.
 * ev_6c627fdc098d062fc30e762de358fb2844ba9203c9bb8f32313df93bcbce3bd5
 * Entry: 0x69edd0; label: FUN_0069edd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0069edd0(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (uint)*(byte *)(*param_1 + 0x1a);
  iVar1 = 0;
  iVar2 = 0;
  if (uVar3 != 0) {
    do {
      if (*(char *)(*param_1 + 0x1b + iVar2) != -1) {
        iVar1 = iVar1 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)uVar3);
  }
  return iVar1;
}


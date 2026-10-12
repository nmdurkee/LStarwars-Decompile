/* Ghidra pseudocode, not original source.
 * ev_e3284882596e4924dd8e2753f6ae25b39d285bc55fae2794478040fb50a7242b
 * Entry: 0x500b00; label: FUN_00500b00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00500b00(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint *in_EDX;
  int unaff_EDI;
  
  if (in_EDX[4] != 0) {
    uVar1 = in_EDX[4] + in_ECX;
    in_EDX[4] = uVar1;
    if (*(int *)(uVar1 + 4) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(uVar1 + 4) + in_ECX;
    }
    *(int *)(uVar1 + 4) = iVar2;
    if (unaff_EDI != 0) {
      if (4 < (*in_EDX & 0xff)) {
        if (*(int *)(uVar1 + 0x1c) != 0) {
          uVar3 = FUN_005e91f0(*(int *)(uVar1 + 0x1c));
          *(undefined4 *)(uVar1 + 0x1c) = uVar3;
        }
        uVar3 = FUN_005da600(*(undefined4 *)(uVar1 + 0x20));
        *(undefined4 *)(uVar1 + 0x20) = uVar3;
      }
      if (*(int *)(uVar1 + 8) != 0) {
        uVar3 = FUN_005e91f0(*(int *)(uVar1 + 8));
        *(undefined4 *)(uVar1 + 8) = uVar3;
      }
      uVar3 = FUN_005da600(*(undefined4 *)(uVar1 + 0xc));
      *(undefined4 *)(uVar1 + 0xc) = uVar3;
    }
  }
  return;
}


/* Ghidra analysis pseudocode, not original source.
 * ev_b66c424cb3575f57780fb90d996a1c84f19feddd26ab04bda15cdd4040b17690
 * Entry: 0x500b00; label: FUN_00500b00
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


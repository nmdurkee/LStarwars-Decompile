/* Ghidra pseudocode, not original source.
 * ev_2eacd74f46b42f047692015e667debd6c21dbe0f18f3288a1bcbfaeff2ef0d47
 * Entry: 0x4f0230; label: FUN_004f0230
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f0230(void)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_EDI;
  
  iVar3 = DAT_0091ee8c;
  if (DAT_00915fb4 < DAT_0091ee8c) {
    iVar3 = DAT_00915fb4;
  }
  iVar4 = iVar3;
  if (DAT_009163bc < iVar3) {
    iVar4 = DAT_009163bc;
  }
  uVar1 = (uint)(DAT_009163bc < iVar3);
  if (DAT_009167c4 < iVar4) {
    uVar1 = 2;
    iVar4 = DAT_009167c4;
  }
  if (DAT_00916bcc < iVar4) {
    uVar1 = 3;
  }
  piVar2 = (int *)(&DAT_00915fb0 + uVar1 * 0x408);
  if (*piVar2 != 0) {
    *(undefined4 *)(*piVar2 + 0x38) = 0;
  }
  (&DAT_00915fb4)[uVar1 * 0x102] = DAT_0091ee8c;
  *piVar2 = (int)unaff_EDI;
  DAT_0091ee8c = DAT_0091ee8c + 1;
  unaff_EDI[0xe] = piVar2;
  if (unaff_EDI[10] != 0) {
    iVar3 = -unaff_EDI[10];
    FUN_004ff430(*unaff_EDI,iVar3,iVar3 >> 0x1f,1);
    FUN_004ff3b0(*unaff_EDI,uVar1 * 0x408 + 0x915fb8,unaff_EDI[10]);
  }
  return;
}


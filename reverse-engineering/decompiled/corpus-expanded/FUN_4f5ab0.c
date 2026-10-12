/* Ghidra pseudocode, not original source.
 * ev_afcbc9daecc4d4a2b146ef6b9891ec5ae66b352999eedb1b1bbc487287b5378a
 * Entry: 0x4f5ab0; label: FUN_004f5ab0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_004f5ab0(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = FUN_004f5950();
  uVar2 = *param_1;
  while (uVar2 < 0xf) {
    switch(uVar2) {
    case 0:
      FUN_004f5380();
      iVar3 = FUN_004f5950();
      uVar1 = uVar1 + iVar3;
      break;
    case 1:
      FUN_004f5380();
      iVar3 = FUN_004f5950();
      uVar1 = uVar1 - iVar3;
      break;
    default:
      goto switchD_004f5ad7_caseD_2;
    case 9:
      FUN_004f5380();
      uVar2 = FUN_004f5950();
      uVar1 = uVar1 | uVar2;
      break;
    case 10:
      FUN_004f5380();
      uVar2 = FUN_004f5950();
      uVar1 = uVar1 & uVar2;
      break;
    case 0xc:
      FUN_004f5380();
      uVar2 = FUN_004f5950();
      uVar1 = uVar1 ^ uVar2;
      break;
    case 0xd:
      FUN_004f5380();
      iVar3 = FUN_004f5950();
      if ((uVar1 != 0) || (iVar3 != 0)) {
LAB_004f5b5a:
        uVar1 = 1;
      }
      break;
    case 0xe:
      FUN_004f5380();
      iVar3 = FUN_004f5950();
      if ((uVar1 != 0) && (iVar3 != 0)) goto LAB_004f5b5a;
      uVar1 = 0;
    }
    uVar2 = *param_1;
  }
switchD_004f5ad7_caseD_2:
  return uVar1;
}


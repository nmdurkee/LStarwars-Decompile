/* Ghidra pseudocode, not original source.
 * ev_e691f105e7e9df146417299401ecc100ef54520e911e9eb278e110fa7bbc9740
 * Entry: 0x4c7750; label: FUN_004c7750
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004c7750(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 local_4;
  
  local_4 = 0x3f800000;
  iVar3 = -1;
  iVar2 = -1;
  sVar1 = DAT_00880824;
  if (DAT_008800a0 == FUN_004c6e90) {
LAB_004c77be:
    iVar2 = (int)sVar1;
    iVar3 = (int)DAT_00880868;
  }
  else if (DAT_008800a0 == (code *)&LAB_004c39a0) {
    sVar1 = DAT_008808a0;
    if (DAT_008801ac != 5) {
      sVar1 = DAT_008808a4;
    }
    iVar3 = (int)sVar1;
    iVar2 = FUN_004c6c70();
    if (iVar2 == 0) {
      local_4 = 0x3e800000;
    }
    iVar2 = (int)DAT_0088086c;
  }
  else {
    sVar1 = DAT_0088086c;
    if (DAT_008800a0 == FUN_004c41a0) goto LAB_004c77be;
  }
  if (DAT_00951b50 == 0) {
    if (iVar3 != -1) goto LAB_004c77dd;
  }
  else {
    iVar3 = -1;
  }
  if (iVar2 == -1) {
    return;
  }
LAB_004c77dd:
  FUN_004b79a0(DAT_0087b6c8,iVar3,local_4,0xffffffff,iVar2,0xffffffff,(int)DAT_00880e8c,DAT_0087b6c9
               ,iVar3,local_4,0xffffffff,iVar2,0xffffffff,(int)DAT_00880e8c);
  return;
}


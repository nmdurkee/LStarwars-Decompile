/* Ghidra pseudocode, not original source.
 * ev_04b6c5fb0da19ab46b9dcd6e2bf7aaf6621f6765e7317b7c56ac1531caca2973
 * Entry: 0x65a690; label: FUN_0065a690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065a690(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  DAT_029620f4 = 0;
  if ((*(byte *)(param_2 + 0x11) & 1) == 0) {
    uVar1 = 0x3f800000;
    iVar2 = DAT_02962010 * 0xb5 + DAT_02920aa8;
    (&DAT_02930038)[iVar2] = 0;
  }
  else {
    uVar1 = 0x42480000;
    iVar2 = DAT_02962010 * 0xb5 + DAT_02920aa8;
    (&DAT_02930038)[iVar2] = 1;
  }
  (&DAT_02930058)[iVar2] = uVar1;
  FUN_006279f0(param_1);
  FUN_00624220(param_1);
  return;
}


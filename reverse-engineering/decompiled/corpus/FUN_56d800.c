/* Ghidra analysis pseudocode, not original source.
 * ev_9c4a7344b4ed6999b1698de871080e88c37121f37ac9563577536a7a556549db
 * Entry: 0x56d800; label: FUN_0056d800
 */

int FUN_0056d800(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x4690);
  if ((iVar3 != 0) && (iVar4 = 0, 0 < *(int *)(param_1 + 0x4694))) {
    do {
      bVar1 = *(byte *)(iVar3 + 0x34);
      if (((bVar1 & 2) != 0) &&
         ((((bVar1 & 1) != 0 && ((bVar1 & 4) == 0)) &&
          (iVar2 = FUN_0056d760(param_2,iVar3,0,param_3), iVar2 != 0)))) {
        return iVar3;
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x40;
    } while (iVar4 < *(int *)(param_1 + 0x4694));
  }
  return 0;
}


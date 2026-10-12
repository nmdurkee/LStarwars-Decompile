/* Ghidra analysis pseudocode, not original source.
 * ev_7906274d0bf06d109a71291565ad9b380751ea78f5df54402dc74cb176b33c5a
 * Entry: 0x55a390; label: FUN_0055a390
 */

int FUN_0055a390(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = 0;
  if ((((param_1 != 0) && (DAT_0093b268 != (int *)0x0)) && (param_3 != 0)) &&
     (iVar5 = 0, 0 < *DAT_0093b268)) {
    iVar4 = 0;
    piVar3 = DAT_0093b268;
    iVar7 = iVar6;
    do {
      if (param_4 <= iVar7) {
        return iVar7;
      }
      pcVar1 = *(code **)(piVar3[2] + 0x68 + iVar4);
      iVar6 = iVar7;
      if (((pcVar1 != (code *)0x0) &&
          (iVar2 = (*pcVar1)(param_3 + iVar7 * 4,param_2,param_4 - iVar7,param_5),
          piVar3 = DAT_0093b268, iVar6 = param_4, iVar2 != -1)) &&
         (iVar6 = iVar7 + iVar2, param_4 < iVar7 + iVar2)) {
        FUN_00559570();
        return param_4;
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x9c;
      iVar7 = iVar6;
    } while (iVar5 < *piVar3);
  }
  return iVar6;
}


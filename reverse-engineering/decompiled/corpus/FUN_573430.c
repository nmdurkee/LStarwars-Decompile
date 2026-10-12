/* Ghidra analysis pseudocode, not original source.
 * ev_9251851307bb379bfc9bcabd13d9f753a758e856e200aa29981eaf91127b618c
 * Entry: 0x573430; label: FUN_00573430
 */

int FUN_00573430(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < DAT_00951360) {
    iVar3 = 0;
    do {
      iVar1 = FUN_004f8b10(iVar3 + 0x40 + DAT_00951354,param_1);
      if (iVar1 == 0) {
        if (param_2 != (int *)0x0) {
          *param_2 = iVar2;
        }
        return iVar2 * 0x9c + DAT_00951354;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x9c;
    } while (iVar2 < DAT_00951360);
  }
  if (param_2 != (int *)0x0) {
    *param_2 = -1;
  }
  return 0;
}


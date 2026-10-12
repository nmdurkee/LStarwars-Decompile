/* Ghidra pseudocode, not original source.
 * ev_ea1530849940888f284d0032d7a98207406f19684b2cf3146fa9fb18feca4f87
 * Entry: 0x467ad0; label: FUN_00467ad0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00467ad0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((param_4 != (int *)0x0) && (*(short *)((int)param_4 + 0xe) != 0)) {
    iVar3 = 0;
    iVar2 = 0;
    do {
      iVar1 = FUN_004f1ff0(*param_4 + iVar3);
      if (iVar1 != 0) {
        FUN_00559ee0(param_1,param_2,0,*param_4 + iVar3);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0xa4;
    } while (iVar2 < (int)(uint)*(ushort *)((int)param_4 + 0xe));
  }
  return;
}


/* Ghidra pseudocode, not original source.
 * ev_899eb35a27e8c18144a9bface4dcd684320477ea32232f25bcb19f5ddc9c569a
 * Entry: 0x449ac0; label: FUN_00449ac0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00449ac0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_4;
  
  iVar5 = 0;
  iVar4 = 0;
  local_4 = 0;
  if ((((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
      (*piVar1 != 0)) && (iVar2 = *piVar1, param_6 != 0)) {
    if (0 < param_5) {
      do {
        iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"spline=");
        if (iVar3 == 0) {
          iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"looping");
          if (iVar3 == 0) {
            local_4 = 1;
          }
        }
        else {
          iVar4 = FUN_005d0690(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),iVar3 + 7);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_5);
    }
    *(undefined4 *)(iVar2 + 0xe64) = 0;
    *(undefined4 *)(iVar2 + 0xe68) = 0;
    *(undefined4 *)(iVar2 + 0xe6c) = 0;
    *(undefined4 *)(iVar2 + 0xe70) = 0;
    *(undefined4 *)(iVar2 + 0xe74) = 0;
    *(undefined4 *)(iVar2 + 0xe78) = 0;
    *(undefined4 *)(iVar2 + 0xe7c) = 0;
    *(undefined4 *)(iVar2 + 0xe80) = 0;
    if (iVar4 != 0) {
      FUN_00553570((undefined4 *)(iVar2 + 0xe64),iVar4,0,local_4);
    }
  }
  return 1;
}


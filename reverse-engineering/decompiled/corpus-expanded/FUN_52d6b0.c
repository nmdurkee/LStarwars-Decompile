/* Ghidra pseudocode, not original source.
 * ev_cdff09935bddc4594064dfeb1f42a846ac78fe961445b4150dea7d25416822c1
 * Entry: 0x52d6b0; label: FUN_0052d6b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0052d6b0(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,int param_6)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_8;
  
  iVar5 = 0;
  iVar4 = 0;
  iVar3 = 0;
  local_8 = 1;
  bVar1 = false;
  if ((((param_1 != 0) && (*(char **)(param_1 + 0x10) != (char *)0x0)) &&
      (**(char **)(param_1 + 0x10) != '\0')) && ((param_6 != 0 && (0 < param_5)))) {
    do {
      iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),&DAT_00757f40);
      if (iVar2 == 0) {
        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),&DAT_00757d6c);
        if (iVar2 == 0) {
          iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"bothways");
          if (iVar2 == 0) {
            bVar1 = true;
          }
          else {
            iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"FALSE");
            if (iVar2 == 0) {
              local_8 = 0;
            }
          }
        }
        else {
          iVar3 = iVar2 + 3;
        }
      }
      else {
        iVar4 = iVar2 + 5;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_5);
    if (((iVar4 != 0) && (iVar3 != 0)) &&
       (FUN_0052d5f0(*(undefined4 *)(*(int *)(param_1 + 0x10) + 8),iVar4,iVar3,local_8), bVar1)) {
      FUN_0052d5f0(*(undefined4 *)(*(int *)(param_1 + 0x10) + 8),iVar3,iVar4,local_8);
    }
  }
  return 1;
}


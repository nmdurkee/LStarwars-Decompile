/* Ghidra analysis pseudocode, not original source.
 * ev_82de32114f0a758998fb1b139028178946084d97602e6dd81f3d90db1eb3e6aa
 * Entry: 0x5ae150; label: FUN_005ae150
 */

void FUN_005ae150(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_3 != 0) {
    piVar1 = *(int **)(param_3 + 0x5108);
    iVar3 = 0;
    if (0 < piVar1[1]) {
      iVar4 = 0;
      do {
        iVar2 = FUN_004f1ff0(*piVar1 + iVar4);
        if (iVar2 != 0) {
          FUN_00559ee0(param_1,param_2,0,**(int **)(param_3 + 0x5108) + iVar4);
        }
        piVar1 = *(int **)(param_3 + 0x5108);
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0x28;
      } while (iVar3 < piVar1[1]);
    }
  }
  return;
}

